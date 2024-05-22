#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <typeinfo>
#include "usuario.hpp"
#include "livro.hpp"
void defaultAdmin(std::vector<Admin>* admins){
    Admin admin("Admin", "Admin", "Admin", "ADM", "ADM", "biblioteca@ifc.confia");
    admins->push_back(admin);
}
void Cadastrar(std::vector<Usuario>* usuarios, std::vector<Admin>* admins){
    bool conflito;
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
    for(int i = 0; i < usuarios->size(); ++i){
        for(int j = 0; j < admins->size(); ++j){
            if(usuarios->at(i).login==login || admins->at(i).login==login){
            std::cout << "Esse nome de usuario ja existe!" << std::endl;
            conflito=true;
            }
        }
    }
    if(!conflito){
        Usuario user(login, senha, nome, cpf, telefone, email);
        usuarios->push_back(user);
    }
}
void ConsultarLivros(std::vector<Livro>* livros){
    std::cout << "Temos disponiveis: " << std::endl;
    for(int i = 0; i < livros->size(); ++i){
        std::cout << livros->at(i).nome << std::endl;
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
    std::string nomeLivro;
    bool status;
    std::cout << "Digite o nome do livro que voce quer: " << std::endl;
    std::cin >> nomeLivro;
    for(int i = 0; i < livros->size(); ++i){
        if(livros->at(i).nome==nomeLivro){
            status = user->Emprestar(&livros->at(i));
        }
    }
}
void Devolver(Usuario* user){
    std::time_t hoje = std::time(nullptr);
    user->Devolver(hoje);
}
void opcaoUser(Usuario* user, std::vector<Livro>* livros){
    int Opc;
    do{
        std::cout << "1- Consultar livros dispoiveis\n2- Realizar novo emprestimo\n3- Devolver um livro\n4- Ver valor de multa pendente\n5- Pagar multa\n6- Logout\nSelecione a opcao: " << std::endl;
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
            std::cout << "Logout!" << std::endl;
            break;
        case 7:
            if(dynamic_cast<Usuario*>(user)){

            }
        default:
            std::cout << "Opcao invalida!" << std::endl;
            break;
        }
    } while(Opc!=6);
}
void Login(std::vector<Usuario>* usuarios, std::vector<Admin>* admins, std::vector<Livro>* livros){
    std::string login, senha;
    bool status=false, hasLoged=false;
    do{
        std::cout << "Login\nDigite o seu nome de usuario: " << std::endl;
        std::cin >> login;
        std::cout << "Digite a sua senha: " << std::endl;
        std::cin >> senha;
        for(int i = 0; i < usuarios->size(); ++i){
            status = usuarios->at(i).Login(login, senha);
            if(status){
                std::cout << "Exito ao logar!" << std::endl;
                hasLoged=true;
                opcaoUser(&usuarios->at(i), livros);
            }
        }
        for(int i = 0; i < admins->size(); ++i){
            status = usuarios->at(i).Login(login, senha);
            if(status){
                std::cout << "Bem-vindo admin" << std::endl;
                hasLoged=true;
                opcaoUser(&admins->at(i), livros);
            }
        }
        if(!hasLoged){
            std::cout << "Nome de usuario e/ou senha incorretos(s)!" << std::endl;
        }
    } while(!status);
}
void CadLivro(std::vector<Livro>* livros){
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
    livros->push_back(livro);
}
int main(){
    std::vector<Admin> admins;
    std::vector<Usuario> usuarios;
    std::vector<Livro> livros;
    defaultAdmin(&admins); 
    int Opc;
    do{
        std::cout << "1- Cadastar\n2- Login\n3- Sair\nQuer fazer o que?" << std::endl;
        std::cin >> Opc;
        switch (Opc)
        {
        case 1:
            Cadastrar(&usuarios, &admins);
            break;
        case 2:
            Login(&usuarios, &admins, &livros);
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
