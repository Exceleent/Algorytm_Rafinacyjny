//
// Created by dell on 5/19/2019.
//

#include "Node.h"

Node::Node(){

}

Node::Node(std::size_t numerZadania1)
{numerZadania = numerZadania1;}

Node::Node(const Node &node){
    numerZadania = node.numerZadania;
    rodzajZasobu = node.rodzajZasobu;
    nastepniki1 = node.nastepniki1;
    krawedzie1 = node.krawedzie1;
} /// Przekopiowanie noda..

Node::~Node(){
    numerZadania = std::size_t {0};
    rodzajZasobu.first = std::size_t {0};
    rodzajZasobu.second.first = std::size_t {0};
    rodzajZasobu.second.second = std::size_t {0};
    nastepniki1.clear();
    krawedzie1.clear();
    nastepniki1.shrink_to_fit();
    krawedzie1.shrink_to_fit();
}

void Node::dodajKrawedz(Node::wartosc_krawedzi krawedz){
    krawedzie1.push_back(krawedz);
}

Node::wartosc_krawedzi Node::pobierzKrawedzOIndexie(std::size_t index){return krawedzie1.at(index);}


void Node::ustawRodzajZasobu(std::size_t zasob, std::size_t cost, std::size_t time){
    rodzajZasobu = std::pair<std::size_t,std::pair<std::size_t,std::size_t>>(zasob,std::pair<std::size_t,std::size_t>(cost,time));
}


void Node::dodajNastepnika(const Node &nastepnik) {
    nastepniki1.push_back(nastepnik);
}

Node::czas Node::pobierzCzas(){
    return rodzajZasobu.second.second;
}

Node::koszt Node::pobierzkoszt() {
    return rodzajZasobu.second.first;
}

std::size_t Node::pobierzRodzajZasobu(){
    return rodzajZasobu.first;
}

Node Node::pobierzNastepnikOIndexie(std::size_t index) {
    return nastepniki1.at(index);
}

std::size_t Node::pobierzIloscNastepnikow(){
    return nastepniki1.size();
}
std::size_t Node::pobierzNumerZadania(){
    return numerZadania;
}
