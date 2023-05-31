/************************************************/
//	Author- Dhruv Kamalakar Wagh	    		//
// 	Subject- Data Structure Laboratory  		//
// 	Assignment Number 5. Threaded Binary Tree. 	// 
/***********************************************/
#include <iostream>
#define MAX 100
using namespace std;
class node { //node declaration
   public:
      int data;
      node *left, *right;
      bool lbit, rbit;
};
class ThreadedBinaryTree {
   private:
   node *root;
   public:
   ThreadedBinaryTree() { //constructor to initialize the variables
      root= new node();
      root->right= root->left= root;
      root->lbit = true;
      root->data = MAX;
   }
    void insert(int key);
    void inorder();
};

void ThreadedBinaryTree::insert(int key)
{
    node *p = root;
    for (;;) 
    {
        if (p->data< key) 
        { //move to right thread
            if (p->rbit)
            {
                break;
            }
            p = p->right;
        }
        else if (p->data > key) 
        { // move to left thread
            if (p->lbit)
            break;
            p = p->left;
        }
        else 
        {
            return;
        }
    }
    node *temp = new node();
    temp->data = key;
    temp->rbit= temp->lbit= true;
    if (p->data < key) 
    {
        temp->right = p->right;
        temp->left= p;
        p->right = temp;
        p->rbit= false;
    }
    else 
    {
        temp->right = p;
        temp->left = p->left;
        p->left = temp;
        p->lbit = false;
    }
}
void ThreadedBinaryTree:: inorder()
{ //print the tree
    node *temp = root, *p;
    for (;;) 
    {
        p = temp;
        temp = temp->right;
        if (!p->rbit) 
        {
            while (!temp->lbit) 
            {
                temp = temp->left;
            }
        }
        if (temp == root)
        {
            break;
        }
        cout<<temp->data<<" ";
    }
    cout<<endl;
}
int main() 
{
    char s;
    int n,count;
    ThreadedBinaryTree tbt;
    do{
        cout<<"Threaded Binary Tree\n";
        cout<<"How many nodes are to be inserted? - ";
        cin>>count;
        for(int i = 0;i<count;i++)
        {
            cout<<"Enter the node-";
            cin>>n;
            tbt.insert(n);                  
        }
        cout<<"Inorder Traversed Threaded Binary Tree :"<<"\n";
        tbt.inorder();
        cout<<"Do you want to enter new data? -";
        cin>>s;
       
    }while(s=='y' || s == 'Y');
    cout<<"\n";
    return 0;
}