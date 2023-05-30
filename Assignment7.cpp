/********************************************************/
//	Author- Dhruv Kamalakar Wagh	    	            //
// 	Subject- Data Structure Laboratory  	            //
// 	Assignment Number 7. Prim's Algorithm Application.  // 
/*******************************************************/
#include<iostream>
using namespace std;
class tree
{
    int arr[20][20],visited[20];
    int v,e,l,u,w;
    public:
        void insert();
        void display();
        void minimum();
};
void tree::insert()
{
    cout<<"\nEnter the number of vertices-";
    cin>>v;
    for(int i =0;i<v;i++)
    {
        visited[i] = 0;
        for(int j = 0;j<v;j++)
        {
            arr[i][j] = 999;
        }
    }
    
    cout<<"\nEnter the number of edges-";
    cin>>e;
    for(int i =0;i<e;i++)
    {
        for(int j = 0;j<e;j++)
        {
            cout<<"\nEnter the end vertices of edges-";
            cin>>l>>u;
            cout<<"\nEnter the weight of edge-";
            cin>>w;
            arr[l-1][u-1] = arr[u-1][l-1] = w;
        }
    }
}
void tree::display()
{
    cout<<"\nAdjacency matrix-";
    for(int i = 0;i<v;i++)
    {
        cout<<endl;
        for(int j = 0; j<v;j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
}
void tree::minimum()
{
    int p=0,q = 0,total = 0,min;
    visited[0] = 1;
    for(int iCnt = 0;iCnt < (v-1);iCnt++)
    {
        min= 999;
        for(int i = 0;i<v;i++)
        {
            if(visited[i]==1)
            {
                for(int j = 0;j<v;j++)
                {
                    if(visited[i]!=1)
                    {
                        if(min>arr[i][j])
                        {
                            min = arr[i][j];
                            p = i;
                            q = j;
                        }
                    }
                }
            }
        }
        visited[p] = 1;
        visited[q] = 1;
        total = total+min;
        
        cout<<"\nMinimum cost of edge ("<<(p+1)<<"->"<<(q+1)<<"), with minimum cost is-"<<min<<endl;
    }
    cout<<"\nTotal Minimum cost of complete graph is- "<<total;
}

int main()
{
    tree tobj;
    int ch;
    do
	{
		cout<<"==========PRIM'S ALGORITHM================="<<endl;
		cout<<"\n1.INPUT\n \n2.DISPLAY\n \n3.MINIMUM\n"<<endl;
		cout<<"Enter your choice :"<<endl;
		cin>>ch;
	
	switch(ch)
	{	
	case 1: cout<<"*******INPUT YOUR VALUES*******"<<endl;	
		tobj.insert();
		break;

	case 2: cout<<"*******DISPLAY THE CONTENTS********"<<endl;
		tobj.display();
		break;

	case 3: cout<<"*********MINIMUM************"<<endl;
		tobj.minimum();
		break;
	}
	
	}while(ch!=4);
	return 0;
}