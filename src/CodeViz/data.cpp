#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <set>
#include <map>

#include "data.h"

Data::Data()
{
    for (auto key : AVAIABLE_FILE_EXTENSION)
    {
        CodeLine[key] = 0;
    }
}

Data::~Data()
{
}

int Data::file_count(const std::filesystem::path file)
{
    // 忽略文件夹
    for (auto &ignore_dir : this->IGNORE_DIR)
    {
        if (file.generic_string().find(ignore_dir) != std::string::npos)
        {
            return 1;
        }
    }

    // 提取后缀名
    std::string extension = file.extension().generic_string();

    if (extension.empty())
    {
        return 1;
    }
    else
    {
        extension.erase(extension.begin());
    }

    // 匹配代码文件
    auto a = AVAIABLE_FILE_EXTENSION.find(extension);

    if (a == AVAIABLE_FILE_EXTENSION.end())
    {
        return 1;
    }

    // 统计代码行数
    std::string relative_path = std::filesystem::relative(file, this->ROOT_DIR).generic_string();
    FileData[relative_path] = File(relative_path);
    std::ifstream file_stream(file);
    std::string line;
    int line_count = 0;

    while (std::getline(file_stream, line))
    {
        int start = 0;
        while (line[start] == ' ')
            start++;
        if (line.size() == 0)
        {
            FileData[relative_path].blank++;
        }
        else if (line.find("//") == start || line.find("/*") == start)
        {
            FileData[relative_path].comment++;
        }
        else
        {
            FileData[relative_path].code++;
            line_count++;
        }
    }

    CodeLine[extension] += line_count;

    return 0;
}