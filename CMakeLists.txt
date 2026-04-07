cmake_minimum_required(VERSION 4.2)
project(data_structure)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(data_structure src/main.cpp
        src/LinearListArray.cpp
        include/LinearListArray.h
        src/LinearListLinked.cpp
        include/LinearListLinked.h
        src/Polynomial.cpp
        include/Polynomial.h
        src/BigInt.cpp
        include/BigInt.h
)
