//
// Created by dell on 5/19/2019.
//

#include "Node.h"

typedef int rodzaj_zadania; //// Number zadania
typedef std::pair<int,std::pair<int,int>> rodzaj_zasobu; /// Tutaj trzymamy koszt oraz czas
typedef int czas_razy_koszt;
typedef std::vector<Node> nastepniki;


void Node::ustawZadanie(rodzaj_zadania rodzajZadania1) {
    rodzajZadania = rodzajZadania1;
}

void Node::ustawRodzajZasobu(int zasob, int cost, int time){
    rodzajZasobu = std::pair<int,std::pair<int,int>>(zasob,std::pair<int,int>(cost,time));
}

void Node::ustawWartosc(){
    czasRazyKoszt = rodzajZasobu.second.first * rodzajZasobu.second.second;
}

void Node::dodajZadanie(Node taskToAdd) {
    nastepniki1.push_back(taskToAdd);
}

czas_razy_koszt Node::pobierzWartosc(){
    return czasRazyKoszt;
}

int Node::pobierzRodzajZasobu(){
    return rodzajZasobu.first;
}

Node Node::pobierzNastepnik(int index) {
    return nastepniki1[index];
}

int Node::pobierzIloscNastepnikow(){
    return nastepniki1.size();
}