#include<iostream>
#include<string>
using  namespace std;

class list {
private:
	int* arr = 0;
	int size, len, * current, * temp, sum, last;
public:

	//Constructor for initializing List
	list() {
		len = 0;
		cout << "Enter the size of array: ";
		cin >> size;
		arr = new int[size];
		current = arr;

		for (int i = 0; i < size; i++) {
			*current = 0;
			current++;
		}
		current = NULL;
	}


	void push(int val)
	{
		if (len == 0) {
			current = arr;
			*current = val;
			len++;
			cout << "The number " << val << " has been successfully pushed into the stack!" << endl;
			return;
		}
		if (len == size) {
			cout << "The Stack is full!!" << endl;
			return;
		}
		current = arr;
		current = current + len;
		*current = val;
		len++;
		cout << "The number " << val << " has been successfully pushed into the stack!" << endl;
		return;
	}

	void pop()
	{
		int x = 0;
		x = len;
		current = arr;
		if (len == 0)
		{
			cout << "The stack is Empty!!" << endl;
		}

		else
		{
			for (int i = 0; i < len; i++)
			{
				if (*current == len) {
					cout << "The number " << *current << " has been successfully popped from the stack!" << endl;
					*current = 0;
					len = len - 1;
					return;
				}
				current++;
			}
		}

	}

	void stackcheck() {
		if (len == 0)
		{
			cout << "The stack is empty!" << endl;
			return;
		}

		if (len == size)
		{
			cout << "The stack is full!" << endl;
		}

		if (len < size)
		{
			cout << "The stack is full with " << len << " elements and empty with " << size - len << " elements" << endl;
		}
	}

};

int main() {
	list l1;
	l1.push(1);
	l1.push(2);
	l1.push(3);
	l1.push(4);
	l1.push(5);
	l1.push(6);
	l1.push(7);
	l1.push(8);
	l1.push(9);
	l1.pop();
	l1.pop();
	l1.stackcheck();
	l1.pop();
	l1.pop();
	l1.pop();
	l1.stackcheck();
	l1.pop();
	l1.pop();
	l1.pop();
	l1.pop();
	l1.pop();
	l1.pop();

	return 0;
}