add_library(CodeViz "")

target_sources(CodeViz
PRIVATE
    data.cpp
    project.cpp
)

target_include_directories(CodeViz
PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)