#include <iostream>

using namespace std;

class node
{
   public:
   int info;
   node *next;
   node(int el, node *ptr=0)
   {
       info=el;
       next=ptr;
   }
};

class slist
{
    private:
    node *head;
    node *tail;
    
    public:
    slist()
    {
      head=tail=0;
    }
    
    int IsEmpty()
    {
        return head==0;
    }
    
    void addtohead(int e1)
    {
         head=new node(e1,head);
         if(tail==0)
         {
            tail=head;
         }
   }
   
   void addtotail(int e1)
   {
        tail->next=new node(e1);
        tail=tail->next;
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
             for(tmp=head;tmp->next!=tail;tmp=tmp->next);
             delete tail;
             tail=tmp;
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
   slist lst;
   
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
