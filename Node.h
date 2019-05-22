//
// Created by dell on 5/19/2019.
//

#ifndef ALGORYTM_RAFINACYJNY_NODE_H
#define ALGORYTM_RAFINACYJNY_NODE_H
#include <iostream>
#include <vector>

class Node {
    typedef std::size_t gen;
    typedef std::size_t wartosc_krawedzi;
    typedef std::pair<std::size_t,std::pair<std::size_t,std::size_t>> rodzaj_zasobu; /// numer zadania, koszt oraz czas(dla przy danym zasobie)
    typedef std::vector<Node> nastepniki;
    typedef std::vector<wartosc_krawedzi > krawedzie;
    typedef std::size_t czas;
    typedef std::size_t koszt;

private:
    gen gen_zadania;
    rodzaj_zasobu rodzajZasobu;
    czas czas_wykonania_zadania;
    koszt koszt_wykonania_zadania;
    nastepniki nastepniki1;
    krawedzie krawedzie1;
public:
    Node(); ///
    Node(gen);
    Node(const Node &node); //// Copy constructor, do tworzenia kopi osobnika..
    void dodajKrawedz(wartosc_krawedzi krawedz);
    wartosc_krawedzi pobierzKrawedzOIndexie(std::size_t index);
    void ustawRodzajZasobu(std::size_t zasob, std::size_t cost, std::size_t time);
    void dodajNastepnika(const Node &nastepnik);
    czas pobierzCzas();
    koszt pobierzkoszt();
    std::size_t pobierzRodzajZasobu();
    std::size_t pobierzIloscNastepnikow();
    Node pobierzNastepnikOIndexie(std::size_t index);
};


#endif //ALGORYTM_RAFINACYJNY_NODE_H
