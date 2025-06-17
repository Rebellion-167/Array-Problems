/**
 * Given an integer array arr, find the contiguous subarray 
 * (containing at least one number) which
 * has the largest sum and returns its sum and prints the subarray.
 * 
 * In some cases, the question might say to consider the sum of the empty subarray 
 * while solving this problem. So, in these cases, before returning the answer we 
 * will compare the maximum subarray sum calculated with 0(i.e. The sum of an empty 
 * subarray is 0). And after that, we will return the maximum one.
 * 
 * Example 1:
 * Input: arr = [-2,1,-3,4,-1,2,1,-5,4] 
 * Output: 6 
 * Explanation: [4,-1,2,1] has the largest sum = 6. 
 * 
 * Examples 2: 
 * Input: arr = [1] 
 * Output: 1 
 * Explanation: Array has only one element and which is giving positive sum of 1. 
 * 
 */

#include <bits/stdc++.h>
using namespace std;

pair<int, pair<int, int>> maxSubarraySum(vector<int> &arr) {
    int n = arr.size();
    int max = INT_MIN; //Storing the minimum possible number
    int sum = 0; //Storing the sum for each subarray
    int start; //Indicating the start of an new subarray

    int arrStart = -1; //Will contain the starting index of the maximum sum subarray
    int arrEnd = -1; //Will contain the ending index of the maximum sum subarray

    //Implementing Kadane's Algorithm
    for(int i=0;i<n;i++) {
        if(sum == 0) start = i;

        sum += arr[i];

        if(sum > max) {
            max = sum;
            arrStart = start;
            arrEnd = i;
        }

        //Crucial part of the algorithm - not carrying any negative sum forward
        if(sum < 0) {
            sum = 0;
        }
    }

    if(max < 0) max = 0;

    return {max, {arrStart, arrEnd}};
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

    pair<int, pair<int, int>> p = maxSubarraySum(arr);

    cout << "The maximum sum from the array is : " << p.first << endl;
    cout << "The subarray containing the maximum sum is : [";
    if(p.first > 0) {
        for(int i=p.second.first;i<=p.second.second;i++) {
            cout << arr[i] << " ";
        }
    } 
    cout << "]";

    return 0;
}

/**
 * Approach : Kadane's Algorithm
 * 
 * The intuition of the algorithm is not to consider the subarray as a part of the 
 * answer if its sum is less than 0. A subarray with a sum less than 0 will always 
 * reduce our answer and so this type of subarray cannot be a part of the subarray 
 * with maximum sum.
 * 
 * Here, we will iterate the given array with a single loop and while iterating we 
 * will add the elements in a sum variable. Now, if at any point the sum becomes less 
 * than 0, we will set the sum as 0 as we are not going to consider any subarray with 
 * a negative sum. Among all the sums calculated, we will consider the maximum one.
 * 
 * Thus we can solve this problem with a single loop.
 * 
 * Time Complexity: O(N), where N = size of the array.
 * Reason: We are using a single loop running N times.
 * 
 * Space Complexity: O(1) as we are not using any extra space.
 */