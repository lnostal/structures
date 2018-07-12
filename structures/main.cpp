//
//  main.cpp
//  structures
//
//  Created by Nosta on 21.06.2018.
//  Copyright © 2018 Nosta. All rights reserved.
//

#include <iostream>
#include "Stack.hpp"

int main(int argc, const char * argv[]) {
    
    Stack<int> integer = Stack<int>();
    
    integer.Push(1);
    integer.Push(2);
    integer.Push(3);
    integer.Push(4);
    integer.Push(5);
    integer.Show();
    integer.Sort(integer);
    integer.Show();
    std::cout << "--------------\n";
    integer.Push(1);
    integer.Push(-2);
    integer.Push(3);
    integer.Push(-4);
    integer.Push(5);
    integer.Show();
    integer.Sort(integer);
    integer.Show();
    std::cout << "--------------\n";
    
    Stack<std::string> letters = Stack<std::string>();
    letters.Push("d");
    letters.Push("a");
    letters.Push("n");
    letters.Push("b");
    letters.Show();
    letters.Sort(letters);
    letters.Show();
    std::cout << "--------------\n";
    letters.Push("date");
    letters.Push("alkoholikerin");
    letters.Push("nil");
    letters.Push("bus");
    letters.Show();
    letters.Sort(letters);
    letters.Show();
    
    return 0;
}
