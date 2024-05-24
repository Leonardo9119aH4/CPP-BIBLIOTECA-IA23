#include <iostream>
void func(int* Z){
    //Z=1;
}
int main(){
    int X=0;
    int* Y=&X;
    func(&X);
    std::cout << Y;
    return 0;
}