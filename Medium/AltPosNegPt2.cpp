/**
 * There’s an array ‘A’ of size ‘N’ with positive and negative elements (not 
 * necessarily equal). Without altering the relative order of positive and negative
 *  elements, you must return an array of alternately positive and negative values. 
 * The leftover elements should be placed at the very end in the same order as in array A.
 * Note: Start the array with positive elements.
 * 
 * Example 1:
 * Input: arr[] = {1,2,-4,-5,3,4}, N = 6
 * Output: 1 -4 2 -5 3 4
 * Explanation: 
 * Positive elements = 1,2
 * Negative elements = -4,-5
 * To maintain relative ordering, 1 must occur before 2, and -4 must occur before -5.
 * Leftover positive elements are 3 and 4 which are then placed at the end of the array.
 * 
 * Example 2:
 * Input: arr[] = {1,2,-3,-1,-2,-3}, N = 6
 * Output: 1 -3 2 -1 3 -2
 * Explanation: 
 * Positive elements = 1,2
 * Negative elements = -3,-1,-2,-4
 * To maintain relative ordering, 1 must occur before 2.
 * Also, -3 should come before -1, and -1 should come before -2.
 * After alternate ordering, -2 and -4 are left, which would be placed at the end 
 * of the ans array.
 * 
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> alternateMore(vector<int> &arr) {
    int n = arr.size();

    //Declaring two vectors to store the 
    //positive and negative numbers seperately
    vector<int> pos;
    vector<int> neg;

    //Segregrating the array into positive and negative
    for(int i=0;i<n;i++) {
        if(arr[i] >= 0) 
            pos.push_back(arr[i]);
        else
            neg.push_back(arr[i]);
    }

    //If positives are lesser than negatives
    if(pos.size() < neg.size()) {

        //First we will fill the array alternatively
        //with positive and negative numbers
        for(int i=0;i<pos.size();i++) {
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }

        //Filling the remaining negatives at the end
        int index = pos.size()*2;
        for(int i=pos.size();i<neg.size();i++) {
            arr[index] = neg[i];
            index++;
        }
    } 
    
    //If negatives are lesser than positives
    else {

        //Filling the array alternatively
        //with positives and negatives
        for(int i=0;i<neg.size();i++) {
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }

        //Filling the remaining positives at the end
        int index = neg.size()*2;
        for(int i=neg.size();i<pos.size();i++) {
            arr[index] = pos[i];
            index++;
        }
    }

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

    vector<int> result = alternateMore(arr);

    cout << "The required array : ";
    for(int i=0;i<n;i++) {
        cout << result[i] << " ";
    }

    return 0;
}