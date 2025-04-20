// Given an array, we have to find the largest element in the array.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;//to store the size of the array
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

    //Finding the largest element
    int max = arr[0]; //initializing to the first element

    for(int i=1;i<n;i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }

    cout << "The Largest Element is : " << max;

    return 0;
}