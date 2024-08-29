cmake_minimum_required(VERSION 3.28)

project(CodeViz)

set(CXX_STANDARD 17)

add_subdirectory(src)

add_executable(CodeViz main.cpp)

target_link_libraries(CodeViz PRIVATE CodeVizsrc)
