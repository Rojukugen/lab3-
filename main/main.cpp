#include <iostream>
#include "StackLib.h"
void main()
{
  // �������� ���� �� ����� �����
  STACK <int> st1;

  st1.Print(); // st1 = { }

  // +5
  st1.push(5); // st1 = { 5 }

  // +9
  st1.push(9); // st1 = { 5, 9 }

  // +13
  st1.push(13); // st1 = { 5, 9, 13 }

  // +7
  st1.push(7); // st1 = { 5, 9, 13, 7 }
  st1.Print();
  cout << "Count: " << st1.Count() << endl;

  // ----------------------
  STACK<int> st2;
  st2 = st1; // ����� ��������� �����������
  STACK<int> st3 = st2; // ����� ������������ �����������
  // ----------------------

  // -1 item
  int t;
  t = st1.pop(); // t = 7
  cout << "Delete item: " << t << endl;
  st1.Print(); // 5, 9, 13
  cout << "Head: " << st1.Head() << endl;

  // -2 items
  st1.pop(); // st1 = { 5, 9 }
  st1.pop(); // st1 = { 5 }
  st1.Print();

  // -2 items
  st1.pop(); // st1 = { }
  st1.pop();
  st1.Print();

  if (st1.IsEmpty())
    cout << "Stack is empty." << endl;
  else
    cout << "Stack is not empty" << endl;

  cout << "Stack st2:" << endl;
  st2.Print();

  cout << "Stack st3:" << endl;
  st3.Print();

  // ����� ��������� ����������� � ���� �������
  st1 = st3 = st2;
  st1.Print();
}