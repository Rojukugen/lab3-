#include <iostream>
#include "Queue.h"
int main()
{
  
    Queue<int> Q1;
    Q1.print("Q1");

    Q1.push(5);
    Q1.print("Q1");

    Q1.push(8);
    Q1.push(11);
    Q1.push(17); 
    Q1.print("Q1");

    int d;
    d = Q1.GetItem();
    cout << "d = " << d << endl;

    Q1.print("Q1");

    Queue<int> Q2 = Q1;
    Q2.print("Q2");

    Queue<int> Q3;
    Q3 = Q1 = Q2;
    Q1.push(333);
    Q2.push(555);

    Q1.print("Q1");
    Q2.print("Q2");
    Q3.print("Q3");

    Q2.clear();
    if (Q2.IsEmpty())
      cout << "OK" << endl;
    else
      cout << "NO" << endl;

    cout << "n = " << Q3.GetN() << endl;
  
  return 0;
}
