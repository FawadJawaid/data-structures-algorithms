#include<iostream>

using namespace std;

class Queue
{
    private:
    int a[5];
    int head,tail;
    int item;
    
    public:
    Queue()
    {
        head=tail=-1;
        item=0;
        
        for(int i=0;i<5;i++)
        {
             a[i]=0;
        }
    }
    
    int enqueue(int value)
    {
        if(item==5)
         return 0;
        else
        {
            item++;
            tail=(tail+1)%5;
            a[tail]=value;
        
            if(item==1)
             head=(head+1)%5;
        
            return 1;
        }
    }
    
    int dequeue(int value)
    {
        if(item==0)
          return 0;
        else
        {
            item--;
            value=a[head];
            head=(head+1)%5;
            
            return 1;
        }
    }
    
    void Print()
    {
         for(int i=0;i<5;i++)
         {
              cout<<a[i]<<" ";
         }
    }
};       
          
int main()
{
    Queue *q=new Queue;
    
    cout<<"Queue."<<endl;
    q->enqueue(1);
    q->enqueue(2);
    q->dequeue(1);
    q->enqueue(3);
    q->enqueue(4);
    q->enqueue(5);
    //q->dequeue(5);
    q->enqueue(6);
    //q->enqueue(7);
    
    q->Print();
    
    system("pause");
    return 0;
}
    
        
    
