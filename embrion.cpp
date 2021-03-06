//
// Created by dell on 5/19/2019.
//

#include "embrion.h"
#include <sstream>
#include <random>
std::vector<std::vector<Node::rodzaj_zasobu>> embrion::zasoby;
std::vector<std::pair<embrion::kosztKanalu,embrion::przepustowoscKanalu >> embrion::kanaly;
 std::vector<Node::rodzaj_zasobu> embrion::zasobyNajszybsze;
 std::vector<Node::rodzaj_zasobu> embrion::zasobyNajtansze;
 std::vector<Node::rodzaj_zasobu> embrion::zasobyNajmniejszyIloczynCzasuIKosztu;



bool embrion::WczytanoNawiasOtwierajacy(std::size_t indeks){
    return listaSasiedztwa[indeks] == -1;
}


bool embrion::WczytanoNawiasZamykajacy(std::size_t indeks) {
    return listaSasiedztwa[indeks] == -2;
}

void embrion::wyczyscStos(std::stack<std::size_t > &stack){
 while(!stack.empty()) stack.pop();
}
void embrion::ustawIndeksNaPrawidlowyElement(std::size_t &indeks) {
    indeks++;
    while((listaSasiedztwa.at(indeks) < 0) && (indeks < listaSasiedztwa.size()-1)) indeks++;
}
void embrion::zwiekszIndeks(std::size_t & indeks){
    indeks++;
}

void embrion::wylaczDodawanieZadan(bool & dodaj){
    dodaj = false;
}

void embrion::wlaczDodawanieZadan(bool & dodaj){
    dodaj = true;
}

bool embrion::czyDodajemyZadania(bool dodaj){
    return dodaj;
}


void embrion::przejdzDoNastepnegoElementuWLiscie(std::size_t & indeksLokalny , std::size_t & indeksGlobalny){
    indeksLokalny = indeksGlobalny + 1;
}

void embrion::zamienListeSasiedztwaNaZbiorZadan() {
    std::size_t indeks_global{0};
    std::size_t indeks_lokal{0};
    std::stack<std::size_t> stack;
    bool dodaj;
    while(indeks_global != listaSasiedztwa.size()-1) {
        wylaczDodawanieZadan(dodaj);
        Node *zadanie = new Node(listaSasiedztwa.at(indeks_global));
        przejdzDoNastepnegoElementuWLiscie(indeks_lokal,indeks_global);
        if(WczytanoNawiasOtwierajacy(indeks_lokal)) wlaczDodawanieZadan(dodaj);
        while(indeks_lokal != listaSasiedztwa.size()-1){
            if(WczytanoNawiasOtwierajacy(indeks_lokal)) {
                stack.push(std::size_t{0});
            }
            else if(WczytanoNawiasZamykajacy(indeks_lokal)) {
                if(!stack.empty()) {
                    stack.pop();
                }
            }
            else if(stack.size() == 1 && czyDodajemyZadania(dodaj)) {
                Node *dziecko = new Node(listaSasiedztwa.at(indeks_lokal));
                zadanie->dodajNastepnika(*dziecko);
                delete dziecko;
            }
            zwiekszIndeks(indeks_lokal);
        }
        zbiorZadan.push_back(*zadanie);
        ustawIndeksNaPrawidlowyElement(indeks_global);
        wyczyscStos(stack);
        delete zadanie;
    }
}

void embrion::zamienZbiorZadanNaListeSasiedztwa(){
    std::size_t indeksDoZamkniecia = 0;
    listaSasiedztwa.clear();
    listaSasiedztwa.shrink_to_fit();
        std::cout << zbiorZadan.at(0).pobierzNumerZadania();
        std::cout << "\n";
        listaSasiedztwa.push_back(zbiorZadan.at(0).pobierzNumerZadania());
    for(auto zadanie : zbiorZadan) {
        if(zadanie.pobierzIloscNastepnikow() > 0) {
             auto indeks = std::find(listaSasiedztwa.rbegin(),listaSasiedztwa.rend(),zadanie.pobierzNumerZadania());
             auto baseindeks =  indeks.base() ;
                listaSasiedztwa.insert(baseindeks  ,-2);
            for(int i = zadanie.pobierzIloscNastepnikow()-1 ; i >= 0 ; i--) {
                  indeks = std::find(listaSasiedztwa.rbegin(),listaSasiedztwa.rend(),zadanie.pobierzNumerZadania());
                   baseindeks =  indeks.base() ;
                listaSasiedztwa.insert(baseindeks ,zadanie.pobierzNastepnikOIndexie(i).pobierzNumerZadania());
            }
            indeks = std::find(listaSasiedztwa.rbegin(),listaSasiedztwa.rend(),zadanie.pobierzNumerZadania());
            baseindeks =  indeks.base() ;
            listaSasiedztwa.insert(baseindeks,-1);
        }
    }
    for(auto k : listaSasiedztwa) {
        std::cout << k << " ";
    }

}


