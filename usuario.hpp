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
        Usuario(std::string _login, std::string _senha, std::string _nome, std::string _cpf, std::string _telefone, std::string _email, bool _isAdmin);
        ~Usuario();
        bool Login(std::string _login, std::string _senha);
        int Emprestar(Livro* _livro);
        bool Devolver(std::time_t dataDevEfetiva, int devId);
        void ConsultarEmpr();
        void Multar(time_t _timePoint);
        void PagarMulta(float valor);
        float getMulta();
        void setMulta(float valor);
        void setLivroDispo(Livro* _livro, bool _emprestado);
        bool temEmpr();
        bool getAdmin();
        std::string getNome();
        std::string getCPF();
        std::string getTelefone();
        std::string getEmail();
    protected:
        std::string cpf, nome, telefone, email;
        float multa;
        int countId;
        bool isAdmin;
        std::vector<Emprestimo*> emprestimos;
    private:
        std::string senha;
};
#endif
