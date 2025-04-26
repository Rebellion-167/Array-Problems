// //Given an integer array sorted in non-decreasing order, remove the
// duplicates in place such that each unique element appears only once. The
// relative order of the elements should be kept the same.

// If there are k elements after removing the duplicates, then the first k
// elements of the array should hold the final result. It does not matter what
// you leave beyond the first k elements.


#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &arr)
{
    int n = arr.size();
    int i = 0;
    for(int j=1;j<n;j++)
    {
        if(arr[i] != arr[j]) {
            i++;
            arr[i] = arr[j];
        }
    }
    return i+1;
}

int main()
{
    int n; //to store the number of elements
    cout << "Enter the value of n : ";
    cin >> n;

    vector<int> arr;

    cout << "Enter elements in the array : ";

    for(int i=0;i<n;i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int k = removeDuplicates(arr);

    cout << "Array after removing duplicates : ";
    for(int i=0;i<k;i++)
        cout << arr[i] << " ";

    return 0;
}