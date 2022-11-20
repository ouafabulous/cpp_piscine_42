#include "Data.hpp"

uintptr_t   serialize(Data* ptr) {
    uintptr_t   ret = reinterpret_cast<uintptr_t>((void *)ptr);
    return (ret);
}
