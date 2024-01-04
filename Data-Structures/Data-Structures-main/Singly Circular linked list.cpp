#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node* next;
};
class CircularList :public node
{
	node* first, * last, * head;
public:

	int sum;

	CircularList()
	{
		int sum = 0;
		first = NULL;
		last = NULL;
		head = NULL;
	}
	void create()
	{
		node* temp;
		temp = new node;
		int n;
		cout << "\nEnter an Element:";
		cin >> n;
		temp->data = n;
		temp->next = first;
		if (first == NULL)
		{
			first = temp;
			head = temp;
			last = first;
			sum++;
		}

		else
		{
			last->next = temp;
			last = temp;
			sum++;
		}
	}

	void display() {
		node* temp = first;
		if (temp == NULL)
		{
			cout << "List is Empty!" << endl;
		}
		for (int i = 0; i < sum; i++)
		{
			cout << temp->data;
			cout << "-->";
			temp = temp->next;
		}
		cout << "head" << endl;
	}

	void length()
	{
		cout << "The total number of nodes are : " << sum << endl;
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

	void Delete(int index)
	{
		node* previous = NULL, * current = first;
		int count = 1;

		if (first != NULL)
		{
			while (count != index)
			{
				previous = current;
				current = current->next;
				count++;
			}
			if (count == index)
			{
				cout << "The Deleted item is : " << current->data << endl;
				previous->next = current->next;
				sum--;
				return;
			}
		}
		else
		{
			cout << "Not able to Delete!" << endl;
			return;
		}
	}

	void Josephus() {
		node* temp = first;
		node* previous = NULL, * current = first;
		bool x = false;
		last->next = head;
		head == first;
		while (sum != 1) {
			for (int i = 0; i < 3; i++)
			{
				if (x == true)
				{
					previous = current, temp;
					current = current->next;
					temp = temp->next;
				}

				x = true;
			}
			previous->next = current->next;
			sum--;
		}
		if (sum == 1) {
			current = current->next;

			cout << "THE LEADER FOR JOSEPHUS FUNCTION IS : ";
			cout << current->data << endl;

			current = temp, first, last, head;
			current->next = head;
			previous = NULL;

		}
	}

};

int main()
{
	CircularList l;

	for (int i = 0; i < 9; i++)
	{
		l.create();
	}

	l.display();
	l.length();
	l.insert();
	l.display();
	l.Delete(5);
	l.length();
	l.display();
	l.Josephus();





	/*  CircularList l;
	  for (int i = 0; i < 13; i++)
	  {
		  l.create();
	  }
	  l.display();
	  l.length();
	  l.insert();
	  l.length();
	  l.display();
	  l.remove();
	  l.length();
	  l.display();
	  l.Delete(2);
	  l.length();
	  l.display();
	  l.Josephus();*/
	return 0;
}