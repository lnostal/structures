//
//  main.cpp
//  structures
//
//  Created by Nosta on 21.06.2018.
//  Copyright © 2018 Nosta. All rights reserved.
//

#include <iostream>
#include "Stack.hpp"
#include "StackWithTimeCount.h"
#include "StackTests.h"

#include <chrono>
#include <thread>
#include <cmath>

//#define RUN_TESTS

std::string GetTimeForNumberOfElementsEqualTo(int numberOfElements)
{
    Stack<int> stack = Stack<int>();
    
    for (int i = numberOfElements; i > 0; i--)
    {
        stack.Push(i);
    }
    
    auto start = std::chrono::steady_clock::now();
    stack.Sort(stack);
    auto finish = std::chrono::steady_clock::now();
    
    auto time = std::chrono::duration_cast<std::chrono::microseconds>(finish - start).count() / 1000.00;
    char* s_time = new char;
    std::sprintf(s_time, "%.2lf %s", time, "ms");

    return s_time;
}

long GetCountOfOperationsForNumberOfElementsEqualTo(int numberOfElements)
{
    operations = 0;
    
    StackWithTimeCount<int> stack = StackWithTimeCount<int>();
    
    for (int i = numberOfElements; i > 0; i--)
    {
        stack.Push(i);
    }

    stack.Sort(stack);
    
    return operations;
}

int main(int argc, const char * argv[])
{
    
#ifdef RUN_TESTS
    Sort_IntegersSorted_Successfully();
    Sort_StringsSorted_Successfully();
    IsEmpty_StackNotEmpty_Successfully();
#endif
    
    std::cout << "100\t\t\t" << GetTimeForNumberOfElementsEqualTo(100) << "\t\t\t";
    std::cout << GetCountOfOperationsForNumberOfElementsEqualTo(100) << std::endl;
    std::cout << "1000\t\t"  << GetTimeForNumberOfElementsEqualTo(1000) << "\t\t\t";
    std::cout << GetCountOfOperationsForNumberOfElementsEqualTo(1000) << std::endl;
    std::cout << "10000\t\t" << GetTimeForNumberOfElementsEqualTo(10000) << "\t\t";
    std::cout << GetCountOfOperationsForNumberOfElementsEqualTo(10000) << std::endl;
    std::cout << "22000\t\t" << GetTimeForNumberOfElementsEqualTo(22000) << "\t\t";
    std::cout << GetCountOfOperationsForNumberOfElementsEqualTo(22000) << std::endl;
    
    return 0;
}
