//
// Created by dell on 5/19/2019.
//

#include "individual.h"

individual::individual(){}

individual::individual(const individual & individual1) {
koszt = individual1.koszt;
fitness  = individual1.fitness;
zbiorZadan = individual1.zbiorZadan;
sciezka_krytyczna = individual1.sciezka_krytyczna;
krawedzie_na_sciezce_krytycznej = individual1.krawedzie_na_sciezce_krytycznej;
liczbaKanalowKomunikacyjnych = individual1.liczbaKanalowKomunikacyjnych;
}

bool individual::WczytanoNawiasOtwierajacy(std::size_t indeks){
    return listaSasiedztwa[indeks] == -1;
}

bool individual::WczytanoNawiasZamykajacy(std::size_t indeks) {
    return listaSasiedztwa[indeks] == -2;
}

void individual::wyczyscStos(std::stack<std::size_t > &stack){
    while(!stack.empty()) stack.pop();
}
void individual::ustawIndeksNaPrawidlowyElement(std::size_t &indeks) {
    indeks++;
    while((listaSasiedztwa.at(indeks) < 0) && (indeks < listaSasiedztwa.size()-1)) indeks++;
}
void individual::zwiekszIndeks(std::size_t & indeks){
    indeks++;
}

void individual::wylaczDodawanieZadan(bool & dodaj){
    dodaj = false;
}

void individual::wlaczDodawanieZadan(bool & dodaj){
    dodaj = true;
}

bool individual::czyDodajemyZadania(bool dodaj){
    return dodaj;
}


void individual::przejdzDoNastepnegoElementuWLiscie(std::size_t & indeksLokalny , std::size_t & indeksGlobalny){
    indeksLokalny = indeksGlobalny + 1;
}

void individual::zamienListeSasiedztwaNaZbiorZadan() {
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

void individual::zamienZbiorZadanNaListeSasiedztwa(){
    std::size_t indeksDoZamkniecia = 0;
    listaSasiedztwa.clear();
    listaSasiedztwa.shrink_to_fit();
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
 individual::~individual() {
     koszt = 0;
     fitness =0;
     liczbaKanalowKomunikacyjnych = 0;
     zbiorZadan.clear();
     sciezka_krytyczna.clear();
     krawedzie_na_sciezce_krytycznej.clear();
     zbiorZadan.shrink_to_fit();
     sciezka_krytyczna.shrink_to_fit();
     krawedzie_na_sciezce_krytycznej.shrink_to_fit();
}

 individual individual::createindividual(const embrion &exembrion, individual::gen_dla_osobnika genDlaOsobnika,
                       individual::gen_dla_kanalu genDlaKanalu) {
     std::vector <Node> temporary = exembrion.zwrocZbiorZadan();
     individual *nowy_osobnik = new individual();
     std::random_device rd;  //Will be used to obtain a seed for the random number engine
     std::mt19937 gen(rd());
     std::uniform_int_distribution<int> losoweZadanieGenerator = std::uniform_int_distribution(0, static_cast<int>((exembrion.liczbaZadanWGrafie())) -1);
     int liczbaZadan = losoweZadanieGenerator(gen);
     for(int i = 0 ; i < liczbaZadan ; i++) {
         Node *zad1 = new Node();
     }


    nowy_osobnik->zbiorZadan = exembrion.zwrocZbiorZadan();
    nowy_osobnik->listaSasiedztwa = exembrion.zwrocListeSasiedztwa();

    return *nowy_osobnik;
}

void individual::ustawWartoscDoSelekcji(){}


individual individual::mutacja() {
    individual *zmutowany = new individual(*this);
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> losoweZadanieGenerator = std::uniform_int_distribution(0, static_cast<int>((zbiorZadan.size())) -1);
    std::size_t losoweZadanie = losoweZadanieGenerator(gen);
    losowyZasobDlaZadania(zmutowany->zbiorZadan.at(losoweZadanie));
    return *zmutowany;
}


individual individual::skopiuj() {
    return individual(*this);
}


individual::wartosc_do_selekcji individual::pobierzWartoscDoSelekcji() {
    return fitness;
}


void individual::aktualizacja_liczby_kanalow(){
    for(int i = 0 ; i < zbiorZadan.size() ; i++) {
        for(int j = 0 ; j < zbiorZadan[i].pobierzIloscNastepnikow() ;j++) {
            if(zbiorZadan[i].pobierzRodzajZasobu() != zbiorZadan[i].pobierzNastepnikOIndexie(j).pobierzRodzajZasobu()) liczbaKanalowKomunikacyjnych++;
        }
    }
}


void individual::stworz_sciezke_krytyczna(){}


std::size_t individual::liczbaZasobowDlaZadaniaONumerze(std::size_t index){
    return embrion::zasoby.at(index).size();
}


void individual::losowyZasobDlaZadania(Node & n){
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd());
    std::size_t numerZadania = n.pobierzNumerZadania();
    std::uniform_int_distribution<int>losowyZasobGenerator = std::uniform_int_distribution(0, static_cast<int>(liczbaZasobowDlaZadaniaONumerze(numerZadania))-1);
    int numerZasobu =losowyZasobGenerator(gen);
    n.ustawRodzajZasobu(embrion::zasoby[numerZadania][numerZasobu].first,embrion::zasoby[numerZadania][numerZasobu].second.first,embrion::zasoby[numerZadania][numerZasobu].second.second);
}