//
// Created by dell on 5/19/2019.
//

#include "embrion.h"
#include <sstream>
#include <random>

std::vector<std::vector<Node::rodzaj_zasobu>> embrion::zasoby;
std::vector<std::pair<embrion::kosztKanalu,embrion::przepustowoscKanalu >> embrion::kanaly;


embrion::embrion() {
    std::ifstream mystream ("tree.txt");
    std::ifstream mystream2 ("zasoby.txt");
    std::ifstream mystream3 ("kanaly.txt");
    uzupelnijZbiorZadan(mystream);
    uzupelnijZasoby(mystream2);
    uzupelnijKanaly(mystream3);
    for(int i = 0 ; i < liczbaZadanWGrafie() ;i++){
        losowyZasobDlaZadania(zbiorZadan.at(i));
    }
}

void embrion::evaluate(){}  /// Funckja odpalajaca ewolucje...

void embrion::print(){
    for(auto k : zbiorZadan){
        std::cout << k.pobierzNumerZadania() << ", " << k.pobierzNastepnikOIndexie(0).pobierzNumerZadania() << ", " << k.pobierzKrawedzOIndexie(0)  ;
    }
}


void embrion::uzupelnijZbiorZadan(std::ifstream &file) {
    int edgeValue =0;
    std::size_t NodeValue =0;
    std::string lineFromFile{};
    std::stringstream ssLineFromFile;
    char bracket ;
    while(!file.eof()){
        getline(file, lineFromFile);
        ssLineFromFile.str(lineFromFile);
        ssLineFromFile >> NodeValue;
        Node *task = new Node(NodeValue);
        while(!ssLineFromFile.eof()){
            ssLineFromFile >> NodeValue;
            if(ssLineFromFile.eof()) break;
            Node *child = new Node(NodeValue);
            task->dodajNastepnika(*child);
            ssLineFromFile >> bracket;
            ssLineFromFile >> edgeValue;
            task->dodajKrawedz(edgeValue);
            ssLineFromFile >> bracket;
        }
        ssLineFromFile.str("");
        ssLineFromFile.clear();
        zbiorZadan.push_back(*task);
    }
}

void embrion::uzupelnijZasoby(std::ifstream &file) {
    std::string lineFromFile{};
    std::stringstream ssLineFromFile;
    while (!file.eof()) {
        std::vector<Node::rodzaj_zasobu> allResourcesForTask;
        getline(file, lineFromFile);
        ssLineFromFile.str(lineFromFile);
        while(!ssLineFromFile.eof()) {
            Node::rodzaj_zasobu z1;
            ssLineFromFile >> z1.first; //// Wczytuje rodzaj zasobu
            //if(ssLineFromFile.eof()) break;
            ssLineFromFile >> z1.second.first; //// Wczytuje koszt zasobu
            ssLineFromFile >> z1.second.second; //// Wczytuje czas zasobu
            allResourcesForTask.push_back(z1);
        }
        ssLineFromFile.clear();
        ssLineFromFile.str("");
        pushResourcesTaskInToEmbrionResource(allResourcesForTask);
    }
}


void embrion::uzupelnijKanaly(std::ifstream &file){
    std::string lineFromFile{};
    std::stringstream ssLineFromFile;
    while (!file.eof()) {
        getline(file,lineFromFile);
        ssLineFromFile.str(lineFromFile);
        while(!ssLineFromFile.eof()){
            std::pair<kosztKanalu , przepustowoscKanalu> p;
            ssLineFromFile >> p.first;
            if(ssLineFromFile.eof()) break;
            ssLineFromFile >> p.second;
            kanaly.push_back(p);
        }
    }
}


void embrion::pushResourcesTaskInToEmbrionResource(std::vector<Node::rodzaj_zasobu>&zasobyZadania){
    zasoby.push_back(zasobyZadania);
}

std::size_t embrion::liczbaZadanWGrafie(){
    return zbiorZadan.size();
}

void embrion::losowyZasobDlaZadania(Node & n){
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd());
std::size_t numerZadania = n.pobierzNumerZadania();
std::uniform_int_distribution<int>losowyZasobGenerator = std::uniform_int_distribution(0, static_cast<int>(liczbaZasobowDlaZadaniaONumerze(numerZadania))-1);
int numerZasobu =losowyZasobGenerator(gen);
n.ustawRodzajZasobu(zasoby[numerZadania][numerZasobu].first,zasoby[numerZadania][numerZasobu].second.first,zasoby[numerZadania][numerZasobu].second.second);
}



std::size_t embrion::liczbaZasobowDlaZadaniaONumerze(std::size_t index){
    return zasoby.at(index).size();
}



