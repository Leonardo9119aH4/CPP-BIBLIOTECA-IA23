#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <typeinfo>
#include "usuario.hpp"
#include "livro.hpp"
void defaultAdmin(std::vector<Usuario>* usuarios){
    Usuario user("Admin", "Admin", "Admin", "ADM", "ADM", "biblioteca@ifc.confia", true);
    usuarios->push_back(user);
}
void Cadastrar(std::vector<Usuario>* usuarios, bool isAdmin) {
    bool conflito = false;
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
    for (int i = 0; i < usuarios->size(); ++i) {
        if (usuarios->at(i).login == login) {
            std::cout << "Esse nome de usuario ja existe!" << std::endl;
            conflito = true;
        }
        if (!conflito) {
            if (isAdmin) {
                Usuario user(login, senha, nome, cpf, telefone, email, true);
                usuarios->push_back(user);
                break;
            }
            else {
                Usuario user(login, senha, nome, cpf, telefone, email, false);
                usuarios->push_back(user);
                break;
            }
        }
    }
}
void ConsultarLivros(std::vector<Livro>* livros){
    std::cout << "Temos disponiveis: " << std::endl;
    for(int i = 0; i < livros->size(); ++i){
        std::cout << "Nome: " << livros->at(i).nome << "; ISBN: " << livros->at(i).isbn << "; Ano: " << livros->at(i).ano << "; Genero: " << livros->at(i).genero << "; Autor: " << livros->at(i).autor << "; Editora: " << livros->at(i).editora << std::endl;
    }
}
void ConsultarMulta(Usuario* user){
    std::cout << "Voce possui multa de R$" << user->getMulta() << std::endl;
}
void PagarMulta(Usuario* user){
    float valor;
    std::cout << "Voce tem multa de R$" << user->getMulta() << "\nQual valor voce vai pagar? " << std::endl;
    std::cin >> valor;
    user->PagarMulta(valor);
}
void Emprestar(Usuario* user, std::vector<Livro>* livros){
    std::string isbn;
    bool status=false, livroExiste=false;
    std::cout << "Digite o ISBN do livro que voce quer: " << std::endl;
    std::cin >> isbn;
    for(int i = 0; i < livros->size(); ++i){
        if(livros->at(i).isbn==isbn){
            status = user->Emprestar(&livros->at(i));
            livroExiste = true;
            break;
        }
    }
    if (livroExiste) {
        if (status) {
            std::cout << "Emprestimo realizado com exito!" << std::endl;
        }
        else {
            std::cout << "Voce nao pode realizar o emprestimo pois tem multa pendente" << std::endl;
        }
    }
    else {
        std::cout << "Esse livro nao existe!" << std::endl;
    }
}
void Devolver(Usuario* user){
    bool devolvido;
    int devId;
    std::time_t hoje = std::time(nullptr);
    std::cout << "Digite o ID do emprestimo a devolver: " << std::endl;
    std::cin >> devId;
    devolvido = user->Devolver(hoje, devId);
    if(devolvido){
        std::cout << "O livro foi devolvido!" << std::endl;
    }
    else{
        std::cout << "Não possui emprestimo com ID especificado." << std::endl;
    }
}
void ConsultarEmpr(Usuario* user){
    user->ConsultarEmpr();
}
void DeletarLivro(std::vector<Livro>* livros){
    std::string isbn;
    std::cout << "Digite o ISBN do livro a ser deletado:" << std::endl;
    std::cin >> isbn;
    for(int i = 0; i < livros->size(); ++i){
        if(livros->at(i).isbn==isbn){
            livros->erase(livros->begin() + i);
        }
    }
}
void DeletarUsuario(std::vector<Usuario>* usuarios){
    std::string username;
    std::cout << "Digite o nome de usuario a ser deletado:" << std::endl;
    std::cin >> username;
    for(int i = 0; i < usuarios->size(); ++i){
        if(usuarios->at(i).login==username){
            usuarios->erase(usuarios->begin() + i);
        }
    }
}
void MultarUsuario(std::vector<Usuario>* usuarios){
    std::string username;
    float valor;
    std::cout << "Digite o nome de usuario a alterar a multa:" << std::endl;
    std::cin >> username;
    std::cout << "Digite o valor da multa a ser aplicado:" << std::endl;
    std::cin >> valor;
    for(int i = 0; i < usuarios->size(); ++i){
        if(usuarios->at(i).login==username){
            usuarios->at(i).setMulta(valor);
        }
    }
}
void CadLivro(std::vector<Livro>* livros){
    std::string nome, isbn, genero, autor, editora;
    int ano;
    bool conflito=false;
    std::cout << "Cadastro livro\nDigite o nome do livro:" << std::endl;
    std::cin >> nome;
    std::cout << "Digite o ISBN do livro:" << std::endl;
    std::cin >> isbn;
    std::cout << "Digite o genero do livro:" << std::endl;
    std::cin >> genero;
    std::cout << "Digite o ano de edicao do livro:" << std::endl;
    std::cin >> ano;
    std::cout << "Digite o autor do livro:" << std::endl;
    std::cin >> autor;
    std::cout << "Digite a editora do livro:" << std::endl;
    std::cin >> editora;
    for (int i = 0; i < livros->size(); ++i) {
        if (livros->at(i).isbn == isbn) {
            conflito = true;
            std::cout << "Ja existe um livro com esse ISBN!" << std::endl;
        }
    }
    if(!conflito) {
        Livro livro(nome, isbn, genero, ano, autor, editora);
        livros->push_back(livro);
    }
}
void opcaoUser(Usuario* user, std::vector<Livro>* livros, std::vector<Usuario>* usuarios){
    int Opc;
    do{
        if(user->getAdmin()){ //admin
            std::cout << "1- Consultar livros dispoiveis\n2- Realizar novo emprestimo\n3- Devolver um livro\n4- Ver valor de multa pendente\n5- Pagar multa\n6- Ver emprestimos realizados\n7- Cadastrar livro\n8-Cadastrar Admin\n9- Deletar livro\n10- Deletar usuario\n11- Multar usuario\n12- Logout\nSelecione a opcao: " << std::endl;
        }
        else{
            std::cout << "1- Consultar livros dispoiveis\n2- Realizar novo emprestimo\n3- Devolver um livro\n4- Ver valor de multa pendente\n5- Pagar multa\n6- Ver emprestimos realizados\n7- Logout\nSelecione a opcao: " << std::endl;
        }
        std::cin >> Opc;
        switch (Opc)
        {
        case 1:
            ConsultarLivros(livros);
            break;
        case 2:
            Emprestar(user, livros);
            break;
        case 3:
            Devolver(user);
            break;
        case 4:
            ConsultarMulta(user);
            break;
        case 5:
            PagarMulta(user);
            break;
        case 6:
            ConsultarEmpr(user);
            break;
        case 7:
            if(user->getAdmin()){
                CadLivro(livros);
            }
            else{
                Opc=12;
            }
            break;
        case 8:
            if(user->getAdmin()){
                Cadastrar(usuarios, true);
            }
            break;
        case 9:
            if(user->getAdmin()){
                DeletarLivro(livros);
            }
            break;
        case 10:
            if(user->getAdmin()){
                DeletarUsuario(usuarios);
            }
            break;
        case 11:
            if(user->getAdmin()){
                MultarUsuario(usuarios);
            }
            break;
        case 12:
            std::cout << "Logout!" << std::endl;
            break;
        default:
            std::cout << "Opcao invalida!" << std::endl;
            break;
        }
    } while(Opc!=12);
}
void Login(std::vector<Usuario>* usuarios, std::vector<Livro>* livros){
    std::string login, senha;
    bool status=false, hasLoged=false;
    std::cout << "Login\nDigite o seu nome de usuario: " << std::endl;
    std::cin >> login;
    std::cout << "Digite a sua senha: " << std::endl;
    std::cin >> senha;
    for(int i = 0; i < usuarios->size(); ++i){
        status = usuarios->at(i).Login(login, senha);
        if(status){
            hasLoged=true;
            if (usuarios->at(i).getAdmin()) {
                std::cout << "Bem-vindo, admin!" << std::endl;
            }
            else {
                std::cout << "Exito ao logar!" << std::endl;
            }
            opcaoUser(&usuarios->at(i), livros, usuarios);
        }
    }
    if(!hasLoged){
        std::cout << "Nome de usuario e/ou senha incorreto(s)!" << std::endl;
    }
}
int main(){
    std::vector<Usuario> usuarios;
    std::vector<Livro> livros;
    defaultAdmin(&usuarios); 
    int Opc;
    do{
        std::cout << "1- Cadastar\n2- Login\n3- Sair\nQuer fazer o que?" << std::endl;
        std::cin >> Opc;
        switch (Opc)
        {
        case 1:
            Cadastrar(&usuarios, false);
            break;
        case 2:
            Login(&usuarios, &livros);
            break;
        case 3:
            return 0;
            break;
        default:
        std::cout << "Opcao invalida!" << std::endl;
            break;
        }
    } while(Opc!=3);
    return -1;
}
