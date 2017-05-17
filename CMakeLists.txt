cmake_minimum_required(VERSION 3.7)
project(find-the-bombs)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)
find_package(GSL REQUIRED)

set(INCLUDE_DIRS
        ${PROJET_SOURCE_DIR}
        ${OPENCV_INCLUDE_DIR}
        ${GSL_INCLUDE_DIRS}
        )
set(LIBS
        ${OpenCV_LIBS}
        ${GSL_LIBRARIES}
        )

include_directories(${INCLUDE_DIRS})

set(SRCS
        main.cpp
        colorhistogram.cpp
        commander.cpp
        dog.cpp
        police.cpp
        )

add_executable(find-the-bombs ${SRCS})

target_link_libraries(find-the-bombs ${LIBS})
target_link_libraries(find-the-bombs gflags)