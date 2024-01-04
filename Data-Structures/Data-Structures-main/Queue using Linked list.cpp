#include<iostream>
using namespace std;

class Node {

public:
	int data;
	Node* next;

};

class Queue: public Node{

public:

	int length;
	Node* front;
	Node* rear;
	int size;

	Queue(){
		length = 0;
		data = 0;
		front = NULL;
		rear = NULL;
		next = NULL;	
		cout << "Enter the Length of the Queue : ";
		cin >> size;
		
	}

	void enqueue(int val) {
		if (length == size)
		{
			cout << "Can't Enqueue. Queue is Full." << endl;
			return;
		}

		if (front == NULL)
		{
			Node* temp = new Node;
			temp->data = val;
			length++;
			temp->next = NULL;
			front = temp;
			rear = front;
			return;
		}

		Node* temp = new Node;
		temp->data = val;
		length++;
		rear->next = temp;
		temp->next = NULL;
		rear = temp;
		return;

	}

	void dequeue() {
		if (front == NULL) 
		{
			cout << "Can't Dequeue. Queue is Empty." << endl;
			return;
		}

		Node* temp = front;
		front = front->next;

		cout << "Element Dequed : " << temp->data << endl;
		length--;
		delete(temp);

		return;
	}

	void show() {
		Node* temp;
		temp = front;
		cout << "[ ";
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << " ]       Length: " << length << endl;
		return;
	}
};

int main() {
	Queue q;
	q.enqueue(0);
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);
	q.enqueue(7);
	q.enqueue(8);
	q.enqueue(9);
	q.enqueue(10);

	q.show();

	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();

	q.show();
}