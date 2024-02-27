#include <iostream>
#define CAP 5
using namespace std;

class DQueue {
    int S[CAP];
    int frontIndex;
    int rearIndex;
    int CountVal;

public:
    DQueue() {
        frontIndex = -1;
        rearIndex = -1;
        CountVal = 0;
    }

    bool isEmpty() {
        return CountVal == 0;
    }

    bool isFull() {
        return CountVal == CAP;
    }

    bool enQueue_rear(int v) {
        if (isFull())
            return false;
        if (isEmpty())
            frontIndex = 0;

        rearIndex = (rearIndex + 1) % CAP;
        S[rearIndex] = v;
        CountVal++;
        return true;
    }

    int deQueue_front() {
        if (isEmpty())
            return -1; 
        int v = S[frontIndex];
        frontIndex = (frontIndex + 1) % CAP;
        CountVal--;

        if (isEmpty()) {
            frontIndex = -1;
            rearIndex = -1;
        }
        return v;
    }

    bool enQueue_front(int v) {
        if (isFull())
            return false;

        if (isEmpty()) {
            frontIndex = 0;
            rearIndex = 0;
        } else {
            frontIndex = (frontIndex - 1 + CAP) % CAP;
        }

        S[frontIndex] = v;
        CountVal++;
        return true;
    }

    int deQueue_rear() {
        if (isEmpty())
            return -1;

        int v = S[rearIndex];
        rearIndex = (rearIndex - 1 + CAP) % CAP;
        CountVal--;

        if (isEmpty()) {
            frontIndex = -1;
            rearIndex = -1;
        }
        return v;
    }
};

int main() {
    DQueue S;

    int O = 1, v;

    while (O < 6) {
        cout << "1.enQueue_rear, 2.enQueue_front, 3.deQueue_rear, 4.deQueue_front, 5.Exit ;" << endl
             << "Select operation : ";
        cin >> O;

        switch (O) {
            case 1: {
                cout << "enQueue_rear : ";
                cin >> v;
                if (S.enQueue_rear(v))
                    cout << "enQueue_rear successful";
                else
                    cout << "enQueue_rear failed";
            } break;

            case 2: {
                cout << "enQueue_front : ";
                cin >> v;
                if (S.enQueue_front(v))
                    cout << "enQueue_front successful";
                else
                    cout << "enQueue_front failed";
            } break;

            case 3: {
                int result = S.deQueue_rear();
                if (result != -1)
                    cout << "deQueue_rear : " << result;
                else
                    cout << "Queue is empty";
            } break;

            case 4: {
                int result = S.deQueue_front();
                if (result != -1)
                    cout << "dequeue_front : " << result;
                else
                    cout << "Queue is empty";
            } break;

            case 5: {
                O = 10;
            }
        }
        cout << endl;
    }

    return 0;
}