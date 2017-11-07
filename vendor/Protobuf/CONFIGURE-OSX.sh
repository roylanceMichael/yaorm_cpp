#!/bin/bash -x

rm -rf _Build
mkdir _Build && cd _Build
cmake -D BUILD_PLATFORM:string=OSX -G Xcode ..
