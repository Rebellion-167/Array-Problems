/**
 * You are given an array of prices where prices[i] is the price of a given stock on 
 * an ith day.
 * 
 * You want to maximize your profit by choosing a single day to buy one stock and 
 * choosing a different day in the future to sell that stock. Return the maximum profit 
 * you can achieve from this transaction. If you cannot achieve any profit, return 0.
 * 
 * Example 1:
 * Input: prices = [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
 * 
 * Note: That buying on day 2 and selling on day 1 is not allowed because you must 
 * buy before you sell.
 * 
 * Example 2:
 * Input: prices = [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transactions are done and the max profit = 0.
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &arr) {
    int buy = arr[0]; //Let's assume I'm buying on the first day
    int profit = 0;
    int n = arr.size();

    for(int i=1;i<n;i++) {
        int cost = arr[i] - buy; // Calculating the profit for my transaction
        profit = max(profit, cost); //Finding the maximum profit
        buy = min(buy, arr[i]); //Checking to see whether current buying price is less
    }
    
    return profit;
}

int main() {
    int n;
    cout << "Enter the number of days : ";
    cin >> n;

    vector<int> arr;

    cout << "Enter the price of the stock on each day : ";
    for(int i=0;i<n;i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int maxPro = maxProfit(arr);

    cout << "The maximum profit is : " << maxPro;

    return 0;
}

/**
 * Time Complexity : O(N) where N=size of the array
 * 
 * Space Complexity: O(1)
 */