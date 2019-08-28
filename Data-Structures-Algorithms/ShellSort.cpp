//Shell Sort Algorithm
#include<iostream>
#include<conio.h>

using namespace std;

static const int size = 11;
int arr1[size]={12,24,17,34,6,10,6,3,8,9,1};
int arr2[size]={10,8,6,20,4,3,22,1,0,15,16};

class Sorting
{
      public:
      void PrintArray(int input[])
      {
           for(int i=0;i<size;i++)
             cout<<input[i]<<" ";
           cout<<endl;
      }
      
      void Swap(int *i, int *j) 
      {
           int tmp;
           tmp=*i;
           *i=*j;
           *j=tmp;
      }
       
      void ShellSort(int a[], int n)
      {
           int i,j,k,h,NoofGaps,inc[n],min,temp;
           
           for(i=0,NoofGaps=0,h=1;h<n;i++)
           {
               NoofGaps=i;
               inc[i]=h;
               h=3*h+1;
           }
           PrintArray(a);
           
           for(;NoofGaps>=0;NoofGaps--)
           {
               h=inc[NoofGaps];
               cout<<"Gap: "<<h<<endl;
               for(k=h;k<2*h;k++)
               {
                   for(i=k;i<n;i+=h)
                   {
                      min=a[i];
                      for(j=i;j-h>=0&&min<a[j-h];j-=h)
                         a[j]=a[j-h];
                      a[j]=min;
                      PrintArray(a);
                   }
               }
           }
      }
      
};
                      
int main()
{
    Sorting sort;
    
    sort.ShellSort(arr2,size);
    
    getch();
    return 0;
}           
           
