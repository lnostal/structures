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
    
    Stack<int> s = Stack<int>();
//    std::cout << "Пусто? " << s.IsEmpty() << std::endl;
//    s.Push(1);
//    s.Push(2);
//    s.Push(666);
//    std::cout << s.Pop() << std::endl;
//    std::cout << "Пусто? " << s.IsEmpty() << std::endl;
//    s.Show();
//    std::cout << "\t";
//    std::cout << s.Size() << std::endl;
//    //s.Delete(2);
//    s.Show();
//    std::cout << "Пусто? " << s.IsEmpty() << std::endl;
//
//    s.Clear();
//    std::cout << "Пусто? " << s.IsEmpty() << std::endl;
    
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);
    s.Push(5);
    s.Show();
    s.Sort();
    //s.Pop();
    //s.Pop();
    //s.Show();
    

    
    return 0;
}
