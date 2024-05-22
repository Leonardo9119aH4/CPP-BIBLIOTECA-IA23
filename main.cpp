#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include "usuario.hpp"
#include "livro.hpp"
std::vector<Admin*> admins;
std::vector<Usuario*> usuarios;
std::vector<Livro*> livros;
void defaultAdmin(){
    Admin* admin = new Admin("Admin", "Admin", "Admin", "ADM.ADM.ADM.BL", "ADM", "biblioteca@ifc.confia");
    admins.push_back(admin);
}
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
void ConsultarLivros(){
    std::cout << "Temos disponiveis: " << std::endl;
    for(Livro* livro : livros){
        std::cout << livro->nome << std::endl;
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
void Emprestar(Usuario* user){
    bool foi = user->Emprestar(livros[0]);
    if(foi){
        std::cout << "Emprestado com exito!" << std::endl;
    }
    else{
        std::cout << "Voce tem multa pendente!" << std::endl;
    }
}
void Devolver(Usuario* user){
    std::time_t hoje = std::time(nullptr);
    user->Devolver(hoje);
}
void opcaoUser(Usuario* user){
    int Opc;
    do{
        std::cout << "1- Consultar livros dispoiveis\n2- Realizar novo emprestimo\n3- Devolver um livro\n4- Ver valor de multa pendente\n5- Pagar multa\n6- Logout\nSelecione a opcao: " << std::endl;
        std::cin >> Opc;
        switch (Opc)
        {
        case 1:
            ConsultarLivros();
            break;
        case 2:
            Emprestar(user);
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
        default:
            std::cout << "Opcao invalida!" << std::endl;
            break;
        }
    } while(Opc!=6);
}
void opcaoAdmin(Admin* admin){

}
void Login(){
    std::string login, senha;
    bool status=false, hasLoged=false;
    do{
        std::cout << "Login\nDigite o seu nome de usuario: " << std::endl;
        std::cin >> login;
        std::cout << "Digite a sua senha: " << std::endl;
        std::cin >> senha;
        for(Usuario* user : usuarios){
            status = user->Login(login, senha);
            if(status){
                std::cout << "Exito ao logar!" << std::endl;
                hasLoged=true;
                opcaoUser(user);
            }
        }
        for(Admin* admin : admins){
            status = admin->Login(login, senha);
            if(status){
                std::cout << "Bem-vindo admin" << std::endl;
                hasLoged=true;
                opcaoAdmin(admin);
            }
        }
        if(!hasLoged){
            std::cout << "Nome de usuario e/ou senha incorretos(s)!" << std::endl;
        }
    } while(!status);
}
void CadLivro(){
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
    Livro* livro = new Livro(nome, isbn, genero, ano, autor, editora);
    livros.push_back(livro);
}
int main(){
    defaultAdmin(); //temporario
    CadLivro(); //temporario
    int Opc;
    do{
        std::cout << "1- Cadastar\n2- Login\n3- Sair\nQuer fazer o que?" << std::endl;
        std::cin >> Opc;
        switch (Opc)
        {
        case 1:
            Cadastrar();
            break;
        case 2:
            Login();
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
