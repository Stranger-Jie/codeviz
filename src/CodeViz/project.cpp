
#include <vector>
#include <iomanip>

#include <iostream>
#include <filesystem>
#include <string>
#include <set>
#include <fstream>
#include "project.h"

Project::Project(const std::string &ROOT_DIR)
{
    this->ROOT_DIR = std::filesystem::path(ROOT_DIR);
    this->Data::ROOT_DIR = this->ROOT_DIR;
}

void Project::add_ignore(const std::string &ignore_dir)
{
    this->IGNORE_DIR.push_back(ignore_dir);
    this->Data::IGNORE_DIR = this->IGNORE_DIR;
}

void Project::code_count()
{
    int count_files = 0;
    for (auto &file : std::filesystem::recursive_directory_iterator(this->ROOT_DIR))
    {
        if (this->file_count(file.path()) == 0)
        {
            count_files++;
        }
    }
    // std::cout << "exist " << count_files << " files" << std::endl;
}

void Project::print_count()
{
    std::cout << "Code Line Count" << std::endl;
    std::cout << "----------------" << std::endl;

    for (auto &key : AVAIABLE_FILE_EXTENSION)
    {
        std::cout << std::setw(5) << CodeLine[key] << " " << key << " files" << std::endl;
    }

    std::cout << "File Code Count" << std::endl;
    std::cout << "----------------" << std::endl;

    for (auto &key : FileData)
    {
        std::cout << key.first << " code lines:"<<key.second.code;
        std::cout << "\tblank lines:" << key.second.blank;
        std::cout << "\tcomment lines:" << key.second.comment;
        std::cout << "\ttotal lines:" << key.second.code + key.second.blank + key.second.comment << std::endl;
    }
}