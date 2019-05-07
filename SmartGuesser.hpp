#include "calculate.hpp"
#include "Guesser.hpp"
using bullpgia::Guesser;
namespace bullpgia
{
class SmartGuesser : public bullpgia::Guesser
{
virtual std::string guess()override;
virtual void learn(std::string)override;
virtual void startNewGame(unsigned int)override;
};
}