#!/bin/sh
autoreconf -i && ./configure PKG_CONFIG="pkg-config --static" && make
