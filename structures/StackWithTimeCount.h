//
//  StackWithTimeCount.h
//  structures
//
//  Created by Nosta on 04.08.2018.
//  Copyright © 2018 Nosta. All rights reserved.
//

//#ifndef StackWithTimeCount_h
//#define StackWithTimeCount_h

/*
 Обращение к элементу                            – 1 операция
 Присваивание                                    – 2 операции
 Арифметические операции                         – 2 операции
 Выделение памяти                                – 2 операции
 Высвобождение памяти                            - 2 операции ?
 Логические операции                             – 1 операция
 Открытие потока данных                          – 1 операция
 Использование стандартных средств ввода-вывода  – 1 операция
 Назначение языка по умолчанию                   – 1 операция
 Возвращение значения                            - 1 операция ?
 */

#include <stdio.h>
#include <iostream>
#include <sstream>

long operations = 0;

template<class T>
class StackWithTimeCount
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
    StackWithTimeCount();                                           // 9
    ~StackWithTimeCount();                                          // 14n + 2
    
    T Pop();                                                        // 19
    T Peek();                                                       // 3
    int Size();
    void Clear();                                                   // 14n
    bool IsEmpty();                                                 // 2
    void Sort(StackWithTimeCount<T>& stack);                        
    void Push(const T& newElement);                                 // 17
    void Show(const std::string& separator = " ");
    std::string WriteToString(const std::string& separator = " ");
};

/*
 \brief Инициализация стека
 */
template<class T>
StackWithTimeCount<T>::StackWithTimeCount()
{
    myStack = new Element<T>;   // присваивание и выделение памяти: 2 + 2
    myStack->head = nullptr;    // обращение к элементу и присвоение: 1 + 2
    numberOfElements = 0;       // присваивание: 2

    operations += 9;

}

template<class T>
StackWithTimeCount<T>::~StackWithTimeCount()
{
    Clear();            // 14n
    myStack = nullptr;  // присваивание: 2

    operations += 2;
}

/*!
 \brief Проверка стека на наличие в нем элементов
 */
template <class T>
bool StackWithTimeCount<T>::IsEmpty()
{
    operations += 2;

    return numberOfElements == 0;   // логическая операция и возвращение значения: 1 + 1
}

/*!
 \brief Удаляет крайний элемент стека
 \return <T> Крайний элемент стека
 */
template <class T>
T StackWithTimeCount<T>::Pop()
{
    Element<T> *temp = myStack->head;   // выделение памяти, обращение к элементу и присваивание: 2 + 1 + 2
    T returnedE = temp->e;              // выделение памяти, обращение к элементу и присваивание: 2 + 1 + 2
    myStack->head = temp->next;         // обращение к элементу, обращение к элементу и присваивание: 1 + 1 + 2
    delete temp;                        // высвобождение памяти: 2
    numberOfElements--;                 // арифметическая операция: 2
    
    operations += 19;

    return returnedE;                   // возвращение значения: 1
}

/*!
 \brief Возвращает крайний элемент стека
 \return <T> Крайний элемент стека
 */
template <class T>
T StackWithTimeCount<T>::Peek()
{
    operations += 3;

    return myStack->head->e;    //  обращение к элементу, обращение к элементу, возвращение значения: 1 + 1 + 1
}

/*!
 \brief Добавление нового элемента
 */
template<class T>
void StackWithTimeCount<T>::Push(const T& newElement)
{
    Element<T> *temp = new Element<T>;  // выделение памяти, обращение к элементу и присваивание: 2 + 1 + 2
    temp->e = newElement;               // обращение к элементу и присваивание: 1 + 2
    temp->next = myStack->head;         // обращение к элементу, обращение к элементу и присваивание: 1 + 1 + 2
    myStack->head = temp;               // обращение к элементу и присваивание: 1 + 2
    numberOfElements++;                 // арифметическая операция: 2

    operations += 17;
}

/*!
 \brief Вывод стека на экран
 \param separator Символ или строка, использующиеся в качестве разделителя между элементами стека
 */
template<class T>
void StackWithTimeCount<T>::Show(const std::string& separator)
{
    Element<T> *temp = myStack->head;
    while (temp != nullptr)
    {
        std::cout << temp->e << separator;
        temp = temp->next;
    }
    std::cout << std::endl;
}

/*!
 \brief Записывает стек в строку через разделитель
 \param separator Символ или строка, использующиеся в качестве разделителя между элементами стека
 \return string Результирующая строка
 */
