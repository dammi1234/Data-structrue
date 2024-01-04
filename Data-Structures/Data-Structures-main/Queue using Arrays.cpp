#include<iostream>
using namespace std;

class Queue {
	int *front;
	int *rear;
	int* arr;
	int len, size;


public:
	Queue(){
		len = 0;
		cout << "Enter the size of array : ";
		cin >> size;
		arr = new int[size];

		front = arr;
		for (int i = 0; i < size; i++) {
			*front = -1;
			front++;
		}
		front = NULL;
		rear = NULL;
	}

	void show() {  //For self Ease!!
		cout << "[ ";
		int* temp = front;
	
		for (int i = 0; i < len; i++) {
			cout << *temp << ",";
			temp++;
		}
		cout << " ]" << endl;
		return;
	}

	bool isEmpty() {
		if (len == 0) {
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isFull() {
		if (len == size) {
			return true;
		}
		else
		{
			return false;
		}
	}

	void enqueue(int val) {
		if (isFull()) {
			cout << "Queue is full..!! " << endl;
			return;
		}

		if (front == NULL)
		{
			front = arr;
			rear = front;
			*rear = val;
			len++;
			cout << "Enqueued..!!" << endl;
			return;
		}

		rear++;
		*rear = val;
		len++;
		cout << "Enqueued..!!" << endl;
		return;

	}

	void dequeue() {
		if (isEmpty()) {
			cout << "underflow" << endl;
			return;
		}


		cout << "Element Dequeued : " << *front << endl;
		front++;
		len--;
		return;
	}
};


int main() {
	Queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.dequeue();
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);
	q.dequeue();
	q.show();
}