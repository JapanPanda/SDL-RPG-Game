cmake_minimum_required(VERSION 3.1)
project(rpggame)

find_path(SDL2_INCLUDE_DIR SDL.h PATH_SUFFIXES SDL2)
find_library(SDL2_LIBRARIES NAMES SDL2)

find_library(SDL2_IMAGE_LIBRARIES NAMES SDL2_image)

message(STATUS ${SDL2_INCLUDE_DIR})
include_directories(rpggame ${SDL2_INCLUDE_DIR})
add_executable(rpggame)
add_subdirectory(src)
target_link_libraries(rpggame ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

