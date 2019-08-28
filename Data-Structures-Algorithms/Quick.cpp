#include <iostream>
using namespace std;

void quickSort(int arr[], int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right)  / 2];
 
      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };
 
      /* recursion */
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}
int main ()
{
    int arr[11]={10,8,6,20,4,3,22,1,0,15,16};
    quickSort(arr,0,10);
    for (int i=0; i<11; i++)
    cout <<arr[i]<<endl;
    
    
    system ("pause");
    return 0;
}
