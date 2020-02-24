# overhead-camera-people-counter

## Why it exists?

I created it out of the need to explore the OpenCV library to count people passing through a door. The algorithm is based on https://github.com/jeffskinnerbox/people-counter.

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

