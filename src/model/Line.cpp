#ifndef LINE_CPP
#define LINE_CPP

#include <opencv2/opencv.hpp>

#define LINE_DIRECTION_UP 1
#define LINE_DIRECTION_DOWN -1

using namespace cv;

class Line {

public:

    Point start;
    Point end;

    Line() {
    }

    Line(int startX, int startY, int endX, int endY) {
        this->start = Point(startX, startY);
        this->end = Point(endX, endY);
    }

    inline bool operator==(const Line& right) {
        return start == right.start && end == right.end;
    }
};

#endif