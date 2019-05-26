//
// Created by dell on 5/19/2019.
//

#ifndef ALGORYTM_RAFINACYJNY_EMBRION_H
#define ALGORYTM_RAFINACYJNY_EMBRION_H
#include "Node.h"
#include <iterator>
#include <algorithm>
#include <stdlib.h>
#include <stack>
#include <experimental/random>
#include <fstream>
#include <sstream>
#include <map>


class embrion {
    /////// Tutaj trzeba jeszcze przygotowac wszystkie stale zmienne...
    ///// 1. Prawdopodobienstwa
    ///// 3. Graf wczytany z pliku
public:
    typedef std::size_t kosztKanalu;
    typedef std::size_t przepustowoscKanalu;
private:
    static std::vector<std::vector<Node::rodzaj_zasobu>> zasoby;
    static std::vector<std::pair<kosztKanalu,przepustowoscKanalu >> kanaly;
    std::vector <Node> zbiorZadan; /// Wektor symulucjacy drzewo
    void pushResourcesTaskInToEmbrionResource(std::vector<Node::rodzaj_zasobu>&zasobyZadania);
    void uzupelnijZbiorZadan(std::ifstream &file);
    void uzupelnijZasoby(std::ifstream &file);
    void uzupelnijKanaly(std::ifstream &file);
    std::size_t liczbaZadanWGrafie();
    void losowyZasobDlaZadania(Node &node);
    std::size_t liczbaZasobowDlaZadaniaONumerze(std::size_t index);
    embrion();//// Tworzy embrion z uzupelniony zbiorem_zadan


public:
    void print();
    static embrion & getembrion() {
        static embrion exembrion;
        return exembrion;
    }
    void evaluate();
};


#endif //ALGORYTM_RAFINACYJNY_EMBRION_H
