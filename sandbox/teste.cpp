#include <iostream>
#include <string>
#include <typeinfo>
class Obj{
    public:
        Obj(){

        }
        int Y;
};
class Sub : public Obj{
    public:
        Sub(){

        }
        int Z;
};
int main(){
    Obj X;
    if(dynamic_cast<Obj>(X)){
        std::cout << "True";
    }
    return 0;
}