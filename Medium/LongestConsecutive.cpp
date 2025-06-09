/**
 * You are given an array of ‘N’ integers. You need to find the length of the longest 
 * sequence which contains the consecutive elements.
 * 
 * Example 1:
 * Input: [100, 200, 1, 3, 2, 4]
 * Output: 4
 * Explanation: The longest consecutive subsequence is 1, 2, 3, and 4.
 * 
 * Input: [3, 8, 5, 7, 6]
 * Output: 4
 * Explanation: The longest consecutive subsequence is 5, 6, 7, and 8.
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &arr) {
    int n = arr.size();

    //Base case - If n is zero
    if(n == 0) return 0;
    int longest = 1;

    //Unordered set to store single occurence of elements
    unordered_set<int> st;

    //Storing the array in the set
    for(int i=0;i<n;i++) {
        st.insert(arr[i]);
    }

    //Searching for the first element of the consecutive series
    //and checking whether next exists
    for(auto it : st) {
        if(st.find(it-1) == st.end()) {
            int count = 1;
            int x = it;
            while(st.find(x+1) != st.end()) {
                count++;
                x++;
            }
            longest = max(longest, count);
        }
    }

    return longest;
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

    int longest = longestConsecutive(arr);

    cout << "Length of longest consecutive sequence is : " << longest << endl;

    return 0;
}