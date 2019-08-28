//Elementary Sorting Algorithms
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
      
      void BubbleSort(int a[], int n)
      {
           for(int i=0;i<n-1;i++)
           {
                for(int j=n-1;j>i;j--)
                {
                    if(a[j]<a[j-1])
                    {
                        Swap(&a[j-1],&a[j]);
                    }
                }
           } 
           PrintArray(a);    
      }
      
      void InsertionSort(int a[], int n)
      {
           int min;
           for(int i=1;i<n;i++)
           {
                min = a[i];
                for(int j=i;j>0&&min<a[j-1];j--)
                     a[j]=a[j-1];
                a[i]=min;
           }
           PrintArray(a);
      }
      
      void SelectionSort(int a[], int n)
      {
           int least;
           for(int i=0;i<n-1;i++)
           {
                least=i;
                for(int j=i+1;j<n;j++)
                {
                    if(a[j]<a[least])
                    {
                         least=j;
                    }
                }
                Swap(&a[least],&a[i]);
           }
           PrintArray(a);
      }          
      
};

                      
int main()
{
    Sorting sort;
    
    cout<<"Bubble Sort: "<<endl;
    sort.BubbleSort(arr2,size);
    
    cout<<endl<<"Insertion Sort: "<<endl;
    sort.InsertionSort(arr2,size);
    
    cout<<endl<<"Selection Sort: "<<endl;
    sort.SelectionSort(arr2,size);
    
    getch();
    return 0;
} 
