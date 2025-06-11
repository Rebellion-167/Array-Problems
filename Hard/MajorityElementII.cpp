/**
 * Given an array of N integers. Find the elements that appear more than N/3 
 * times in the array. If no such element exists, return an empty vector.
 * 
 * Example 1:
 * Input Format: N = 5, array[] = {1,2,2,3,2}
 * Result: 2
 * Explanation: Here we can see that the Count(1) = 1, Count(2) = 3 and Count(3) = 1.
 * Therefore, the count of 2 is greater than N/3 times. Hence, 2 is the answer.
 * 
 * Example 2:
 * Input Format:  N = 6, array[] = {11,33,33,11,33,11}
 * Result: 11 33
 * Explanation: Here we can see that the Count(11) = 3 and Count(33) = 3. 
 * Therefore, the count of both 11 and 33 is greater than N/3 times. Hence, 11 and 
 * 33 is the answer.
 * 
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> findMajority(vector<int> &arr) {
    int n = arr.size(); //size of the array

    int cnt1 = 0, cnt2 = 0; //counts
    int ele1 = INT_MIN; //element 1
    int ele2 = INT_MIN; //element 2

    //Applying the Extended Boyer Moore's Voting Algorithm:
    for(int i=0;i<n;i++) {
        if(cnt1==0 && ele2 != arr[i]) {
            cnt1 = 1;
            ele1 = arr[i];
        } else if(cnt2==0 && ele1 != arr[i]) {
            cnt2 = 1;
            ele2 = arr[i];
        } 
        else if(ele1 == arr[i]) cnt1++;
        else if(ele2 == arr[i]) cnt2++;
        else {
            cnt1--;
            cnt2--;
        }
    }
    cnt1=0,cnt2=0;

    vector<int> ans; //list of answers
    
    //Manually check if the stored elements in
    //ele1 and ele2 are the majority elements:
    for(int i=0;i<n;i++) {
        if(arr[i] == ele1) cnt1++;
        if(arr[i] == ele2) cnt2++;
    }
    int mini = (int)(n/3) + 1;
    if(cnt1 >= mini) {
        ans.push_back(ele1);
    }
    if(cnt2 >= mini && ele2 != ele1) {
        ans.push_back(ele2);
    }
    sort(ans.begin(), ans.end());
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

    vector<int> ans = findMajority(arr);

    cout << "The required majorities are : ";
    for(auto it : ans) {
        cout << it << " ";
    }
    return 0;
}