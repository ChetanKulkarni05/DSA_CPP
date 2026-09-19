#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int> &arr, int n, int m, int maxAllocatedTime){
    int painters = 1 , time = 0;
    for(int i=0; i<n; i++){
        if(time + arr[i] <= maxAllocatedTime){
            time += arr[i];
        }
        else{
            painters++;
            time = arr[i];
        }
    }
    return painters <= m ? true : false;
}

int minTimeToFind(vector<int> &arr, int n, int m){
    int sum = 0 , maxVal = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
        maxVal = max(maxVal , arr[i]);
    }
    
    int st = maxVal , end = sum , ans = 0;

    while (st <= end)
    {
        int mid = st + (end - st) / 2 ;
        if(isPossible(arr, n, m, mid)){   // left
            ans = mid;
            end = mid - 1;
        }
        else{                             // right
            st = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {40,30,10,20};
    int n = 4 , m = 2 ;

    cout<<minTimeToFind(arr,n,m)<<endl;
    return 0;
}