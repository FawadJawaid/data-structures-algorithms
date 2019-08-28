#include<iostream>

using namespace std;

class PriorityQueue
{
      private:
      int item;
      int priority;
      int head,tail;
      int a[5];
      
      public:
      PriorityQueue()
      {
          item=0;
          priority=0;
          head=tail=-1;
          
          for(int i=0;i<5;i++)
          {
               a[i]=0;
          }
      }
      
      int Penqueue(int value, int p)
      {
          if(item<5)
          {
             item++;
             int i=head;
             while(i<=tail&&(p<priority))
                 i=(i+1)%5;
             int temp=i;
             
             for(temp=head;temp<=tail;temp=(temp+1)%5);
             
             a[temp]=value;
             priority=p;
             tail=(tail+1)%5;
             
             return 1;
          }
          return 0;
      }
      
      int Pdequeue(int value, int p)
      {
          if(item==0)
           return 0;
          else
          {         
              item--;
              //priority=p;
              value=a[head];
              head=(head+1)%5;
              
              return 1;
          }
      }
      
      void PPrint()
      {
           for(int i=0;i<5;i++)
           {
               cout<<a[i]<<" ";
           }
      }
};
            
int main()
{
    PriorityQueue *p=new PriorityQueue;
    
    cout<<"Priority Queue."<<endl;
    //p->PPrint();
    
    p->Penqueue(1,0);
    p->Penqueue(2,1);
    p->Pdequeue(2,1);
    p->Penqueue(4,2);
    p->Penqueue(3,3);
    p->Penqueue(5,4);
    //p->Penqueue(6,1);
    //p->Penqueue(7,0);
              
          
   p->PPrint();
   
   system("pause");
   return 0;
}
                 
