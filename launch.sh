#!/bin/sh
clang++ -std=c++20 bubbleSort.cpp -I/opt/homebrew/Cellar/sfml/2.5.1_2/include/ -o $1 -L/opt/homebrew/Cellar/sfml/2.5.1_2/lib -lsfml-graphics -lsfml-window -lsfml-system
