/**
 * Given an array Arr[] of integers, rearrange the numbers of the given array 
 * into the lexicographically next greater permutation of numbers.
 * 
 * If such an arrangement is not possible, it must rearrange to the lowest possible 
 * order (i.e., sorted in ascending order).
 * 
 * Example 1 :
 * Input format: Arr[] = {1,3,2}
 * Output: Arr[] = {2,1,3}
 * Explanation: All permutations of {1,2,3} are {{1,2,3} , {1,3,2}, {2,13} , 
 * {2,3,1} , {3,1,2} , {3,2,1}}. So, the next permutation just after {1,3,2} is {2,1,3}.
 * 
 * Example 2:
 * Input format: Arr[] = {3,2,1}
 * Output: Arr[] = {1,2,3}
 * Explanation: As we see all permutations of {1,2,3}, we find {3,2,1} at the last 
 * position. So, we have to return the topmost permutation.
 * 
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> permutation(vector<int> &arr) {
    int n = arr.size();
    int index = -1; //To store the index where the order is changing

    //Find the break point
    for(int i=n-2;i>=0;i--) {
        if(arr[i] < arr[i+1]) {
            index = i;
            break;
        }
    }

    //If index remains -1, it is the biggest possible permutation.
    //So just reversing the given array to get the lowest one
    if(index == -1) {
        reverse(arr.begin(), arr.end());
        return arr;
    }

    //Find the number from index+1 till the end which is just
    //greater than the index element
    for(int i=n-1;i>index;i--) {
        if(arr[i] > arr[index]) {
            swap(arr[i], arr[index]);
            break;
        }
    }

    //Now, just we will reverse the right half of index
    reverse(arr.begin()+index+1, arr.end());

    return arr;
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

    vector<int> answer = permutation(arr);

    cout << "The next permutation is : ";
    for(auto it : answer) {
        cout << it << " ";
    }

    return 0;
}