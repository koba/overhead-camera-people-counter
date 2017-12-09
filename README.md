# overhead-camera-people-counter

## Why do it exists?

It was created out of the need to explore OpenCV library in order to count people passsing through a door. I based my research and the code on this article http://www.femb.com.mx/people-counter and the [OpenCV API reference](http://docs.opencv.org/3.0-beta/modules/refman.html).

## Installing Dependencies

### Linux

Compiler:

```sh
apt-get install cmake g++ gdb
```

OpenCV:

```sh
apt-get install git libavcodec-dev libavformat-dev libgtk2.0-dev libswscale-dev pkg-config
cd ~/
git clone https://github.com/opencv/opencv.git
cd opencv
mkdir release
cd release
cmake -DCMAKE_BUILD_TYPE=RELEASE -DCMAKE_INSTALL_PREFIX=/usr/local ..
make
make install
```

### macOS

Compiler:

```sh
brew install cmake
```

OpenCV:

```sh
brew install opencv3 --with-ffmpeg
brew link opencv3 --force
```

### Windows

Compiler: 

[cmake-3.9.0-win64-x64](https://cmake.org/files/v3.9/cmake-3.9.0-win64-x64.msi)

OpenCV:

[opencv-3.2.0-vc14](https://sourceforge.net/projects/opencvlibrary/files/opencv-win/3.2.0/opencv-3.2.0-vc14.exe/download)
    
## Build

`cmake --build /build`

## Run

`./build/people-counter data/bus.avi`

## License

[GPL-3.0](https://github.com/agurz/people-counter/blob/master/LICENSE)

