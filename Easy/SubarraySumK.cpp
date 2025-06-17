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
 * Input Format: N = 5, k = 10, array[] = {2,3,5,1,9}
 * Result: 3
 * Explanation: The longest subarray with sum 10 is {2, 3, 5}. And its length is 3.
 */

#include <bits/stdc++.h>
using namespace std;

int longestSubarray(int n, int k, vector<int> &arr)
{
    int sum = arr[0]; // Initializing the sum to the first element of the array
    int i=0,j=0;
    int maxLen = 0;
    while(j<n)
    {
        while(i<j && sum > k)
        {
            sum -= arr[i];
            i++;
        }
        // If sum is equal to k, updating the max length
        if(sum==k)
            maxLen = max(maxLen, j-i+1);    

        // Moving forward the right pointer
        j++;
        if(j < n) sum += arr[j];
    }

    return maxLen;
}

int main()
{
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    vector<int> arr;

    cout << "Enter the elements : ";
    for(int i=0;i<n;i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int k; //To store the sum
    cout << "Enter the value of k : ";
    cin >> k;

    int len = longestSubarray(n,k,arr);

    cout << "The length of the longest subarray is : " << len << endl;

    return 0;
}

/**
 * Time Complexity: O(2*N), where N = size of the given array.
 * Reason: The outer while loop i.e. the right pointer can move up to index 
 * n-1(the last index). Now, the inner while loop i.e. the left pointer can 
 * move up to the right pointer at most. So, every time the inner loop does 
 * not run for n times rather it can run for n times in total. So, the time 
 * complexity will be O(2*N) instead of O(N2).
 * 
 * Space Complexity: O(1) as we are not using any extra space.
 */