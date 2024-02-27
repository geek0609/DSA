#include <iostream>
#define CAP 10
using namespace std;

class Queue {
    int S[CAP];
    int frontIndex;
    int rearIndex;
    int CountVal;

    public :

    Queue (){
        frontIndex = -1;
        rearIndex = -1;
        CountVal = 0;
    }

    bool isEmpty ()
    {
        if (CountVal==0)
        return true;

        else return false;
    }

    bool isFull ()
    {
        if (CountVal == CAP)
        return true;

        else return false;
    }


    bool enQueue (int v)
    {
        if (isFull ()) return false;

        else {
            if (isEmpty()) frontIndex = 0;

            rearIndex = (rearIndex + 1)%CAP;
            S[rearIndex] = v;
            ++CountVal;
            return true;
        }
    }


    int deQueue ()
    {
        if (isEmpty()) return false;

        else {
            int v = S[frontIndex];
            frontIndex = (frontIndex + 1)%CAP;

            CountVal--;
            if (isEmpty()) {
                frontIndex = -1;
                rearIndex = -1;
            }

            return v;
        }
    }

    int Count ()
    {
        return CountVal;
    }

};

int main ()
{
    int O = 1, v;

    Queue S;

    while (O<8)
    {
        cout<<"Select operation from - 1.enqueue, 2.dequeue, 3.count, 4.Count, 5.isEmpty, 6.isFull, 7.Exit : ";
        cin>>O;

        switch (O){

            case 1 : cout<<"enqueue : "; cin>>v;  if (S.enQueue(v)) cout<<"Enqueue successfull"; else cout<<"Enqueue failed"; cout<<endl; break;
            case 2 : if(S.isEmpty()) cout<<"Empty Queue"; else {v = S.deQueue(); cout<<v;} break;
            case 3 : cout<<S.Count(); break;
            case 4 : cout<<S.Count(); break;
            case 5 : if (S.isEmpty()) cout<<"Empty queue"; else cout<<"The Queue is not empty"; break;
            case 6 : if (S.isFull()) cout<<"Full queue"; else cout<<"The Queue is not full"; break;
            case 7 : cout<<"Queue ended"; O =87; break;
        }
        cout<<endl;
    }

    return 0;
}