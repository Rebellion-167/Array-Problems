/**
 * Given an array that contains only 1 and 0 return the count of 
 * maximum consecutive ones in the array.
 * 
 * Examples:
 * 
 * Example 1:
 * 
 * Input: prices = {1, 1, 0, 1, 1, 1}
 * Output: 3
 * Explanation: There are two consecutive 1’s and three consecutive 1’s in the array 
 * out of which maximum is 3.
 * 
 * Input: prices = {1, 0, 1, 1, 0, 1} 
 * Output: 2
 * Explanation: There are two consecutive 1's in the array. 
 */

#include <bits/stdc++.h>
using namespace std;

int maxOnes(vector<int> &arr)
{
    int count = 0;                              // Temporary count
    int max_count = 0;                          // Max-no-of-consecutive-ones count
    int n = arr.size();

    for(int i=0;i<n;i++)
    {
        if(arr[i] == 1)                        // Checking if element is equal to one
        {
            count++;                           
        }
        else
        {
            count = 0;                          // Setting the temporary count back to zero
        }

        max_count = max(max_count, count);     // Setting the max count to be the highest
    }

    return max_count;                          // Returning the max-no-of-consecutive-ones count
}

int main()
{
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    vector<int> arr;

    cout << "Enter elements into the array : ";
    for(int i=0;i<n;i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int consecutive = maxOnes(arr);

    cout << "The maximum consecutive 1's are : " << consecutive << endl;

    return 0;
}

/**
 * Time Complexity : O(N) where N=size of the array
 * Space Complexity : O(1)
 */