void embrion::uzupelnijListeSasiedztwa(std::ifstream &file) {
    Node::numer_zadania nodeValue = 0;
    std::string lineFromFile{};
    std::stringstream ssLineFromFile;
    while (!file.eof()) {
        getline(file, lineFromFile);
        ssLineFromFile.str(lineFromFile);
        while (!ssLineFromFile.eof()) {
          ssLineFromFile >> nodeValue;
          listaSasiedztwa.push_back(nodeValue);
            }
        }
}
void embrion::wydrukujListeSasiedztwa(){
    for(auto elem : listaSasiedztwa) {
        std::cout << elem << " ";
    }
}
embrion::embrion() {
    std::ifstream mystream ("tree.txt");
    std::ifstream mystream2 ("zasoby.txt");
    std::ifstream mystream3 ("kanaly.txt");
    uzupelnijZbiorZadan(mystream);
    uzupelnijZasoby(mystream2);
    uzupelnijKanaly(mystream3);
}

void embrion::evaluate(){}  /// Funkckja odpalajaca ewolucje...

void embrion::print(){
    for(auto k : zbiorZadan){
        std::cout << k.pobierzNumerZadania() << ", " << k.pobierzNastepnikOIndexie(0).pobierzNumerZadania() << ", " << k.pobierzKrawedzOIndexie(0)  ;
    }
}


void embrion::uzupelnijZbiorZadan(std::ifstream &file) {
    int edgeValue =0;
    std::size_t nodeValue =0;
    std::string lineFromFile{};
    std::stringstream ssLineFromFile;
    char bracket ;
    while(!file.eof()){
        getline(file, lineFromFile);
        ssLineFromFile.str(lineFromFile);
        ssLineFromFile >> nodeValue;
        Node *task = new Node(nodeValue);
        while(!ssLineFromFile.eof()){
            ssLineFromFile >> nodeValue;
            if(ssLineFromFile.eof()) break;
            Node *child = new Node(nodeValue);
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

void embrion::uzupelnijZasobNajtanszy(){
    embrion::zasobyNajszybsze.reserve(embrion::zasoby.size());
    for(int i = 0 ; i < embrion::zasoby.size() ; i++) {
        for(int j = 0 ; j < embrion::zasoby[i].size() ; j++) {
          if(j == 0)  embrion::zasobyNajtansze.insert(std::next(embrion::zasobyNajtansze.begin(),i),embrion::zasoby[i][j]);
          if(embrion::zasobyNajtansze[i].second.first > embrion::zasoby[i][j].second.first) embrion::zasobyNajtansze[i] = embrion::zasoby[i][j];
        }
    }
}
void embrion::uzupelnijZasobNajszybszy(){
    embrion::zasobyNajszybsze.reserve(embrion::zasoby.size());
    for(int i = 0 ; i < embrion::zasoby.size() ; i++) {
        for(int j = 0 ; j < embrion::zasoby[i].size() ; j++) {
            if(j == 0)  embrion::zasobyNajszybsze.insert(std::next(embrion::zasobyNajszybsze.begin(),i),embrion::zasoby[i][j]);
            if(embrion::zasobyNajszybsze[i].second.second < embrion::zasoby[i][j].second.second) embrion::zasobyNajszybsze[i] = embrion::zasoby[i][j];
        }
    }
}
void embrion::uzupelnijZasobKtoregoIloczynNajmniejszy(){
    for(int i = 0 ; i < embrion::zasoby.size() ; i++) {
        for(int j = 0 ; j < embrion::zasoby[i].size() ; j++) {
            if(j == 0)  embrion::zasobyNajmniejszyIloczynCzasuIKosztu.insert(std::next(embrion::zasobyNajmniejszyIloczynCzasuIKosztu.begin(),i),embrion::zasoby[i][j]);
            if(embrion::zasobyNajmniejszyIloczynCzasuIKosztu[i].second.first * embrion::zasobyNajmniejszyIloczynCzasuIKosztu[i].second.second
                        > embrion::zasoby[i][j].second.first * embrion::zasoby[i][j].second.second) embrion::zasobyNajszybsze[i] = embrion::zasoby[i][j];
        }
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

std::size_t embrion::liczbaZadanWGrafie() const{
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

std::vector<Node>  embrion::zwrocZbiorZadan() const{
    return zbiorZadan;
}


std::vector<Node::numer_zadania >  embrion::zwrocListeSasiedztwa() const{
    return listaSasiedztwa;
}





