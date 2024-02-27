#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *prev, *next;

    node (int Data=0, node* PreviousNode=NULL, node* NextNode=NULL) {
        data = Data;
        prev = PreviousNode;
        next = NextNode;
    }

};


class DoubleLinkedList {

private:
    node* headPtr, *tailPtr;

public:
    DoubleLinkedList () {
        headPtr = NULL;
        tailPtr = NULL;
    }

    bool isEmpty () {
        return headPtr == NULL;

    }

    int count () {
        node* temp = headPtr;
        if (isEmpty()) return 0;
        int count=1;
        while (temp->next != NULL){
            count++;
            temp = temp->next;
        }

        return count;

    }

    void printList() {

        node* temp = headPtr;
        if (isEmpty()) return ;
        int count=1;
        while (temp->next != NULL){
            cout << count << "\t" << temp->data << "\n";
            count++;
            temp = temp->next;
        }
        cout << count << "\t" << temp->data << "\n";

    }

    bool insertBeg(int v) {
        node* newNode = new node (v, NULL , headPtr);

        headPtr = newNode;
        if (tailPtr == NULL) tailPtr = headPtr;
        else headPtr->prev = newNode;
        return true;
    }

    int deleteBegin() {
        node* rm = headPtr;
        int rv = rm->data;
        if (count()==1) {
            headPtr = tailPtr = NULL;
        }
        else {
            headPtr->next->prev = NULL;
            headPtr = headPtr->next;
        }
        delete rm;
        return rv;
    }

    bool insertEnd (int v) {
        node* newNode = new node (v, tailPtr , NULL);


        if (headPtr == NULL) headPtr = tailPtr = newNode;
        else tailPtr->next = newNode;
        tailPtr = tailPtr->next;
        return true;
    }

    int deleteEnd() {
        if (count() == 1) {
            node* remove = tailPtr;
            int rv = remove->data;
            tailPtr = headPtr = NULL;
            delete remove;
            return rv;
        }
        node* temp = tailPtr;
        tailPtr->prev->next=NULL;
        int rv = temp->data;
        delete temp;
        return rv;
    }

};

int main() {

    DoubleLinkedList mList;
    mList.insertBeg(99);
    mList.insertBeg(100);
    mList.insertBeg(10101);
    mList.insertBeg(1010);
    mList.insertEnd(29);
    mList.printList();
    cout << endl << mList.deleteBegin() << endl << mList.deleteEnd() << endl;
    mList.printList();

    return 0;
}