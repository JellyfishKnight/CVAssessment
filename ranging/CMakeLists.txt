project(ranging)
cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 14)

aux_source_directory(. DIR_RANGING)

add_library(${PROJECT_NAME} ${DIR_RANGING})

# —∞’“OpenCVø‚
set(OpenCV_DIR /home/wjy/OPENCV/BUILD/install)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package( OpenCV 4 REQUIRED )

include_directories(
        ${OpenCV_INCLUDE_DIRS}
)

set(OPENCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs)

target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} ${TargetClass})
