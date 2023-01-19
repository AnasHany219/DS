#include <iostream>
using namespace std;

class DoublyLinkedList
{
private:
	struct node{
		int data;
		node* next;
		node* prev;
	};
	int count;
	node* first;
	node* last;

public:
	DoublyLinkedList(){
		first = last = NULL;
		count = 0;
	};

	bool Empty(){
		return (count == 0);
	}

	void InsertFirst(int val){
		node* NewNode = new node;
		NewNode->data = val;
		if (Empty()){
			first = last = NewNode;
			first->next = last->prev = NULL;
		}
		else{
			NewNode->next = first;
			NewNode->prev = NULL;
			first->prev = NewNode;
			first = NewNode;
		}
		count++;
	}

	void InsertLast(int val){
		node* NewNode = new node;
		NewNode->data = val;
		if (Empty()){
			first = last = NewNode;
			first->next = last->prev = NULL;
		}
		else{
			NewNode->prev = last;
			NewNode->next = NULL;
			last->next = NewNode;
			last = NewNode;
		}
		count++;
	}

	void InsertAtPos(int val, int pos){
		if (pos<0 || pos>count)
			cout << "Out Of Range" << endl;
		else{
			if (pos == 0)
				InsertFirst(val);
			else if (pos == count)
				InsertLast(val);
			else{
				node* NewNode = new node;
				NewNode->data = val;
				node* cur = first;
				for (int i = 1; i < pos; i++){
					cur = cur->next;
				}
				NewNode->next = cur->next;
				NewNode->prev = cur;
				cur->next->prev = NewNode;
				cur->next = NewNode;
				count++;
			}
		}
	}

	void RemoveFirst() {
		if (Empty())
			cout << "Is Empty" << endl;
		else if (count == 1){
			delete first;
			first = last = NULL;
			count--;
		}
		else{
			node* cur = first;
			first = first->next;
			first->prev = NULL;
			delete cur;
			count--;
		}
	}

	void RemoveLast(){
		if (Empty())
			cout << "Is Empty" << endl;
		else if (count == 1){
			delete first;
			first = last = NULL;
			count--;
		}
		else{
			node* cur = last;
			last = last->prev;
			last->next = NULL;
			delete cur;
			count--;
		}
	}

	void RemoveElement(int val){
		if (Empty())
			cout << "Is Empty" << endl;
		else{
			node* cur = first;
			while (cur != NULL && cur->data != val){
				cur = cur->next;
			}
			if (cur == NULL)
				cout << "This Element Not There" << endl;
            else if (cur->next == NULL)
				RemoveLast();
			else if (cur->prev == NULL)
				RemoveFirst();
			else{
				cur->prev->next = cur->next;
				cur->next->prev = cur->prev;
				delete cur;
				count--;
			}
		}
	}

	void Display() {
		cout << "Element List : " << endl;
		node* cur = first;
		while (cur != NULL)
		{
			cout << " " << cur->data << endl;
			cur = cur->next;
		}
	}

	void ReverseDisplay() {
		cout << "Element List After Reverse : " << endl;
		node* cur = last;
		while (cur != NULL)
		{
			cout << " " << cur->data << endl;
			cur = cur->prev;
		}
	}

	~DoublyLinkedList(){
		node* temp;
		while (first != NULL)
		{
			temp = first;
			first = first->next;
			delete temp;
		}
		last = NULL;
		count = 0;
	}
};


int main(){
    cout << "Hello World!\n";
    return 0;
}
