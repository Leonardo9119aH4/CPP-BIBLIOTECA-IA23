#include <iostream>
#include <vector>
#include "usuario.hpp"
Usuario* Cadastrar(){
    std::string login, senha, nome, cpf, telefone, email;
    std::cout << "Crie seu nome de usuario: " << std::endl;
    std::cin >> login;
    std::cout << "Crie sua senha: " << std::endl;
    std::cin >> senha;
    std::cout << "Digite o seu nome completo: " << std::endl;
    std::cin >> nome;
    std::cout << "Digite o seu cpf: " << std::endl;
    std::cin >> cpf;
    std::cout << "Digite o seu telefone: " << std::endl;
    std::cin >> telefone;
    std::cout << "Digite o seu email: " << std::endl;
    std::cin >> email;
    Usuario user1 = new Usuario(login, senha, nome, cpf, telefone, email);
    return user1;
}
void Login(){
    std::string login, senha;
    do{
        std::cout << "Digite o seu nome de usuario: " << std::endl;
        std::cin >> login;
        std::cout << "Digite a sua senha: "
    }
}
int main(){
    Usuario &user1 = Cadastrar();
    return 0;
}