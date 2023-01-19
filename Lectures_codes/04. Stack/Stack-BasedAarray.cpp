#include <iostream>
using namespace std;

const int MAX_ITEMS = 1000;
class stack{
private:
    int top;
public:
    int items[MAX_ITEMS];
// Default Constructor
    stack(){
        top = -1;
    }
    bool isEmpty();
    bool isFull();
    bool push(int x);
    int pop();
    int peek();
};
// Check empty stack
bool stack::isEmpty(){
    return (top == -1);
}
// Check full stack
bool stack::isFull(){
    return (top == MAX_ITEMS);
}
// Add Element to stack
bool stack::push(int x){
    if(isFull()){
        cout << "\nStack Overflow\n";
        return false;
    }
    else{
        items[++top] = x;
        cout << x << " Pushed into stack\n";
        return true;
    }
}
// Remove last element
int stack::pop(){
    if(isEmpty()){
        cout << "\nStack Underflow.\n";
        return 0;
    }
    else{
        int x = items[top--];
        return x;
    }
}
// Get the last element
int stack::peek(){
    if(isEmpty()){
        cout << "\nThe Stack is empty.\n";
        return 0;
    }
    else{
        int x = items[top--];
        return x;
    }
}
int main() {
    stack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.pop() << " Popped from stack\n";

    cout << "Elements present in stack: ";
    while(!st.isEmpty())
    {
        cout << st.peek() << " ";
    }
    cout << "\n";
    return 0;
}
/*
-------------Output-------------
10 Pushed into stack
20 Pushed into stack
30 Pushed into stack
30 Popped from stack
Elements present in stack: 20 10
*/
