//
// Created by dell on 5/19/2019.
//

#ifndef ALGORYTM_RAFINACYJNY_NODE_H
#define ALGORYTM_RAFINACYJNY_NODE_H
#include <iostream>
#include <vector>

class Node {
public:
    typedef int numer_zadania;
    typedef std::size_t wartosc_krawedzi;
    typedef std::pair<std::size_t,std::pair<std::size_t,std::size_t>> rodzaj_zasobu; /// rodzaj zasobu, koszt oraz czas(dla przy danym zasobie)
    typedef std::vector<Node> nastepniki;
    typedef std::vector<wartosc_krawedzi > krawedzie;
    typedef std::size_t czas;
    typedef std::size_t koszt;

private:
    numer_zadania numerZadania;
    rodzaj_zasobu rodzajZasobu;
    nastepniki nastepniki1;
    krawedzie krawedzie1;
public:
    Node(); ///
    Node(std::size_t);  /// Ustawia numer zadania w wezle reprezentujacym zadanie
    Node(const Node &node); //// Copy constructor, do tworzenia kopi osobnika..
    ~Node();
    void ustawNumerZadania(std::size_t);
    void dodajKrawedz(wartosc_krawedzi krawedz);
    wartosc_krawedzi pobierzKrawedzOIndexie(std::size_t index);
    void ustawRodzajZasobu(std::size_t zasob, std::size_t cost, std::size_t time);
    void dodajNastepnika(const Node &nastepnik);
    czas pobierzCzas();
    koszt pobierzkoszt();
    std::size_t pobierzRodzajZasobu();
    std::size_t pobierzIloscNastepnikow();
    Node::numer_zadania pobierzNumerZadania();
    Node pobierzNastepnikOIndexie(std::size_t index);
    void usunNastepniki();
    void usunKrawedzie();
};


#endif //ALGORYTM_RAFINACYJNY_NODE_H
