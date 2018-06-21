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
    
    Stack s = Stack();
    
    /*s.Add(1);
    s.Add(2);
    s.Add(666);
    s.Add(6664);
    s.Add(6663);
    s.Add(6662);
    
    s.Show();
    std::cout << "\t";
    std::cout << s.Size() << std::endl;
    
    s.Delete(2);
    s.Delete(6663);

    s.Show();
    std::cout << "\t\t";
    std::cout << s.Size() << std::endl;*/
    
    s.Sort();
    
    return 0;
}
