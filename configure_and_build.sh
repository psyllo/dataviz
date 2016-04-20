#!/bin/sh
autoreconf -i
./configure \
    CC="gcc -g -ggdb -Wall" \
    CXX="g++ -std=c++11 -g -ggdb -Wall" \
    PKG_CONFIG="pkg-config --static"
make
