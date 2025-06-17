/**
 * There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative 
 * elements. Without altering the relative order of positive and negative elements, 
 * you must return an array of alternately positive and negative values.
 * 
 * Note: Start the array with positive elements.
 * 
 * Example 1:
 * Input: arr[] = {1,2,-4,-5}, N = 4
 * Output: 1 -4 2 -5
 * Explanation: 
 *      Positive elements = 1,2
 *      Negative elements = -4,-5
 * To maintain relative ordering, 1 must occur before 2, and -4 must occur before -5.
 * 
 * Example 2:
 * Input: arr[] = {1,2,-3,-1,-2,-3}, N = 6
 * Output: 1 -3 2 -1 3 -2
 * Explanation: 
 *      Positive elements = 1,2,3
 *      Negative elements = -3,-1,-2
 * To maintain relative ordering, 1 must occur before 2, and 2 must occur before 3.
 * Also, -3 should come before -1, and -1 should come before -2.
 * 
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> alternate(vector<int> &arr) {
    int n = arr.size();
    int posIndex = 0; //Storing the index of positive elements
    int negIndex = 1; //Storing the index of negative elements

    vector<int> res(n, 0); //To store the resultant array

    for(int i=0;i<n;i++) {
        if(arr[i] < 0) {
            res[negIndex] = arr[i];
            negIndex += 2;
        } else {
            res[posIndex] = arr[i];
            posIndex += 2;
        }
    }

    return res;
}

int main() {
    int n;
    cout << "Enter the number of elements :" ;
    cin >> n;

    vector<int> arr;

    cout << "Enter the elements : ";
    for(int i=0;i<n;i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    vector<int> result = alternate(arr);

    cout << "The required array : ";
    for(int i=0;i<n;i++) {
        cout << result[i] << " ";
    }

    return 0;
}

/**
 * Time Complexity : O(N) where N=size of the array
 * Space Complexity : O(N)
 */