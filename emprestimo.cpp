#include <iostream>
#include <chrono>
#include <ctime>
#include <random>
#include "livro.hpp"
#include "emprestimo.hpp"
Emprestimo::Emprestimo(std::time_t _dataEmpr, std::time_t _dataDevolucao, Livro* _livro, std::vector<Emprestimo*>* emprestimos) {
    dataEmprestimo = _dataEmpr;
    dataDevolucao = _dataDevolucao;
    livro = _livro;
    id = emprestimos->size() + 1;
    livro->setDisponiveis(livro->getDisponiveis() - 1);
}
Emprestimo::~Emprestimo() {
    livro->setDisponiveis(livro->getDisponiveis() + 1);
}
Livro* Emprestimo::getLivro() {
    return livro;
}
std::time_t Emprestimo::getDataEmpr() {
    return dataEmprestimo;
}
std::time_t Emprestimo::getDataDevolucao() {
    return dataDevolucao;
}
int Emprestimo::getId() {
    return id;
}
int Emprestimo::getDiaEmpr() {
    struct tm diaTm;
    localtime_s(&diaTm, &dataEmprestimo);
    int dia = diaTm.tm_mday;
    return dia;
}
int Emprestimo::getDiaDev() {
    struct tm diaTm;
    localtime_s(&diaTm, &dataDevolucao);
    int dia = diaTm.tm_mday;
    return dia;
}
