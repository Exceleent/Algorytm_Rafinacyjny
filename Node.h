//
// Created by dell on 5/19/2019.
//

#ifndef ALGORYTM_RAFINACYJNY_NODE_H
#define ALGORYTM_RAFINACYJNY_NODE_H
#include <iostream>
#include <vector>

class Node {
    typedef int rodzaj_zadania; //// Number zadania
    typedef std::pair<int,std::pair<int,int>> rodzaj_zasobu; /// Tutaj trzymamy koszt oraz czas
    typedef int czas_razy_koszt;
    typedef std::vector<Node> nastepniki;

private:
    rodzaj_zadania rodzajZadania;
    rodzaj_zasobu rodzajZasobu;
    czas_razy_koszt czasRazyKoszt;
    nastepniki nastepniki1;
public:
    void ustawZadanie(rodzaj_zadania rodzajZadania1);
    void ustawRodzajZasobu(int zasob, int cost, int time);
    void ustawWartosc();
    void dodajZadanie(Node taskToAdd);
    czas_razy_koszt pobierzWartosc();
    int pobierzRodzajZasobu();
    int pobierzIloscNastepnikow();
    Node pobierzNastepnik(int index);
};


#endif //ALGORYTM_RAFINACYJNY_NODE_H
