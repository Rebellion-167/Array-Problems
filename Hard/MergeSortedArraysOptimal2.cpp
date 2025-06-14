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

void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2)
{
    if (arr1[ind1] > arr2[ind2])
    {
        swap(arr1[ind1], arr2[ind2]);
    }
}
void mergeArrays(long long arr1[], long long arr2[], int n, int m)
{
    // Length of the imaginary single array
    int len = n + m;

    // Initial Gap
    int gap = (len / 2) + (len % 2); // len%2 acts as the ceil operator

    while (gap > 0)
    {
        // 2 pointers
        int left = 0;
        int right = left + gap;
        while (right < len)
        {
            // arr1 and arr2
            if (left < n && right >= n)
            {
                swapIfGreater(arr1, arr2, left, right - n);
            }
            // arr2 and arr2
            else if (left >= n)
            {
                swapIfGreater(arr2, arr2, left - n, right - n);
            }
            // arr1 and arr1
            else
            {
                swapIfGreater(arr1, arr1, left, right);
            }
            left++, right++;
        }
        // Breaking if iteration with gap=1 is completed
        if (gap == 1)
            break;

        // Otherwise updating gap
        gap = (gap / 2) + (gap % 2);
    }
}

int main()
{
    int n, m;
    cout << "Enter the size of first array : ";
    cin >> n;

    long long arr1[n];
    cout << "Enter the elements in the first array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter the size of the second array : ";
    cin >> m;

    long long arr2[m];
    cout << "Enter the elements in the second array : ";
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    mergeArrays(arr1, arr2, n, m);

    cout << "The merged arrays are : " << endl;
    cout << "arr1[] = ";
    for (auto it : arr1)
    {
        cout << it << " ";
    }

    cout << "\narr2[] = ";
    for (auto it : arr2)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}

/**
 * Time Complexity: O((n+m)*log(n+m)), where n and m are the sizes of the 
 * given arrays.
 * Reason: The gap is ranging from n+m to 1 and every time the gap gets divided 
 * by 2. So, the time complexity of the outer loop will be O(log(n+m)). Now, for 
 * each value of the gap, the inner loop can at most run for (n+m) times. So, the 
 * time complexity of the inner loop will be O(n+m). So, the overall time complexity 
 * will be O((n+m)*log(n+m)).
 * 
 * Space Complexity: O(1) as we are not using any extra space.
 */