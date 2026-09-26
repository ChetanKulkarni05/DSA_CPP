// search element in the array and return the index of target index

#include<iostream>
using namespace std;

int linearSearch(int arr[] , int size , int target){

    for(int i=0; i<size; i++){
        if(arr[i] == target){       //found
            return i;
        }
    }
    return -1;             // not found
}

int main(){
    int arr[] = {4,5,2,6,7,9};
    int size = 6;
    int target = 7;
    
    cout<<"Target " << target <<" at index: "<< linearSearch(arr,size,target)<<endl;
    return 0;
}