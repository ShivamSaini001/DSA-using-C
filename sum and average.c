#include<stdio.h>
#include<stdlib.h>

// Write a C program to enter n elements of array and find sum and avaerage using dynamic array.
void calSumAvg(int *arr, int size){
    int sum = 0;
    float avg;
    for(int i = 0; i < size; i++){
        sum += *(arr+i);
    }
    printf("\nThe sum is: %d", sum);
    avg= (float)sum/size;
    printf("\nThe average is: %.2f", avg);
}

// Reverse the array in dynamic array.
void reverseArray(int *arr, int size){
    int temp;
    for(int i = 0; i < size/2; i++){
        temp = *(arr + i);
        *(arr + i) = *(arr + size - 1 - i);
        *(arr + size - 1 - i) = temp;
    }

    printf("\nReversed array is: ");
    for(int i = 0; i < size; i++){
        printf("%d ", *(arr + i));
    }
}

// Check the sequence of elements is in AP or not using dynamic array.
void checkAP(int *arr, int size){
    int a, b, c, flag = 1;
    a = *(arr);
    b= *(arr + 1);
    c= *(arr + 2);
    int cd = (b - a) < (c - b) ? (b - a) : (c - b);

    // nth term = a+(n-1)d;
    for(int i = 0; i < size; i++){
        if(a+(i*cd) != *(arr + i)){
            printf("\nGiven series is not in AP! ");
            flag = 0;
            break;
        }
    }
    if(flag){
        printf("\nGiven series is in AP! ");
    }
}

int main(){
    int size, *arr;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    arr = (int*) malloc(sizeof(int) * size);
    printf("Enter the elements of the array: ");
    for(int i = 0; i < size; i++){
        scanf("%d", (arr+i));
    }

    calSumAvg(arr, size);
    reverseArray(arr, size);
    checkAP(arr, size);

    return 0;
}

