/**
 * You are given an array arr[] of positive integers and an integer k, find the number 
 * of subarrays in arr[] where the count of distinct integers is at most k.
 * 
 * Note: A subarray is a contiguous part of an array.
 * 
 * Examples:
 * Input: arr[] = [1, 2, 2, 3], k = 2
 * Output: 9
 * Explanation: Subarrays with at most 2 distinct elements are: [1], [2], [2], [3], 
 * [1, 2], [2, 2], [2, 3], [1, 2, 2] and [2, 2, 3].
 * 
 * Input: arr[] = [1, 1, 1], k = 1
 * Output: 6
 * Explanation: Subarrays with at most 1 distinct element are: [1], [1], [1], [1, 1], 
 * [1, 1] and [1, 1, 1].
 * 
 * Input: arr[] = [1, 2, 1, 1, 3, 3, 4, 2, 1], k = 2
 * Output: 24
 * Explanation: There are 24 subarrays with at most 2 distinct elements.
 */

#include <bits/stdc++.h>
using namespace std;

int countSubarrays(vector<int>& arr, int k) {
    int n = arr.size();
    int count = 0;
    int left = 0, right = 0;
    unordered_map<int, int> mpp;

    while(right < n) {
        mpp[arr[right]]++;
        while(mpp.size() > k) {
            mpp[arr[left]]--;
            if(mpp[arr[left]] == 0)
                mpp.erase(arr[left]);
            left++;
        }
        count += right - left + 1;
        right++;
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

    int cnt = countSubarrays(arr, k);

    cout << cnt << endl;

    return 0;
}