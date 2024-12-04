cmake_minimum_required(VERSION 3.28)

project(release LANGUAGES CXX)
# set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_subdirectory(src)

# jsoncons
find_package(jsoncons CONFIG REQUIRED)
target_link_libraries(release PRIVATE jsoncons)
if (jsoncons_FOUND)
    message(STATUS "jsoncons found")
endif()

# toml11
find_package(toml11 CONFIG REQUIRED)
target_link_libraries(release PRIVATE toml11::toml11)