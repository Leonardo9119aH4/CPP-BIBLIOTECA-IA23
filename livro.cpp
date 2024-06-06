#include <iostream>
#include "livro.hpp"
Livro::Livro(std::string _nome, std::string _isbn, std::string _genero, int _ano, std::string _autor, std::string _editora, int _dispo) {
    nome = _nome;
    isbn = _isbn;
    genero = _genero;
    ano = _ano;
    autor = _autor;
    editora = _editora;
    disponiveis = _dispo;
}
Livro::~Livro() {};
int Livro::getDisponiveis() {
    return disponiveis;
}
void Livro::setDisponiveis(int _dispo) {
    disponiveis = _dispo;
}


