
class VideoCapturePeopleCounterDelegate {

public:
    
    virtual void onFrameProcess(const Mat& frame, const Mat& debugFrame) = 0;
    
    virtual void onFrameWithPersonDetected(const Mat& frame, const Mat& debugFrame, const Person* person) = 0;

};