#include <iostream>
#include "emprestimo.hpp"
class Usuario{
    public:
        std::string login;
        Usuario(std::string _login, std::string _senha, std::string _nome, std::string _cpf, std::string _telefone, std::string _email){
            login = _login;
            senha = _senha;
            nome = _nome;
            cpf = _cpf;
            telefone = _telefone;
            email = _email;
        }
        ~Usuario(){};
        bool Login(std::string _login, std::string _senha){
            bool loginStatus;
            if(_login == login && senha == _senha){
                loginStatus = true;
            }
            else{
                loginStatus = false;
            }
            return loginStatus;
        }
    protected:
        std::string cpf, nome, telefone, email;
        float multa;
        Emprestimo emprestimo;
    private:
        std::string senha;
};