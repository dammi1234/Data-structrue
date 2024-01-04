#include <iostream>
#include <list>
using namespace std;

class node
{
public:
	int data;
	node* left;
	node* right;

	node()
	{
		data = 0;
		left = NULL;
		right = NULL;
	}
};


///////-----------------  Printing Tree code  -------------------///////////
struct Trunk
{
	Trunk* prev;
	string str;

	Trunk(Trunk* prev, string str)
	{
		this->prev = prev;
		this->str = str;
	}
};

// Helper function to print branches of the binary tree
void showTrunks(Trunk* p)
{
	if (p == NULL)
		return;

	showTrunks(p->prev);

	cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void printTree(node* root, Trunk* prev, bool isRight)
{
	if (root == NULL)
		return;

	string prev_str = "    ";
	Trunk* trunk = new Trunk(prev, prev_str);

	printTree(root->right, trunk, true);

	if (!prev)
		trunk->str = "---";
	else if (isRight)
	{
		trunk->str = ".---";
		prev_str = "   |";
	}
	else
	{
		trunk->str = "`---";
		prev->str = prev_str;
	}

	showTrunks(trunk);
	cout << root->data << endl;

	if (prev)
		prev->str = prev_str;
	trunk->str = "   |";

	printTree(root->left, trunk, false);
}


///////////////-------------------------------////////////////////////////


class BST : public node
{
	node* root;
	int duplicate;

public:

	BST()
	{
		root = NULL;
		duplicate = 0;
	}



	node* insert(int val, node* current)
	{
		node* ans = find(current, val);
		if (ans == NULL)
		{
			if (current == NULL)
			{
				current = new node;
				current->data = val;
				current->left = current->right = NULL;
			}
			else if (val < current->data)
				current->left = insert(val, current->left);
			else if (val > current->data)
				current->right = insert(val, current->right);
			return current;
		}
		else
		{
			cout << "\n\n Duplicate occured!   Value = " <<val<< "\n\n\n";
			return NULL;
		}
		
	}

	////finds the num to replace for the deleted one///
	node* inorderSuccessor(node* t)
	{
		if (t == NULL)
			return NULL;
		else if (t->left == NULL)
			return t;
		else
			return inorderSuccessor(t->left);
	}

	node* inorderPredecessor(node* p) {
		if (p == NULL)
			return NULL;
		else if (p->right == NULL)
			return p;
		else
			return inorderPredecessor(p->right);
	}

	/////////--------------------/////

	node* remove(int x, node* t) {
		node* temp;
		if (t == NULL)
			return NULL;
		else if (x < t->data)
			t->left = remove(x, t->left);
		else if (x > t->data)
			t->right = remove(x, t->right);
		else if (t->left && t->right)
		{

			temp = inorderSuccessor(t->right);//for successor ,  for predecessor:   temp = inorderPredecessor(t->left); 
			t->data = temp->data;
			t->right = remove(t->data, t->right);
		}
		else
		{
			temp = t;
			if (t->left == NULL)
				t = t->right;
			else if (t->right == NULL)
				t = t->left;
			delete temp;
		}

		return t;
	}

	

	/////   Treversals   /////

	void preorder(node* treehead)
	{
		if (treehead == NULL)
		{
			return;
		}
		cout << treehead->data << "\t";
		preorder(treehead->left);
		preorder(treehead->right);
	}


	void inorder(node* treehead)
	{
		if (treehead == NULL)
		{
			return;
		}
		inorder(treehead->left);
		cout << treehead->data << "\t";
		inorder(treehead->right);
	}


	void postorder(node* treehead)
	{
		if (treehead == NULL)
			return;

		postorder(treehead->left);
		postorder(treehead->right);
		cout << treehead->data << "\t";
	}

	///////-----------------------------------///////

	node* find(node* nod, int value) {
		if (nod == NULL)
			return NULL;
		else if (value < nod->data)
			return find(nod->left, value);
		else if (value > nod->data)
			return find(nod->right, value);
		else
			return nod;
	}



	////////-----------------Max and Min functions-------------/////
	node* findMin(node* t)
	{
		if (t == NULL)
			return NULL;
		else if (t->left == NULL)
			return t;
		else
			return findMin(t->left);
	}

	node* findMax(node* t) {
		if (t == NULL)
			return NULL;
		else if (t->right == NULL)
			return t;
		else
			return findMax(t->right);
	}

	// Function to print level order traversal of given binary tree
	void levelOrderTraversal(node* root)
	{
		// create an empty queue and enqueue root node
		list<node*> queue;
		queue.push_back(root);

		// pointer to store current node
		node* curr = NULL;

		// run till queue is not empty
		while (queue.size())
		{
			// process each node in queue and enqueue their
			// non-empty left and right child to queue
			curr = queue.front();
			queue.pop_front();

			cout << curr->data << "\t";

			if (curr->left)
				queue.push_back(curr->left);

			if (curr->right)
				queue.push_back(curr->right);
		}

	}

	
};


int main()
{
	BST b;
	node* root = NULL;
	
	root=b.insert(25,root);
	b.insert(5, root);
	b.insert(40, root);
	b.insert(15, root);
	b.insert(10, root);
	b.insert(17, root);
	b.insert(55, root);
	b.insert(47, root);
	b.insert(27, root);
	b.insert(3, root);
	b.insert(39, root);
	b.insert(99, root);
	b.insert(99, root);

	

	/////////  Printing Treee   /////////////
	cout << "/------------------Displaying Tree------------------\\\n" << endl;
	printTree(root, NULL, false);
	cout << "\n-------------------------------------------------------" << endl;
	////-----------------------------------------////

	cout << "\n\n PREORDER \t";
	b.preorder(root);
	cout << "\n\n INORDER \t";
	b.inorder(root);
	cout << "\n\n POSTORDER \t";
	b.postorder(root);
	cout << "\n\n LEVAL ORDER \t";
	b.levelOrderTraversal(root);
	cout << "\n\n";

	b.remove(40,root);

	cout << "\n\n\t\tDisplaying Tree after Deletion !!\n\n";

	/////////  Printing Treee   /////////////
	cout << "/------------------Displaying Tree------------------\\\n" << endl;
	printTree(root, NULL, false);
	cout << "\n-------------------------------------------------------" << endl;
	////-----------------------------------------////
	

	node* min = b.findMin(root);
	cout << "The Minimum value in the Tree is : " << min->data << endl;

	node* max = b.findMax(root);
	cout << "\n\nThe Maximumm value in the Tree is : " << max->data << endl;



	node* search = b.find(root, 3);
	if (search == NULL)
		cout << "Value not found." << endl;
	else
		cout << "\n\n\n\The node having value " << search->data << " is present in the Tree." << endl;


	

	return 0;
}
