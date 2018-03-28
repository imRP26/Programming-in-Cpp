#include<iostream>

using namespace std;

/*Progrma to print data within a range say K1 and K2 in a BST-ASked in Microsort and Flipkart.
1)Recursive method-
2)Level order traverasl method
3)Threaded tree and inorder successor


*/

struct BSTnode{
	
	int data;	
	struct BSTnode *left,*right;
};

//1)Recursive method-
void RangePrint(BSTnode *root)
{
	if(!root)	return;
	
	
	
	
}


BSTnode *newNode(int data)
{
	BSTnode *temp = new BSTnode();
	
	temp->data = data;
	
	temp->left = temp->right = NULL;
	
	return temp;
}


BSTnode *insert(BSTnode *root,int value)
{
	//we first need to find the appropiate location to insert data
	if(root==NULL)
	{
		BSTnode *temp  = new BSTnode();
		temp->data = value;
		temp->left = temp->right = NULL;
		
		root = temp;
	}
	
	
	else if(root->data > value)
	{
		root->left = insert(root->left,value);
	}
		
	else if(root->data < value)
	{
		root->right = insert(root->right,value);
	}
	
	
	
	//returning root of the updated tree
	return root;
}


int main()
{
	
	BSTnode *root  = newNode(4);
	
	insert(root,2);
	insert(root,3);
	insert(root,1);
	insert(root,7);
	insert(root,6);
	insert(root,12);
	insert(root,20);
	
	return 0;
}

