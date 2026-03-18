cmake_minimum_required(VERSION 4.0)
project(projectEuler)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -march=native -flto=auto")

add_library(projectEulerLib INTERFACE)
target_include_directories(projectEulerLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(projectEuler main.cpp)
target_link_libraries(projectEuler PRIVATE projectEulerLib)