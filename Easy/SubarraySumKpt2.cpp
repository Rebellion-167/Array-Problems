/**
 * Given an array and a sum k, we need to print the length of the longest 
 * subarray that sums to k.
 * 
 * Example 1:
 * Input Format: N = 3, k = 5, array[] = {2,3,5}
 * Result: 2
 * Explanation: The longest subarray with sum 5 is {2, 3}. And its length is 2.
 * 
 * Example 2:
 * Input Format: N = 3, k = 1, array[] = {-1, 1, 1}
 * Result: 3
 * Explanation: The longest subarray with sum 1 is {-1, 1, 1}. And its length is 3.
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int longestSubarrayPosNeg(vector<int> &arr, int k)
{
    int n = arr.size();
    int maxLen = 0;

    vector<int> prefixSum(n,0);  // To store the prefix sums at each indexes
    prefixSum[0] = arr[0];

    unordered_map<int, int> m;

    for(int i=1;i<n;i++)
    {
        prefixSum[i] = prefixSum[i-1] + arr[i]; 
    }

    for(int j=0;j<n;j++)
    {
        if(prefixSum[j] == k)
            maxLen = max(maxLen, j+1);
        
        int val = prefixSum[j] - k;

        if(m.find(val) != m.end())
        {
            int len = j - m[val];
            maxLen = max(maxLen, len);
        }

        if(m.find(prefixSum[j]) == m.end())
            m[prefixSum[j]] = j;
    }

    return maxLen;
}

int main()
{
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    vector<int> arr;

    cout << "Enter elements : ";
    for(int i=0;i<n;i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int k;
    cout << "Enter the value of k : ";
    cin >> k;

    int len = longestSubarrayPosNeg(arr, k);

    cout << "The length of the longest subarray is " << len << endl;

    return 0;
}