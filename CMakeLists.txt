cmake_minimum_required(VERSION 3.21)
project(caruntu)

set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME} main.cpp IoBase.h IoBase.cpp IOStream.h IOStream.cpp
        Proprietate.h Proprietate.cpp Apartament.h Apartament.cpp Casa.h Casa.cpp
        Contract.h Contract.cpp
        Exception1.h Exception1.cpp Exception2.h Exception2.cpp)
