#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

void identify(Base *p)
{
    if (A *pA = dynamic_cast<A *>(p))
        std::cout << *pA;
    else if (B *pB = dynamic_cast<B *>(p))
        std::cout << *pB;
    else if (C *pC = dynamic_cast<C *>(p))
        std::cout << *pC;
}

void identify(Base &p)
{
    try
    {
        A &rA = dynamic_cast<A &>(p);
        std::cout << rA;
    }
    catch (const std::exception &e)
    {
        try
        {
            B &rB = dynamic_cast<B &>(p);
            std::cout << rB;
        }
        catch (const std::exception &e)
        {
            try
            {
                C &rC = dynamic_cast<C &>(p);
                std::cout << rC;
            }
            catch (const std::exception &e)
            {
            }
        }
    }
}