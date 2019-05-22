//
// Created by dell on 5/19/2019.
//

#include "individual.h"

individual::individual(){}

individual::individual(const individual &) {}

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
            if(zbior_zadan[i].pobierzRodzajZasobu() != zbior_zadan[i].pobierzNastepnikOIndexie(j).pobierzRodzajZasobu()) kanaly++;
        }
    }
}
void individual::stworz_sciezke_krytyczna(){}