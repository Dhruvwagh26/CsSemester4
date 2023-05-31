/************************************************/
//	Author- Dhruv Kamalakar Wagh	    		//
// 	Subject- Data Structure Laboratory  		//
// 	Assignment Number 4. Binary Search Tree. 	// 
/***********************************************/
#include<iostream>
#include<math.h>
using namespace std;

struct Bstnode
{
    int data;
    Bstnode *left = NULL;
    Bstnode *right = NULL;
};

class Btree
{
    int n,x,flag;
    
    public:
        Bstnode *root;
        Btree()
        {
            root = NULL;
        }
 
        Bstnode *GetNewNode(int value);
        Bstnode *insert( Bstnode *temp , int idata);
        void input();
        void display();
        void inorder(Bstnode *temp);
        void postorder(Bstnode *temp);
        void preorder(Bstnode *temp);
        int search(Bstnode *temp ,int idata);
        void minvalue(Bstnode *temp);
        void mirror(Bstnode *temp);
        int depth(Bstnode *temp);
};
Bstnode* Btree::GetNewNode(int value)
{
    Bstnode *newn = new Bstnode();
    newn->data = value;
    newn->left = NULL;
    newn->right = NULL;
    return newn;
}

Bstnode* Btree::insert( Bstnode *temp , int idata)
{
    if( temp == NULL )
    {
        temp = GetNewNode(idata);
    }
    else if( temp->data > idata)
    {
        temp->left = insert(temp->left , idata);
    }
    else
    {
        temp->right = insert( temp->right , idata);
    }
    return temp;
}
void Btree::input()
{
    cout<<"ENTER NUMBER OF ELEMENTS IN THE BST : ";
    cin>>n;
    for(int i = 0 ; i < n ; i++)
    {
        cout<<"NUMBER = ";
        cin>>x;
        root = insert(root , x);
    }
}

void Btree::display()
{
    cout<<endl<<"--- INORDER TRAVERSAL ---"<<endl;
    inorder(root);
    cout<<endl;
    cout<<endl<<"--- POSTORDER TRAVERSAL ---"<<endl;
    postorder(root);
    cout<<endl;
    cout<<endl<<"--- PREORDER TRAVERSAL ---"<<endl;
    preorder(root);
    cout<<endl;
 }
 void Btree::inorder(Bstnode *temp)
{
    if(temp != NULL)
    {
        inorder(temp->left);
        cout<<temp->data<<"  ";
        inorder(temp->right);
    }
}   
 
void Btree::postorder(Bstnode *temp)
{
    if(temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        cout<<temp->data<<" ";
    }
}
 
void Btree::preorder(Bstnode *temp)
{
    if(temp != NULL)
    {
        cout<<temp->data<<" ";
        preorder(temp->left);
        preorder(temp->right);
    }
} 
int Btree::search(Bstnode *temp ,int idata)
{
    if( temp != NULL)
    {
        if(temp->data == idata)
        {
            cout<<":-- RECORD FOUND --:"<<endl;
            return 1;
        }
        else if(idata < temp->data)
        {
            this->search(temp->left, idata);
        }
        else if(idata > temp->data)
        {
            this->search(temp->left , idata);
        }
    }
    else
    {
        return 0;
    }
}
void Btree::minvalue(Bstnode *temp)
{
    while(temp->left != NULL)
    {
        temp = temp->left;
    }
    cout<<"MINIMUM VALUE = "<<temp->data<<endl;
}
void Btree::mirror(Bstnode *temp)
{
    if(temp == NULL)
    {
        return;
    }
    else
    {
        Bstnode *newn;
        mirror(temp->left);
        mirror(temp->right);
        newn = temp->left;
        temp->left = temp->right;
        temp->right = newn; 
    }
}
 
int Btree::depth(Bstnode *temp)
{
    if(temp == NULL) 
        return 0;
    return (max((depth(temp->left)),(depth(temp->right))) +1);  
}
int main()
{
    Btree obj;
    obj.input();
    obj.display();
    int a = 0;
    a = obj.search(obj.root,10);
    if( a == 0)
    {
        cout<<"ELEMENT NOT FOUND"<<endl;
    }
    else
        cout<<"ELEMENT FOUND"<<endl;
 
    cout<<endl<<a<<endl;
    cout<<"\nMinimum value in BST is-";
    obj.minvalue(obj.root);

    obj.mirror(obj.root);
    obj.inorder(obj.root);
 
    cout<<endl<<"The depth of tree is -"<<obj.depth(obj.root);

    return 0;
}  