#include <iostream>
#include <string>
struct Foo {
    int n;
    Foo() {
       std::cout << "static constructor\n";
    }
    ~Foo() {
       std::cout << "static destructor\n";
    }
};
Foo f; // static object
int main()
{
    std::string str = "1234";
    str.at(1)++;
    std::cout << str;
    std::cout << "main function\n";
}