/**
 * You are given an array arr[] of integers. Your task is to find the maximum sum of 
 * the smallest and second smallest elements across all subarrays (of size >= 2) of 
 * the given array.
 * 
 * Examples :
 * Input: arr[] = [4, 3, 5, 1]
 * Output: 8
 * Explanation: All subarrays with at least 2 elements and find the two smallest 
 * numbers in each:
 * [4, 3] → 3 + 4 = 7
 * [4, 3, 5] → 3 + 4 = 7
 * [4, 3, 5, 1] → 1 + 3 = 4
 * [3, 5] → 3 + 5 = 8
 * [3, 5, 1] → 1 + 3 = 4
 * [5, 1] → 1 + 5 = 6
 * Maximum Score is 8.
 * 
 * Input: arr[] = [1, 2, 3]
 * Output: 5
 * Explanation: All subarray with at least 2 elements and find the two smallest 
 * numbers in each:
 * [1, 2] → 1 + 2 = 3
 * [1, 2, 3] → 1 + 2 = 3
 * [2, 3] → 2 + 3 = 5
 * Maximum Score is 5
 */

#include <bits/stdc++.h>
using namespace std;

int maxScore(vector<int>& arr) {
   int n = arr.size();
   int maxSum = INT_MIN;
   stack<int> st;

   for(int i=0;i<n;i++) {
    while(!st.empty() && arr[i] < st.top()) {
        maxSum = max(maxSum, arr[i] + st.top());
        st.pop();
    }
    if(!st.empty()) {
        maxSum = max(maxSum, arr[i] + st.top());
    }
    st.push(arr[i]);
   }
   return maxSum;
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

    int maxi = maxScore(arr);
    cout << maxi << endl;
    return 0;
}

/**
 * Time Complexity : O(n) since we are iterating over the array
 * Space Complexity : O(n) since we are using a stack
 */