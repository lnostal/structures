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
        bool IsEmpty();
        void Show();
        void Sort();
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
void Stack<T>::Sort()
{
    int sizeOfArray = Size();
    T mass[sizeOfArray];
    
    // копируем содержимое стека в массив
    int index = 0;
    while (!IsEmpty())
    {
        T element = Pop();
        mass[index] = element;
        index++;
    }

    
}

#endif /* Stack_hpp */
