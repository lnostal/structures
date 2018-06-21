//
//  Stack.hpp
//  structures
//
//  Created by Nosta on 21.06.2018.
//  Copyright © 2018 Nosta. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>

class Stack
{
    private:
        struct Element
        {
            int e;
            Element *next;
            Element *head;
        };
    
        Element *myStack;
        int numberOfElements;
    
    public:
        Stack();
        ~Stack();
    
        void Add(int newElement);
        bool Delete(int elementToDelete);
        void Show();
        void Sort();
        int Size();
        void Clear();
};

#endif /* Stack_hpp */
