/**
 * Given an unsorted array arr containing both positive and negative numbers. 
 * Your task is to rearrange the array and convert it into an array of alternate 
 * positive and negative numbers without changing the relative order.
 * 
 * Note:
 * - Resulting array should start with a positive integer 
 *      (0 will also be considered as a positive integer).
 * - If any of the positive or negative integers are exhausted, 
 *      then add the remaining integers in the answer as it is by maintaining the 
 *      relative order.
 * - The array may or may not have the equal number of positive and negative integers.
 * 
 * Examples:
 * Input: arr[] = [9, 4, -2, -1, 5, 0, -5, -3, 2]
 * Output: [9, -2, 4, -1, 5, -5, 0, -3, 2]
 * Explanation: The positive numbers are [9, 4, 5, 0, 2] and the 
 * negative integers are [-2, -1, -5, -3]. Since, we need to start 
 * with the positive integer first and then negative integer and so 
 * on (by maintaining the relative order as well), hence we will take
 *  9 from the positive set of elements and then -2 after that 4 and 
 * then -1 and so on.
 * 
 * Input: arr[] = [-5, -2, 5, 2, 4, 7, 1, 8, 0, -8]
 * Output: [5, -5, 2, -2, 4, -8, 7, 1, 8, 0]
 * Explanation : The positive numbers are [5, 2, 4, 7, 1, 8, 0] 
 * and the negative integers are [-5,-2,-8]. According to the given conditions 
 * we will start from the positive integer 5 and then -5 and so on. 
 * After reaching -8 there are no negative elements left, so according 
 * to the given rule, we will add the remaining elements (in this case 
 * positive elements are remaining) as it in by maintaining the relative order.
 * 
 * Input: arr[] = [9, 5, -2, -1, 5, 0, -5, -3, 2]
 * Output: [9, -2, 5, -1, 5, -5, 0, -3, 2]
 * Explanation: The positive numbers are [9, 5, 5, 0, 2] and the 
 * negative integers are [-2, -1, -5, -3]. Since, we need to start 
 * with the positive integer first and then negative integer and so on 
 * (by maintaining the relative order as well), hence we will take 9 from 
 * the positive set of elements and then -2 after that 5 and then -1 and so on.
 */

#include <bits/stdc++.h>
using namespace std;

void rearrange(vector<int> &arr)
{
    int n = arr.size();

    vector<int> positive;   // To store the positive numbers
    vector<int> negative;   // To store the negative numbers

    for(int i=0;i<n;i++)
    {
        if(arr[i] >= 0)
            positive.push_back(arr[i]);
        else
            negative.push_back(arr[i]);
    }

    //Taking one from both arrays and putting it into the resultant array
    int i=0, j=0, k=0;
    while(i<n)
    {
        if(j<positive.size())
            arr[i++] = positive[j++];
        if(k<negative.size())
            arr[i++] = negative[k++];
    } 
}

int main()
{
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    vector<int> arr;

    cout << "Enter the elements : ";
    for(int i=0;i<n;i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    rearrange(arr);

    cout << "The resultant array is : ";
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";

    return 0;
}

/**
 * Time Complexity : O(N) where N = size of the array
 * Reason : Splitting the array into positives and negatives: O(n). Merging them back alternately: O(n)
 * Total: O(n)
 * 
 * Space Complexity : O(N)
 * Reason : Extra Space for positive and negative vector.
 */