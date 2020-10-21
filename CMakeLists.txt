cmake_minimum_required(VERSION 3.3.1)

project(balucki_fajter)

set(OpenCV_DIR "C:/opencv/vs-make")

find_package(OpenCV 4.4.0 REQUIRED)

include_directories(
	${OpenCV_INCLUDE_DIRS}
)

add_executable(main
	src/main.cpp
)

target_link_libraries(balucki_fajter
	${OpenCV_LIBS}
)