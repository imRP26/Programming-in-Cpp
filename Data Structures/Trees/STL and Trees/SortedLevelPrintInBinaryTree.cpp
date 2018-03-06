#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>


using namespace std;

//PROGRAM TO PRINT NODES AT EACH LEVEL IN SORTED MANNER USING MAPS-TIME COMPLEXITY = O(nlogn)
//as maps are implemented using self balancing Binary search trees


struct BinaryTreeNode{
	
	int data;
	struct BinaryTreeNode *left,*right;
};



void SortedLevelPrintUtil(struct BinaryTreeNode *root, map< int,vector<int> > &Map,int level)
{
	if(!root) return ;
	
	SortedLevelPrintUtil(root->left,Map,level+1); //increment level as we recur to each left node
	
	Map[level].push_back(root->data); //insert level as key and the node's data in vector
	
	SortedLevelPrintUtil(root->right,Map,level+1); //increment level as we recur to each right node
}


void SortedLevelPrint(struct BinaryTreeNode *root)
{
	map< int,vector<int> > Map;
	
	map< int,vector<int> >::iterator i;
	
	//fill the map
	
	SortedLevelPrintUtil(root,Map,0);
	
	cout<<"level"<<setw(10)<< " Sorted Level Nodes:"<<endl;
	
	for(i=Map.begin(); i!=Map.end();i++)
	{
		//now we just need to sort the vector
		
		cout<<i->first<<"      |    ";
		
		sort(i->second.begin(), i->second.end());
		
		for(int j= 0 ; j< i->second.size();j++)
		{
			cout<<i->second[j]<<" ";
		}
		
		cout<<endl;
	}
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
	
	Insert(&root1,7);
	Insert(&root1,10);
	Insert(&root1,3);
	Insert(&root1,8);
	Insert(&root1,100);
	Insert(&root1,6);
	Insert(&root1,9);
	
	
	SortedLevelPrint(root1);

return 0;


}

