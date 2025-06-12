/**
 * Given an array containing both positive and negative integers, we have to 
 * find the length of the longest subarray with the sum of all elements equal to zero.
 * 
 * Example 1:
 * Input Format: N = 6, array[] = {9, -3, 3, -1, 6, -5}
 * Result: 5
 * Explanation: The following subarrays sum to zero:
 * {-3, 3} , {-1, 6, -5}, {-3, 3, -1, 6, -5}
 * Since we require the length of the longest subarray, our answer is 5!
 * 
 * Example 2:
 * Input Format: N = 8, array[] = {6, -2, 2, -8, 1, 7, 4, -10}
 * Result: 8
 * Subarrays with sum 0 : {-2, 2}, {-8, 1, 7}, {-2, 2, -8, 1, 7}, 
 * {6, -2, 2, -8, 1, 7, 4, -10}
 * Length of longest subarray = 8
 * 
 * Example 3:
 * Input Format: N = 3, array[] = {1, 0, -5}
 * Result: 1
 * Subarray : {0}
 * Length of longest subarray = 1
 * 
 * Example 4:
 * Input Format: N = 5, array[] = {1, 3, -5, 6, -2}
 * Result: 0
 * Subarray: There is no subarray that sums to zero
 */

#include <bits/stdc++.h>
using namespace std;

int longestSumZero(vector<int> &arr) {
    int n = arr.size();

    int prefixSum = 0; //to store the prefix sum
    unordered_map<int,int> mpp; //to store the prefix sum along with its index
    int maxLen = 0;

    for(int i=0;i<n;i++) {
        prefixSum += arr[i];
        if(prefixSum == 0) {
            maxLen = i+1;
        } else {
            if(mpp.find(prefixSum) != mpp.end()) {
                //if prefixSum is present in map, find maxLength
                maxLen = max(maxLen, i - mpp[prefixSum]);
            } else {
                //Adding the prefixSum to the map
                mpp[prefixSum] = i;
            }
        }
    }
    return maxLen;
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

    int length = longestSumZero(arr);

    cout << "The length of longest subarray with sum zero : " << length << endl;

    return 0;
}

/**
 * Time Complexity: O(N), as we are traversing the array only once
 * Space Complexity: O(N), in the worst case we would insert all array elements 
 * prefix sum into our hashmap.
 */