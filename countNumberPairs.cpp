#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int arr[] = {1,3,4,2,5,7,6};
    int n = 7;
    
    int k = 2;   //difference in b/w elements
    
    int slow = 0, fast = 1, count = 0;
    
    sort(arr, arr+n);
    
    while(fast < n){
        int diff = arr[fast] - arr[slow];
        
        if(diff == k){
            count++;
            slow++;
            fast++;
        }
        else if(diff < k) fast++;
        else slow++;
    }
    cout << "No. Of pairs : " << count;
    return 0;
}
