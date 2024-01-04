#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
class Node
{
public:
    int data;
    Node* previous;
    Node* top;
    Node* temp;

};
class Lisst :public Node
{
public:
    Lisst() {
        top = NULL;
        previous = NULL;
        temp = NULL;
    }

    void push(int value)
    {
        if (top == NULL)
        {
            top = new Node;
            top->data = value;
            top->previous = NULL;
            temp = top;
        }
        else {
            top = new Node;
            top->data = value;
            top->previous = temp;
            temp = top;
        }

    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "UNDERFLOW" << endl;
            return;
        }
        else
        {
            top = temp;
            top = top->previous;
            cout << "The value popped is : " << temp->data << endl;
            delete temp;
            temp = top;
        }
    }
};


int main() {
    Lisst l;
    l.push(1);
    l.push(2);
    l.push(3);
    l.push(4);
    l.push(5);
    l.pop();
    l.pop();
    l.pop();
    l.pop();
    l.pop();
    l.pop();

    return 0;
}