#include <opencv2/opencv.hpp>

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
};

static bool operator==(const Line& left, const Line& right) {
    return left.start == right.start && left.end == right.end;
}