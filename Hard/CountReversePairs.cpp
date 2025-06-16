/**
 * Given an array of numbers, you need to return the count of reverse pairs. 
 * Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j].
 * 
 * Example 1:
 * Input: N = 5, array[] = {1,3,2,3,1)
 * Output: 2 
 * Explanation: The pairs are (3, 1) and (3, 1) as from both the pairs the 
 * condition arr[i] > 2*arr[j] is satisfied.
 * 
 * Example 2:
 * Input: N = 4, array[] = {3,2,1,4}
 * Output: 1
 * Explanation: There is only 1 pair  ( 3 , 1 ) that satisfy the condition 
 * arr[i] > 2*arr[j].
 * 
 */

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp; // temporary array to store the sorted one

    // using pointers
    int left = low;
    int right = mid + 1;

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
}

int countPairs(vector<int>& arr, int low, int mid, int high) {
    int right = mid + 1;
    int cnt = 0;
    for(int i=low;i<=mid;i++) {
        while(right <= high && arr[i] > 2*arr[right]) {
            right++;
        }
        cnt += right - (mid+1);
    }
    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high)
{
    // base case
    int cnt = 0;
    if (low == high)
        return cnt;

    int mid = (low + high) / 2;
    // Dividing the array into two halves
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);

    //Implementing our counting function
    cnt += countPairs(arr, low, mid, high);
    // Merging the two halves after sorting
    merge(arr, low, mid, high);
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

    int count = mergeSort(arr, 0, n-1);

    cout << "The number of reverse pairs are : " << count << endl;

    return 0;
}

/**
 * Time Complexity: O(2N*logN), where N = size of the given array.
 * Reason: Inside the mergeSort() we call merge() and countPairs() except 
 * mergeSort() itself. Now, inside the function countPairs(), though we are 
 * running a nested loop, we are actually iterating the left half once and 
 * the right half once in total. That is why, the time complexity is O(N). 
 * And the merge() function also takes O(N). The mergeSort() takes O(logN) 
 * time complexity. Therefore, the overall time complexity will be O(logN * (N+N)) 
 * = O(2N*logN).
 * 
 * Space Complexity: O(N), as in the merge sort We use a temporary array to 
 * store elements in sorted order.
 */