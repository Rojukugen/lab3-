﻿
#ifndef _MY_Stack_
#define _MY_Stack_

#include <iostream>
#include <new>
using namespace std;


template <typename T>
class STACK
{
private:
  T* stack; // Динамический масив-указатель на стек
  int count; // Вершина стека - количество элементов типа T в стеке

public:
 
  STACK()
  {
    stack = nullptr; // необязательно
    count = 0; // количество элементов в стеке определяется по значению count
  }

  
  void push(T item)
  {
    T* tmp; // временный указатель

    // блок try необходим для перехвата исключения, если память не выделится
    try {
      // указатель указывает на stack
      tmp = stack;

      // выделить память на 1 элемент больше, чем было выделено до этого
      stack = new T[count + 1];

      // увеличить количество элементов в стеке на 1
      count++;

      // скопировать данные из памяти, на которую указывает tmp в память,
      // на которую указывает stack
      for (int i = 0; i < count - 1; i++)
        stack[i] = tmp[i];

      // добавить последний элемент
      stack[count - 1] = item;

      
      // на эту память указывает tmp
      if (count > 1)
        delete[] tmp;
    }
    catch (bad_alloc e)
    {
      // если память не выделилась
      cout << e.what() << endl;
    }
  }

  // Вытягнуть элемент из стека
  // При вытягивании элемента из стека память не переопределяется
  T pop()
  {
    if (count == 0)
      return 0; // стек пуст
    count--;
    return stack[count];
  }

  // Просмотр элемента в вершине стека
  T Head()
  {
    if (count == 0)
      return 0;
    return stack[count - 1];
  }


  STACK(const STACK& st)
  {
    try {
      // 1. Выделить новый участок памяти для массива stack
      stack = new T[st.count];

      // 2. Скопировать данные из st в текущий объект
      count = st.count;
      for (int i = 0; i < count; i++)
        stack[i] = st.stack[i];
    }
    catch (bad_alloc e)
    {
      // если память не выделилась, то вывести соответствующее сообщение
      cout << e.what() << endl;
    }
  }


  STACK operator=(const STACK& st)
  {
    // Нужно скопировать из st в текущий объект
    // 1. Освободить предварительно выделенную память для текущего объекта
    if (count > 0)
    {
      count = 0;
      delete[] stack; // освободить память под предыдущий массив
    }

    // 2. Выделить новый участок памяти для массива stack
    try {
      // попытка выделить память
      stack = new T[st.count];

      // 3. Скопировать данные из st в текущий объект
      count = st.count;
      for (int i = 0; i < count; i++)
        stack[i] = st.stack[i];
    }
    catch (bad_alloc e)
    {
      // если не удалось виделить память, то вывести соответствующее сообщение
      cout << e.what() << endl;
    }

    // 4. Вернуть текущий объект
    return *this;
  }

  // Деструктор - освобождает память
  ~STACK()
  {
    if (count > 0)
      delete[] stack;
  }

  // Количество элементов в стеке
  int Count()
  {
    return count;
  }

  // Функция, которая определяет пуст ли стек
  bool IsEmpty()
  {
    return count == 0;
  }

  // Функция, выводящая стек
  void Print()
  {
    T* p; // временный указатель, двигается по элементах стека

    // 1. Установить указатель p на вершину стека
    p = stack;

    // 2. Вивід
    cout << "Stack: " << endl;
    if (count == 0)
      cout << "is empty." << endl;

    for (int i = 0; i < count; i++)
    {
      cout << "Item[" << i << "] = " << *p << endl;
      p++; // прокрутить указатель на следующий элемент
    }
    cout << endl;
  }
};


#endif