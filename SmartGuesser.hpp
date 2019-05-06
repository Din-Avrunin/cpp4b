#include "calculate.hpp"
#include "Guesser.hpp"
using bullpgia::Guesser;
namespace bullpgia
{
class SmartGuesser : public bullpgia::Guesser
{
virtual std::string guess(){ return "";};
virtual void learn(std::string){};
virtual void startNewGame(unsigned int){};
};
}