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

    return individual();
}   //// Na podstawie  embrionu (grafu) utworz jego podgraf, rodzaj zasobu przydzielony do zadan jest zdeterminowany przez gen_dla_osobnika(wyboru zasobow) , rodzaj kanalow komunikacyjnych
    /// zdefinoway przez gen_dla_kanalu.....

void individual::ustawWartoscDoSelekcji(){} /// Ustalenie wartosci do selekcji

individual individual::mutacja() { return  individual();} //// Mutacja zamienia zamienia i zwraca nowego osobnika ktory bedzie dodany do nowego pokolenia

individual individual::skopiuj() {return individual(*this);} //// Przenosi osobnika do nowego pokolenia bez zmian

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