/**
 * Given an array, print all the elements which are leaders. A Leader is an element 
 * that is greater than all of the elements on its right side in the array.
 * 
 * Example 1:
 * Input: arr = [4, 7, 1, 0]
 * Output: 7 1 0
 * Explanation:
 * Rightmost element is always a leader. 7 and 1 are greater than the elements in 
 * their right side.
 * 
 * Example 2:
 * Input: arr = [10, 22, 12, 3, 0, 6]
 * Output: 22 12 6
 * Explanation: 
 * 6 is a leader. In addition to that, 12 is greater than all the elements in its 
 * right side (3, 0, 6), also 22 is greater than 12, 3, 0, 6.
 * 
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> findLeaders(vector<int> &arr) {
    int n = arr.size();
    int max = arr[n-1];

    vector<int> ans; //To store the leaders
    //Last element of an array is always a leader
    ans.emplace(ans.begin(), arr[n-1]);

    for(int i=n-2;i>=0;i--) {
        if(arr[i] > max) {
            max = arr[i];
            ans.emplace(ans.begin(), arr[i]);
        }
    }

    return ans;
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

    vector<int> result = findLeaders(arr);
    
    cout << "The leaders are : ";
    for(auto it : result) {
        cout << it << " ";
    }

    return 0;
}

/**
 * Time Complexity : O(N) where N=size of the array
 * Space Complexity : O(N)
 */