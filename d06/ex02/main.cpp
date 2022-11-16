#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

int main()
{
    // for (int i = 0; i != 10; i++){
    //     srand(i);
    //     Base *ret = generate();
    //     identify(ret);
    //     delete ret;
    // }

    for (int i = 0; i != 10; i++){
        srand(i);
        Base *ret_p = generate();
        Base &ret_r = *ret_p;
        identify(ret_r);
        delete ret_p;

    }
 
    return 0;
}
