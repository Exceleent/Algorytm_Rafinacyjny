//
// Created by dell on 5/19/2019.
//

#include "individual.h"

individual::individual(){}

individual::individual(const individual & individual1) {
koszt = individual1.koszt;
fitness  = individual1.fitness;
zbior_zadan = individual1.zbior_zadan;
sciezka_krytyczna = individual1.sciezka_krytyczna;
krawedzie_na_sciezce_krytycznej = individual1.krawedzie_na_sciezce_krytycznej;
liczbaKanalowKomunikacyjnych = individual1.liczbaKanalowKomunikacyjnych;
}

 individual::~individual() {
     koszt = 0;
     fitness =0;
     liczbaKanalowKomunikacyjnych = 0;
     zbior_zadan.clear();
     sciezka_krytyczna.clear();
     krawedzie_na_sciezce_krytycznej.clear();
     zbior_zadan.shrink_to_fit();
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

individual individual::skopiuj() {return individual();} //// Przenosi osobnika do nowego pokolenia bez zmian

individual::wartosc_do_selekcji individual::pobierzWartoscDoSelekcji() {
    return fitness;
}

void individual::aktualizacja_liczby_kanalow(){
    for(int i = 0 ; i < zbior_zadan.size() ; i++) {
        for(int j = 0 ; j < zbior_zadan[i].pobierzIloscNastepnikow() ;j++) {
            if(zbior_zadan[i].pobierzRodzajZasobu() != zbior_zadan[i].pobierzNastepnikOIndexie(j).pobierzRodzajZasobu()) liczbaKanalowKomunikacyjnych++;
        }
    }
}
void individual::stworz_sciezke_krytyczna(){}