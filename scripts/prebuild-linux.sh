# cmake
sudo apt-get install -y cmake g++ gdb

# opencv
sudo apt-get install -y git libavcodec-dev libavformat-dev libgtk2.0-dev libswscale-dev pkg-config
cd ~/
git clone https://github.com/opencv/opencv.git
cd opencv
git checkout 3.2.0
mkdir release
cd release
cmake -DCMAKE_BUILD_TYPE=RELEASE -DCMAKE_INSTALL_PREFIX=/usr/local ..
make
make install