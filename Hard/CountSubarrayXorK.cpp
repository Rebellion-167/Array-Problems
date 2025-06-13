/**
 * Given an array of integers A and an integer B. Find the total number of 
 * subarrays having bitwise XOR of all elements equal to k.
 * 
 * Example 1:
 * Input Format: A = [4, 2, 2, 6, 4] , k = 6
 * Result: 4
 * Explanation: The subarrays having XOR of their elements as 6 are  [4, 2], 
 * [4, 2, 2, 6, 4], [2, 2, 6], [6]
 * Example 2:
 * Input Format: A = [5, 6, 7, 8, 9], k = 5
 * Result: 2
 * Explanation: The subarrays having XOR of their elements as 5 are [5] and 
 * [5, 6, 7, 8, 9]
 */

#include <bits/stdc++.h>
using namespace std;

int countSubarrays(vector<int> &arr, int k) {
    int n = arr.size();
    //Map data structure to store the prefixXor along with count
    unordered_map<int, int> mpp;
    int xr = 0;
    mpp[xr]++; //Adding {0, 1} to the map
    int cnt = 0;//to store the count of the subarrays

    for(int i=0;i<n;i++) {
        xr = xr ^ arr[i];
        int x = xr ^ k; //XOR part to be removed
        cnt += mpp[x];
        mpp[xr]++; //Adding the prefixXors to the map
    }
    return cnt;
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

    int k;
    cout << "Enter the value of k : ";
    cin >> k;

    int count = countSubarrays(arr, k);

    cout << "Number of subarrays with xor " << k << " is : " << count << endl;

    return 0;
}

/**
 * Time Complexity: O(N) or O(N*logN) depending on which map data structure we 
 * are using, where N = size of the array.
 * Reason: For example, if we are using an unordered_map data structure in C++ the 
 * time complexity will be O(N) but if we are using a map data structure, the time 
 * complexity will be O(N*logN). The least complexity will be O(N) as we are using 
 * a loop to traverse the array. Point to remember for unordered_map in the worst 
 * case, the searching time increases to O(N), and hence the overall time complexity 
 * increases to O(N2). 
 * 
 * Space Complexity: O(N) as we are using a map data structure.
 */
