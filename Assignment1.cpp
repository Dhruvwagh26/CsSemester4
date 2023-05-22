#include<iostream>
using namespace std;

class node
{
	string name;
	long int tel;
	int id;
	
	public:
		node()
		{
			tel = 0;
			id = 0;
			name = " ";
		}
		friend class hashing;	
		
};

class hashing
{
	node data[100];	//maximum size is 100.
	string nam;
	long int num;
	int iid;
	int index;
	
	public:
		hashing()
		{
			nam = " ";
			num = 0;
			iid = 0;	
		}
	
		void create(int size);
		void search(int size);
		void deleter(int size);
		void update(int size);	
		void display(int size);
		
};

void hashing::create(int size)
{
	cout<<"\n Entered id is= ";
	cin>>iid;

	cout<<"\n Entered telephone number is= ";
	cin>>num;

	cout<<"\n Entered name is= ";
	cin>>nam;

	index = iid % size; // obtaing last digit of id      ie. new location.


//linear probing..in case collision occurs
	for(int j = 0; j< size; j++)
	{
		if(data[index].id == 0)
		{
			data[index].id = iid;
			data[index].tel = num;
			data[index].name = nam;
			break;
		}	
		else
		{
			index= (index + 1) % size;

		}

	}
}
void hashing::search(int size)
{
	int index1, key, flag = 0;
	cout<<"id to search is = ";
	cin>>key;
	index1 = key % size;

	for(int j = 0; j< size; j++)
	{
		if(data[index1].id == key)
		{
			flag = 1;
			cout<<"\nRecord found :";
			cout<<"\n\tID =";
			cout<<"\n\tTelephone -";
			cout<<"\n\t name = ";
			cout<<"\n\t"<<data[index].id<<"\t"<<data[index].tel<<"\t"<<data[index].name;
			break;
		}
		else
		{
			index1 = (index1 + 1)% size;
		
		}
	}	
	if(flag == 0)
	{
		cout<<"\nRecord";
		cout<<"not found";
			
	}

}
void hashing::deleter(int size)
{
	int index1, key, flag = 0;
	cout<<"\nEnter the record";
	cout<<"ID to delete is = ";
	cin>>key;
	index1 = key % size;
	
	//traversing the directory linearly
	for(int i = 0; i<size; i++)
	{
		if(data[index1].id == key)
		{
			flag =1;
			data[index1].id = 0;
			data[index1].name = " ";
			data[index1].tel = 0;
			cout<<"\nrecord deleted successfully";
			break;		  		
		}
		else
		{
			index1 = (index1 +1)%size;
		}
	
	}
	if(flag == 0)
	{
		cout<<"\nRecord not found";	
	}
}
void hashing::update(int size)
{
	int index1, key, flag = 0;
    cout << "\nEnter record";
    cout << " id to update : ";
	cin>> key;
    index1 = key % size;

    // Traversing the directory
	for (int a = 0; a < size; a++) 
	{
		if (data[index1].id == key) 
		{
	        flag = 1;
        	cout <<"\nEnter";
        	cout <<" name: \t\t\t";
		    cin>> nam;
        	cout <<"\nEnter";
        	cout <<" telephone number: \t";
			cin>> num;
			data[index1].name = nam;
        	data[index1].tel = num;
        	cout <<"\nDetails updated: ";
        	cout <<"\n\tID \tNAME";
        	cout <<" \t\tTELEPHONE ";
        	cout <<"\n\t"<< data[index1].id<< " \t"<< data[index1].name<< " \t"<< data[index1].tel;
	        break;
	    }
        else
		{
			index1 = (index1 + 1) % size;		
		}        
    }
	if(flag == 0)
	{
		cout<<"\nRecord not found";	
	}
}
void hashing::display(int size)
{
	cout<<"\n Displaying the data(\tID\tName\tTelephone) ";
	
	for(int i = 0; i< size; i++)
	{
		if(data[i].id != 0)
		{
			cout<<"\n\t"<<data[i].id<<"\t"<<data[i].name<<"\t"<<data[i].tel;
		}	
	}
}


int main()
{
	int size;
	hashing hobj;
	size = 10;
	char Ans,s;
	int choice;
	do
	{
		cout<<"\nTelephone directory using Hash Table";
		cout<<"\nMenu";
		cout<<"\n1.Create Record \n2. Display Record \n3. Search Record \n4. Update Record \n5. Delete record";
		cout<<"\nEnter your choice- ";	
		cin>>choice;	
		switch(choice)
		{
			case(1):
			{
				cout<<"\n**** CREATE RECORD ****";
				hobj.create(size);
				break;
			}
			case(2):
			{
				cout<<"\n**** DISPLAY RECORD ****";
				hobj.display(size);
				break;
			}
			case(3):
			{
				cout<<"\n**** SEARCH RECORD ****";
				hobj.search(size);
				break;
			}
			case(4):
			{
				cout<<"\n**** UPDATE RECORD ****";
				hobj.update(size);
				break;
			}
			case(5):
			{
				cout<<"\n**** DELETE RECORD ****";
				hobj.deleter(size);
				break;
			}
			
		}
		cout<<"\n DO you want to continue? -(y/n)"; 
			cin>>s;	
	}while(s == 'y');
	
	return 0;
}
