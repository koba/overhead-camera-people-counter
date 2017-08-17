#ifndef IMAGE_GRID_WINDOW_CPP
#define IMAGE_GRID_WINDOW_CPP

#include <assert.h>
#include <string>
#include <opencv2/opencv.hpp>
#include "ImageGridCell.cpp"

using namespace cv;

class ImageGridWindow {

private:

    String title;
    Size size;
    bool isVisible;

    int rows;
    int cols;
    vector<ImageGridCell> cells;

    ImageGridCell& cell(int i, int j) {
        return cells[i + j * rows];
    }

public:

    ImageGridWindow(String title, int rows = 1, int cols = 1) {
        this->title = title;
        this->isVisible = false;

        this->rows = rows;
        this->cols = cols;
        this->cells = vector<ImageGridCell>(rows * cols);
    }

    ImageGridWindow* setGridCellTitle(int i, int j, String title) {
        cell(i, j).setTitle(title);
        return this;
    }

    ImageGridWindow* setGridCellImage(int i, int j, Mat image) {
        cell(i, j).setImage(image);
        return this;
    }

    ImageGridWindow* setSize(int width, int height) {
        assert(!isVisible);

        size = Size(width, height);
        return this;
    }

    ImageGridWindow* addTrackbar(string name, int* value, int maxValue) {
        assert(isVisible);

        createTrackbar(name, title, value, maxValue);
        return this;
    }

    ImageGridWindow* show() {
        assert(!isVisible);
        
        namedWindow(title, WINDOW_NORMAL);
        resizeWindow(title, size.width, size.height);
        isVisible = true;
        return this;
    }
    
    void draw() {
        assert(isVisible);

        Mat image(size.height, size.width, CV_8UC3);
        Size cellImageSize = Size(size.width / cols, size.height / rows);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                Rect cellROIRect = Rect(j * cellImageSize.width, i * cellImageSize.height, cellImageSize.width, cellImageSize.height);
                
                if (cell(i, j).hasImage()) {
                    Mat cellImage;
                    resize(cell(i, j).getImage(), cellImage, cellImageSize);
                    
                    if (cellImage.type() == CV_8UC1) {
                        cvtColor(cellImage, cellImage, CV_GRAY2RGB);
                    }

                    cellImage.copyTo(image(cellROIRect));
                }

                String cellTitle = cell(i, j).getTitle();
                Size cellTitleTextSize = getTextSize(cellTitle, FONT_HERSHEY_COMPLEX_SMALL, 1.0, 1, NULL);
                putText(image, cellTitle, Point(cellROIRect.x + (cellROIRect.width / 2 - cellTitleTextSize.width / 2), cellTitleTextSize.height + 8), FONT_HERSHEY_COMPLEX_SMALL, 0.75, Scalar(0, 0, 255));
            }
        }

        imshow(title, image);

        waitKey(1);
    }
    
};

#endif