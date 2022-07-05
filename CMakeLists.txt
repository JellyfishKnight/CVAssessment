cmake_minimum_required(VERSION 3.22)
project(Assessment)

set(CMAKE_CXX_STANDARD 14)

# 寻找OpenCV库
set(OpenCV_DIR /home/wjy/OPENCV/BUILD/install)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package( OpenCV 4 REQUIRED )

# 添加头文件
include_directories(
        ${OpenCV_INCLUDE_DIRS}
        ${PROJECT_SOURCE_DIR}/ranging
        ${PROJECT_SOURCE_DIR}/PreProcess
        ${PROJECT_SOURCE_DIR}/System
)


add_subdirectory(./ranging)
add_subdirectory(./PreProcess)
add_subdirectory(./System)

set(OPENCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs)
set(TargetClass System PreProcess ranging)

add_executable(${PROJECT_NAME} ${TargetClass} main.cpp)

# 链接OpenCV库
target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} )
target_link_libraries( ${PROJECT_NAME} ${TargetClass} )
