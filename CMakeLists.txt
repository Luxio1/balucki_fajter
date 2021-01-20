    cmake_minimum_required(VERSION 3.3.1)

	project(balucki_fajter)

	set(OpenCV_DIR "C:/opencv/vs-make")
	set(SFML_DIR "C:/SFML-2.5.1/include")

	find_package(OpenCV 4.4.0 REQUIRED)
	find_package(SFML REQUIRED COMPONENTS audio graphics window system)

	include_directories(
			${OpenCV_INCLUDE_DIRS}
			${SFML_INCLUDE_DIRS}
			)

	add_executable(balucki_fajter
			src/main.cpp
			src/GameLoop.cpp		src/GameLoop.hpp
			src/Camera.cpp			src/Camera.hpp
			src/Enemy.cpp			src/Enemy.hpp
			src/HpBar.cpp			src/HpBar.hpp
			src/ActionSprite.cpp	src/ActionSprite.hpp
			src/Background.hpp		src/Background.cpp
			src/Glove.cpp			src/Glove.hpp
			src/PlayAgain.cpp		src/PlayAgain.hpp
			src/Shield.cpp			src/Shield.hpp
			src/Player.cpp			src/Player.hpp 
			)

	target_link_libraries(balucki_fajter
			${OpenCV_LIBS}
			sfml-audio
			sfml-graphics
			sfml-window
			sfml-system
			)
