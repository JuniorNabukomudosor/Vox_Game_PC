cmake_minimum_required(VERSION 3.10)

project(GameVox)

set(CMAKE_CXX_STANDARD 17)

add_executable(GameVox main.cpp)

target_include_directories(GameVox PRIVATE ${CMAKE_SOURCE_DIR}/include usr/include/websocketpp urs/include/asio)

file(GLOB_RECURSE SRC_FILES ${CMAKE_SOURCE_DIR}/src/**.cpp)

target_sources(GameVox PRIVATE ${SRC_FILES}) 

target_link_directories(GameVox PRIVATE ${CMAKE_SOURCE_DIR}/lib)

target_link_libraries(GameVox raylib X11 pthread)