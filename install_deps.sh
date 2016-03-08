#!/bin/bash

# Variables
DEPS_PATH=`pwd`/deps
DEPS_SRC_PATH=$DEPS_PATH/src
DEPS_BUILD_PATH=$DEPS_PATH/build

# Create deps folder
mkdir -p $DEPS_PATH
mkdir -p $DEPS_SRC_PATH
mkdir -p $DEPS_BUILD_PATH


###
# Google Test
###
# Go to deps folder root
cd $DEPS_SRC_PATH
# Download sources
if [ ! -d gtest-1.7.0 ]; then
  echo "=== [START] Download gtest ==="
  wget https://googletest.googlecode.com/files/gtest-1.7.0.zip && unzip gtest-1.7.0.zip
  echo "=== [DONE] Download gtest ==="
fi
# Build & install
if [ -d gtest-1.7.0 ]; then
  echo "=== [START] Build gtest ==="
  mkdir -p $DEPS_SRC_PATH/gtest-1.7.0/build
  cd $DEPS_SRC_PATH/gtest-1.7.0/build && cmake .. -DCMAKE_INSTALL_PREFIX=$DEPS_BUILD_PATH/gtest && make
  echo "=== [DONE] Build gtest ==="
  echo "=== [DONE] Install gtest ==="
  mkdir -p $DEPS_BUILD_PATH/gtest/lib
  cp -r $DEPS_SRC_PATH/gtest-1.7.0/include $DEPS_BUILD_PATH/gtest && cp $DEPS_SRC_PATH/gtest-1.7.0/build/*.a $DEPS_BUILD_PATH/gtest/lib
  echo "=== [DONE] Install gtest ==="
fi

###
# OpenCV
###
# Go to deps folder root
cd $DEPS_SRC_PATH
# Download sources
if [ ! -d opencv ]; then
  echo "=== [START] Download opencv ==="
  git clone https://github.com/Itseez/opencv.git opencv
  echo "=== [DONE] Download opencv ==="
fi
# Build & install
if [ -d opencv ]; then
  echo "=== [START] Build opencv ==="
  mkdir -p $DEPS_SRC_PATH/opencv/build
  cd $DEPS_SRC_PATH/opencv/build && cmake .. -DCMAKE_INSTALL_PREFIX=$DEPS_BUILD_PATH/opencv && make && make install
  echo "=== [DONE] Build opencv ==="
fi
