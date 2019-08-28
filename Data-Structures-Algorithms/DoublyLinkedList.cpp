#include <iostream>

using namespace std;

class node
{
   public:
   int info;
   node *next,*prev;
   node(int el, node *ptr=0, node *ptr1=0)
   {
       info=el;
       next=ptr;
       prev=ptr1;
   }
};

class dlist
{
    private:
    node *head;
    node *tail;
    
    public:
    dlist()
    {
      head=tail=0;
    }
    
    int IsEmpty()
    {
        return head==0;
    }
    
    void addtohead(int e1)
    {
         //node *tmp=head;
         head=new node(e1,head,0);
         //head=head->prev;

         if(tail==0)
         {
            tail=head;
         }
   }
   
   void addtotail(int e1)
   {
        tail->next=new node(e1,0,tail);
        tail=tail->next;
        //for(node *tmp=head;tmp!=tail;tmp=tmp->next);
        //tail->prev=tmp;
   }
   
   int deletefromhead()
   {
       int e1=head->info;
       
       if(!IsEmpty())
       {       
             node *tmp;
             tmp=head;
             head=head->next;
             delete tmp;
             head->prev=0;
           
           return e1;
       }
   }
   
   int deletefromtail()
   {
       int e1=tail->info;
       node *tmp;
       
       if(!IsEmpty())
       {
         if(tail==head)
         {
            tail=head=0;
            delete head;
         }
         else
         {
             tail=tail->prev;
             delete tail->next;
             tail->next=0;
         }
         
         return e1;
       }
   }
   
   void read()
   {
        cout<<"\tList"<<endl;
        for(node *i=head;i!=0;i=i->next)
        {
            cout<<"\t"<<i->info<<endl;
        }
   }
};

int main()
{
   dlist lst;
   
   cout<<"Lnked List"<<endl;
   lst.read();
   
   cout<<endl<<"Linked List after adding to Head"<<endl;
   lst.addtohead(4);
   lst.addtohead(3);
   lst.read();
   
   cout<<endl<<"Linked List after adding to Tail"<<endl;
   lst.addtotail(5);
   lst.addtotail(6);
   lst.read();
   
   cout<<endl<<"Deleting from head data= "<<lst.deletefromhead()<<endl;
   lst.read();  
   cout<<endl<<"Deleting from tail data= "<<lst.deletefromtail()<<endl;
   lst.read();
           
   system("pause");
   return 0;
}       
