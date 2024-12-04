#include <iostream>
#include <string>
#include "CodeViz/project.h"
#include "CodeViz/data.h"
#include "vizignore.cpp"

int main()
{

    std::string path;
    std::cin >> path;

    Project *p = new Project(path);

    vizignore(p);

    p->code_count();

    p->print_count();

    delete p;

    getchar();
    getchar();

    return 0;
}