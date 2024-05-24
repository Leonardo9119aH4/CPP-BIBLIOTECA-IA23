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
        Usuario(std::string _login, std::string _senha, std::string _nome, std::string _cpf, std::string _telefone, std::string _email){
            login = _login;
            senha = _senha;
            nome = _nome;
            cpf = _cpf;
            telefone = _telefone;
            email = _email;
            multa = 0;
        }
        virtual ~Usuario(){};
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
                return true;
            }
            return false;
        }
        bool Devolver(std::time_t dataDevEfetiva, int devId){
            time_t timePointAtraso;
            bool foiDeletado = false;
            for(size_t i = 0; i < emprestimos.size(); ++i){
                if(devId == emprestimos[i].getId()){
                    timePointAtraso = dataDevEfetiva - emprestimos[i].getDataDevolucao();
                    Multar(timePointAtraso);
                    // delete emprestimos[i];
                    // emprestimos[i] = nullptr;
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
            std::tm* tm_ptr = std::localtime(&_timePoint);
            int diasAtraso = tm_ptr->tm_mday;
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
    protected:
        std::string cpf, nome, telefone, email;
        float multa;
        bool isAdmin;
        std::vector<Emprestimo> emprestimos;
    private:
        std::string senha;
};
class Admin : public Usuario{
    public: 
        Admin(std::string _login, std::string _senha, std::string _nome, std::string _cpf, std::string _telefone, std::string _email) : Usuario(_login, _senha, _nome, _cpf, _telefone, _email){
            isAdmin = true;
        }
        void setMulta(Usuario* user, float valor){
            user->setMulta(valor);
        }
        bool isAdmin;
};
#endif