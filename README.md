# people-counter

## Why do it exists?

This repo was created out of the need to explore OpenCV library in order to count people passsing through a door. I based my research on this article http://www.femb.com.mx/people-counter and the [OpenCV API reference](http://docs.opencv.org/3.0-beta/modules/refman.html).

## Build

### Pre-requisites

#### Linux

1. `apt-get install cmake g++ gdb`

2. [TODO: how to install opencv3]

#### macOS

1. `brew install cmake`

2. OpenCV

    ```sh
    brew install opencv3 --with-ffmpeg
    brew link opencv3 --force
    ```

#### Windows

1. Install [cmake](https://cmake.org/files/v3.9/cmake-3.9.0-win64-x64.msi)

2. Install [OpenCV](https://sourceforge.net/projects/opencvlibrary/files/opencv-win/3.2.0/opencv-3.2.0-vc14.exe/download)
    
### Build `people-counter`

#### Linux

`cmake -B/build -H.`

#### macOS / Windows

`cmake --build /build`

## Run

`./build/people-counter data/bus.avi`

## License

[GPL-3.0](https://github.com/agurz/people-counter/blob/master/LICENSE)

---

<div>Icons made by <a href="http://www.freepik.com" title="Freepik">Freepik</a> from <a href="http://www.flaticon.com" title="Flaticon">www.flaticon.com</a> is licensed by <a href="http://creativecommons.org/licenses/by/3.0/" title="Creative Commons BY 3.0" target="_blank">CC 3.0 BY</a></div>
