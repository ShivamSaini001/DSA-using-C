# Quick Sort

```C
  // Time Complexity: best and avg -> O(n logn) | Worst Case -> O(n^2), Space Complexity: O(logn)
  #include<stdio.h>
  
  int partition(int arr[], int l, int h){
          int pivot = arr[l];
          int start = l;
          int end = h;
          while(start < end){
              while(start <=h && arr[start] <= pivot){
                  start++;
              }
  
              while(arr[end] > pivot){
                  end--;
              }
  
              if(start < end){
                  int temp = arr[start];
                  arr[start] = arr[end];
                  arr[end] = temp;
              }
          }
          arr[l] = arr[end];
          arr[end] = pivot;
          return end;
  }
  
  void quickSort(int arr[], int l, int h){
      if(l < h){
          int p = partition(arr, l, h);
          quickSort(arr, l, p-1);
          quickSort(arr, p+1, h);
      }
  }
  
  int main(){
    int n;
    printf("Enter the Size of first Array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i=0;i<n;i++){
      scanf("%d",&arr[i]);
    }
  
    quickSort(arr, 0, n-1);
    
    printf("Sorted array is: ");
    for(int i=0;i<n;i++){
      printf("%d ",arr[i]);
    }
  }

```
