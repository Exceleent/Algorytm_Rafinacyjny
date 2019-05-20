//
// Created by dell on 5/19/2019.
//

#include "Node.h"

void Node::dodajKrawedz(){}

Node::wartosc_krawedzi Node::wyswietlKrawedzOIndexie(std::size_t index){}

void Node::ustawZadanie(rodzaj_zadania rodzajZadania1) {
    rodzajZadania = rodzajZadania1;
}

void Node::ustawRodzajZasobu(std::size_t zasob, std::size_t cost, std::size_t time){
    rodzajZasobu = std::pair<std::size_t,std::pair<std::size_t,std::size_t>>(zasob,std::pair<std::size_t,std::size_t>(cost,time));
}

void Node::ustawWartosc(){
    czasRazyKoszt = rodzajZasobu.second.first + rodzajZasobu.second.second;
}

void Node::dodajZadanie(Node taskToAdd) {
    nastepniki1.push_back(taskToAdd);
}

Node::czas_razy_koszt Node::pobierzWartosc(){
    return czasRazyKoszt;
}

std::size_t Node::pobierzRodzajZasobu(){
    return rodzajZasobu.first;
}

Node Node::pobierzNastepnik(std::size_t index) {
    return nastepniki1[index];
}

std::size_t Node::pobierzIloscNastepnikow(){
    return nastepniki1.size();


}