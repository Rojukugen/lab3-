
#ifndef _MY_Queue_
#define _MY_Queue_

#include <iostream>
#include <new>
using namespace std;


template <typename T>
class Queue
{
private:
  T* p; 
  int count; // количество элементов в очереди

public:
  
  Queue()
  {
    count = 0; 
  }

  
  Queue(const Queue& obj)
  {
    // скопировать obj в текущий объект
    count = obj.count;

    try {
      // попытка выделить память 
      p = new T[count];
      // заполнить значениями
      for (int i = 0; i < count; i++)
        p[i] = obj.p[i];
    }
    catch (bad_alloc e)
    {
      cout << e.what() << endl;
      count = 0; // создать пустую очередь
    }
  }

  // добавить элемент в очередь
  void push(T item)
  {
    T* p2; 
    p2 = p; 

    try {
      // попытка выделить новый фрагмент памяти для p, но на 1 больше
      p = new T[count + 1];

      // скопировать данные из участка на который указывает p2 (старые данные) в участок, на который указывает p
      for (int i = 0; i < count; i++)
        p[i] = p2[i];

      p[count] = item;
      count++;

      if (count > 1)
        delete[] p2;
    }
    catch (bad_alloc e)
    {
      // если память не выделена
      cout << e.what() << endl; 

      // вернуть старый указатель на p
      p = p2;
    }
  }

  // вытянуть первый элемент из очереди
  T pop()
  {
    if (count == 0)
      return 0;

    T item;
    item = p[0];

    // сформировать новый участок памяти, который на 1 меньше
    try {
      T* p2;

     
      p2 = new T[count - 1];

      count--; 
      
      for (int i = 0; i < count; i++)
        p2[i] = p[i + 1]; // копируются все кроме первого элемента

      if (count > 0)
        delete[] p;

      p = p2;
      return item;
    }
    catch (bad_alloc e)
    {
      cout << e.what() << endl;
      return 0;
    }
  }

  Queue& operator=(const Queue& obj)
  {
    T* p2; // указатель на дополнительную память

    try {
      p2 = new T[obj.count];

      // если память выделена успешно,
      // можно освобождать предварительно выделенную память для p
      if (count > 0)
        delete[] p;

      // скопировать obj в текущий объект
      p = p2; // перенаправить p на p2
      count = obj.count;

      for (int i = 0; i < count; i++)
        p[i] = obj.p[i];
    }
    catch (bad_alloc e)
    {
      cout << e.what() << endl;
    }
    return *this; 
  }

  ~Queue()
  {
    if (count > 0)
      delete[] p;
  }

  // взять первый элемент из очереди не вытягивая его
  T GetItem()
  {
    if (count > 0)
      return p[0];
    else
      return 0;
  }

  // очистка очереди
  void clear()
  {
    if (count > 0)
    {
      delete[] p;
      count = 0;
    }
  }

  // проверка существования элементов в очереди
  bool IsEmpty()
  {
    return count == 0;
  }

  // количество элементов в очереди
  int GetN()
  {
    return count;
  }

  // вывод
  void print(const char* objName)
  {
    cout << "Object: " << objName << endl;
    for (int i = 0; i < count; i++)
      cout << p[i] << "\t";
    cout << endl;
    cout << "---------------------" << endl;
  }

};
#endif

