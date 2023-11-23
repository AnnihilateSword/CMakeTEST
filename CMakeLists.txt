cmake_minimum_required(VERSION 3.28.0)

project(CMakeTEST LANGUAGES CXX)

# 优化设置
if (CMAKE_BUILD_TYPE MATCHES Release)
    set(CMAKE_CXX_FLAGS "-O3")
elseif (CMAKE_BUILD_TYPE MATCHES Debug)
    set(CMAKE_CXX_FLAGS "-g")
endif ()

set(CMAKE_CONFIGURATION_TYPES "Debug;Release;")

# 添加子目录
add_subdirectory(CMakeTEST)
add_subdirectory(Message)