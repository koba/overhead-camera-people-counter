# overhead-camera-people-counter

## Why do it exists?

It was created out of the need to explore OpenCV library in order to count people passsing through a door. The algorithm is based on the thoughts written in this article http://www.femb.com.mx/people-counter.

## How to build it?

### 1. Install dependencies

Run the script which corresponding to your OS:

* ./scripts/prebuild-linux.sh
* ./scripts/prebuild-macos.sh
* ./scripts/prebuild-windows.cmd
    
### 2. Build

From `overhead-camera-people-counter` root folder:

```
mkdir build
cd build
cmake ..
make
```

## How to run it?

From `overhead-camera-people-counter` root folder:

```
./build/people-counter data/bus.avi
```

## License

[GPL-3.0](https://github.com/agurz/people-counter/blob/master/LICENSE)

