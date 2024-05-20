#include <iostream>
#include <ctime>

int main() {
    std::time_t dataEmprestimo = std::time(nullptr);
    std::time_t dataDevolucao = dataEmprestimo + 336 * 3600; 
    std::cout << "Data de emprestimo: " << std::ctime(&dataEmprestimo);
    std::cout << "Data de devolucao: " << std::ctime(&dataDevolucao);
    std::cout << "Data de emprestimo: " << dataEmprestimo << std::endl;
    std::cout << "Data de devolucao: " << dataDevolucao << std::endl;
    return 0;
}
