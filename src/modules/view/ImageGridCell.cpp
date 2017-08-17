#ifndef IMAGE_GRID_CELL_CPP
#define IMAGE_GRID_CELL_CPP

#include <opencv2/opencv.hpp>
#include <string>

using namespace cv;
using namespace std;

class ImageGridCell {

private:

    string title;
    Mat image;

public:

    string getTitle() {
        return this->title;
    }

    void setTitle(string title) {
        this->title = title;
    }

    Mat getImage() {
        return this->image;
    }

    void setImage(Mat image) {
        this->image = image;
    }

    bool hasImage() {
        return !image.empty();
    }

};

#endif