#include <chrono>
#include <string>

using namespace std::chrono;

typedef high_resolution_clock::time_point time_p;

class Person {

public:

    int id = 0;
    Rect boundingBox;
    vector<Point> contour;
    Point contourXY;
    vector<Point> trace;

    int x;
    int y;
    
    time_p firstSeen;
    time_p lastSeen;

    Person(vector<Point> contour) {
        this->update(contour);
    }

    // member methods

    bool hasSimilarContour(const vector<Point> contour) const {
        Point contourXY = findContourXY(contour);

        bool contourIsClose = abs(x - contourXY.x) <= boundingBox.width && 
                              abs(y - contourXY.y) <= boundingBox.height;

        return contourIsClose;
    }

    void update(const vector<Point> contour) {
        this->boundingBox = boundingRect(contour);
        this->contour = contour;
        this->contourXY = findContourXY(contour);
        this->trace.push_back(contourXY);
        this->x = contourXY.x;
        this->y = contourXY.y;
    }

private:
    
    Point findContourXY(const vector<Point> contour) const {
        Moments contourMoments = moments(contour);
        
        return Point(
            (int)(contourMoments.m10 / contourMoments.m00),
            (int)(contourMoments.m01 / contourMoments.m00)
        );
    }

};