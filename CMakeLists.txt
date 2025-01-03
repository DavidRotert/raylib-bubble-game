cmake_minimum_required(VERSION 3.28)

# Set some basic project attributes
project (raylib-bubble-game
	VERSION 0.1
	DESCRIPTION "A Hello World Project")

set(CXX_STANDARD, 20)
set(CXX_STANDARD_REQUIRED ON)

# Adding Raylib
include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games
FetchContent_Declare(
	raylib
	GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
	GIT_TAG "5.5"
	GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(raylib)

add_executable(${PROJECT_NAME})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 20)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)
target_include_directories(${PROJECT_NAME} PRIVATE
	src
	engine
)
target_sources(${PROJECT_NAME} PRIVATE
	src/main.cpp
	src/BubbleGame.cpp
	src/Player.cpp
	src/Bubble.cpp
)
target_sources(${PROJECT_NAME} PRIVATE
	engine/Game.cpp
	engine/Entity.cpp
)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

set(RESOURCE_FILES
	resources/submarine.png
)
file(COPY ${RESOURCE_FILES} DESTINATION "resources/")
