/**
 * Given an array of N integers, count the inversion of the array (using merge-sort).
 * 
 * What is an inversion of an array? Definition: for all i & j < size of array, if i < j 
 * then you have to find pair (A[i],A[j]) such that A[j] < A[i].
 * 
 * Example 1:
 * Input Format: N = 5, array[] = {1,2,3,4,5}
 * Result: 0
 * Explanation: we have a sorted array and the sorted array has 0 inversions as 
 * for i < j you will never find a pair such that A[j] < A[i]. More clear example: 
 * 2 has index 1 and 5 has index 4 now 1 < 5 but 2 < 5 so this is not an inversion.
 * 
 * Example 2:
 * Input Format: N = 5, array[] = {5,4,3,2,1}
 * Result: 10
 * Explanation: we have a reverse sorted array and we will get the maximum inversions 
 * as for i < j we will always find a pair such that A[j] < A[i]. Example: 5 has index
 * 0 and 3 has index 2 now (5,3) pair is inversion as 0 < 2 and 5 > 3 which will 
 * satisfy out conditions and for reverse sorted array we will get maximum inversions 
 * and that is (n)*(n-1) / 2.For above given array there is 4 + 3 + 2 + 1 = 10 inversions.
 * 
 * Example 3:
 * Input Format: N = 5, array[] = {5,3,2,1,4}
 * Result: 7
 * Explanation: There are 7 pairs (5,1), (5,3), (5,2), (5,4),(3,2), (3,1), (2,1) and 
 * we have left 2 pairs (2,4) and (1,4) as both are not satisfy our condition. 
 */

#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp; // temporary array to store the sorted one

    // using pointers
    int left = low;
    int right = mid + 1;

    int cnt = 0; //To count the number of pairs

    // Checking whether the arrays are exhausted
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            cnt += (mid - left + 1);
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Adding left-overs
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // Adding values back to the original array
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low]; //[i-low] since low is not always 0
    }

    return cnt; //Returning the number of pairs
}
int mergeSort(vector<int> &arr, int low, int high)
{
    int cnt = 0;
    // base case
    if (low == high)
        return cnt;

    int mid = (low + high) / 2;

    // Dividing the array into two halves
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);

    // Merging the two halves after sorting
    cnt += merge(arr, low, mid, high);

    return cnt;
}

int numberOfInversions(vector<int>& arr, int n) {
    //Counting the number of pairs
    return mergeSort(arr, 0, n-1);
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

    int num = numberOfInversions(arr, n);

    cout << "The number of inversions are : " << num << endl;

    return 0;
}

/**
 * Time Complexity: O(N*logN), where N = size of the given array.
 * Reason: We are not changing the merge sort algorithm except by adding a 
 * variable to it. So, the time complexity is as same as the merge sort.
 * 
 * Space Complexity: O(N), as in the merge sort We use a temporary array to store 
 * elements in sorted order.
 */
