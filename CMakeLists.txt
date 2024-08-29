cmake_minimum_required(VERSION 3.28)

project(release LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_subdirectory(src)


# nlohmann_json 文件
# find_package(BitSerializer CONFIG REQUIRED)
# target_link_libraries(release PRIVATE BitSerializer)
# if (bitserializer_FOUND)
#     message(STATUS "bitserializer found")
# endif()


