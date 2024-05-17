#include <iostream>
#include <vector>
#include <chrono>
#include "usuario.hpp"
#include "emprestimo.hpp"
#include "livro.hpp"
Usuario Cadastrar(){
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
    Usuario user1(login, senha, nome, cpf, telefone, email);
    return user1;
}
void Login(Usuario* user){
    std::string login, senha;
    bool status;
    do{
        std::cout << "Digite o seu nome de usuario: " << std::endl;
        std::cin >> login;
        std::cout << "Digite a sua senha: " << std::endl;
        std::cin >> senha;
        status = user->Login(login, senha);
        if(status){
            std::cout << "Exito ao logar!" << std::endl;
        }
        else{
            std::cout << "Senha e/ou nome de usuario invalido! " << std::endl;
        } 
    } while(!status);
}
int main(){
    Usuario user1 = Cadastrar();
    Login(&user1);
    
    return 0;
}
