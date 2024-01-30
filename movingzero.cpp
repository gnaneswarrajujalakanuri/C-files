#include<iostream>
using namespace std;

int main(){
    int arr[5] = new int[];
    for(int i=0;i<arr.length();i++){
        cin>>arr[i];
    }
    int noofZeros = 0;
    
    for(int i=0;i<arr.length();i++){
        if(arr[i]==0){
            noofZeros++;
        }
        else
            cout<<arr[i]<<" ";
    }
    for (int i = 0; i < noofZeros; i++)
    {
        /* code */
        cout<<0<<" ";
    }
    
}