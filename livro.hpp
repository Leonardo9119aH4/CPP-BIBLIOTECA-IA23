#include <iostream>
#ifndef LIVRO_HPP
#define LIVRO_HPP
class Livro{
    public:
        Livro(std::string _nome, std::string _isbn, std::string _genero, int _ano, std::string _autor, std::string _editora){
            nome = _nome;
            isbn = _isbn;
            genero = _genero;
            ano = _ano;
            autor = _autor;
            editora = _editora;
            emprestado = false;
        }
        ~Livro(){};
        std::string nome, isbn, genero, autor, editora;
        int ano;
        bool emprestado;
};
#endif