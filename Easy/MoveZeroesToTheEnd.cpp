//You are given an array of integers, your task is to move all the zeros in the
// array to the end of the array and move non-negative integers to the front by
// maintaining their order.

// Example 1: 
// Input: 1 ,0 ,2 ,3 ,0 ,4 ,0 ,1 
// Output: 1 ,2 ,3 ,4 ,1 ,0 ,0 ,0
// Explanation: All the zeros are moved to the end and non-negative integers are
// moved to front by maintaining order

// Example 2: 
// Input: 1,2,0,1,0,4,0 
// Output: 1,2,1,4,0,0,0 
// Explanation: All the zeros are moved to the end and non-negative integers are 
// moved to front by maintaining order

#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> &arr){
    int j = -1; //Pointer to find the index of zeroes in the array

    //Placing the pointer j on the zero element value
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i] == 0)
        {
            j = i;
            break;
        }
    }

    //Checking whether no zero exists in the array
    if(j==-1) return;

    //Moving the pointers i and j and swapping accordingly
    for(int i=j+1;i<arr.size();i++)
    {
        if(arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    
}

int main()
{
    cout << "Enter elements in the array : ";
    vector<int> arr; //array to store the elements
    int temp;
    
    while(cin >> temp)
        arr.push_back(temp);

    moveZeroes(arr);

    //Printing the resultant array
    for(int i=0;i<arr.size();i++)
        cout << arr[i] << " ";

    return 0;
}
