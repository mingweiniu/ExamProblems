#!/bin/bash

problem=$1 #file name by input arg

# test file has same name
testFile=${problem}.txt

# edit cpp and compile
vim ${problem}.cpp
g++ ${problem}.cpp

# run a.out 
cat ${testFile}|./a.out
