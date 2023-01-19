#include <iostream>
using namespace std;
class  QueueList{
private:
  struct Node{
    int item;
		Node* next;
  };
  int length;
	Node* frontPtr, * rearPtr;
public:
  QueueList(){
		frontPtr = NULL;
		rearPtr = NULL;
		length = 0;
	}

	int Empty(){
		if (length == 0)
			return 1;
		else
			return 0;
	}

	void enqueue(int val){
		Node* New_Node = new Node;
		New_Node->next = NULL;
		New_Node->item = val;
		if (Empty()){
			rearPtr = frontPtr = New_Node;
		}
		else{
			rearPtr->next = New_Node;
			rearPtr = New_Node;
		}
		length++;
	}

	int dequeue(){
		if (Empty()){
			cout << "Queue is Empty" << endl;
			return 0;
		}
		else if (length == 1){
			delete frontPtr;
			rearPtr = NULL;
			length = 0;
		}
		else{
			Node* item = frontPtr;
			frontPtr = frontPtr->next;
			delete item;
			length--;
		}
	}

	void Display(){
		Node* current = frontPtr;
		cout << "Elements are : " << endl;
		while (current != NULL){
			cout << current->item << endl;
			current = current->next;
		}
	}

	void clearQueue(){
		Node* current;
		while (frontPtr != NULL){
			current = frontPtr;
			frontPtr = frontPtr->next;
			delete current;
		}
		rearPtr = NULL;
		length = 0;
	}
};
int main(){
	QueueList s;
	int item;
	while (true){
		int ch;
		cout << "===========================" << endl;
		cout << "1)push\n2)pop\n3)display\n4)clear\n5)Exit" << endl;
		cout << "===========================" << endl;
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "Enter the element : ";
			cin >> item;
			s.enqueue(item);
			break;
		case 2:
			s.dequeue();
			break;
		case 3:
			s.Display();
			break;
		case 4:
			s.clearQueue();
			break;
		case 5:
			exit(0);
			break;
		default:
			cout << "Enter number from {1 ,2 ,3 ,4 ,5}" << endl;
			break;
		}
	}
	return 0;
}
