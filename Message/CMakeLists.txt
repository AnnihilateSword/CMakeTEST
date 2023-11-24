cmake_minimum_required(VERSION 3.28.0)

project(Message LANGUAGES CXX)

if (WIN32)
    # 生成动态库时，Windows 平台加上这段代码才会输出 lib
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
elseif(UNIX)
    # TODO
endif()

file(GLOB_RECURSE MessageSources src/*.cpp src/*.h)

# 生成动态库
add_library(${PROJECT_NAME}
SHARED
${MessageSources})

# 这里设置为公共的，由于 CMakeTEST 引用了这个项目，CMakeTEST 也会自动包含
target_include_directories(${PROJECT_NAME}
PUBLIC ${CMAKE_CURRENT_LIST_DIR}/src)

# ---------------------------------------------------------------------------------------------------------------
# 拷贝 DLL 操作
# ---------------------------------------------------------------------------------------------------------------
# 创建文件夹（如果不存在下面复制命令会有报错，例如：Debug 模式下不会生成 Release 目录，复制 Release 目录中的文件时会报错）
execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory ${PROJECT_BINARY_DIR}/Debug)
execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory ${PROJECT_BINARY_DIR}/Release)

# 原文件路径
set(ORIGFILE_DEBUG ${PROJECT_BINARY_DIR}/Debug/${PROJECT_NAME}.dll)
set(ORIGFILE_RELEASE ${PROJECT_BINARY_DIR}/Release/${PROJECT_NAME}.dll)
# 目标文件路径
set(TARGET_FOLDER_NAME "CMakeTEST")
set(TARGETFILE_DEBUG ${CMAKE_SOURCE_DIR}/build/${TARGET_FOLDER_NAME}/Debug/${PROJECT_NAME}.dll)
set(TARGETFILE_RELEASE ${CMAKE_SOURCE_DIR}/build/${TARGET_FOLDER_NAME}/Release/${PROJECT_NAME}.dll)

# 添加生成前创建两个 dll 文件（如果不存在，下面复制命令会有报错）
add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E touch "${ORIGFILE_DEBUG}"
)
add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E touch "${ORIGFILE_RELEASE}"
)

# 添加生成后事件复制 DLL 到主程序下
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E
    copy ${ORIGFILE_DEBUG} ${TARGETFILE_DEBUG}
)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E 
    copy ${ORIGFILE_RELEASE} ${TARGETFILE_RELEASE}
)
# ---------------------------------------------------------------------------------------------------------------
