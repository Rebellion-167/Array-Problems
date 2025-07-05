/**
 * Given an array of integers arr, a lucky integer is an integer that has a frequency 
 * in the array equal to its value.
 * Return the largest lucky integer in the array. If there is no lucky integer 
 * return -1.
 * 
 * Example 1:
 * Input: arr = [2,2,3,4]
 * Output: 2
 * Explanation: The only lucky number in the array is 2 because frequency[2] == 2.
 * 
 * Example 2:
 * Input: arr = [1,2,2,3,3,3]
 * Output: 3
 * Explanation: 1, 2 and 3 are all lucky numbers, return the largest of them.
 * 
 * Example 3:
 * Input: arr = [2,2,2,3,3]
 * Output: -1
 * Explanation: There are no lucky numbers in the array.
 */

#include <bits/stdc++.h>
using namespace std;

int findLucky(vector<int>& arr) {
    //Creating an unordered map
    //to store frequencies
    unordered_map<int, int> mpp;
    int n = arr.size();
    int maxi = -1;
    
    //Iterating through the array
    //and storing the frequencies
    for(int i=0;i<n;i++)
        mpp[arr[i]]++;

    //Again iterating the array
    //to find the lucku number
    for(int i=0;i<n;i++) {
        if(mpp[arr[i]] == arr[i])
            maxi = max(maxi, arr[i]);
    }
    return maxi; //if not found
}

int main() {
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    vector<int> arr;

    cout << "Enter the elements : ";
    for(int i=0;i<n;i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int lucky = findLucky(arr);

    cout << lucky << endl;
    return 0;
}