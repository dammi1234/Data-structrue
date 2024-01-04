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

	//Deep Copy Constructor
	list(list& y) {
		size = y.size;
		len = y.len;
		current = y.current;
		temp = y.temp;
		arr = y.arr;
		sum = y.sum;
		last = y.last;

	}


	//Clear Or Empty the List
	void clear() {
		current == arr;
		for (int i = 0; i < size; i++) {
			*current = 0;
			current++;
		}
		current = NULL;
		len = 0;
		sum = 0;
	}


	//Insert a Value at Specific Position
	void insert(int value, int pos) {
		if (len == size) {
			cout << "Sorry! There is no space available " << endl;
		}
		else {
			current = arr;
			int a, b;
			for (int i = 0; i < len; i++) {
				if (i == pos) {
					*current = a;
					*current = 0;
					*current = value;
					for (i; i < len + 1; i++) {
						a = a + *(current + i);
						*(current + i) = a - *(current + i);
						a = a - *(current + i);
					}
					return;
				}



			}
		}
	}

	//Insert the given value in the list at the next available position
	void insert(int x) {
		if (len == 0) {
			current = arr;
			*current = x;
			len++;
			return;
		}
		if (len == size) {
			cout << "The array is full!!" << endl;
			return;
		}
		current = arr;
		current = current + len;
		*current = x;
		len++;
		return;
	}


	//Remove a value at specific position
	void remove(int x) {
		current = arr;
		sum = 0;
		for (int i = 0; i < len; i++)
		{
			if (*current == x) {
				sum = sum + 1;
				*current = 0;

			}

			current++;
		}
		for (int i = 0; i < sum; i++)
		{
			current = arr;
			for (int i = 0; i < len; i++)
			{
				if (*current == 0) {
					*current = *(current + 1);
					*(current + 1) = 0;
				}
				current++;
			}
		}
		len = len - sum;

		cout << "The number " << x << " has been successfully removed!" << endl;
	}



	//Get value stored at a specific position
	int get(int pos) {
		if (pos > len) {
			cout << "Sorry! There is no such position available." << endl;
		}
		else {
			current == arr;
			for (int i = 0; i < pos; i++) {
				current++;
			}
			cout << "The value at " << pos << " is : " << *current << endl;
		}
	}

	//Update Existing value at a position
	void update(int value, int pos) {
		if (pos > len) {
			cout << "Sorry! There is no such position available." << endl;
		}
		else {
			current == arr;
			for (int i = 0; i < pos; i++) {
				current++;
			}
			*current = value;
			cout << "The value has been updated!" << endl;
		}

	}


	//Find a value in the list
	bool find(int value) {
		current = arr;
		for (int i = 0; i < len; i++) {
			if (*current == value) {
				cout << "The value " << value << " is present!" << endl;
				return true;
			}
		}
		cout << "The value " << value << " is not present!" << endl;
		return false;
	}


	//Return Current Length of the list
	int length() {
		int total;
		current = arr;
		for (int i = 0; i < size; i++) {
			if (*current != 0) {
				total++;
			}
		}
		cout << "The total number of entries are : " << total << endl;
		return total;
	}


	//Move to starting position of the list
	void start() {
		current = arr;
		cout << "The starting value is : " << *current << endl;
	}

	//Move to the end of the list
	void end() {
		current = arr;
		for (int i = 0; i < len - 1; i++) {
			current++;
		}
		cout << "The ending value is : " << *current << endl;

	}

	void print() {
		cout << "The list is : " << endl;
		current = arr;
		for (int i = 0; i < len; i++)
		{
			cout << *current << endl;
			current++;
		}
	}

	void next() {
		temp = arr;
		for (int i = 0; i < len; i++)
		{
			last = *temp;
			temp++;
		}
		if (*current != last) {
			for (int i = 0; i < 1; i++) {
				current++;
			}
			cout << "The next value is : " << *current << endl;
		}
		else {
			cout << "Sorry! There is no next value!" << endl;
		}
	}


};

int main() {
	list l1;
	list l2 = l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.insert(4);
	l1.insert(5);
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.insert(4);
	l1.insert(5);
	l1.print();
	l1.remove(3);
	l1.remove(1);
	l1.start();
	l1.end();
	l1.print();



	return 0;
}
