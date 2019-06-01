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
    std::vector<Node::numer_zadania> listaSasiedztwa;
    void zwiekszIndeks(std::size_t & indeks);
    void przejdzDoNastepnegoElementuWLiscie(std::size_t & indeksLokalny , std::size_t & indeksGlobalny);
    void wylaczDodawanieZadan(bool & dodawanie);
    void wlaczDodawanieZadan(bool & dodaj);
    void ustawIndeksNaPrawidlowyElement(std::size_t & indeks );
    void wyczyscStos(std::stack<std::size_t > &stack);
    void pushResourcesTaskInToEmbrionResource(std::vector<Node::rodzaj_zasobu>&zasobyZadania);
    void uzupelnijZbiorZadan(std::ifstream &file);
    void uzupelnijZasoby(std::ifstream &file);
    void uzupelnijKanaly(std::ifstream &file);
    void losowyZasobDlaZadania(Node &node);
    void uzupelnijListeSasiedztwa(std::ifstream &file);
    bool czyDodajemyZadania(bool dodaj);
    bool WczytanoNawiasOtwierajacy(std::size_t indeks);
    bool WczytanoNawiasZamykajacy(std::size_t indeks);



    std::size_t liczbaZadanWGrafie();
    std::size_t liczbaZasobowDlaZadaniaONumerze(std::size_t index);
    embrion();//// Tworzy embrion z uzupelniony zbiorem_zadan

public:
    void zamienZbiorZadanNaListeSasiedztwa();
    void wydrukujListeSasiedztwa();
    void zamienListeSasiedztwaNaZbiorZadan();
    void print();
    static embrion & getembrion() {
        static embrion exembrion;
        return exembrion;
    }
    void evaluate();
};


#endif //ALGORYTM_RAFINACYJNY_EMBRION_H
