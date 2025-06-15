/**
 * You are given a read-only array of N integers with values also in the range 
 * [1, N] both inclusive. Each integer appears exactly once except A which appears 
 * twice and B which is missing. The task is to find the repeating and missing 
 * numbers A and B where A repeats twice and B is missing.
 * 
 * Example 1:
 * Input Format:  array[] = {3,1,2,5,3}
 * Result: {3,4}
 * Explanation: A = 3 , B = 4 
 * Since 3 is appearing twice and 4 is missing
 * 
 * Example 2:
 * Input Format: array[] = {3,1,2,5,4,6,7,5}
 * Result: {5,8}
 * Explanation: A = 5 , B = 8 
 * Since 5 is appearing twice and 8 is missing
 * 
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeating(vector<int>& arr) {
    int n = arr.size();
    int xr = 0;
    
    //Finding the XOR of all elements
    for(int i=0;i<n;i++) {
        xr = xr ^ arr[i];
        xr = xr ^ (i+1);
    }

    //Finding the differentiating bit
    int number = (xr & ~(xr - 1));

    //Grouping the numbers
    int zero = 0;
    int one = 0;
    for(int i=0;i<n;i++) {
        //part of 1 group
        if((arr[i] & number) != 0) {
            one = one ^ arr[i];
        }
        //part of 0 group
        else {
            zero = zero ^ arr[i];
        }
    }

    for(int i=1;i<=n;i++) {
        //part of 1 group
        if((i & number) != 0) {
            one = one ^ i;
        }
        //part of 0 group
        else {
            zero = zero ^ i;
        }
    }

    //Identifying the numbers
    int cnt = 0;
    for(int i=0;i<n;i++) {
        if(arr[i] == one)
            cnt++;
    }
    if(cnt==2) return {one, zero};
    else return {zero, one};
}

int main() {
    int n;
    cout << "Enter the size : ";
    cin >> n;

    vector<int> arr;

    cout << "Enter the elements : ";
    for(int i=0;i<n;i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    vector<int> nums = findMissingRepeating(arr);

    cout << "The repeating number is : " << nums[0] << endl;
    cout << "The missing number is : " << nums[1] << endl;

    return 0;
}