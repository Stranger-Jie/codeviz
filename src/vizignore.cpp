#include <iostream>
#include <array>
#include <string>
#include "CodeViz/project.h"
#include "toml.hpp"

void vizignore(Project *p, std::string path = "./vizignore.toml")
{
    toml::value data = toml::parse(path);
    auto dirs = data["ignoredirs"]["dirs"].as_array();

    for (auto &dir : dirs)
        p->add_ignore(dir.as_string());

    for (auto &dir : p->IGNORE_DIR)
        std::cout << dir << std::endl;
}
