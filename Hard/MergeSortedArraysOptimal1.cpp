/**
 * Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing 
 * order. Merge them in sorted order. Modify arr1 so that it contains the first 
 * N elements and modify arr2 so that it contains the last M elements.
 * 
 * Example 1:
 * Input: 
 * n = 4, arr1[] = [1 4 8 10] 
 * m = 5, arr2[] = [2 3 9]
 * 
 * Output: 
 * arr1[] = [1 2 3 4]
 * arr2[] = [8 9 10]
 * 
 * Explanation: After merging the two non-decreasing arrays, we get, 1,2,3,4,8,9,10.
 * 
 * Example2:
 * Input: 
 * n = 4, arr1[] = [1 3 5 7] 
 * m = 5, arr2[] = [0 2 6 8 9]
 * 
 * Output:
 * arr1[] = [0 1 2 3]
 * arr2[] = [5 6 7 8 9]
 * 
 * Explanation: After merging the two non-decreasing arrays, we get, 0 1 2 3 5 6 7 8 9.
 * 
 */

#include <bits/stdc++.h>
using namespace std;

void mergeArrays(long long arr1[], long long arr2[], int n, int m) {
    //2 pointers
    int left = n-1;
    int right = 0;
    
    //Swapping the elements until arr1[left] is
    //smaller than arr2[right]
    while(left >= 0 && right < m) {
        if(arr1[left] > arr2[right]) {
            swap(arr1[left], arr2[right]);
            left--, right++;
        } else {
            break;
        }
    } 

    //Sorting the two arrays individually
    sort(arr1, arr1+n);
    sort(arr2, arr2+m);
}

int main() {
    int n, m;
    cout << "Enter the size of first array : ";
    cin >> n;

    long long arr1[n];
    cout << "Enter the elements in the first array : ";
    for(int i=0;i<n;i++) {
        cin >> arr1[i];
    }

    cout << "Enter the size of the second array : ";
    cin >> m;

    long long arr2[m];
    cout << "Enter the elements in the second array : ";
    for(int i=0;i<m;i++) {
        cin >> arr2[i];
    }

    mergeArrays(arr1, arr2, n, m);

    cout << "The merged arrays are : " << endl;
    cout << "arr1[] = ";
    for(auto it : arr1) {
        cout << it << " ";
    }
    
    cout << "\narr2[] = ";
    for(auto it : arr2) {
        cout << it << " ";
    } 
    cout << endl;

    return 0;
}

/**
 * Time Complexity: O(min(n, m)) + O(n*logn) + O(m*logm), where n and m are the 
 * sizes of the given arrays.
 * Reason: O(min(n, m)) is for swapping the array elements. And O(n*logn) and 
 * O(m*logm) are for sorting the two arrays.
 * 
 * Space Complexity: O(1) as we are not using any extra space.
 */