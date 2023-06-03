/*****************************************************************/
//	Author- Dhruv Kamalakar Wagh	    	                     //
// 	Subject- Data Structure Laboratory  	                     //
// 	Assignment Number 9. Adelson Vnskii and Landis(AVL Tree).    // 
/****************************************************************/
#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left,*right;
    int ht;
};

class AVL
{
    public:
        node *root;
        AVL()
        {
            root=NULL;
        }
        int height(node*);
        int BF(node*);
        node* insert(node*,int);
        node* rotate_left(node*);
        node* rotate_right(node*);
        node* LL(node*);
        node* RR(node*);
        node* LR(node*);
        node* RL(node*);
        node* delet(node*,int);
        void inorder(node*);
};
node *AVL::insert(node *T,int x)
{
    if(T == NULL)
    {
        T = new node;
        T->data = x;
        T -> right = T->left = NULL;
        T->ht = 1;
    }
    else if(x > T->data)    //insert in right subtree
    {
        T->right = insert(T->right,x);
        if(BF(T) == -2)
        {
            if(x> T->right->data)
            {
                T = RR(T);
            }
            else
            {
                T = RL(T);
            }
        }
    }
    else if(x < T->data)    //insert in left subtree
    {
        T->left = insert(T->left,x);
        if(BF(T) == 2)
        {
            if(x< T->left->data)
            {
                T = LL(T);
            }
            else
            {
                T = LR(T);
            }
        }
    }
    T->ht = height(T);
    return T;
}
int AVL::height(node *T)
{
    int lh,rh;
    if(T->left == NULL)
    {
        lh = 0;
    }
    else
    {
        lh = 1+height(T->left);
    }
    if(T->right == NULL)
    {
        rh = 0;
    }
    else
    {
        rh = 1+height(T->right);
    }
    if(lh>rh)
    {
        return (lh);
    }
    else{
        return (rh);
    }
}

node *AVL::rotate_right(node *x)
{
    node *y;
    y = x->left;
    x->left = y->right;
    y->right = x;
    x->ht = height(x);
    y->ht = height(y);
    return y;
}

node *AVL::rotate_left(node *y)
{
    node *x;
    y = x->right;
    x->right = y->left;
    y->left = x;
    x->ht = height(x);
    y->ht = height(y);
    return x;
}
node *AVL::RR(node *T)
{
    T = rotate_left(T);
    return T;
}
node *AVL::LL(node *T)
{
    T = rotate_right(T);
    return T;
}
node *AVL::LR(node *T)
{
    T->left = rotate_left(T->left);
    T = rotate_right(T);
    return T;
}
node *AVL::RL(node *T)
{
    T->right = rotate_right(T->right);
    T = rotate_left(T);
    return T;
}
int AVL::BF(node *T)
{
    int lh,rh;
    if(T == NULL)
    {
        return 0;
    }
    if(T->left == NULL)
    {
        lh = 0;
    }
    else{
        lh = 1+height(T->left);
    }
    if(T->right == NULL)
    {
        rh = 0;
    }
    else{
        rh = 1+height(T->right);
    }
    return (lh-rh);
}
void AVL::inorder(node*T)
{
    if(T!= NULL)
    {
        inorder(T->left);
        cout<<" "<<T->data<<"(BF = "<<BF(T)<<")";
        inorder(T->right);
    }
}
int main()
{
    int iCh,iCnt,x;
    AVL a;
    cout<<"\n--------------------------------------";
    cout<<"\n\tAVL TREE IMPLEMENTATION";
    cout<<"\n--------------------------------------";   
    do
    {   cout<<"\n--------------------------------";
        cout<<"\n\t\tMENU";
        cout<<"\n--------------------------------";
        cout<<"\n1.Insert\n2.Inorder\n3.Delete\n4.Exit";
        cout<<"\n--------------------------------";
        cout<<"\nEnter your choice :";
        cin>>iCh;
        
        switch(iCh)
        {
            case 1: cout<<"\nEnter number if elements : ";
                cin>>iCnt;
                cout<<"\nEnter the data : ";
                for(int i = 0;i<iCnt;i++)
                {
                    cin>>x;
                    a.insert(a.root,x);
                }
                break;
            
            case 2:
                a.inorder(a.root);
                break;
                
            case 3:
            break;
            case 4: exit(0);
        }
    }while(iCh!=4);
     
    return 0;
}
