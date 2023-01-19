#include <iostream>
using namespace std;

class List{
private:
	struct node{
		int item;
		node* next;
	};
	node* head;
	int lenght;
public:
	List() {
		head = NULL;
		lenght = 0;
	};

	bool Empty() {
		return head == NULL;
	}

	void InsertFirst(int val){
		node* NewNode;
		NewNode->item = val;
		NewNode->next = NULL;
		if (Empty()) {
			head = NewNode;
		}
		else{
			NewNode->next = head;
			head = NewNode;
		}
		lenght++;
	}

	void Display(){
		node* temp = head;
		while (temp != NULL){
			cout << temp->item << endl;
			temp = temp->next;
		}
	}

	int count(){
		int counter = 0;
		node* temp = head;
        while (temp != NULL)
		{
			counter++;
			temp = temp->next;
		}
		return counter;
    }

	bool isfound(int key){
		bool found = false;
		node* temp = head;
		while (temp != NULL){
			if (temp->item == key)
				found = true;
			temp = temp->next;
		}
		return found;

	}

	void insertbefore(int item, int newvalue){
		if (Empty())
			InsertFirst(newvalue);
		if (isfound(item)){
			node* newnode = new node();
			newnode->item = newvalue;
            node* temp = head;
			while (temp != NULL && temp->next->item != item){
				temp = temp->next;
			}
			newnode->next = temp->next;
			temp->next = newnode;
		}
		else{
			cout << "Sorry , Item Not Found \n";
		}
	}

	void append(int newvalue){
		if (Empty())
			InsertFirst(newvalue);
		else{
			node* temp = head;
			while (temp->next != NULL){
				temp = temp->next;
			}
			node* newnode = new node();
			newnode->item = newvalue;
			temp->next = newnode;
			newnode->next = NULL;
		}
	}

	void Delete(int item){
		if (Empty())
			cout << "List is empty , no items to delete \n";
		node* delptr = head;
		if (head->item == item){
			head = head->next;
			delete delptr;
		}
		else{
			node* prev = NULL;
			delptr = head;
			while (delptr->item != item){
				prev = delptr;
				delptr = delptr->next;
			}
			prev->next = delptr->next;
			delete delptr;
		}
	}

};

int main(){
	cout << "Hello World!\n";
}
