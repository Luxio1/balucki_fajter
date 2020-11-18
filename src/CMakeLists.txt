cmake_minimum_required(VERSION 3.18)
project(untitled7)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/" ${CMAKE_MODULE_PATH})

# Where to find CMake modules and OpenCV
set(OpenCV_DIR "C:\\Program Files\\opencv\\mingw-build\\install")

find_package(OpenCV 4.5.0 REQUIRED)

find_package(SFML REQUIRED system window graphics network audio)


include_directories(
        ${OpenCV_INCLUDE_DIRS}
        ${SFML_INCLUDE_DIR}
)

add_executable(untitled7 main.cpp)

# add libs you need
set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs)

# linking
target_link_libraries(untitled7 ${OpenCV_LIBS}
        ${SFML_LIBRARIES}
        sfml-audio sfml-graphics sfml-window sfml-system
        )


