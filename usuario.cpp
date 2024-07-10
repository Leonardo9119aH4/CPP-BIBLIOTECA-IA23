#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include "emprestimo.hpp"
#include "livro.hpp"
#include "usuario.hpp"

Usuario::Usuario(std::string _login, std::string _senha, std::string _nome, std::string _cpf, std::string _telefone, std::string _email, bool _isAdmin) {
    login = _login;
    senha = _senha;
    nome = _nome;
    cpf = _cpf;
    telefone = _telefone;
    email = _email;
    multa = 0;
    countId = 0;
    isAdmin = _isAdmin;
}
Usuario::~Usuario() {};
bool Usuario::Login(std::string _login, std::string _senha) {
    bool loginStatus;
    if (_login == login && senha == _senha) {
        loginStatus = true;
    }
    else {
        loginStatus = false;
    }
    return loginStatus;
}
int Usuario::Emprestar(Livro* _livro) {
    if (multa <= 0) {
        if (_livro->getDisponiveis() > 0) {
            std::time_t dataEmprestimo = std::time(nullptr);
            std::time_t dataDevolucao = dataEmprestimo + 336 * 3600; //time_t só salva em segundos
            auto empr = new Emprestimo(dataEmprestimo, dataDevolucao, _livro, &countId);
            emprestimos.push_back(empr);
            return 1; //codigo de exito
        }
        return -2; //codigo de erro quando o livro nao esta disponivel
    }
    return -1; //codigo de erro quando tem multa pendente
}
bool Usuario::Devolver(std::time_t dataDevEfetiva, int devId) {
    time_t timePointAtraso;
    bool foiDeletado = false;
    Livro* _livro;
    for (int i = 0; i < emprestimos.size(); ++i) {
        if (devId == emprestimos.at(i)->getId()) {
            timePointAtraso = dataDevEfetiva - emprestimos.at(i)->getDataDevolucao();
            Multar(timePointAtraso);
            _livro = emprestimos.at(i)->getLivro();
            delete emprestimos.at(i);
            emprestimos.at(i) = nullptr;
            emprestimos.erase(emprestimos.begin() + i);
            foiDeletado = true;
        }
    }
    return foiDeletado;
}
void Usuario::ConsultarEmpr() {
    bool temEmpr = false;
    for (int i = 0; i < emprestimos.size(); ++i) {
        std::cout << "Emprestimo ID " << emprestimos.at(i)->getId() << " realizado no dia " << emprestimos.at(i)->getDiaEmpr() << " para devolver ate " << emprestimos.at(i)->getDiaDev() << " com o livro " << emprestimos.at(i)->getLivro()->nome << std::endl;
        temEmpr = true;
    }
    if (!temEmpr) {
        std::cout << "Voce nao possui emprestimos ativos." << std::endl;
    }
}
void Usuario::Multar(time_t _timePoint) {
    struct tm diaTm;
    localtime_s(&diaTm, &_timePoint);
    int diasAtraso = diaTm.tm_mday;
    multa += diasAtraso;
}
void Usuario::PagarMulta(float valor) {
    multa -= valor;
}
float Usuario::getMulta() {
    return multa;
}
void Usuario::setMulta(float valor) {
    multa = valor;
}
void Usuario::setLivroDispo(Livro* _livro, bool _dispo) {
    _livro->setDisponiveis(_dispo);
}
bool Usuario::temEmpr() {
    if (emprestimos.size() > 0) {
        return true;
    }
    return false;
}
bool Usuario::getAdmin() {
    return isAdmin;
}
std::string Usuario::getNome() {
    return nome;
}
std::string Usuario::getCPF() {
    return cpf;
}
std::string getTelefone(){
    return telefone;
}
std::string getEmail(){
    return email;
}
