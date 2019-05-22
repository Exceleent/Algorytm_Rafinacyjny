//
// Created by dell on 5/19/2019.
//

#ifndef ALGORYTM_RAFINACYJNY_EMBRION_H
#define ALGORYTM_RAFINACYJNY_EMBRION_H
#include "Node.h"

class embrion {

    /////// Tutaj trzeba jeszcze przygotowac wszystkie stale zmienne...
    ///// 1. Prawdopodobienstwa
    ///// 2. Tablice z zasobami, kosztem i czasem
    ///// 3. Graf wczytany z pliku
private:
    std::vector <Node> zbior_zadan; /// Wektor symulucjacy drzewo
public:
    embrion();//// Tworzy embrion z uzupelniony zbiorem_zadan
    void evaluate();
};


#endif //ALGORYTM_RAFINACYJNY_EMBRION_H
