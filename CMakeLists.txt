cmake_minimum_required(VERSION 3.3.1)

project(balucki_fajter)

set(OpenCV_DIR "C:\\opencv\\vs-make")

find_package(OpenCV 4.4.0 REQUIRED)
find_package(SFML REQUIRED system window graphics network audio)

include_directories(
	${OpenCV_INCLUDE_DIRS}
	${SFML_INCLUDE_DIR}
)

add_executable(balucki_fajter
	src/main.cpp
		src/Camera.cpp src/Camera.h)

target_link_libraries(balucki_fajter
	${OpenCV_LIBS}
	${SFML_LIBRARIES}
)