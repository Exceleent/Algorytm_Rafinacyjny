#include <iostream>
#include "embrion.h"

int main() {
    embrion emb = embrion::getembrion();
    emb.wydrukujListeSasiedztwa();
    emb.zamienListeSasiedztwaNaZbiorZadan();
    emb.zamienZbiorZadanNaListeSasiedztwa();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}