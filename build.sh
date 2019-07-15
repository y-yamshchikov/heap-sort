#!/bin/bash
mv heap old_heap
g++ -c heap.cpp -std=c++17
g++ -o heap heap.o