template<class T>
std::string StackWithTimeCount<T>::WriteToString(const std::string& separator)
{
    std::ostringstream stream;
    
    Element<T> *temp = myStack->head;
    while (temp != nullptr)
    {
        stream << temp->e << separator;
        temp = temp->next;
    }
    
    std::string result;
    result = stream.str();
    result.erase(result.length()-1, 1);
    
    return result;
}

/*!
 \brief Удаление всех элементов
 */
template<class T>
void StackWithTimeCount<T>::Clear()
{
    while (myStack->head != nullptr)            // обращение к элементу и логическая операция: 1 + 1
    {
        Element<T> *temp = myStack->head->next; // выделение памяти, обращение к элементу, обращение к элементу и присваивание: 2 + 1 + 1 + 2
        delete myStack->head;                   // обращение к элементу и высвобождение памяти: 1 + 2
        myStack->head = temp;                   // обращение к элементу и присваивание: 1 + 2
        
        operations += 14; // 14n
    }
}

/*!
 \brief Возвращает количество элементов в стеке
 */
template<class T>
int StackWithTimeCount<T>::Size()
{
    return numberOfElements;
}

/*!
 \brief Сортировка слиянием (рекурсивная)
 \param stack Сортируемый стек
 */
template<class T>
void StackWithTimeCount<T>::Sort(StackWithTimeCount<T>& stack)
{
    operations += 1;        // обращение к методу: 1
    if (stack.IsEmpty())
    {                       /// все, что касается методов класса, будет автоматически
        operations += 1;    /// считаться внутри них, так что их уже не учитываем
        
        return;             // возвращение значения: 1
    }
    
    
    StackWithTimeCount<T> leftPart = StackWithTimeCount<T>();     // выделение папяти, [конструктор] и присваивание: 2 + 2
    StackWithTimeCount<T> rightPart = StackWithTimeCount<T>();    // выделение папяти, [конструктор] и присваивание: 2 + 2
    operations += 4;
    
    // делим стек на две части
    while (!stack.IsEmpty())                // обращение к методу и логическая операция: 1 + 1
    {
        leftPart.Push(stack.Pop());         // обращение к методу, обращение к методу: 1 + 1
        
        if (!stack.IsEmpty())               // обращение к элементу и логическая операция: 1 + 1
        {
            rightPart.Push(stack.Pop());     // обращение к методу, обращение к методу: 1 + 1

            operations += 2;
        }

        operations += 6;
    }
    
    // проделываем это рекурсивно для каждой из частей
    
    if (!leftPart.IsEmpty() && !rightPart.IsEmpty())    // логическая операция, обращение к методу, логическая операция
    {                                                   // логическая операция, обращение к методу: 1 + 1 + 1 + 1 + 1
        Sort(leftPart);
        Sort(rightPart);
        
        operations += 2;                                // вызов методов
    }
    operations += 5;
    
    // сливаем части стека
    StackWithTimeCount tempStack = StackWithTimeCount<T>(); // выделение памяти, [конструктор] и присваивание: 2 + 2
    operations += 4;
    while (!leftPart.IsEmpty() || !rightPart.IsEmpty())     // 1 + 1 + 1 + 1 + 1
    {
        operations += 5;
        
        if (leftPart.IsEmpty())                             // обращение к методу: 1
        {
            tempStack.Push(rightPart.Pop());                // обращение к методу, обращение к методу: 1 + 1

            operations += 3;
        }
        else if (rightPart.IsEmpty())                       // 1
        {
            tempStack.Push(leftPart.Pop());                 // 1 + 1

            operations += 4;                                // проверка предыдущего if-а: 1
        }
        else if (leftPart.Peek() > rightPart.Peek())        // обращение к методу, обращение к методу, арифметическая операция: 1 + 1 + 2
        {
            tempStack.Push(leftPart.Pop());                 // 1 + 1

            operations += 8;                                // проверка предыдущих if-ов: 1 + 1
        }
        else
        {
            tempStack.Push(rightPart.Pop());

            operations += 6;                                // проверка предыдущих if-ов: 1 + 1 + 4
        }
    }
    
    // переворачиваем стек и записываем его в исходный
    while (!tempStack.IsEmpty())        // обращение к методу, логическая операция 1 + 1
    {
        stack.Push(tempStack.Pop());    // 1 + 1

        operations += 4;
    }
}

 /* StackWithTimeCount_h */
