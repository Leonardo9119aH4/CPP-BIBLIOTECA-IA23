#include <iostream>
#include <chrono>
#include <ctime>
#include "usuario.hpp"
#include "livro.hpp"
Usuario Cadastrar(){
    std::string login, senha, nome, cpf, telefone, email;
    std::cout << "Cadastro\nCrie seu nome de usuario: " << std::endl;
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
    Usuario user(login, senha, nome, cpf, telefone, email);
    return user;
}
void Login(Usuario* user){
    std::string login, senha;
    bool status;
    do{
        std::cout << "Login\nDigite o seu nome de usuario: " << std::endl;
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
Livro CadLivro(){
    std::string nome, isbn, genero, autor, editora;
    int ano;
    std::cout << "Cadastro livro\nDigite o nome do livro:" << std::endl;
    std::cin >> nome;
    std::cout << "Digite o isbn do livro:" << std::endl;
    std::cin >> isbn;
    std::cout << "Digite o genero do livro:" << std::endl;
    std::cin >> genero;
    std::cout << "Digite o ano de edicao do livro:" << std::endl;
    std::cin >> ano;
    std::cout << "Digite o autor do livro:" << std::endl;
    std::cin >> autor;
    std::cout << "Digite a editora do livro:" << std::endl;
    std::cin >> editora;
    Livro livro(nome, isbn, genero, ano, autor, editora);
    return livro;
}
void ConsultarLivros(Livro* l1, Livro* l2, Livro* l3){
    std::cout << "Temos disponiveis:\n" << l1->nome << std::endl << l2->nome << std::endl << l3->nome << std::endl;
}
void PagarMulta(Usuario* user){
    float valor;
    std::cout << "Voce tem multa de R$" << user->getMulta() << "\nQual valor voce vai pagar? " << std::endl;
    std::cin >> valor;
    user->PagarMulta(valor);
}
void Emprestar(Livro* l1, Livro* l2, Livro* l3, Usuario* user){
    std::string livro;
    bool status;
    std::cout << "Qual o nome do livro que voce quer emprestado? " << std::endl;
    std::cin >> livro;
    if(l1->nome == livro){
        status = user->Emprestar(l1);
    }
    else if(l2->nome == livro){
        status = user->Emprestar(l2);
    }
    else if(l3->nome == livro){
        status = user->Emprestar(l3);
    }
    else{
        std::cout << "Livro não encontrado! " << std::endl;
        Emprestar(l1, l2, l3, user);
    }
    if(!status){
        std::cout << "Voce nao pode pegar livro emprestado pois tem multa a pagar" << std::endl;
        PagarMulta(user);
    }
}
void Devolver(Usuario* user){
    user->Devolver(0);
}
int main(){
    Usuario user1 = Cadastrar();
    Login(&user1); 
    Livro livro1 = CadLivro();
    Livro livro2 = CadLivro();
    Livro livro3 = CadLivro();
    while(true){
        ConsultarLivros(&livro1, &livro2, &livro3);
        Emprestar(&livro1, &livro2, &livro3, &user1);
        Devolver(&user1);
        if(user1.getMulta()>0){
            PagarMulta(&user1);
        }
    }
    return 0;
}
