#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
//Hashing with chaining with and without replacement.
//Thanks to Eshita !
struct Hash
{
    string word;
    string meaning;
    int chain;
}; 

Hash hT[10];        //hashtable size

class Hashing{
    int count=0;
    public:
    Hashing()
    {
        for(int i=0; i<10; i++)
        {
            hT[i].word="NULL";
            hT[i].meaning="NULL";
            hT[i].chain=-1;
        }
    }

    int hashingFunction(string &word)
    {
        int count = 0;
        int len = word.length();
        for (int i = 0; i < len; i++)
        {
            word[i] = char(tolower(word[i]));
            count += (word[i] - 'a');
        }

        return (count % 10);
    }

    int insertdata()
    {
        int temp;
        string telmeaning;
        string telword;
        cout<<"Enter word to insert: \n";
        cin>>telword;
        int index = hashingFunction(telword);
        cout<<"Enter meaning of word: \n";
        cin>>telmeaning;
        if(count>=10)
        {
            cout<<"Hash table full\n";
            return -1;
        }
        else
        {
            //index=telmeaning%10;
            if(hT[index].word=="NULL")
            {
                hT[index].word=telword;
                hT[index].meaning=telmeaning;
                cout<<"Record is inserted successfully in the phonebook.!"<<"\n";
            }
            else
            {
                temp=index;
                while(hT[index].chain!=-1)
                {
                   index=hT[index].chain;
                   temp=index; 
                }
                //if chain = -1, come out of the while loop
                while(hT[index].word!="NULL")
                {
                    index=(index+1)%10;
                }

                hT[index].word=telword;
                hT[index].meaning=telmeaning;
                hT[temp].chain=index;

            }
            return 1;
        }
    }

    void display()
    {
        cout<<setw(5)<<right<<setw(20)<<right<<"word"<<setw(15)<<right<<"TELEPHONE"<<setw(5)<<right<<"CHAIN\n";
        for(int i=0; i<10; i++)
        {
            cout<<setw(5)<<right<<i<<setw(12)<<right<<hT[i].word<<setw(12)<<right<<hT[i].meaning<<setw(5)<<right<<hT[i].chain<<"\n";
        }
    }

    void del()
    {
        int temp;
        string telword;
        cout<<"\nEnter the word to be deleted-";
        cin>>telword;
        int index = hashingFunction(telword);
        if(hT[index].word == "NULL")
        {
            cout<<"\nNo such word found!";
        }
        if(hT[index].word == telword)
        {
            if(hT[index].chain!= -1)
            {
                hT[index].word = hT[hT[index].chain].word;
                hT[hT[index].chain].word = "NULL";

                hT[index].meaning = hT[hT[index].chain].meaning;
                hT[hT[index].chain].meaning = "NULL";

                hT[index].chain = hT[hT[index].chain].chain;
                hT[hT[index].chain].chain = -1;   
            }
            else
            {
                hT[index].meaning="NULL";
                hT[index].chain=-1;
            }
        }
        else
        {
            temp = index;
            while(hT[index].word != telword)
            {
                temp = index;
                index = hT[index].chain;
            }
            hT[index].word = "NULL";
            hT[index].meaning = "NULL";
            hT[index].chain = -1; 

        }
    }

    void search()
    {
        int flag = 0,temp,index;
        string telword;
        cout<<"\nEnter the word to be searched - ";
        cin>>telword;
        index = hashingFunction(telword);
        if(hT[index].word == "NULL")
        {
            cout<<"\nNo such record.";

        }
        else{
            if(hT[index].word == telword)
            {
                cout<<"\nThe meaning of "<<telword<<" is given as -"<<hT[index].meaning;
                flag = 1;
                return;
            }
            else
            {
                temp = index;
                while(hT[index].chain!=-1)
                {
                    index= hT[index].chain;
                    if(hT[index].word==telword)
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            if(flag==1)
            {
                cout<<"\nThe meaning of "<<telword<<" is given as -"<<hT[index].meaning;
                return;
            }
        }
    }
};
int main()
{
    Hashing h1;
    int choice;
    

    while(1){

    cout<<"Enter choice\n 1. Insert data \n 2. display\n3. Delete data \n4. Search \n5. exit\n";
    cin>>choice;

    switch (choice)
    {
    case 1:
            h1.insertdata();
            break;

    case 2:
            h1.display();
            break;
    case 3:
            h1.del();
            break;

    case 4:
            h1.search();
            break;

    case 5:
            cout << "Exiting...\n";
            return 0;

    default:
            break;
    }
    }

    return 0;
}