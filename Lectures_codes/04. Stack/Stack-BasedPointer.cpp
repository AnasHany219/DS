#include <iostream>
using namespace std;
struct Node{
public:
    int data;
    Node* Next;
    Node() {
        data = 0;
        Next = NULL;
    }
};
class Stack_List{
private:
    Node* Top;
public:
    Stack_List() {
        Top = NULL;
    }
    bool isEmpty() {
        if (Top == NULL)
            return true;
        else
            return false;
    }

    void push(int val) {
        Node* NewNode = new Node;
        NewNode->data = val;
        NewNode->Next = Top;
        Top = NewNode;
    }

    int pop() {
        Node* x = Top;
        Top = Top->Next;
        x->Next = NULL;
        free(x);
        return
            x->data;
    }

	void peak(){
		if (isEmpty())
			cout << "Stack is empty" << endl;
		else
			cout << "Top is : " << Top->data << endl;
	}

	void Display() {
		Node* temp = Top;
		while (temp != NULL){
			cout << temp->data << endl;
			temp = temp->Next;
		}
	}

	int Counter(){
		Node* temp = Top;
		int C = 0;
		while (temp != NULL){
			C++;
			temp = temp->Next;
		}
		return C;
	}
	bool search(int val){
		if (isEmpty())
			cout << "Stack is empty" << endl;
		else
		{
			bool F = false;
			Node* temp = Top;
			while (temp != NULL)
			{
				if (temp->data == val){
					F = true;
					temp = temp->Next;
				}
			}
			return F;
		}
	}
};

int main() {
    Stack_List s;
	int x;
	for (int i = 0; i < 3; i++){
        cout << "Enter item : ";
		cin >> x;
		s.push(x);
	}
	s.Display();
}
/*
-----Output----
Enter item : 10
Enter item : 20
Enter item : 30
30
20
10
*/
