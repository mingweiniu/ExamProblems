#!/bin/bash

problem=$1

testFile=${problem}.txt
vim ${problem}.cpp
g++ ${problem}.cpp
./a.out << ${testFile}
