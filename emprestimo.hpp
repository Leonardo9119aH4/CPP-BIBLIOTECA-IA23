#include <iostream>
#include <chrono>
#include <ctime>
#include <random>
#ifndef EMPRESTIMO_HPP
#define EMPRESTIMO_HPP
#include "livro.hpp"
class Emprestimo{
    public:
        Emprestimo(std::time_t _dataEmpr, std::time_t _dataDevolucao, Livro* _livro, int* _countId);
        ~Emprestimo();
        Livro* getLivro();
        std::time_t getDataEmpr();
        std::time_t getDataDevolucao();
        int getId();
        int getDiaEmpr();
        int getDiaDev();
    protected:
        std::time_t dataEmprestimo, dataDevolucao;
        int id;
        Livro* livro;
};
#endif
