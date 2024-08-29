
#pragma once
#include <filesystem>
#include <string>
#include <set>
#include <vector>
#include <map>

class File
{

public:
    int blank = 0;
    int code = 0;
    int comment = 0;
public:
    std::string path;
    File(const std::string &path)
    {
        this->path = path;
    };
    File(){};
    ~File() {};
};

class Data
{
public:
    std::filesystem::path ROOT_DIR;
    std::vector<std::string> IGNORE_DIR;

public:
    const std::set<std::string> AVAIABLE_FILE_EXTENSION = {"c", "cpp", "py", "js", "md", "hpp"};
    int NUM_EXTENSION = AVAIABLE_FILE_EXTENSION.size();

    std::map<std::string, int> CodeLine;

    std::map<std::string, File> FileData;

    Data();
    ~Data();

    int file_count(const std::filesystem::path file);
};