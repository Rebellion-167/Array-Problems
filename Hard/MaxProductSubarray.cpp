/**
 * Given an array that contains both negative and positive integers, 
 * find the maximum product subarray.
 * 
 * Example 1:
 * Input: Nums = [1,2,3,4,5,0]
 * Output: 120
 * Explanation: In the given array, we can see 1×2×3×4×5 gives maximum product value.
 * 
 * Example 2:
 * Input: Nums = [1,2,-3,0,-4,-5]
 * Output: 20
 * Explanation: In the given array, we can see (-4)×(-5) gives maximum product value.
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int findMaxProduct(vector<int>& arr) {
    int n = arr.size();

    int prefix = 1;
    int suffix = 1;
    int maxi = INT_MIN;

    for(int i=0;i<n;i++){
        if(prefix == 0) prefix = 1;
        if(suffix == 0) suffix = 1;

        prefix *= arr[i];
        suffix *= arr[n-i-1];

        maxi = max(maxi, max(prefix, suffix));
    }
    return maxi;
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

    int product = findMaxProduct(arr);

    cout << "The maximum product from the array is : " << product << endl;

    return 0;
}

/**
 * Time Complexity: O(N), N = size of the given array.
 * Reason: We are using a single loop that runs for N times.
 * 
 * Space Complexity: O(1) as No extra data structures are used for computation.
 */