cmake_minimum_required(VERSION 3.28)# 定义项目名称和版本

project(MyProject VERSION 1.0)# 设置 C 标准

set(CMAKE_C_STANDARD 17)# 设置构建路径，避免污染根目录

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/archive)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/library)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/runtime)# 遍历项目根目录下的 .c 和 .cpp 文件，排除 CMake 编译器检测文件夹

file(GLOB_RECURSE files "*.c" "*.cpp")

list(FILTER files EXCLUDE REGEX ".*/CMakeFiles/.*") # 排除 CMakeFiles 目录中的文件# 遍历每个文件并添加可执行目标

foreach (file ${files})
    # 1. 获取文件相对于根目录的相对路径
    # 例如：training/chapter2/4.cpp
    file(RELATIVE_PATH rel_path ${CMAKE_SOURCE_DIR} ${file})

    # 2. 将路径中的 / 和 . 替换为 _ 来创建唯一的目标名
    # 例如：training_chapter2_4_cpp
    string(REPLACE "/" "_" exe ${rel_path})
    string(REPLACE "." "_" exe ${exe})

    # 3. 添加可执行目标
    add_executable(${exe} ${file})
    message(STATUS " -- ${file} will be compiled to runtime/${exe}")
endforeach ()