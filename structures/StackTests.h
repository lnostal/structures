//
//  StackTests.h
//  structures
//
//  Created by Nosta on 13.07.2018.
//  Copyright © 2018 Nosta. All rights reserved.
//

#ifndef StackTests_h
#define StackTests_h

#include "Stack.hpp"
#include <iostream>

bool Sort_StringsSorted_Successfully()
{
    Stack<std::string> letters = Stack<std::string>();
    letters.Push("ass");
    letters.Push("d");
    letters.Push("a");
    letters.Push("n");
    letters.Push("b");
    letters.Push("date");
    letters.Push("alkoholikerin");
    letters.Push("nil");
    letters.Push("bus");
    letters.Sort(letters);
    
    std::string expectedString = "nil n date d bus b ass alkoholikerin a";
    std::string resultString = letters.WriteToString(" ");
    
    bool successfully = expectedString == resultString;
   
    if (successfully)
    {
        std::cout << "Sort_StringsSorted_Successfully\t\t[OK]" << std::endl;
    }
    else
    {
        std::cout << "Sort_StringsSorted_Successfully\t\t[FAIL]" << std::endl;
    }
    
    return successfully;
}

bool Sort_IntegersSorted_Successfully()
{
    Stack<int> integer = Stack<int>();
    
    integer.Push(1);
    integer.Push(2);
    integer.Push(3);
    integer.Push(4);
    integer.Push(5);
    integer.Push(1);
    integer.Push(-2);
    integer.Push(3);
    integer.Push(-4);
    integer.Push(5);
    integer.Sort(integer);
    
    std::string expectedString = "5 5 4 3 3 2 1 1 -2 -4";
    std::string resultString = integer.WriteToString(" ");
    
    bool successfully = expectedString == resultString;
    
    if (successfully)
    {
        std::cout << "Sort_IntegersSorted_Successfully\t[OK]" << std::endl;
    }
    else
    {
        std::cout << "Sort_IntegersSorted_Successfully\t[FAIL]" << std::endl;
    }
    
    return successfully;
}

#endif /* StackTests_h */
