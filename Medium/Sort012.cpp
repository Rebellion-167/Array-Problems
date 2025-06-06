/**
 * Given an array consisting of only 0s, 1s, and 2s. 
 * Write a program to in-place sort the array without using inbuilt sort functions. 
 * ( Expected: Single pass-O(N) and constant space).
 * 
 * Examples:
 * 
 * Input: nums = [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 * 
 * Input: nums = [2,0,1]
 * Output: [0,1,2]
 * 
 * Input: nums = [0]
 * Output: [0]
 * 
 */

#include <bits/stdc++.h>
using namespace std;

void sortArray(vector<int> &arr)
{
    int low=0, mid=0, high=arr.size()-1; // 3 pointers

    while(mid <= high)
    {
        if(arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } else if(arr[mid] == 1) {
            mid++;
        } else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
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

    sortArray(arr);

    cout << "The array after sorting : ";
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";

    return 0;

}

/**
 * This problem is a variation of the popular Dutch National flag algorithm. 
 * 
 * This algorithm contains 3 pointers i.e. low, mid, and high, and 3 main rules.  
 * The rules are the following:
 * 
 * arr[0….low-1] contains 0. [Extreme left part]
 * arr[low….mid-1] contains 1.
 * arr[high+1….n-1] contains 2. [Extreme right part], n = size of the array
 * The middle part i.e. arr[mid….high] is the unsorted segment. 
 * 
 * Time Complexity: O(N), where N = size of the given array.
 * Reason: We are using a single loop that can run at most N times.
 * 
 * Space Complexity: O(1) as we are not using any extra space.
 */