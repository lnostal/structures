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
#include <math.h>

template<class T>
class Stack
{
    private:

        template<class E>
        struct Element
        {
            E e;
            Element *next;
            Element *head;
        };
    
        Element<T> *myStack;
        int numberOfElements;
    
    public:
        Stack();
        ~Stack();
    
        void Push(const T& newElement);
        T Pop();
        T Peek();
        bool IsEmpty();
        void Show();
        void Sort(Stack<T>& input);
        void Clear();
        int Size();
};

/*
 \brief Инициализация стека
 */
template<class T>
Stack<T>::Stack()
{
    Element<T> *e = new Element<T>;
    myStack = e;
    myStack->head = NULL;
    numberOfElements = 0;
}

template<class T>
Stack<T>::~Stack()
{
    Clear();
    myStack = NULL;
}

/*!
 \brief Проверка стека на пустоту
 */

template <class T>
bool Stack<T>::IsEmpty()
{
    if (myStack->head == NULL)
        return true;
    
    return false;
}

template <class T>
T Stack<T>::Pop()
{
    Element<T> *temp = myStack->head;
    T returnedE = temp->e;
    
    if (temp != NULL)
    {
        myStack->head = temp->next;
        delete temp;
        numberOfElements--;
    }
    
    return returnedE;
}

template <class T>
T Stack<T>::Peek()
{
    return myStack->head->e;
}

/*!
 \brief Добавление нового элемента
 */
template<class T>
void Stack<T>::Push(const T& newElement)
{
    Element<T> *temp = new Element<T>;
    temp->e = newElement;
    temp->next = myStack->head;
    myStack->head = temp;
    numberOfElements++;
}

/*!
 \brief Вывод стека на экран
 */
template<class T>
void Stack<T>::Show()
{
    Element<T> *temp = myStack->head;
    while (temp != NULL)
    {
        std::cout << temp->e << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

/*!
 \brief Удаление всех элементов
 */
template<class T>
void Stack<T>::Clear()
{
    while (myStack->head != NULL)
    {
        Element<T> *temp = myStack->head->next;
        if (myStack->head != NULL)
            delete myStack->head;
        myStack->head = temp;
    }
}

/*!
 \brief Возвращает количество элементов в стеке
 */
template<class T>
int Stack<T>::Size()
{
    return numberOfElements;
}

template<class T>
void Stack<T>::Sort(Stack<T>& stack)
{
    if (stack.IsEmpty())
    {
        return;
    }
    
    Stack<T> leftPart = Stack<T>();
    Stack<T> rightPart = Stack<T>();
    
    // делим стек на две части
    while (!stack.IsEmpty())
    {
        leftPart.Push(stack.Pop());
        
        if (!stack.IsEmpty())
        {
            rightPart.Push(stack.Pop());
        }
    }
    
    // проделываем это рекурсивно для каждой из частей
    if (!leftPart.IsEmpty() && !rightPart.IsEmpty())
    {
        Sort(leftPart);
        Sort(rightPart);
    }
    
    // сливаем части стека
    Stack tempStack = Stack<T>();
    while (!leftPart.IsEmpty() || !rightPart.IsEmpty())
    {
        if (leftPart.IsEmpty())
        {
            tempStack.Push(rightPart.Pop());
        }
        else if (rightPart.IsEmpty())
        {
            tempStack.Push(leftPart.Pop());
            // set an appropriate compare method
        }
        else if (leftPart.Peek() > rightPart.Peek())
        {
            tempStack.Push(leftPart.Pop());
        }
        else
        {
            tempStack.Push(rightPart.Pop());
        }
    }
    
    // переворачиваем стек и записываем его в исходный
    while (!tempStack.IsEmpty())
    {
        stack.Push(tempStack.Pop());
    }
}

#endif /* Stack_hpp */
