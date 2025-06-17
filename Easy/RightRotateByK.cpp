//Given an integer array nums, rotate the array to the right by k steps, where k
// is non-negative.

#include <bits/stdc++.h>
using namespace std;

void rightRotate(vector<int> &nums, int k) {
    int n = nums.size();
    k = k % n; // Effective rotations

    // Reverse the entire array
    reverse(nums.begin(), nums.end());

    // Reverse the first k elements
    reverse(nums.begin(), nums.begin() + k);

    // Reverse the remaining n - k elements
    reverse(nums.begin() + k, nums.end());
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

    int k;//to store the number of steps of rotation

    cout << "Enter the number of rotations : ";
    cin >> k;

    //Printing the array before rotation
    cout << "Array before right rotation : ";
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    //Calling the function to right rotate the array by k steps
    rightRotate(arr,k);

    //Printing the resultant array

    cout << "Array after right rotating by " << k << " steps : ";
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}

/**
 * Time Complexity : O(N) where N = size of the array
 * Reason : Each reverse operation is O(N)
 * 
 * Space Complexity: O(1)
 */