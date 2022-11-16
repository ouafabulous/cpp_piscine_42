#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base   *generate(void) {
    
    if (rand() % 3 == 0) {
        A *retA = new A;
        return ((Base *)(retA));
    }
    else if (rand() % 3 == 1) {
        B *retB = new B;
        return ((Base *)(retB));
    }
    else if (rand() % 3 == 2) {
        C *retC = new C;
        return ((Base *)(retC));
    }
    return (generate());
} 