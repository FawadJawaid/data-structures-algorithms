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
      
      void QuickSort(int a[],int low,int high)
      {
           int i=low,j=high;
           int pivot = a[low + (high - low) / 2];
           
           //low=i;
          // high=;
           
           while(i<=j)
           {
                while(a[i]<pivot) 
                     i++;
                while (a[j]>pivot) 
                     j--;
                  
                if(i<=j)
                {
                   Swap(&a[i],&a[j]);
                   i++;
                   j--;
                }
           }
           
           if(low < j)  
              QuickSort(a,low,j);
           if(i < high)  
              QuickSort(a,i,high);
           
           PrintArray(a);
      }
      
      void MergeSort(int a[], int low, int high, int n)
      {
           int mid=(high-low)/2;
           int temp[n];
           int i=low,j=mid+1,k=0;
           
           while(i<=mid && j<=high)
           {
                if(a[i]<a[j])
                {
                   temp[k++]=a[i++];
                }
                else
                {
                    temp[k++]=a[j++];
                }
           }
           
           while(i<=mid)  temp[k++]=a[i++];
           while(j<=high) temp[k++]=a[j++];
           
           for(i=0;i<n;i++)
           {
               a[i]=temp[i];
           }
           
           PrintArray(a);
      }
           
           
};

int main()
{
    Sorting sort;
    
    cout<<"Quick Sort: "<<endl;
    sort.QuickSort(arr2,0,10);
    
    cout<<endl<<"Merge Sort: "<<endl;
    sort.MergeSort(arr2,0,10,size);
    
    getch();
    return 0;
}        
