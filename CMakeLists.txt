cmake_minimum_required(VERSION 3.5)
project(a CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

find_package(Qt<QTVERSION> COMPONENTS Widgets)
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

file(GLOB_RECURSE CPP_FILES 
    "${CMAKE_SOURCE_DIR}/3D/*.cpp"
    "${CMAKE_SOURCE_DIR}/main.cpp")


add_executable(a ${CPP_FILES})

target_link_libraries(a sfml-system sfml-window sfml-graphics)