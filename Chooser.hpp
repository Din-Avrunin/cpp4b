#pragma once
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;
namespace bullpgia
{
class Chooser
{

    public:
    unsigned int length;
    string typeinfo;
    string str;
    virtual string choose(unsigned int length) { return NULL;}
};
}