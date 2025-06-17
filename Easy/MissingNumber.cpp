/**
    Given an integer N and an array of size N containing N numbers from 1 to N. 
    Find the number(between 1 to N), that is not present in the given array.

    Example 1:
    Input Format: N = 5, array[] = {1,2,4,5}
    Result: 3
    Explanation: In the given array, number 3 is missing. So, 3 is the answer.

    Example 2:
    Input Format: N = 3, array[] = {1,3}
    Result: 2
    Explanation: In the given array, number 2 is missing. So, 2 is the answer.

    Approach Used : XOR Approach

    We will use the two important properties of XOR : 
        1. XOR of two same numbers is always 0 i.e. a ^ a = 0
        2. XOR of a number with 0 will result in the number itself i.e. 0 ^ a = a.
*/

#include <bits/stdc++.h>
using namespace std;

int findMissingNumber(vector<int> &arr, int n) {
    
    int xor1 = 0, xor2 = 0;

    for(int i=0;i<n-1;i++)
    {
        xor2 = xor2 ^ arr[i];               // XOR of array elements
        xor1 = xor1 ^ (i+1);                // XOR upto [1...N-1]
    }
    xor1 = xor1 ^ n;                        // XOR upto [1..N]

    return (xor1 ^ xor2);
    
}

int main()
{
    int n;                                  //user input
    cout << "Enter the number n : ";
    cin >> n;

    vector<int> arr;                       // array to store numbers

    cout << "Enter the elements : ";

    for(int i=1;i<n;i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int missing = findMissingNumber(arr, n);

    cout << "The missing number is : " << missing << endl;

    return 0;
}

/**
 * Time Complexity : O(N) where N=size of the array
 * Space Complexity : O(1)
 */