#include <iostream>
#include <string>

int main()
{
    std::string str = "";
    int length = 9;
for(size_t i = 0; i < length; i++)
{
   str =  str + '0';
}



    std::cout << str;

}