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

/**
 * Time Complexity: O(2*N) { The worst case complexity is O(2*N) which is a 
 * combination of O(N) of traversing the array to segregate into neg and pos 
 * array and O(N) for adding the elements alternatively to the main array}.
 * 
 * Explanation: The second O(N) is a combination of O(min(pos, neg)) + 
 * O(leftover elements). There can be two cases: when only positive or only 
 * negative elements are present, O(min(pos, neg)) + O(leftover) = O(0) + O(N), 
 * and when equal no. of positive and negative elements are present, O(min(pos, neg)) 
 * + O(leftover) = O(N/2) + O(0). So, from these two cases, we can say the 
 * worst-case time complexity is O(N) for the second part, and by adding the first 
 * part we get the total complexity of O(2*N).
 * 
 * Space Complexity:  O(N/2 + N/2) = O(N) { N/2 space required for each of the positive and negative element arrays, where N = size of the array A}.
 */