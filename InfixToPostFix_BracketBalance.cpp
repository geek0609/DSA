#include "iostream"
#include "cstring"
#define CAPAC 100
#define INVALID '\0'


using namespace std;


void printaline () {
    cout << endl << endl;
    for (int i=0; i<15; i++) cout << "_";
    cout << endl << endl;
}

// Class definition for the stack
class stack {
private:
    char s[CAPAC]{}; // Array to store stack elements
    int topIndex;      // Index to keep track of the top element

public:
    // Constructor to initialize the stack
    stack() {
        topIndex = -1; // Set topIndex to -1 to indicate an empty stack
    }

    // Function to return the number of elements in the stack
    int count() const {
        return topIndex + 1;
    }

    // Function to check if the stack is empty
    bool isEmpty() const {
        return count() == 0;
    }

    // Function to check if the stack is full
    bool isFull() const {
        return count() == CAPAC;
    }

    // Function to push an element onto the stack
    bool push(char element) {
        if (!isFull()) {
            s[++topIndex] = element; // Increment topIndex and add the element to the stack
            return true;              // Return true to indicate successful push
        } else
            return false; // Return false if the stack is full
    }

    // Function to peek at the top element of the stack without removing it
    char peek() const {
        if (isEmpty())
            return INVALID; // Return INVALID if the stack is empty
        return s[topIndex]; // Return the top element
    }

    // Function to pop the top element from the stack
    char pop() {
        if (isEmpty())
            return INVALID; // Return INVALID if the stack is empty
        return s[topIndex--]; // Return the top element and decrement topIndex
    }

    // Function to display the elements of the stack
    void displayStack() const {
        if (isEmpty())
            return; // Return if the stack is empty

        printaline();
        cout << endl
             << s[topIndex] << "  <-HEAD" << endl; // Display the top element

        // Display the rest of the elements
        for (int i = topIndex-1; i >=0 ; i--) {
            cout << s[i];
            if (i==0) cout << "  <-TAIL";
            cout << endl;
        }
        printaline();
    }
};


int linearSearch (char key, char list[]) {
    int i = 0;
    while (list[i]) {
        if (key == list[i++]) return i-1;
    }
    return -1;
}

bool bracketBalancing (char input[]){


    // Considered bracket types
    // 1. <> (60, 62)
    // 2. () (40, 41)
    // 3. [] (91, 93)
    // 4. {} (123, 125)

    int i=0, checkBracket;

    char openings[] = "<([{";
    char closings[] = ">)]}";

    stack A;

    while (input[i] != '\0') {
        checkBracket = linearSearch(input[i], openings);

        if ( checkBracket != -1) {
            A.push(input[i]);
        }

        checkBracket = linearSearch(input[i], closings);

        if ( checkBracket != -1) {

            char prev = A.pop();
            int prevIndex = linearSearch(prev, openings);

            if (prevIndex != checkBracket) return false;

        }

        i++;
    }

    if (A.isEmpty()) return true;

    return false;
}

// Function to check if a character is an operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to get the precedence of an operator
int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to convert infix expression to postfix
void infixToPostfix(char infix[], char postfix[], bool debug=false) {
    stack operatorStack;
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        char current = infix[i];

        if (isalnum(current)) {
            postfix[j++] = current;
        } else if (isOperator(current)) {
            while (!operatorStack.isEmpty() && getPrecedence(operatorStack.peek()) >= getPrecedence(current)) {
                postfix[j++] = operatorStack.pop();
            }
            operatorStack.push(current);
        } else if (current == '(') {
            operatorStack.push(current);
        } else if (current == ')') {
            while (!operatorStack.isEmpty() && operatorStack.peek() != '(') {
                postfix[j++] = operatorStack.pop();
            }
            operatorStack.pop(); // Pop '('
        }
        if (debug) operatorStack.displayStack();

        i++;
    }

    // Pop remaining operators from the stack
    while (!operatorStack.isEmpty()) {
        postfix[j++] = operatorStack.pop();
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}




int main() {


    char input[] = "a+b/a+b(b+c*c)/d+c/c-c*d ", postfix[CAPAC];

    if (!bracketBalancing(input)){
        cout << "Unbalanced";
        return -1;
    }

    infixToPostfix(input, postfix);


    cout << postfix;

    return 69;
}
