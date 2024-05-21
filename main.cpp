#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include "usuario.hpp"
#include "livro.hpp"
std::vector<Usuario*> usuarios;
std::vector<Livro*> livros;
void Cadastrar(){
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
    Usuario* user = new Usuario(login, senha, nome, cpf, telefone, email);
    usuarios.push_back(user);
}
void Login(){
    std::string login, senha;
    bool status;
    do{
        std::cout << "Login\nDigite o seu nome de usuario: " << std::endl;
        std::cin >> login;
        std::cout << "Digite a sua senha: " << std::endl;
        std::cin >> senha;
        for(Usuario* user : usuarios){
            status = user->login(login, senha);
            if(status){
                std::cout << "Exito ao logar!" << std::endl;
                opcaoUser(user);
            }
            else{
                std::cout << "Login e/ou senha errado(s)!" << std::endl;
            }
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
void ConsultarLivros(){
    for()
}
void PagarMulta(Usuario* user){
    float valor;
    std::cout << "Voce tem multa de R$" << user->getMulta() << "\nQual valor voce vai pagar? " << std::endl;
    std::cin >> valor;
    user->PagarMulta(valor);
}
void Emprestar(){

}
void Devolver(Usuario* user){

}
void opcaoUser(Usuario* user){
    while(true){
        ConsultarLivros();
        Emprestar();
        Devolver();
    }
}
int main(){

    return 0;
}
