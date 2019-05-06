#include "SmartGuesser.hpp"
#include <vector>
#include <set>
#include <iostream>
#include <iterator>
#include <string>

using namespace bullpgia;
using namespace std;

bool firstTime;
int index;
string myGuess;
string lastReply;
unsigned int myLength;

 string guess()
 {
    return myGuess;
 }
 void learn(string replyStr) 
 {
     if (firstTime) 
     {
        myGuess.at(index)++;
        firstTime=false;
     }
     //for the best = "0,0" "1,0"
    else if (replyStr.at(0)>lastReply.at(0))
     {
            index++;
            myGuess.at(index)++;
           
     }
     //for the worst = "1,0" "0,0"
     else if (replyStr.at(0)<lastReply.at(0))
     {
            index--;
            myGuess.at(index)--;
     }
     else // e.g. "1,0" "1,0"
     {
            myGuess.at(index)++;
     }
     lastReply=replyStr;
     std::cout << myGuess << " ";
     
 }
 void startNewGame(unsigned int length)
 {
    myLength=length;


for(size_t i = 0; i < length; i++)
{
   myGuess =  myGuess + '0';
}

    lastReply="0,0";
    index=0;
    firstTime=true;
 }