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