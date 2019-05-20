//
// Created by dell on 5/19/2019.
//
#ifndef ALGORYTM_RAFINACYJNY_INDIVIDUAL_H
#define ALGORYTM_RAFINACYJNY_INDIVIDUAL_H
#include "Node.h"
#include "embrion.h"

class individual {
    typedef std::size_t gen_dla_osobnika;
    typedef std::size_t gen_dla_kanalu;
    typedef double wartosc_do_selekcji;
    typedef std::size_t liczba_kanalow_komunikacyjnych;
    typedef std::size_t koszt_kanalu;
private:
    koszt_kanalu koszt; /// Zalezy od genu
    wartosc_do_selekcji fitness = 0; /// Wartosc na podstawie ktore bedzie tworzy ranking
    std::vector <Node> zbior_zadan; /// Wektor symulucjacy drzewo
    std::vector <Node> sciezka_krytyczna; /// Sciezka krytyczna
    std::vector <koszt_kanalu> krawedzie_na_sciezce_krytycznej; //// Kolejne krawedzie na sciezce krytycze
    liczba_kanalow_komunikacyjnych kanaly =0; /// Liczba kanalow
public:
    individual();
    void ustawWartoscDoSelekcji();  ////
    wartosc_do_selekcji pobierzWartoscDoSelekcji(); ////
    void mutacja(); //// Mutacja losujemy jakies zadanie i zamieniamy zasob
    individual(embrion exembrion,gen_dla_osobnika genDlaOsobnika,gen_dla_kanalu genDlaKanalu);  //// Na podstawie embrionu i rodzaju genu tworzy osobnika, ustawiamy koszt kanalu wypelniamy zbior zadan
    void stworz_sciezke_krytyczna(); //// Tworzy sciezke Krytyczna
    void aktualizacja_liczby_kanalow(); ////
};


#endif //ALGORYTM_RAFINACYJNY_INDIVIDUAL_H
