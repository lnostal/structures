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
        bool Delete(const T& elementToDelete);
        bool IsEmpty();
        Stack<T> Reverse(Stack stack);
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

/*
 brief Возвращает перевернутый стек
 */

template<class T>
Stack<T> Stack<T>::Reverse(Stack stack)
{
    Stack reversedStack = Stack();
    while (!stack.IsEmpty())
        reversedStack.Push(stack.Pop());
        
    return reversedStack;
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
 \brief Удаление элемента из стека
 
 Удаление происходит засчет поочередного сравнивания входного значения с элементами стека.
 В случае, если будет обнаружено совпадение, элемент удалится, и метод вернет true. Иначе
 вполне закономерно вернется false.
 
 \param elementToDelete Удаляемый элемент
 \return bool Результат работы метода
 */
template<class T>
bool Stack<T>::Delete(const T& elementToDelete)
{
    Element<T> *temp = myStack->head;
    Element<T> *previous = temp;
    
    while (temp != NULL)
    {
        if (temp->e == elementToDelete)
        {
            previous->next = temp->next;
            delete temp;
            numberOfElements--;
            
            return true;
        }
        previous = temp;
        temp = temp->next;
    }
    return false;
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
    
//    // данный алгоритм был лютейшее говно
//
//
//        if (input.isEmpty()) {
//            return;
//        }
//
//        Stack stackLeft = new Stack();
//        Stack stackRight = new Stack();
//
//        // split
//        while (!input.isEmpty()) {
//            stackLeft.push(input.pop());
//            if (!input.isEmpty()) {
//                stackRight.push(input.pop());
//            }
//        }
//
//        // recurse
//        if (!stackLeft.isEmpty() && !stackRight.isEmpty()) {
//            mergesortStack(stackLeft);
//            mergesortStack(stackRight);
//        }
//
//        // merge
//        Stack tmpStack = new Stack();
//        while (!stackLeft.isEmpty() || !stackRight.isEmpty()) {
//            if (stackLeft.isEmpty()) {
//                tmpStack.push(stackRight.pop());
//            } else if (stackRight.isEmpty()) {
//                tmpStack.push(stackLeft.pop());
//                // set an appropriate compare method
//            } else if (stackLeft.peek().compareTo(stackRight.peek()) >= 0) {
//                tmpStack.push(stackLeft.pop());
//            } else {
//                tmpStack.push(stackRight.pop());
//            }
//        }
//
//        // reverse stack
//        while (!tmpStack.isEmpty()) {
//            input.push(tmpStack.pop());
//        }
//
}

#endif /* Stack_hpp */
