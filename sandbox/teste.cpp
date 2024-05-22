#include <iostream>
#include <chrono>
int main(){
    time_t data = std::time(nullptr);
    std::tm* tm_ptr = std::localtime(&data);
    int dia = tm_ptr->tm_mday;
    std::cout << dia;
    return 0;
}