//#include <stdio.h>
#include<iostream>
//#include <stdlib.h>
#include<iostream>
//#include <assert.h>

#define		N	4

using namespace std;

class Node { public:
      int Data;  Node *Next; };

Node * InsertionSort(Node *list);
char number();
struct Node *CreateRandomList(int size);
void DestroyList(struct Node *list);
Node *Input(int);
void read();
void PrintList(struct Node *list);

Node *HEAD=NULL;


/////////////////////////////////
//   INSERTION SORT ////////////////
Node *InsertionSort(Node *list)
	{	 Node *k;
       Node *nwlist;
	if(list==0 || list->Next==0) { return list; }
	
	nwlist=list; k=list->Next; nwlist->Next=0; // 1st node is new list
	while(k!=0)
		{	struct Node *ptr;
		if(nwlist->Data>k->Data)  // Check if insert before first
			{ struct Node *tmp;
			tmp=k;  k=k->Next; tmp->Next=nwlist;
			nwlist=tmp; continue;
			}

		for(ptr=nwlist;ptr->Next!=0;ptr=ptr->Next) // check rest
			{
			if(ptr->Next->Data>k->Data)
				{ break; } 
			}

		if(ptr->Next!=0)
			{  struct Node *tmp;
			tmp=k;  k=k->Next; tmp->Next=ptr->Next;
			ptr->Next=tmp; continue;
			}
		else
			{
			ptr->Next=k;  k=k->Next;  
			ptr->Next->Next=0; continue;
			}
		}
	return nwlist;
	}




//////////////////////////////
int main(void)
	{	
        Node *list;
     int num; 
     int numOfEl;    
     cout << "Enter number of characters you want to input: ";    
     cin >> numOfEl;    
     /*cout << "Enter " << numOfEl << " characters: ";    
     for(int i = 0 ; i < numOfEl ; i++)    
     {        
           cin >> num;        
           list=CreateRandomList(num,numOfEl);    
     }    
     //list=CreateRandomList(num);
     cout << "\nList before sorting.\n";    
     /*read();*/  /*  PrintList(list);
     list=InsertionSort(list);
     cout<<endl;    
     cout << "List after sorting.\n";*/
     //Read();
	
	
    cout << "Enter " << numOfEl << " characters: ";	
	list=CreateRandomList(numOfEl);  PrintList(list);
	list=InsertionSort(list);  PrintList(list);
	//DestroyList(list); 
    system("pause");
    return 0;
	}


//////////////////////////////
void PrintList(struct Node *list)
	{	struct Node *p;
	cout<<"List: ";
	for(p=list;p!=0;p=p->Next)
		{  cout<<static_cast<char>(p->Data)<<" "; }
	cout<<"\n";
	}


char number()
{
     char num;
//cout << "Enter " << numOfEl << " characters: ";    
    // for(int i = 0 ; i < numOfEl ; i++)    
     //{        
           cin >> num;        
           //list=CreateRandomList(num,numOfEl);    
     //}
     return num;    
}

//////////////////////////////
struct Node * CreateRandomList(int size)
	{	int i;	struct Node *list;
	list=0;
	for(i=0;i<size;++i)
	{	
            Node *nw;
		//nw=(struct Node *)malloc(sizeof(struct Node)); 
        nw=new Node[sizeof(Node)];
        assert(nw!=0);
		nw->Data=number()/*rand()*/; nw->Next=list; list=nw;
	}
	return list;
	}



Node *Input(int num)
{    
        Node *list;
        Node *front, *tail;    
        tail = new Node;    
        tail->Data = num;    
        tail->Next = NULL;    
        if(HEAD == NULL)        
         HEAD = tail;    
        else    
        {        
           front = HEAD;       
           while(front->Next!=NULL)            
             front = front->Next;       
           front->Next = tail;    
        }
        //return list;
}

void read()
      {
       int j=0;
       cout<</*"Node*/" \tdata"<<endl;
       for(Node *i = HEAD; i!=0; i= i->Next)
       {
        //j++;
        cout<</*j<<*/" \t "<<i -> Data<<endl;
        }
       }


///////////////////////////////
void DestroyList(struct Node *list)
	{	
	while(list!=0)
		{	struct Node *tmp;
		tmp=list; list=list->Next; free(tmp);
		}
	}
