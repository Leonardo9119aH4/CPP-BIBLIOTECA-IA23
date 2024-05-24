#include <iostream>
#include <chrono>
#include <ctime>
#include <random>
#ifndef EMPRESTIMO_HPP
#define EMPRESTIMO_HPP
#include "livro.hpp"
class Emprestimo{
    public:
        Emprestimo(std::time_t _dataEmpr, std::time_t _dataDevolucao, Livro* _livro, std::vector<Emprestimo>* emprestimos){
            dataEmprestimo = _dataEmpr;
            dataDevolucao = _dataDevolucao;
            livro = _livro;
            id = emprestimos->size()+1;
        }
        ~Emprestimo(){
            delete livro;
            livro = nullptr;
        }
        Livro* getLivro(){
            return livro;
        }
        std::time_t getDataEmpr(){
            return dataEmprestimo;
        }
        std::time_t getDataDevolucao(){
            return dataDevolucao;
        }
        int getId(){
            return id;
        }
        int getDiaEmpr(){
            std::tm* tm_ptr = std::localtime(&dataEmprestimo);
            int dia = tm_ptr->tm_mday;
            return dia;
        }
        int getDiaDev(){
            std::tm* tm_ptr = std::localtime(&dataDevolucao);
            int dia = tm_ptr->tm_mday;
            return dia;
        }
    protected:
        std::time_t dataEmprestimo, dataDevolucao;
        int id;
        Livro* livro;
};
#endif
