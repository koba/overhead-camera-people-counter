#include <opencv2/opencv.hpp>
#include <string>
#include "help.cpp"
#include "model/Line.cpp"
#include "model/Person.cpp"
#include "view/ImageGridWindow.cpp"

#define ALGORITHM_ENTRANCE_LINE_Y 110 
#define ALGORITHM_EXIT_LINE_Y 120 

#define COLOR_ENTRANCE_LINE Scalar(255, 0, 0)
#define COLOR_EXIT_LINE Scalar(0, 0, 255)
#define COLOR_SHAPE Scalar(0, 255, 0)
#define COLOR_SHAPE_BOUNDS_RECT Scalar(0, 0, 255)
#define COLOR_SHAPE_TRACE Scalar(255, 255, 0)

using namespace cv;
using namespace std;

int main(int argc, char** argv) {

    if (argc < 2) return help();

    VideoCapture camera(argv[1]);

    Ptr<BackgroundSubtractor> backgroundSubstractor = createBackgroundSubtractorMOG2();
    int frameNumber = 0;
    vector<Person*> people;
    int peopleUp = 0;
    int peopleDown = 0;
    Line entranceLine;
    Line exitLine;

    ImageGridWindow* window = new ImageGridWindow("people-counter", 1, 2);

    // video processing dynamic variables
    int o = 8;      // opening
    int c = 8;      // closing

    // set and show the window
    window
        ->setGridCellTitle(0, 0, "Output")
        ->setGridCellTitle(0, 1, "Debug")
        ->setSize(1600, 600)
        ->show()
        ->addTrackbar("Opening", &o, 32)
        ->addTrackbar("Closing", &c, 32);

    // loop over the frames of the video
    while (camera.isOpened()) {

        Mat frame, tempFrame;

        // read a frame
        bool frameRead = camera.read(frame);

        if (!frameRead) break;

        // set lines
        if (frameNumber == 0) {
            entranceLine = Line(0, ALGORITHM_ENTRANCE_LINE_Y, frame.cols, ALGORITHM_ENTRANCE_LINE_Y);
            exitLine = Line(0, ALGORITHM_EXIT_LINE_Y, frame.cols, ALGORITHM_EXIT_LINE_Y);
        }

        // substract background from frame
        backgroundSubstractor->apply(frame, tempFrame);

        // binarize frame
        threshold(tempFrame, tempFrame, 128, 255, THRESH_BINARY);

        // morph ops
        morphologyEx(tempFrame, tempFrame, MORPH_OPEN, Mat(o, o, CV_8UC1, Scalar(1)));
        morphologyEx(tempFrame, tempFrame, MORPH_CLOSE, Mat(c, c, CV_8UC1, cv::Scalar(1)));

        // erase old contours (seen 16 frames ago)
        for (int i = 0; i < people.size(); i++) {
            if (frameNumber - people[i]->getLastFrame() > 16) {
                people.erase(people.begin() + i);
            }
        }

        // find contours
        vector<vector<Point> > contours;
        vector<Vec4i> hierarchy;
        findContours(tempFrame, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

        for (int i = 0; i < contours.size(); ++i) {
            if (contourArea(contours[i]) > Person::MIN_CONTOUR_AREA) {
                
                Person* person = NULL;
                vector<Point> contour = contours[i];

                for (int j = 0; j < people.size(); ++j) {
                    if (person == NULL && people[j]->hasSimilarContour(contour)) {
                        person = people[j];
                        person->updatePosition(contour);
                        person->setLastFrame(frameNumber);
                    }
                }

                if (person == NULL) {
                    person = new Person(contour);
                    person->setLastFrame(frameNumber);
                    people.push_back(person);
                }

                // check if person has crossed the lines
                int direction;
                
                if (person->isCrossingTheLine(entranceLine, &direction)) {
                    if (direction == LINE_DIRECTION_UP) peopleUp++;
                }

                if (person->isCrossingTheLine(exitLine, &direction)) {
                    if (direction == LINE_DIRECTION_DOWN) peopleDown++;
                }

                // draw bounding box
                //rectangle(frame, person->getBoundingBoxTLPoint(), person->getBoundingBoxBRPoint(), COLOR_SHAPE_BOUNDS_RECT, 2);

                // draw contour
                drawContours(frame, contours, i, COLOR_SHAPE, 2, 8);

                // draw contour trace
                vector<Point> trace = person->getTrace();
                if (trace.size() > 2) {
                    for (int j = 0; j < trace.size() - 2; ++j) {
                        line(frame, trace[j], trace[j + 1], COLOR_SHAPE_TRACE, 2);
                    }
                }

            }
        }

        // draw measurement lines
        line(frame, Point(0, ALGORITHM_ENTRANCE_LINE_Y), Point(frame.cols, ALGORITHM_ENTRANCE_LINE_Y), COLOR_ENTRANCE_LINE, 2);
        line(frame, Point(0, ALGORITHM_EXIT_LINE_Y), Point(frame.cols, ALGORITHM_EXIT_LINE_Y), COLOR_EXIT_LINE, 2);

        // draw counters
        putText(frame, to_string(peopleUp) + " UP", Point(10, 20), FONT_HERSHEY_COMPLEX_SMALL, 0.75, COLOR_ENTRANCE_LINE);
        putText(frame, to_string(peopleDown) + " DOWN", Point(10, 36), FONT_HERSHEY_COMPLEX_SMALL, 0.75, COLOR_EXIT_LINE);

        // show results
        window
            ->setGridCellImage(0, 0, frame)
            ->setGridCellImage(0, 1, tempFrame)
            ->draw();

        // keep counting frames
        ++frameNumber;
    }

    waitKey(30000);

    // cleanup the camera and close any open windows
    camera.release();
    destroyAllWindows();

}