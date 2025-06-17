/**
 * Given an array of integers and an integer k, return the total number of 
 * subarrays whose sum equals k.
 * 
 * Example 1:
 * Input Format: N = 4, array[] = {3, 1, 2, 4}, k = 6
 * Result: 2
 * Explanation: The subarrays that sum up to 6 are [3, 1, 2] and [2, 4].
 * 
 * Example 2:
 * Input Format: N = 3, array[] = {1,2,3}, k = 3
 * Result: 2
 * Explanation: The subarrays that sum up to 3 are [1, 2], and [3].
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int countSubarrays(vector<int> &arr, int k) {
    int n = arr.size();

    //Unordered map to store the prefix sum and its count;
    unordered_map<int, int> mpp;
    mpp[0] = 1; //Setting 0 in the map

    int prefixSum = 0, count = 0;

    for(int i=0;i<n;i++) {
        //adding current element to prefix sum
        prefixSum += arr[i];
        //calculating x - k
        int rem = prefixSum - k;
        //adding the number of subarrays to be removed
        count += mpp[rem];
        //updating the count of prefix sum in the map
        mpp[prefixSum] += 1;
    }
    return count;
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

    int k;
    cout << "Enter the value of k : ";
    cin >> k;

    int num = countSubarrays(arr, k);

    cout << "The number of subarrays whose sum is " << k << " is : " << num;

    return 0;
}

/**
 * Time Complexity: O(N) or O(N*logN) depending on which map data structure 
 * we are using, where N = size of the array.
 * Reason: For example, if we are using an unordered_map data structure in C++ 
 * the time complexity will be O(N) but if we are using a map data structure, 
 * the time complexity will be O(N*logN). The least complexity will be O(N) as 
 * we are using a loop to traverse the array.
 * 
 * Space Complexity: O(N) as we are using a map data structure.
 */