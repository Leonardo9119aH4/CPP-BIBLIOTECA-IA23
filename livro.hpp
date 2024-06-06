#include <iostream>
#ifndef LIVRO_HPP
#define LIVRO_HPP
class Livro{
    public:
        Livro(std::string _nome, std::string _isbn, std::string _genero, int _ano, std::string _autor, std::string _editora, int _dispo);
        ~Livro();
        int getDisponiveis();
        void setDisponiveis(int _dispo);
        std::string nome, isbn, genero, autor, editora;
        int ano;
    protected:
        int disponiveis;
};
#endif