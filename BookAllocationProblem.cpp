#include<iostream>
#include<vector>
using namespace std;


bool isValid(vector<int> &arr , int n , int m , int maxAllocatedPages){
    int student = 1 , pages = 0;
    for(int i=0 ; i<n ; i++){
        if(arr[i] > maxAllocatedPages){
            return false;
        }
        
        if(pages + arr[i] <= maxAllocatedPages){
            pages += arr[i];
        }
        else{
            student++;
            pages = arr[i];
        }
    }
    return student > m ? false : true;
}

int allocateBooks(vector<int> &arr , int n , int m){
    int sum = 0 ;
    for(int i=0 ; i<n ; i++){
        sum += arr[i];
    }

    int st = 0 , end = sum , ans = -1 ;     // range

    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if(isValid (arr, n, m, mid)){    // left
            ans = mid; 
            end = mid - 1;
        }
        else{                          // right
            st = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {2,1,3,4};
    int n = 4 , m = 2 ; 

    cout<<allocateBooks(arr , n , m)<<endl;
    return 0;
}