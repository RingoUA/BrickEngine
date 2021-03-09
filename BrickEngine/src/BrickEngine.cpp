#include <iostream>
#include "BrickEngine.hpp"

void BrickEngine(){
    #ifdef NDEBUG
    std::cout << "BrickEngine/0.1: Hello World Release!" <<std::endl;
    #else
    std::cout << "BrickEngine/0.1: Hello World Debug!" <<std::endl;
    #endif
}
