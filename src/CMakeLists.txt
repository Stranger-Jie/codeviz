
add_executable(release main.cpp)


add_subdirectory(CodeViz)
# add_subdirectory(CodeVizUI)

target_link_libraries(release
PRIVATE
    CodeViz
    # CodeVizUI
)
