// Given two sorted arrays, arr1, and arr2 of size n and m. 
//Find the union of two sorted arrays.

// The union of two arrays can be defined as the common and distinct elements 
// in the two arrays.NOTE: Elements in the union should be in ascending order.

// Example 1:
// Input:
// n = 5,m = 5.
// arr1[] = {1,2,3,4,5}  
// arr2[] = {2,3,4,4,5}
// Output: {1,2,3,4,5}

// Explanation: 
// Common Elements in arr1 and arr2  are:  2,3,4,5
// Distnict Elements in arr1 are : 1
// Distnict Elemennts in arr2 are : No distinct elements.
// Union of arr1 and arr2 is {1,2,3,4,5} 

// Example 2:
// Input:
// n = 10,m = 7.
// arr1[] = {1,2,3,4,5,6,7,8,9,10}
// arr2[] = {2,3,4,4,5,11,12}
// Output: {1,2,3,4,5,6,7,8,9,10,11,12}
// Explanation: 
// Common Elements in arr1 and arr2  are:  2,3,4,5
// Distnict Elements in arr1 are : 1,6,7,8,9,10
// Distnict Elemennts in arr2 are : 11,12
// Union of arr1 and arr2 is {1,2,3,4,5,6,7,8,9,10,11,12} 

#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(int a[],int b[], int n, int m) {
    int i = 0, j = 0;//pointers to the two arrays
    vector<int> Union; //the Union array
    while(i < n && j < m)
    {
        if(a[i] <= b[j])
        {
            if(Union.size() == 0 || Union.back() != a[i])
                Union.push_back(a[i]);
            i++;
        } else {
            if(Union.size() == 0 || Union.back() != b[j])
                Union.push_back(b[j]);
            j++;
        }
    }

    while(i < n) //If element left in a
    {
        if(Union.back() != a[i])
            Union.push_back(a[i]);
        i++;
    }

    while(j < m) //If element left in b
    {
        if(Union.back() != b[j])
            Union.push_back(b[j]);
        j++;
    }

    return Union;
}

int main()
{
    int n,m;
    cout << "Enter the size of both the arrays : ";
    cin >> n >> m;

    int arr1[n];
    int arr2[m];

    cout << "Enter elements in the first array : ";
    for(int i=0;i<n;i++)
        cin >> arr1[i];
    cout << "Enter elements in the second array : ";
    for(int i=0;i<m;i++)
        cin >> arr2[i];

    vector<int> result = findUnion(arr1, arr2, n, m);

    //Printing the union array
    for(int i=0;i<result.size();i++)
        cout << result[i] << " ";

    return 0;
}