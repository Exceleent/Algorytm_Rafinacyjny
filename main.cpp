#include <iostream>
#include "embrion.h"

int main() {
    embrion emb = embrion::getembrion();
    emb.wydrukujListeSasiedztwa();
    emb.zamienListeSasiedztwaNaZbiorZadan();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}