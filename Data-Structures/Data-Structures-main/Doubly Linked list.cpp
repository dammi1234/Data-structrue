#include <iostream>
using namespace std;

class node {
public:
	int data;
	node* next;
	node* previous;
};

class list : public node
{
	node* first, * last;
	int sum;

public:

	list() {
		first = NULL;
		last = NULL;
	}

	void create() {
		node* temp;
		temp = new node;
		int num;
		cout << "Enter a number : ";
		cin >> num;
		sum++;
		temp->data = num;
		temp->next = NULL;

		if (first == NULL)
		{
			first = temp;
			last = first;
			temp->previous = NULL;
		}

		else
		{
			last->next = temp;
			temp->previous = last;
			last = temp;
		}
	}

	void insert()
	{
		node* previous, * current;
		previous = NULL;
		current = first;
		int count = 1, position, choice, num;

		node* temp = new node;
		cout << "Enter a number : ";
		cin >> num;
		temp->data = num;
		temp->next = NULL;
		cout << "Insert the number as :" << endl;
		cout << " 1:FIRSTNODE \n 2:LASTNODE \n 3:IN BETWEEN FIRST&LAST NODES";
		cout << "\n Enter Your Choice : ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			temp->next = first;
			first = temp;
			sum++;
			break;
		case 2:
			last->next = temp;
			last = temp;
			sum++;
			break;
		case 3:
			cout << "Enter the Position to Insert : ";
			cin >> position;
			if (position > sum + 1) {
				cout << "Sorry, Cannot Enter at this position !" << endl;
				return;
			}
			while (count != position)
			{
				previous = current;
				current = current->next;
				count++;
			}
			if (count == position)
			{
				previous->next = temp;
				temp->next = current;
				sum++;
			}
			else
				cout << "Not Able to Insert!" << endl;
			break;

		}
	}

	void remove()
	{
		node* previous = NULL, * current = first;
		int count = 1, position, choice;
		cout << "\nREMOVE\n1:FIRSTNODE\n2:LASTNODE\n3:IN BETWEEN FIRST&LAST NODES";
		cout << "\nEnter Your Choice:";
		cin >> choice;

		if (choice == 1)
		{
			if (first != NULL)
			{
				cout << "Removed number is : " << first->data << endl;
				first = first->next;
				sum--;
				return;
			}
			else
			{
				cout << "Not able to Remove!" << endl;
				return;
			}
		}

		if (choice == 2)
		{
			while (current != last)
			{
				previous = current;
				current = current->next;
			}
			if (current == last) {
				cout << "Removed number is : " << current->data << endl;
				previous->next = NULL;
				last = previous;
				sum--;
				return;
			}
			else
			{
				cout << "Not able to Remove!" << endl;
				return;
			}
		}

		if (choice == 3)
		{
			cout << "Enter the position to be Removed :";
			cin >> position;

			while (count != position)
			{
				previous = current;
				current = current->next;
				count++;
			}
			if (count == position)
			{
				cout << "Removed number is : " << current->data << endl;
				previous->next = current->next;
				sum--;
				return;
			}
			else
			{
				cout << "Not able to Remove!" << endl;
				return;
			}
		}
	}


	void display() {
		node* temp = first;
		if (temp == NULL)
		{
			cout << "List is Empty!" << endl;
		}
		while (temp != NULL)
		{
			cout << temp->data;
			cout << "-->";
			temp = temp->next;
		}
		cout << "NULL" << endl;
	}

	void length()
	{
		int total = 0;
		node* temp = first;
		if (temp == NULL)
		{
			cout << "List is Empty!" << endl;
		}
		while (temp != NULL)
		{
			total++;
			temp = temp->next;
		}
		cout << "The number of Elements are : " << total << endl;
	}

	void find()
	{
		int value, position = 0;
		bool flag = false;
		if (first == NULL)
		{
			cout << "List is Empty!" << endl;
			return;
		}
		cout << "Enter the value to be Searched : ";
		cin >> value;
		node* temp;
		temp = first;
		while (temp != NULL)
		{
			position++;
			if (temp->data == value)
			{
				flag = true;
				cout << "Element" << value << "is Found at " << position << " Position" << endl;
				return;
			}
			temp = temp->next;
		}

		if (!flag)
		{
			cout << "Element " << value << " not Found in the List" << endl;
		}
	}

	void update()
	{
		int value = 0, newval = 0;
		cout << "Enter the value you want to update : ";
		cin >> value;
		node* temp = first;
		if (temp == NULL)
		{
			cout << "Sorry List is Empty!" << endl;
			return;
		}
		else
		{
			while (temp != NULL)
			{
				if (temp->data == value)
				{
					cout << "Enter the value you want to update against '" << temp->data << "' : ";
					cin >> newval;
					temp->data = newval;
					cout << "Successfully Updated!" << endl;
					return;
				}
				temp = temp->next;
			}

			cout << "Sorry Value not found!" << endl;
		}

	}
};

int main()
{
	list l;
	l.create();
	l.display();
	l.insert();
	l.display();
	l.insert();
	l.display();
	l.insert();
	l.display();
	l.insert();
	l.display();
	l.length();
	l.display();
	l.remove();
	l.length();
	l.display();
	l.update();
	l.display();
	return 0;
}