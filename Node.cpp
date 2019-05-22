//
// Created by dell on 5/19/2019.
//

#include "Node.h"

Node::Node(){

}

Node::Node(Node::gen gen1)
{}

Node::Node(const Node &node){} /// Przekopiowanie noda..

void Node::dodajKrawedz(Node::wartosc_krawedzi krawedz){}

Node::wartosc_krawedzi Node::pobierzKrawedzOIndexie(std::size_t index){return 0;}


void Node::ustawRodzajZasobu(std::size_t zasob, std::size_t cost, std::size_t time){
    rodzajZasobu = std::pair<std::size_t,std::pair<std::size_t,std::size_t>>(zasob,std::pair<std::size_t,std::size_t>(cost,time));
}


void Node::dodajNastepnika(const Node &nastepnik) {
    nastepniki1.push_back(nastepnik);
}

Node::czas Node::pobierzCzas(){
    return czas_wykonania_zadania;
}

Node::koszt Node::pobierzkoszt() {
    return koszt_wykonania_zadania;
}

std::size_t Node::pobierzRodzajZasobu(){
    return rodzajZasobu.first;
}

Node Node::pobierzNastepnikOIndexie(std::size_t index) {
    return nastepniki1[index];
}

std::size_t Node::pobierzIloscNastepnikow(){
    return nastepniki1.size();


}