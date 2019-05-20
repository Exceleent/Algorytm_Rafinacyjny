//
// Created by dell on 5/19/2019.
//

#include "individual.h"

individual::individual(){}
individual::individual(embrion exembrion, individual::gen_dla_osobnika genDlaOsobnika,
                       individual::gen_dla_kanalu genDlaKanalu) {}

void individual::ustawWartoscDoSelekcji(){ ////
    for(int i = 0; i < sciezka_krytyczna.size() ; i++) {
        fitness += sciezka_krytyczna[i].pobierzWartosc();;;
    }
    fitness += koszt*kanaly;
}

void individual::mutacja() {}

individual::wartosc_do_selekcji individual::pobierzWartoscDoSelekcji() {
    return fitness;
}

void individual::aktualizacja_liczby_kanalow(){
    for(int i = 0 ; i < zbior_zadan.size() ; i++) {
        for(int j = 0 ; j < zbior_zadan[i].pobierzIloscNastepnikow() ;j++) {
            if(zbior_zadan[i].pobierzRodzajZasobu() != zbior_zadan[i].pobierzNastepnik(j).pobierzRodzajZasobu()) kanaly++;
        }
    }
}