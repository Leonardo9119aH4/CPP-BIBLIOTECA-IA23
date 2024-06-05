#include <iostream>
#include <chrono>
#include <ctime>
#include <random>
#include "livro.hpp"
#include "emprestimo.hpp"
Emprestimo::Emprestimo(std::time_t _dataEmpr, std::time_t _dataDevolucao, Livro* _livro, std::vector<Emprestimo>* emprestimos) {
    dataEmprestimo = _dataEmpr;
    dataDevolucao = _dataDevolucao;
    livro = _livro;
    id = emprestimos->size() + 1;
}
Emprestimo::~Emprestimo() {};
Emprestimo::Livro* getLivro() {
    return livro;
}
Emprestimo::std::time_t getDataEmpr() {
    return dataEmprestimo;
}
Emprestimo::std::time_t getDataDevolucao() {
    return dataDevolucao;
}
Emprestimo::int getId() {
    return id;
}
Emprestimo::int getDiaEmpr() {
    struct tm diaTm;
    localtime_s(&diaTm, &dataEmprestimo);
    int dia = diaTm.tm_mday;
    return dia;
}
Emprestimo::int getDiaDev() {
    struct tm diaTm;
    localtime_s(&diaTm, &dataDevolucao);
    int dia = diaTm.tm_mday;
    return dia;
}
