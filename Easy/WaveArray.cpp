/**
 * Given a sorted array arr[] of distinct integers. 
 * Sort the array into a wave-like array(In Place). 
 * In other words, arrange the elements into a sequence such that 
 * arr[1] >= arr[2] <= arr[3] >= arr[4] <= arr[5].....
 * 
 * If there are multiple solutions, find the lexicographically smallest one.
 * 
 * Note: The given array is sorted in ascending order, and you don't need to return anything to change the original array.
 */

#include <bits/stdc++.h>
using namespace std;

void generateWaveArray(vector<int> &arr)
{
    int n = arr.size();

    for(int i=0;i<n-1;i+=2)
    {
        swap(arr[i], arr[i+1]);
    }
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

    generateWaveArray(arr);

    cout << "The Wave array is : ";
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    
    return 0;
}