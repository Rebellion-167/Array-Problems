/**
 * Given an array of N integers, your task is to find unique triplets that add up 
 * to give a sum of zero. In short, you need to return an array of all the unique 
 * triplets [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i, and their sum is 
 * equal to zero.
 * 
 * Example 1: 
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Explanation: Out of all possible unique triplets possible, [-1,-1,2] and [-1,0,1] 
 * satisfy the condition of summing up to zero with i!=j!=k
 * 
 * Example 2:
 * Input: nums=[-1,0,1,0]
 * Output: Output: [[-1,0,1],[-1,1,0]]
 * Explanation: Out of all possible unique triplets possible, [-1,0,1] and [-1,1,0] 
 * satisfy the condition of summing up to zero with i!=j!=k.
 * 
 */

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generateTriplet(int n, vector<int> &arr) {
    vector<vector<int>> ans; //list of lists to store the triplets
    sort(arr.begin(), arr.end()); //sorting the array for our convenience
    for(int i=0;i<n;i++) {
        //removing duplicates
        if(i!=0 && arr[i] == arr[i-1]) continue;

        //moving 2 pointers
        int j = i+1;
        int k = n-1;

        while(j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if(sum < 0) {
                j++;
            } else if(sum > 0) {
                k--;
            } else {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                //skipping the duplicates
                while(j < k && arr[j] == arr[j-1]) j++;
                while(j < k && arr[k] == arr[k+1]) k--;
            }
        }
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    vector<int> arr;

    cout << "Enter the elements : ";
    for(int i=0;i<n;i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    vector<vector<int>> triplets; //To store the triplets
    triplets = generateTriplet(n, arr);

    cout << "The triplets are : " << endl;
    for(auto it : triplets) {
        for(auto ele : it) {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}

/**
 * Time Complexity: O(NlogN)+O(N2), where N = size of the array.
 * Reason: The pointer i, is running for approximately N times. And both the 
 * pointers j and k combined can run for approximately N times including the 
 * operation of skipping duplicates. So the total time complexity will be O(N2). 
 * 
 * Space Complexity: O(no. of quadruplets), This space is only used to store the 
 * answer. We are not using any extra space to solve this problem. So, from that 
 * perspective, space complexity can be written as O(1).
 */