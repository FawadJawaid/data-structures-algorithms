#include <iostream>

using namespace std;

class stack
{
      private:
              
      int a[10];
      int tos;
      
public:      
stack()
{       
    for(int i=0;i<10;i++)
    {         
    a[i]=0;
    }
    tos=-1;
}

int isempty()
{
    if(tos==-1)
      return 1;
    else
      return 0;
}

int isfull()
{
    if(tos==10-1)
      return 1;
    else
      return 0;
}

int push(int value)
{
    if (isfull())
       return 0;
    else{
      a[++tos]=value;
        return 1;
    }
}

int pop(int value)
{
    if(isempty())
       return 0;
    else
    {
        value=a[tos--];
        return 1;
    }
}

void PrintArray()
{
   for(int i=0;i<10;i++)
   {
        cout<<a[i]<<" ";
   }
}
};

int  main()
{
    stack *s=new stack;  
    
    cout<<"Stack"<<endl;
    s->PrintArray();
    
    s->push(1);
    s->push(2);
    cout<<endl<<endl<<"Stack after pushing 1 and 2."<<endl;
    s->PrintArray();
    
    s->pop(2);
    s->push(3);
    cout<<endl<<endl<<"Stack after poping 2 and pushing 3."<<endl;
    s->PrintArray();
    
    cout<<endl;
    
    system("pause");
    return 0;
}   
    
