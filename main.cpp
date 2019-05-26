#include <iostream>
#include "embrion.h"

int main() {
    embrion emb = embrion::getembrion();
    emb.print();

   // std::cout << "Hello, World!" << std::endl;
    return 0;
}