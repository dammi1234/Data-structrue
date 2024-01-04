#include <iostream>
using namespace std;

class node {

public:
	int data = 0;
	node* left;
	node* right;

	node()
	{
		left = NULL;
		right = NULL;
	}
	node(int val)
	{
		data =val;
		left = NULL;
		right = NULL;
	}
};


///////  Printing Tree code ///////////
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




class Btree : public node 
{
public:
	node* root, parentof;
	Btree()
	{
		root = NULL;
		parentof = NULL;
	}

	node* findparent(node* current, node* ptrofval, node* parent)
	{
		if (current == NULL)
		{
			return NULL;
		}
		if (current == ptrofval)
		{
			return parent;
		}
		else
		{
			node* t = NULL;
			t = findparent(current->left, ptrofval, current);
			if (t != NULL)
			{
				return t;
			}
			else
			{
				t = findparent(current->right, ptrofval, current);
				return t;
			}
		}
	}

	void printparent(node* current, node* ptrofval, node* parent)
	{
		node* parentof = findparent(current, ptrofval, parent);
		cout << "The parent of " << ptrofval->data << " is " << parentof->data << " . " << endl;
	}

	node* siblings(node* root, node* ptrofval)
	{
		node* par = findparent(root, ptrofval, root);

		if (par->left == ptrofval)
			return par->right;
		else
			return par->left;
	}

	void printsiblings(node* root, node* ptrofval)
	{
		node* p = siblings(root, ptrofval);
		if (p == NULL)
		{
			cout << "Sorry! " << ptrofval->data << " has no sibling.";
		}
		else
		cout << "The sibling of " << ptrofval->data << " is " << p->data <<" . ";
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


	int getleval(node* ptr, int val, int leval)
	{
		if (ptr == NULL)
			return 0;
		if (ptr->data == val)
			return leval;
		return getleval(ptr->left, val, leval + 1) | getleval(ptr->right, val, leval + 1);
	}

	void printleval(node* ptr, int val, int leval)
	{
		int num = getleval(ptr, val, leval);
		cout << "\n\nThe leval of " << val << " is " << num << "." << endl;
	}

	int maxDepth(node* nod)
	{
		if (nod == NULL)
		{
			return -1;
		}
		else
		{
			int Ldepth = maxDepth(nod->left);
			int Rdepth = maxDepth(nod->right);

			if (Ldepth > Rdepth)
				return (Ldepth + 1);
			else
				return (Rdepth + 1);
		}
	}


	void printDepth(node* nod)
	{
		int dep = maxDepth(nod);
		cout << "The maximum Depth of this Tree is : " << dep << endl;
	}

};

int main()
{
	Btree b;
	
		//  Creating Tree  //

	node* root = new node(5);
	root->left = new node(2);
	root->right = new node(7);
	root->right->left = new node(3);
	root->right->right = new node(9);
	root->left->left = new node(6);
	root->left->left->right = new node(1);

		////----------------------////



	/////////  Printing Treee   /////////////
	cout << "/------------------Displaying Tree------------------\\\n" << endl;
	printTree(root, NULL , true);
	cout << "\n-------------------------------------------------------" << endl;
	////-----------------------------------------////


	b.findparent(root, root->left->left->right, root);		///findparent returns parent.
	b.printparent(root, root->left->left->right, root);		/// this one prints it .

	b.siblings(root, root->left->left);		////returns sibling
	b.printsiblings(root, root->left);		///prints sibling

	cout << "\n\n";
	b.preorder(root);

	cout << "\n\n";
	b.inorder(root);

	cout << "\n\n";
	b.postorder(root);


	b.getleval(root, 1, 0);		////return's leval
	b.printleval(root, 1, 0);   ////print's leval

	b.maxDepth(root);		  //////return's Depth
	b.printDepth(root);       //////print's Depth

	return 0;
}
