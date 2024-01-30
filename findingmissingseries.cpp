//Finding the missing number from the series
#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int *arr = malloc(sizeof(int)*n);
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int largest = arr[0];
    for(int i = 1;i<n;i++){
        if(largest < arr[i])
        largest = arr[i];
    }
    // printf("\nThe largest is %d",largest);
    int total = (largest * (largest+1))/2;
    int sum = 0;
    for(int i = 0;i<n;i++){
        sum += arr[i];
    }
    printf("The missing number is %d",(total - sum));

}