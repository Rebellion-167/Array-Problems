/**
 * Given an array of N integers, write a program to return an element that 
 * occurs more than N/2 times in the given array. 
 * You may consider that such an element always exists in the array.
 * 
 * Example 1:
 * Input Format: N = 3, nums[] = {3,2,3}
 * Result: 3
 * Explanation: When we just count the occurrences of each number and compare 
 * with half of the size of the array, you will get 3 for the above solution. 
 * 
 * Example 2:
 * Input Format:  N = 7, nums[] = {2,2,1,1,1,2,2}
 * Result: 2
 * Explanation: After counting the number of times each element appears and comparing 
 * it with half of array size, we get 2 as result.
 * 
 * Example 3:
 * Input Format:  N = 10, nums[] = {4,4,2,4,3,4,4,3,2,4}
 * Result: 4
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &arr) {
    int n = arr.size();
    int cnt = 0; //To keep the count of the element
    int el; // To keep the element

    //Implementing Moore's Voting Algorithm
    for(int i=0;i<n;i++) {
        if(cnt == 0) {
            cnt = 1;
            el = arr[i];
        } else if(arr[i] == el) {
            cnt++;
        } else {
            cnt--;
        }
    }

    //This step is optional if it is said that the array contains a majority element
    int cnt1 = 0;
    for(int i=0;i<n;i++) {
        if(arr[i] == el) cnt1++;
    }

    if(cnt1 > floor(n/2)) return el;

    return -1;
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

    int major = majorityElement(arr);

    cout << "The majority element is : " << major << endl;

    return 0;
}

/**
 * Approach: Moore’s Voting Algorithm:
 * 
 * Intuition:
 * If the array contains a majority element, its occurrence must be greater 
 * than the floor(N/2). Now, we can say that the count of minority elements and 
 * majority elements is equal up to a certain point in the array. So when we traverse 
 * through the array we try to keep track of the count of elements and the element 
 * itself for which we are tracking the count. 
 * 
 * After traversing the whole array, we will check the element stored in the variable. 
 * If the question states that the array must contain a majority element, the stored 
 * element will be that one but if the question does not state so, then we need to check 
 * if the stored element is the majority element or not. If not, then the array does not 
 * contain any majority element.
 * 
 * Approach: 
 * 
 * Initialize 2 variables:
 *      Count –  for tracking the count of element
 *      Element – for which element we are counting
 * 
 * Traverse through the given array.
 * 
 *      If Count is 0 then store the current element of the array as Element.
 *      If the current element and Element are the same increase the Count by 1.
 *      If they are different decrease the Count by 1.
 * 
 * The integer present in Element should be the result we are expecting.
 *  
 * Time Complexity: O(N) + O(N), where N = size of the given array.
 * Reason: The first O(N) is to calculate the count and find the expected 
 * majority element. The second one is to check if the expected element is 
 * the majority one or not.
 * 
 * Note: If the question states that the array must contain a majority element, 
 * in that case, we do not need the second check. Then the time complexity 
 * will boil down to O(N).
 * 
 * Space Complexity: O(1) as we are not using any extra space.
 */