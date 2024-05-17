#include <iostream>
#include <chrono>
#include "livro.hpp"
class Emprestimo{
    public:
        Emprestimo(){
            
        }
        ~Emprestimo(){}
    protected:
        auto data, hora, dataDevolucao;
        Livro livro;
};