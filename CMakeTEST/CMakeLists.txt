cmake_minimum_required(VERSION 3.28.0)

project(CMakeTEST LANGUAGES CXX)

file(GLOB_RECURSE CMakeTESTSources src/*.cpp src/*.h)

# 生成可执行文件
add_executable(${PROJECT_NAME} ${CMakeTESTSources})

target_include_directories(${PROJECT_NAME}
PUBLIC ${CMAKE_CURRENT_LIST_DIR}/src)

# 如果是项目会优先引用项目，如果不是则链接库
target_link_libraries(${PROJECT_NAME} Message)