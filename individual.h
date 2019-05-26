//
// Created by dell on 5/19/2019.
//
#ifndef ALGORYTM_RAFINACYJNY_INDIVIDUAL_H
#define ALGORYTM_RAFINACYJNY_INDIVIDUAL_H
#include "Node.h"
#include "embrion.h"

class individual {
public:
    typedef std::size_t gen_dla_osobnika;
    typedef std::size_t gen_dla_kanalu;
    typedef double wartosc_do_selekcji;
    typedef std::size_t liczba_kanalow_komunikacyjnych;

private:
    embrion::kosztKanalu koszt; /// Zalezy od genu
    wartosc_do_selekcji fitness ; /// Wartosc na podstawie ktore bedzie tworzy ranking
    std::vector <Node> zbior_zadan; /// Wektor symulucjacy drzewo
    std::vector <Node> sciezka_krytyczna; /// Sciezka krytyczna
    std::vector <embrion::kosztKanalu > krawedzie_na_sciezce_krytycznej; //// Kolejne krawedzie na sciezce krytycze
    liczba_kanalow_komunikacyjnych liczbaKanalowKomunikacyjnych ; /// Liczba kanalow
public:
    individual(const individual& individual1); //// Copy constructor do skopiowania osobnika
    individual();
    ~individual();
    void ustawWartoscDoSelekcji();  ////
    wartosc_do_selekcji pobierzWartoscDoSelekcji(); ////
    individual mutacja(); //// Mutacja losujemy jakies zadanie i zamieniamy zasob.
    individual skopiuj(); //// Przenosi kopie osobnika do nowego pokolenia bez zmian.
    individual createindividual(const embrion &exembrion,gen_dla_osobnika genDlaOsobnika,gen_dla_kanalu genDlaKanalu);  //// Na podstawie embrionu i rodzaju genu tworzy osobnika, ustawiamy koszt kanalu wypelniamy zbior zadan
    void stworz_sciezke_krytyczna(); //// Tworzy sciezke Krytyczna
    void aktualizacja_liczby_kanalow(); ////
};


#endif //ALGORYTM_RAFINACYJNY_INDIVIDUAL_H
