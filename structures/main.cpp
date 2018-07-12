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

//#define RUN_TESTS

int main(int argc, const char * argv[])
{
    
#ifdef RUN_TESTS
    Sort_IntegersSorted_Successfully();
    Sort_StringsSorted_Successfully();
#endif
    
    return 0;
}
