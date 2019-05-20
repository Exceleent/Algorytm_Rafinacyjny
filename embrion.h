//
// Created by dell on 5/19/2019.
//

#ifndef ALGORYTM_RAFINACYJNY_EMBRION_H
#define ALGORYTM_RAFINACYJNY_EMBRION_H
#include "individual.h"

class embrion {
private:
    std::vector <Node> zbior_zadan; /// Wektor symulucjacy drzewo
public:
    embrion();//// Tworzy embrion z uzupelniony zbiorem_zadan
    void evaluate();
};


#endif //ALGORYTM_RAFINACYJNY_EMBRION_H
