//
//  main.cpp
//  structures
//
//  Created by Nosta on 21.06.2018.
//  Copyright © 2018 Nosta. All rights reserved.
//

#include <iostream>
#include "Stack.hpp"
#include "StackTests.h"

#include <chrono> //Crusade

#define RUN_TESTS

int main(int argc, const char * argv[])
{
    auto start = std::chrono::steady_clock::now();
    
#ifdef RUN_TESTS
    Sort_IntegersSorted_Successfully();
    Sort_StringsSorted_Successfully();
    IsEmpty_StackNotEmpty_Successfully();
#endif
    
    auto finish = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count() << "ms" << std::endl;
    
    return 0;
}
