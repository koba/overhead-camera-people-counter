#include <opencv2/opencv.hpp>

using namespace cv;

#define COLOR_ENTRANCE_LINE Scalar(255, 0, 0)
#define COLOR_EXIT_LINE Scalar(0, 0, 255)
#define COLOR_SHAPE Scalar(0, 255, 0)
#define COLOR_SHAPE_BOUNDS_RECT Scalar(0, 0, 255)
#define COLOR_SHAPE_TRACE Scalar(255, 255, 0)

class WindowController : public VideoCapturePeopleCounterDelegate {

public:

    WindowController(const VideoCapturePeopleCounter* counter) {
        this->counter = counter;

        showWindow();
    }

    ~WindowController() {
        destroyAllWindows();
    }

    // member methods

    void showWindow() {
        window = new ImageGridWindow("people-counter", 1, 2);
        
        // set and show the window
        window
            ->setGridCellTitle(0, 0, "Output")
            ->setGridCellTitle(0, 1, "Debug")
            ->setSize(1600, 600)
            ->show();
            //->addTrackbar("Opening", &o, 32)
            //->addTrackbar("Closing", &c, 32);
    }

    // VideoCapturePeopleCounterDelegate methods
    
    void onFrameProcess(const Mat& frame, const Mat& debugFrame) {
        // draw measurement lines
        line(frame, Point(0, counter->refLine.end.y), Point(frame.cols, counter->refLine.end.y), COLOR_ENTRANCE_LINE, 2);

        // draw counters
        putText(frame, to_string(counter->peopleWhoEnteredCount) + " UP", Point(10, 20), FONT_HERSHEY_COMPLEX_SMALL, 0.75, COLOR_ENTRANCE_LINE);
        putText(frame, to_string(counter->peopleWhoExitedCount) + " DOWN", Point(10, 36), FONT_HERSHEY_COMPLEX_SMALL, 0.75, COLOR_EXIT_LINE);

        // show results
        window
            ->setGridCellImage(0, 0, frame)
            ->setGridCellImage(0, 1, debugFrame)
            ->draw();
    }
    
    void onFrameWithPersonDetected(const Mat& frame, const Mat& debugFrame, const Person* person) {
        // draw contour
        vector<vector<Point> > contours;
        contours.push_back(person->contour);
        drawContours(frame, contours, 0, COLOR_SHAPE, 2, 8);

        // draw trace
        if (person->trace.size() > 2) {
            for (int j = 0; j < person->trace.size() - 2; ++j) {
                line(frame, person->trace[j], person->trace[j + 1], COLOR_SHAPE_TRACE, 2);
            }
        }
    }

private:

    const VideoCapturePeopleCounter* counter; 
    ImageGridWindow* window;

};