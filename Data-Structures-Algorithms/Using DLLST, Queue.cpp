#include<iostream>

using namespace std;

class node
{
    public:
    int info;
    node *next,*prev;
    
    node(int el,node *ptr=0,node *ptr1=0)
    {
        info=el;
        next=ptr;
        prev=ptr1;
    }
};

class Queue1
{
      private:
      node *head,*tail;
      
      public:
      Queue1()
      {
          head=tail=0;
      }
      
      
      int IsEmpty()
      {
          return head==0;
      }
      
      void enqueue1(int value)
      {
           if(tail!=0)
           {
           tail->next=new node(value,0,tail);
           tail=tail->next;
           }
           else {head=tail=new node(value);}
      }
      
      int dequeue1()
      {
           int e1=head->info;
           
           if(!IsEmpty())
           {
              node *tmp;
              tmp=head;
              delete tmp;
              head=head->next;
              head->prev=0;
              
              return e1;
           }
      }
      
      void read()
      {
           //cout<<"Queue."<<endl;
           for(node *i;i!=0;i=i->next)
           {
                 cout<<i->info<<" ";
           }
      }
};

int main()
{
    Queue1 q1;
    
    cout<<"Queue."<<endl;
    q1.enqueue1(1);
    q1.enqueue1(2);
    q1.dequeue1();
    q1.enqueue1(3);
    q1.enqueue1(4);
    q1.enqueue1(5);
    
    
    q1.read();
    
    
    system("pause");
    return 0;
}
           
