# 设置CMake的最低版本要求
cmake_minimum_required(VERSION 3.28)

# 设置C++标准
set(CXX_STANDARD 17)

# 添加源文件
file(GLOB_RECURSE CPP_FILES ./*.cpp)
file(GLOB_RECURSE HPP_FILES ./*.hpp)

# add_library()

# 创建一个库
add_library(CodeVizsrc ${CPP_FILES} ${HPP_FILES})

# 链接库到可执行文件
target_link_libraries(CodeVizsrc PUBLIC CodeViz)