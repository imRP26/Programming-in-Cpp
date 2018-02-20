#include<iostream>
#include<queue>

using namespace std;

/*program to find distance between 2 nodes in a Binary tree
distance(n1,n2) = dist(root,n1) + dist(root,n2) - 2*dist(root,LCA(n1,n2)) 
*/

struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left,*parent;
	BinaryTreeNode *right;
};



//function to find the distance from a root to a node
int dist(BinaryTreeNode *root,int n1,int d=0)
{
	
	if(root)
	{
		if(root->data==n1)
		{
			return d;
		}
		
		//recur to the left subtree and increment d, until the node n1 is found
		int l = dist(root->left,n1,d+1);
		
		//recur to the right subtree and increment d, until the node n1 is found
		int r = dist(root->right,n1,d+1);
		
		//if l is non-zero
		if(l) return l;
		else return r;		
		
		
		
	}	
	
}

//progrm to find the LCA of 2 nodes
BinaryTreeNode *FindLCAusingSingleTraversal(struct BinaryTreeNode *root, int n1,int n2)
{
	
		//base condition
		if(root==NULL) return NULL;
		
		if(root->data==n1 || root->data==n2)
		 	return root;
		
		//otherwise recur down to left and right subtrees
		BinaryTreeNode *left = FindLCAusingSingleTraversal(root->left,n1,n2);
		BinaryTreeNode *right = FindLCAusingSingleTraversal(root->right,n1,n2);
		
		//if both left and right funcion calls return non-NULL then we have found the LCA , and its is their parent
		if(left && right)	return root;
		
		return (left) ? left : right;

	
	
	
}

//function to find distance between 2 nodes-i.e the number of edges between them, or length of path
int DistNode(BinaryTreeNode *root,int n1,int n2)
{
	int d1 = dist(root,n1);
	
	int d2 = dist(root,n2);
	
	//finding LCA of n1 and n2 nodes
	BinaryTreeNode *LCA = FindLCAusingSingleTraversal(root,n1,n2);
	
	//distance between root and LCA of n1 and n2
	int dLCA= dist(root,LCA->data);
	
	return (d1+d2-2*dLCA);
}

void Insert( struct BinaryTreeNode **root,int data)
{
	struct BinaryTreeNode *new_node = new BinaryTreeNode();
	struct BinaryTreeNode *temp;
	queue<BinaryTreeNode *> q;
	new_node->data = data;
	new_node->left=NULL;
	new_node->right=NULL;
	
	if(*root==NULL)
	{
		*root = new_node;
		return;
	}
	
	q.push(*root);
	
	while(!q.empty())
	{
		temp  = q.front();
		q.pop();
		
		if(temp->left==NULL)
		{
			temp->left = new_node;
			return;
			
			
		}
		
		else
		{
			q.push(temp->left);
		}
			
		if(temp->right==NULL)
		{
			temp->right = new_node;
			return;
			
		}	
		
		else
		{
			q.push(temp->right);
		}
	}
	
}


int main()
{
	struct BinaryTreeNode *root1= NULL;
	
	Insert(&root1,1);
	Insert(&root1,2);
	Insert(&root1,3);
	Insert(&root1,4);
	Insert(&root1,5);
	Insert(&root1,6);
	Insert(&root1,7);
	Insert(&root1,8);
	Insert(&root1,9);

	cout<<DistNode(root1,2,8);
	return 0;
}