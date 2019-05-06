#pragma once
#include <string>
namespace bullpgia {
class Guesser
{
    public:
unsigned int length;
std::string typeinfo;
virtual std::string guess(){ return "";};
virtual void learn(std::string){};
virtual void startNewGame(unsigned int){};
};
}
