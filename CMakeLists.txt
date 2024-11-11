cmake_minimum_required(VERSION 3.28)

# Set some basic project attributes
project (raylib-bubble-game
	VERSION 0.1
	DESCRIPTION "A Hello World Project")

set(CXX_STANDARD_VERSION, 20)

# Adding Raylib
include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games
FetchContent_Declare(
	raylib
	GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
	GIT_TAG "master"
	GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(raylib)

add_executable(${PROJECT_NAME})
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)
target_include_directories(${PROJECT_NAME} PRIVATE
	src
	engine
)
target_sources(${PROJECT_NAME} PRIVATE
	src/main.cpp
	src/BubbleGame.cpp
)
target_sources(${PROJECT_NAME} PRIVATE
	engine/Game.cpp
)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
