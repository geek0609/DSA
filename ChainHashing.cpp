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

    ~DoubleLinkedList () {
        delete headPtr;
        delete tailPtr;
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

    bool search(int V) {

        node* temp = headPtr;
        if (isEmpty()) return false ;
        int count=1;
        while (temp != NULL){
            if (temp->data == V) {
                return true;
                break;
            }
            count++;
            temp = temp->next;
        }
        return false;
    }

    bool insertBeg(int v) {
        node* newNode;
        newNode = new node(v, NULL, headPtr);

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

class Hash {

    int bucket;
    DoubleLinkedList* table[10];

    int hashFunction (int x) {
        return (x%bucket);
    }

public:
    Hash() {
        bucket = 10;
        for (int i = 0; i < bucket; i++) {
            table[i] = new DoubleLinkedList(); // Initialize each DoubleLinkedList object
        }
    }

    ~Hash() {
        for (int i =0; i<bucket; i++) {
            delete table[i];
        }
        delete table;
    }

    bool insert (int x) {
        table[hashFunction(x)]->insertBeg(x);
        return true;
    }

    void display () {
        for (int i =0; i<bucket; i++) {

            if (!table[i]->isEmpty()) {
                cout << "For table " << i << endl;
                table[i]->printList();
                cout << endl << endl;
            }
        }
    }

    void displaySingle (int v) {
        table[v]->printList();
    }


    bool search (int v) {
        int hashVal = hashFunction(v);
        return table[hashVal]->search(v);
    }


};

int main()
{
    Hash hashTable;

    hashTable.insert(100);
    hashTable.insert(100);
    hashTable.insert(123);
    hashTable.insert(33);
    hashTable.insert(12);
    hashTable.insert(42069);

    hashTable.display();
    int n=69;
    int x = hashTable.search(n);
    cout << "The number " << n << " exists in table: " << x;
    return 0;
}
