/**
 * Given a non-empty array of integers arr, every element appears twice 
 * except for one. Find that single one.
 * 
 * Example 1:
 * Input Format: arr[] = {2,2,1}
 * Result: 1
 * Explanation: In this array, only the element 1 appear once and so it is the answer.
 * 
 * Example 2:
 * Input Format: arr[] = {4,1,2,1,2}
 * Result: 4
 * Explanation: In this array, only element 4 appear once and the other elements 
 * appear twice. So, 4 is the answer.
 */

#include <bits/stdc++.h>
using namespace std;

int findOnce(vector<int> &arr)
{
    int n = arr.size();
    int xor1 = 0;

    //Performing the XOR of all elements of the array using a loop
    for(int i=0;i<n;i++)
        xor1 = xor1 ^ arr[i];
    //final XOR will be the answer.
    return xor1;
}

int main()
{
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    vector<int> arr;

    cout << "Enter elements in the array : ";
    for(int i=0;i<n;i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int once = findOnce(arr);

    cout << "The number that appears once is " << once;

    return 0;
}