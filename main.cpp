#include <iostream>
#include <string>
#include "src/CodeViz/project.h"
#include "src/CodeViz/data.h"

int main(){
    Project *p = new Project("E:/Github-pro/codeviz");

    p->add_ignore("build");

    p->code_count();

    p->print_count();

    return 0;
}