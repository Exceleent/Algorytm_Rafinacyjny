//
// Created by dell on 5/19/2019.
//

#include "population.h"
population::population(){
}
void population::stworzNajlepszegoOsobnika(){
    for(auto indiv : aktualnaPopulacja) {
        if(najlepszyOsobnik.pobierzWartoscDoSelekcji() < indiv.pobierzWartoscDoSelekcji()) najlepszyOsobnik = indiv;
    }
}
void population::dodajOsobnika(individual individual){
    aktualnaPopulacja.push_back(individual);
}
individual population::zwrocNajlepszegoOsobnika() {
    return individual();
}
population::paraDoKrzyzowania population::selekcja() {
    return paraPoKrzyzowania(individual(),individual());
}
population::paraPoKrzyzowania population::krzyzowanie(population::paraDoKrzyzowania paraDoKrzyzowania1) {
    return paraPoKrzyzowania(individual(),individual());

}