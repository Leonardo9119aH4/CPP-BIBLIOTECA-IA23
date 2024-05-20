#include <iostream>
#include <chrono>
#include <ctime>
#ifndef EMPRESTIMO_HPP
#define EMPRESTIMO_HPP
#include "livro.hpp"
class Emprestimo{
    public:
        Emprestimo(std::time_t _dataEmpr, std::time_t _dataDevolucao, Livro* _livro){
            dataEmprestimo = _dataEmpr;
            dataDevolucao = _dataDevolucao;
            // livro = _livro;
        }
        ~Emprestimo(){}
        // Livro getLivro(){
        //     return livro;
        // }
        std::time_t getDataEmpr(){
            return dataEmprestimo;
        }
        std::time_t getDataDevolucao(){
            return dataDevolucao;
        }
    protected:
        std::time_t dataEmprestimo, dataDevolucao;
        // Livro livro;
};
#endif
