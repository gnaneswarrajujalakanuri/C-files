//Wavearray
#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void wavearray(int a[],int l){
    for(int i = 0;i<l;i += 2){
        swap(&a[i],&a[i+1]);
    }
}
int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int *arr = malloc(sizeof(int)*n);
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    wavearray(arr,n);
    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
}