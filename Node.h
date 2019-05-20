//
// Created by dell on 5/19/2019.
//

#ifndef ALGORYTM_RAFINACYJNY_NODE_H
#define ALGORYTM_RAFINACYJNY_NODE_H
#include <iostream>
#include <vector>

class Node {
    typedef std::size_t wartosc_krawedzi;
    typedef std::size_t rodzaj_zadania; //// Number zadania
    typedef std::pair<std::size_t,std::pair<std::size_t,std::size_t>> rodzaj_zasobu; /// Tutaj trzymamy koszt oraz czas
    typedef std::size_t czas_razy_koszt;
    typedef std::vector<Node> nastepniki;
    typedef std::vector<wartosc_krawedzi > krawedzie;

private:
    rodzaj_zadania rodzajZadania;
    rodzaj_zasobu rodzajZasobu;
    czas_razy_koszt czasRazyKoszt;
    nastepniki nastepniki1;
    krawedzie krawedzie1;
public:
    void dodajKrawedz();
    wartosc_krawedzi wyswietlKrawedzOIndexie(std::size_t index);
    void ustawZadanie(rodzaj_zadania rodzajZadania1);
    void ustawRodzajZasobu(std::size_t zasob, std::size_t cost, std::size_t time);
    void ustawWartosc();
    void dodajZadanie(Node taskToAdd);
    czas_razy_koszt pobierzWartosc();
    int pobierzRodzajZasobu();
    int pobierzIloscNastepnikow();
    Node pobierzNastepnik(std::size_t index);
};


#endif //ALGORYTM_RAFINACYJNY_NODE_H
