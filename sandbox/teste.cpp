#include <iostream>
#include <string>
#include <typeinfo>
class A{
    public:
        A(){

        }
        int Y;
};
int main(){
    A X;
    std::string name = typeid(X).name();
    std::cout << name;
    return 0;
}