#!/bin/bash

sudo apt-get install -y qt5-default
mkdir build
cd build
qmake ../TowerDefense.pro
make
./TowerDefense
