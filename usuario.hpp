#include <iostream>
#include <chrono>
#include <ctime>
#ifndef USUARIO_HPP
#define USUARIO_HPP
#include "emprestimo.hpp"
#include "livro.hpp"
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
            multa = 0;
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
        bool Emprestar(Livro* _livro){
            if(multa<=0){
                std::time_t dataEmprestimo = std::time(nullptr);
                std::time_t dataDevolucao = dataEmprestimo + 336*3600; //time_t só salva em segundos
                Emprestimo empr1(dataEmprestimo, dataDevolucao, _livro);
                // emprestimo = empr1;
                return true;
            }
            return false;
        }
        void Devolver(std::time_t dataDevEfetiva){
            int diasAtraso = 5; //dataDevEfetiva - emprestimo.getDataDevolucao();
            // delete emprestimo;
            // emprestimo* = NULL;
            if(diasAtraso>0){
                Multar(diasAtraso);
            }
        }
        void Multar(int _diasAtraso){
            multa += _diasAtraso*1;
        }
        void PagarMulta(float valor){
            multa -= valor;
        }
        float getMulta(){
            return multa;
        }
        void setMulta(float valor){
            multa = valor;
        }
    protected:
        std::string cpf, nome, telefone, email;
        float multa;
        bool isAdmin;
        // Emprestimo emprestimo;
    private:
        std::string senha;
};
class Admin : Usuario{
    public: 
        Admin(){
            isAdmin = true;
        }
        void setMulta(Usuario user, float valor){
            user.setMulta(valor);
        }
};
#endif