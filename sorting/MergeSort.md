# Merge Sort

```C
  // Time Complexity: O(n logn), Space Complexity: O(n)
  #include<stdio.h>
  
  void merge(int arr[], int mid,int l,int h){
    int i=l; 
    int j=mid+1;
    int k=0;
    int n = h-l+1;
    int result[n];
      
    while(i<=mid && j <= h){
      if(arr[i] <= arr[j]){
        result[k++]=arr[i++];
      }
      else{
        result[k++]=arr[j++];
      }
    }
    while(j <= h){
      result[k++]=arr[j++];
    }
    while(i <= mid){
      result[k++]=arr[i++];
    }
  
    k = 0;
    while(k < n){
      arr[l+k]=result[k];
      k++;
    }
  }
  
  void mergeSort(int arr[], int l, int h){
    if(l < h){
      int mid=(l+h)/2;
      mergeSort(arr, l, mid);  // Sort left half
      mergeSort(arr, mid+1, h);  // Sort right half
      merge(arr, mid, l, h);  // Merge Both Sorted halfs
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
  
    mergeSort(arr, 0, n-1);
    printf("Sorted array is: ");
    for(int i=0;i<n;i++){
      printf("%d ",arr[i]);
    }
  }
```
