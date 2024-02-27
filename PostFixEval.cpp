#include <iostream>
#include <string>
#define CAP 20
using namespace std;

class Stack {
    float S[CAP];
    int topIndex;

    public :

    Stack ()
    {
        topIndex = -1;
    }

    int Count ()
    {
        return topIndex+1;
    }

    bool isEmpty ()
    {
        if (Count() == 0) return true;

        else 
        return false;
    }

    bool isFull()
    {
        if (Count()==CAP) return true;

        else 
        return false;
    }

    int Top ()
    {
        if (isEmpty()) return -1;

        else 
        return S[topIndex];
    }

    bool Push (int v)
    {
        if (isFull()) return false;

        else {
            ++topIndex;
            S[topIndex] = v;

            return true;
        }
    }

    int Pop ()
    {
        int v;

        if (isEmpty()) 
        {
            cout<<"Empty stack";
            return -1;
        }

        else {
            v = S[topIndex];
            topIndex--;
        }

        return v;
    }
};

int main ()
{
    Stack X;

    int opnd1, opnd2;
    
    string Postfix;
    cout<<"Enter the postfix expression : ";
    cin>>Postfix;

    char a;

    for (int i=0 ; i< Postfix.length(); ++i)
    {
        a = Postfix[i];
        if (a >= '0' && a <= '9')
        X.Push(a - '0');

        else if (a == '+' || a == '-' || a == '*' || a == '/')
        {
            if(X.Count() < 2) {
                cout << "Invalid postfix expression";
                return 0;
            }
            opnd1 = X.Pop();
            opnd2 = X.Pop();

            switch(a) {
                case '+': X.Push(opnd2+opnd1); break;
                case '-': X.Push(opnd2-opnd1); break;
                case '*': X.Push(opnd2*opnd1); break;
                case '/': X.Push(opnd2/opnd1); break;
            }
        }

        else 
        {
            cout<<"Invalid postfix expression";
            return 0;
        }
    }

    if(X.Count() != 1) {
        cout << "Invalid postfix expression";
        return 0;
    }

    cout<<"The value of the postfix expression is : "<<X.Pop();

    return 0;
}