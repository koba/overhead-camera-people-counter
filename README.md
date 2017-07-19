# people-counter

## Why do it exists?

This repo was created out of the need to explore OpenCV library in order to count people passsing through a door. I based my research on this article http://www.femb.com.mx/people-counter and the [OpenCV API reference](http://docs.opencv.org/3.0-beta/modules/refman.html).

## Build Requirements

* cmake

* OpenCV

    <img src="https://i.imgur.com/olgvKch.png" witdh="16" height="16" /> **Linux**

    ```
    [TODO: how to install opencv3]
    ```

    <img src="https://i.imgur.com/ndpoovo.png" witdh="16" height="16" />  **macOS**

    ```sh
    brew install opencv3 --with-ffmpeg
    brew link opencv3 --force
    ```

    <img src="https://i.imgur.com/Hau30UN.png" witdh="16" height="16" />  **Windows**

    [Download and install OpenCV for Windows](https://sourceforge.net/projects/opencvlibrary/files/opencv-win/3.2.0/opencv-3.2.0-vc14.exe/download)
    
## Build

`cmake --build /build --target all`

## Run

`./build/people-counter data/bus.avi`

## License

[GPL-3.0](https://github.com/agurz/people-counter/blob/master/LICENSE)

---

<div>Icons made by <a href="http://www.freepik.com" title="Freepik">Freepik</a> from <a href="http://www.flaticon.com" title="Flaticon">www.flaticon.com</a> is licensed by <a href="http://creativecommons.org/licenses/by/3.0/" title="Creative Commons BY 3.0" target="_blank">CC 3.0 BY</a></div>