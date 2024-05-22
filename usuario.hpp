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
                Emprestimo* empr = new Emprestimo(dataEmprestimo, dataDevolucao, _livro);
                emprestimos.push_back(empr);
                return true;
            }
            return false;
        }
        void Devolver(std::time_t dataDevEfetiva){
            int devId, diasAtraso;
            bool foiDeletado = false;
            std::cout << "Digite o ID do emprestimo a devolver: " << std::endl;
            std::cin >> devId;
            for(size_t i = 0; i < emprestimos.size(); ++i){
                if(devId == emprestimos[i]->getId()){
                    diasAtraso = dataDevEfetiva - emprestimos[i]->getDataDevolucao();
                    Multar(diasAtraso);
                    delete emprestimos[i];
                    emprestimos[i] = nullptr;
                    emprestimos.erase(emprestimos.begin() + i);
                    foiDeletado = true;
                }
            }
            if(foiDeletado){
                std::cout << "Emprestimo devolvido com exito!" << std::endl;
            }
            else{
                std::cout << "Nenhum emprestimo encontrado com ID especificado" << std::endl;
            }
            
        }
        void ConsultarEmpr(){
            for(Emprestimo* empr : emprestimos){
                std::cout << "Emprestimo ID " << empr->getId() << " realizado no dia " << empr->getDiaEmpr() << " para devolver ate " << empr->getDiaDev() << "com o livro " << empr->getLivro()->nome << std::endl; 
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
        std::vector<Emprestimo*> emprestimos;
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