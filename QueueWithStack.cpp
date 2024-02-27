#include <iostream>
#define CAP 10
using namespace std;
class Stack {
    int topIndex;
    int S[CAP];

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

    bool isFull ()
    {
        if (Count() == CAP) return true;

        else 
        return false;
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
        if (isEmpty()) return -1;

        else {
            int v = S[topIndex];
            --topIndex;

            return v;
        }
    }

    void Print()
    {
        if (isEmpty())
            cout << "Empty Stack";
        else {
            for (int i = topIndex; i >= 0; --i)
                cout << S[i] << " ";
        }
    }
};

class Queue {
    Stack S1, S2;

    public : 

    bool enQueue(int v)
    {
        if (S1.isFull())
        {
            cout << "Queue overflow.";
            return false;
        }
        else
        {
            while (!S1.isEmpty())
            {
                S2.Push(S1.Pop());
            }

            S1.Push(v);

            while (!S2.isEmpty())
            {
                S1.Push(S2.Pop());
            }

            return true;
        }
    }


    int deQueue ()
    {
        int v;

        if (S1.isEmpty() && S2.isEmpty()) 
        {
            cout<<"Queue underflow.";
            return -1;
        }

        else {

            v = S2.Pop();

            return v;
        }
    }

    void Print()
    {
        if (S2.isEmpty())
        {
            while (!S1.isEmpty())
            {
                S2.Push(S1.Pop());
            }
        }

        S2.Print();
    }
};


int main() {
    Queue q;
    int choice, value;

    cout << "\n\nMenu:\n1. Enqueue\n2. Dequeue\n3. Print\n4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    while(choice != 4) {
        switch(choice) {
            case 1: 
                cout << "Enter the value to enqueue: ";
                cin >> value;
                if(q.enQueue(value))
                    cout << "Enqueue operation successful.\n";
                else
                    cout << "Enqueue operation failed.\n";
                break;
            case 2: 
                value = q.deQueue();
                if(value != -1)
                    cout << "Dequeued: " << value << "\n";
                else
                    cout << "Dequeue operation failed.\n";
                break;
            case 3: 
                cout << "Queue: ";
                q.Print();
                break;
            default: 
                cout << "Invalid choice. Please enter a valid option.\n";
        }

        cout << "\n\nMenu:\n1. Enqueue\n2. Dequeue\n3. Print\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
    }

    cout << "Exiting...\n";
    return 0;
}