cmake_minimum_required(VERSION 3.26)
project(TraceCode)

set(CMAKE_CXX_STANDARD 17)

add_executable(TraceCode main.cpp
        questions/appleColor.h
        questions/buildTree.h
        questions/snippets.h
        questions/securityLevel.h
        questions/catColor.h
        questions/redTea.h
        questions/binarySearch.h
        questions/stack.h
        questions/transportation.h
        questions/catToy.h
        questions/mathVector.h
        questions/complexNumber.h
        questions/fibonacciN.h
        questions/cardGame.h)