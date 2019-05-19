//
// Created by dell on 5/19/2019.
//
#ifndef ALGORYTM_RAFINACYJNY_INDIVIDUAL_H
#define ALGORYTM_RAFINACYJNY_INDIVIDUAL_H
#include "Node.h"
#include "embrion.h"

class individual {
    typedef int gen_dla_osobnika;
    typedef int gen_dla_kanalu;
    typedef double wartosc_do_selekcji;
    typedef int liczba_kanalow_komunikacyjnych;
    typedef int koszt_kanalu;
private:
    koszt_kanalu koszt; /// Zalezy od genu
    wartosc_do_selekcji fitness = 0; /// Wartosc na podstawie ktore bedzie tworzy ranking
    std::vector <Node> zbior_zadan; /// Wektor symulucjacy drzewo
    liczba_kanalow_komunikacyjnych kanaly =0; // Liczba kanalow
public:
    individual();
    void ustawWartoscDoSelekcji();
    wartosc_do_selekcji pobierzWartoscDoSelekcji();
    void mutacja(); //// Mutacja losujemy jakies zadanie i zamieniamy zasob
    individual(embrion exembrion,gen_dla_osobnika genDlaOsobnika,gen_dla_kanalu genDlaKanalu);  //// Na podstawie embrionu i rodzaju genu tworzy osobnika, ustawiamy koszt kanalu wypelniamy zbior zadan
    void aktualizacja_liczby_kanalow();
};


#endif //ALGORYTM_RAFINACYJNY_INDIVIDUAL_H
