//
// Created by dell on 5/19/2019.
//

#ifndef ALGORYTM_RAFINACYJNY_POPULATION_H
#define ALGORYTM_RAFINACYJNY_POPULATION_H
#include "individual.h"


class population {
typedef std::vector<individual> populacja;
typedef individual najlepszy_osobnik;
typedef std::pair<individual,individual> paraDoKrzyzowania;
typedef std::pair<individual,individual> paraPoKrzyzowania;


private:
    populacja aktualnaPopulacja;
    najlepszy_osobnik najlepszyOsobnik ;

public:
    population();
    ~population();

    void stworzNajlepszegoOsobnika(); /// Tworzy aktualnie najlepszego osobnika
    void dodajOsobnika(const individual &individual); /// Dodaje osobnika do populacji
    individual zwrocNajlepszegoOsobnika(); //// Zwraca najlepszego osobnika np do wypisu
    paraDoKrzyzowania selekcjaDoKrzyzowania(); //// Z Calej populacji wybiera pare i zwraca ja do krzyzowania
    individual selekcjaDoMutacjiIKopiowania(); //// Z Calej populacji wybiera osobnika i zwraca go do mutacji/kopiowania
    paraPoKrzyzowania krzyzowanie(paraDoKrzyzowania paraDoKrzyzowania1); //// Krzyzuje dwojke i zwraca ich dzieci
};


#endif //ALGORYTM_RAFINACYJNY_POPULATION_H
