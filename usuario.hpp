#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#ifndef USUARIO_HPP
#define USUARIO_HPP
#include "emprestimo.hpp"
#include "livro.hpp"
class Usuario{
    public:
        std::string login;
        Usuario(std::string _login, std::string _senha, std::string _nome, std::string _cpf, std::string _telefone, std::string _email, bool _isAdmin){
            login = _login;
            senha = _senha;
            nome = _nome;
            cpf = _cpf;
            telefone = _telefone;
            email = _email;
            multa = 0;
            isAdmin = _isAdmin;
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
                Emprestimo empr(dataEmprestimo, dataDevolucao, _livro, &emprestimos);
                emprestimos.push_back(empr);
                _livro->emprestado = true;
                return true;
            }
            return false;
        }
        bool Devolver(std::time_t dataDevEfetiva, int devId){
            time_t timePointAtraso;
            bool foiDeletado = false;
            Livro* _livro;
            for(size_t i = 0; i < emprestimos.size(); ++i){
                if(devId == emprestimos[i].getId()){
                    timePointAtraso = dataDevEfetiva - emprestimos[i].getDataDevolucao();
                    Multar(timePointAtraso);
                    _livro = emprestimos.at(i).getLivro();
                    _livro->emprestado = false;
                    emprestimos.erase(emprestimos.begin() + i);
                    foiDeletado = true;
                }
            }
            return foiDeletado;        
        }
        void ConsultarEmpr(){
            bool temEmpr=false;
            for(Emprestimo empr : emprestimos){
                std::cout << "Emprestimo ID " << empr.getId() << " realizado no dia " << empr.getDiaEmpr() << " para devolver ate " << empr.getDiaDev() << " com o livro " << empr.getLivro()->nome << std::endl;
                temEmpr=true;
            }
            if(!temEmpr){
                std::cout << "Voce nao possui emprestimos ativos." << std::endl;
            }
        }
        void Multar(time_t _timePoint){
            struct tm diaTm;
            localtime_s(&diaTm, &_timePoint);
            int diasAtraso = diaTm.tm_mday;
            multa += diasAtraso;
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
        void setLivroStatus(Livro* _livro, bool _emprestado) {
            _livro->emprestado = _emprestado;
        }
        bool getAdmin() {
            return isAdmin;
        }
    protected:
        std::string cpf, nome, telefone, email;
        float multa;
        bool isAdmin;
        std::vector<Emprestimo> emprestimos;
    private:
        std::string senha;
};
#endif