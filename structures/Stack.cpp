//
//  Stack.cpp
//  structures
//
//  Created by Nosta on 21.06.2018.
//  Copyright © 2018 Nosta. All rights reserved.
//

#include "Stack.hpp"
#include <iostream>
#include <array>

using namespace std;

/*!
 \brief Инициализация нового стека
 */
Stack::Stack()
{
    Element *e = new Element;
    myStack = e;
    myStack->head = NULL;
    numberOfElements = 0;
}

Stack::~Stack()
{
    Clear();
    myStack = NULL;
}

/*!
 \brief Добавление нового элемента
 */
void Stack::Add(int newElement)
{
    Element *temp = new Element;
    temp->e = newElement;
    temp->next = myStack->head;
    myStack->head = temp;
    numberOfElements++;
}

/*!
 \brief Вывод стека на экран
 */
void Stack::Show()
{
    Element *temp = myStack->head;
    while (temp != NULL)
    {
        std::cout << temp->e << " ";
        temp = temp->next;
    }
}

/*!
 \brief Удаление всех элементов
 */
void Stack::Clear()
{
    while (myStack->head != NULL)
    {
        Element *temp = myStack->head->next;
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

bool Stack::Delete(int elementToDelete)
{
    Element *temp = myStack->head;
    Element *previous = temp;
    
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

int Stack::Size()
{
    return numberOfElements;
}

void Stack::Sort()
{
    int arr[8] = { 2, 1, 4, -10, 6, 4, 7, -11 };
    
    int *newArray = new int[8];
    
    newArray = arr;
    
    int middleOfStack = 8 / 2;
    if (8 % 2 == 1)
    {
        middleOfStack++;
    }
    
    int *tempArray = new int[8];
    int step = 1;
    int stage;
    
    while (step < 8)
    {
        stage = step;
        int firstWayIndex = 0;
        int secondWayIndex = middleOfStack;
        int newElementIndex = 0;
        
        while (stage <= middleOfStack)
        {
            while (firstWayIndex < stage && secondWayIndex < 8 && secondWayIndex < (middleOfStack + stage))
            {
                if (newArray[firstWayIndex] < newArray[secondWayIndex])
                {
                    tempArray[newElementIndex] = newArray[firstWayIndex];
                    firstWayIndex++;
                    newElementIndex++;
                }
                else
                {
                    tempArray[newElementIndex] = newArray[secondWayIndex];
                    secondWayIndex++;
                    newElementIndex++;
                }
            }
            
            while (firstWayIndex < stage)
            {
                tempArray[newElementIndex] = newArray[firstWayIndex];
                newElementIndex++;
                firstWayIndex++;
            }
            
            while (secondWayIndex < (middleOfStack + stage) && secondWayIndex < 8)
            {
                tempArray[newElementIndex] = newArray[secondWayIndex];
                newElementIndex++;
                secondWayIndex++;
            }
            
            stage = stage + step;
        }
        
        step = step * 2;

        for (int i = 0; i < 8; i++)
        {
            newArray[i] = tempArray[i];
        }
    }
    for (int i = 0; i < 8; i++)
    {
        std::cout << newArray[i] << " ";
    }
}
