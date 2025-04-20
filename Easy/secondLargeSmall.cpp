// Given an array, find the second smallest and second largest element in the array.
// Print ‘-1’ in the event that either of them doesn’t exist.

#include <bits/stdc++.h>
using namespace std;

int secondSmallest(vector<int> &arr)
{
    if(arr.size() < 2)
        return -1;
    int small = INT_MAX;
    int second_small = INT_MAX;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < small)
        {
            second_small = small;
            small = arr[i];
        }
        else if(arr[i] < second_small && arr[i] != small)
        {
            second_small = arr[i];
        }
    }
    return second_small;
}

int secondLargest(vector<int> &arr)
{
    if(arr.size() < 2)
        return -1;

    int large = INT_MIN;
    int second_large = INT_MIN;

    for(int i=0;i<arr.size();i++)
    {
        if(arr[i] > large)
        {
            second_large = large;
            large = arr[i];
        }
        else if(arr[i] > second_large && arr[i] != large)
        {
            second_large = arr[i];
        }
    }
    return second_large;
}

int main()
{
    int n;//to store the number of elements
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

    int second_small = secondSmallest(arr);
    int second_large = secondLargest(arr);

    cout << "The second smallest number is " << second_small << endl;
    cout << "The second largest number is " << second_large;

    return 0;
}