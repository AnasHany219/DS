#include <iostream>
using namespace std;
class ArrayQueue{
private:
	int front, rear, size, lengh;
	int* Arr;
public:
	ArrayQueue(){
		cout << "Enter Queue Size: ";
		cin >> size;
		Arr = new int[size];
		front = 0;
		rear = size - 1;
		lengh = 0;
	}

	bool isFull(){
		if (lengh == size - 1)
			return 1;
		else
			return 0;
	}

	bool isEmpty(){
		if (lengh == 0)
			return 1;
		else
			return 0;
	}

	void enqueue(int item){
		if (isFull())
			cout << "Queue Overflow \n";
		else{
            rear = (rear + 1) % size;
			Arr[rear] = item;
			lengh++;
		}
	}

	void dequeue(){
		if (isEmpty()){
			cout << "Queue Underflow \n";
		}
		else{
			front = (front + 1) % size;
			lengh--;
		}
	}

	int GetFront(){
        if (isEmpty()){
			cout << "Queue Underflow \n";
			return -1;
		}
		else
			return Arr[front];
    }

	int GetLengh(){
		return lengh;
	}

	void traverse(){
		if (isEmpty())
			cout << "Queue is Empty \n";
		else{
			for (int i = front;i <= rear;i++)
				cout << Arr[i] << " ";
		}
		cout << endl;
	}
};
int main(){
	ArrayQueue a;
	a.enqueue(10);
	a.enqueue(20);
	a.enqueue(30);
	a.enqueue(40);
	a.enqueue(50);
	a.enqueue(60);
	a.dequeue();
	a.GetFront();
	a.GetLengh();
	a.traverse();

}

/*
-------Output------
Enter Queue Size: 7
20 30 40 50 60
*/
