cmake_minimum_required(VERSION 3.10)
project(MyCTraining)

# 1. 递归查找所有 .c 文件
file(GLOB_RECURSE SOURCES "training/*.c")

foreach(FILE_PATH ${SOURCES})
    # 计算相对路径 (例如: training/chapter7/6.c)
    file(RELATIVE_PATH REL_PATH ${CMAKE_SOURCE_DIR} ${FILE_PATH})

    # 把路径里的斜杠 / 换成下划线 _ (变成 training_chapter7_6.c)
    string(REPLACE "/" "_" TARGET_NAME ${REL_PATH})

    # 去掉 .c 后缀 (变成 training_chapter7_6)
    string(REPLACE ".c" "" TARGET_NAME ${TARGET_NAME})

    # 创建唯一目标
    add_executable(${TARGET_NAME} ${FILE_PATH})
endforeach()