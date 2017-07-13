# people-counter

### Why do it exists?

This repo was created out of the need to explore OpenCV library in order to count people passsing through a door. I based my research on this article http://www.femb.com.mx/people-counter and the [OpenCV API reference](http://docs.opencv.org/3.0-beta/modules/refman.html).

### How it works?

[TODO]

### Build Requirements

* cmake
* OpenCV

#### OpenCV Installation

* Linux:

    [TODO: how to install opencv3]

* macOS:

    `brew install opencv3 --with-ffmpeg`

    `brew link opencv3 --force`

* Windows:

    [Download and install OpenCV](https://sourceforge.net/projects/opencvlibrary/files/opencv-win/3.2.0/opencv-3.2.0-vc14.exe/download)
    
### Build

`cmake --build /build --target all`

### Run

* Linux / macOS:

    `./build/people-counter data/bus.avi`

* Windows:

    `\build\people-counter.exe  data\\bus.avi`