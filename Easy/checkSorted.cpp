//Given an array of size n, write a program to check if the given array is
//sorted in (ascending / Increasing / Non-decreasing) order or not. If the
//array is sorted then return True, Else return False.

#include <bits/stdc++.h>
using namespace std;

bool checkSort(vector<int> &arr)
{
    bool sort = true;
    int n = arr.size();
    for(int i=n-1;i>0;i--)
    {
        if(arr[i-1] > arr[i])
            return false;
    }

    return true;
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

    bool answer = checkSort(arr);
    if(answer)
        cout << "Array is sorted.";
    else   
        cout << "Array is not sorted.";

    return 0;
}