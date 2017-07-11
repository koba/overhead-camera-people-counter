#ifndef PERSON_CPP
#define PERSON_CPP

#include <opencv2/opencv.hpp>
#include "Line.cpp"
#include "../util/intersect.cpp"

using namespace cv;
using namespace std;

class Person {

private:

    Rect boundingBox;
    vector<Point> contour;
    vector<Point> trace;
    int x;
    int y;
    int lastFrame;
    vector<Line> crossedLines;
    
    Point getContourPosition(vector<Point> contour) {
        Moments contourMoments = moments(contour);
        
        return Point(
            (int)(contourMoments.m10 / contourMoments.m00),
            (int)(contourMoments.m01 / contourMoments.m00)
        );
    }

public:

    static int MIN_CONTOUR_AREA;

    Person(vector<Point> contour) {
        this->contour = contour;
        this->updatePosition(contour);
    }

    vector<Point> getContour() {
        return contour;
    }

    Point getBoundingBoxTLPoint() {
        return boundingBox.tl();
    }

    Point getBoundingBoxBRPoint() {
        return boundingBox.br();
    }

    vector<Point> getTrace() {
        return trace;
    }

    int getLastFrame() {
        return lastFrame;
    }

    void setLastFrame(int lastFrame) {
        this->lastFrame = lastFrame;
    }

    void updatePosition(vector<Point> contour) {
        Point contourPosition = getContourPosition(contour);
        
        this->boundingBox = boundingRect(contour);
        this->trace.push_back(contourPosition);
        this->x = contourPosition.x;
        this->y = contourPosition.y;
    }

    bool isCrossingTheLine(Line line, int* direction = NULL) {
        for (int i = 0; i < crossedLines.size(); i++) {
            if (line == crossedLines[i]) {
                return false;
            }
        }

        if (trace.size() > 2) {
            for (int i = 0; i < trace.size() - 2; i++) {
                if (intersect(trace[i], trace[i + 1], line.start, line.end)) {
                    if (direction != NULL) {
                        *direction = trace[i].y > line.start.y ? LINE_DIRECTION_UP : LINE_DIRECTION_DOWN;
                    }
                    
                    crossedLines.push_back(line);
                    return true;
                }
            }
        }

        return false;
    }

    bool hasSimilarContour(vector<Point> contour) {
        Point contourPosition = getContourPosition(contour);

        bool contourIsClose = abs(x - contourPosition.x) <= boundingBox.width && 
                              abs(y - contourPosition.y) <= boundingBox.height;

        return contourIsClose;
    }

};

int Person::MIN_CONTOUR_AREA = 2000;

#endif