//Given an array of N integers, left rotate the array by one place.

#include <bits/stdc++.h>
using namespace std;

void leftRotateOne(vector<int> &nums)
{
    int temp = nums[0];
    int n = nums.size();
    for(int i=0;i<n-1;i++)
    {
        nums[i] = nums[i+1];
    }
    nums[n-1] = temp;
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

    cout << "Array before left rotating by one : ";
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    leftRotateOne(arr); //left rotating the array by one

    cout << "Array after left rotating by one : ";
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}

//Time Complexity - O(n) since we iterate over the array once.
//Space Complexity - O(1) as no extra space is used.