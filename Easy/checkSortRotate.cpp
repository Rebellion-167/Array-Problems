// Given an array nums, return true if the array was originally sorted in
// non-decreasing order, then rotated some number of positions (including zero).
// Otherwise, return false.

// There may be duplicates in the original array.

// Note: An array A rotated by x positions results in an array B of the same
// length such that B[i] == A[(i+x) % A.length] for every valid index i.

#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;

    //Checking if the array is non-descending
    for(int i=1;i<n;i++)
    {
        if(nums[i-1] > nums[i])
            count++;
    }

    //Checking if the last element is greater than the first element
    if(nums[n-1] > nums[0])
        count++;
    
    //If the count of violations is less than or equal to 1, return true
    return count <= 1;
}

int main()
{
    int n; //to store the number of elements
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

    bool answer = check(arr);

    if(answer)
        cout << "true";
    else
        cout << "false";

    return 0;
}