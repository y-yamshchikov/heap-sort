#!/bin/bash
mv heap old_heap
g++ -c heap.cpp -std=c++17 -ggdb3
g++ -o heap heap.o -ggdb3
