#pragma once
#include <filesystem>
#include <string>
#include <set>
#include <vector>

#include "data.h"

class Project : Data
{
public:
    std::filesystem::path ROOT_DIR = Data::ROOT_DIR;
    std::vector<std::string> IGNORE_DIR = Data::IGNORE_DIR;

public:
    Project(){};
    Project(const std::string &ROOT_DIR);

    ~Project(){};

    void add_ignore(const std::string &ignore_dir);

    void code_count();

    void print_count();
};