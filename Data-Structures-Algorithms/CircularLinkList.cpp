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

class clist
{
    private:
    node *head;
    node *tail;
    
    public:
    clist()
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
         /*de *i=head;
         
         while(i->next!=head)
         {
             i=i->next;
         }
         
         i=new node(e1,head);
         ->next;*/     
        tail->next=new node(e1,head);
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
             tail->next=head;
         }
         
         return e1;
       }
   }
   
   void read()
   {
        node *j=0;
        cout<<"\tList"<<endl;
        for(node *i=head;j!=tail;j=i,i=i->next)
        {
            cout<<"\t"<<i->info<<endl;
        }
   }
   
   int Count()
   {
       int count=0;
       node *j=0;
       
       for(node *i=head;j!=tail;j=i,i=i->next)
       {
            count++;
       }
        
       return count; 
   }
};

int main()
{
   clist lst;
   
   cout<<"Linked List"<<endl;
   lst.read();
   cout<<endl<<"There are "<<lst.Count()<<" nodes."<<endl;
   
   
   cout<<endl<<"Linked List after adding to Head"<<endl;
   lst.addtohead(4);
   lst.addtohead(3);
   lst.read();
   cout<<endl<<"There are "<<lst.Count()<<" nodes."<<endl;
   
   cout<<endl<<"Linked List after adding to Tail"<<endl;
   lst.addtotail(5);
   lst.addtotail(6);
   lst.read();
   cout<<endl<<"There are "<<lst.Count()<<" nodes."<<endl;
   
   
   
   cout<<endl<<"Deleting from head data= "<<lst.deletefromhead()<<endl;
   lst.read();
   cout<<endl<<"There are "<<lst.Count()<<" nodes."<<endl;  
   cout<<endl<<"Deleting from tail data= "<<lst.deletefromtail()<<endl;
   lst.read();
   cout<<endl<<"There are "<<lst.Count()<<" nodes."<<endl;
           
   system("pause");
   return 0;
}       
