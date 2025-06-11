/**
 * Given the number of rows n. Print the first n rows of Pascal’s triangle.
 * 
 * Example 1:
 * Input Format: N = 5
 * Result: 
 * 1 
 * 1 1 
 * 1 2 1 
 * 1 3 3 1 
 * 1 4 6 4 1    
 * Explanation: There are 5 rows in the output matrix. 
 * Each row is formed using the logic of Pascal’s triangle.
 * 
 * Example 2:
 * Input Format: N = 1
 * Result: 1
 * Explanation: The output matrix has only 1 row.
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow; //To store each row
    ansRow.push_back(ans); //Inserting the 1st element

    for(int col = 1;col<row;col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

int main() {
    int n;
    cout << "Enter the number of rows : ";
    cin >> n;

    vector<vector<int>> triangle;

    //Generating the Pascal Triangle
    for(int row = 1;row<=n;row++) {
        vector<int> temp = generateRow(row);
        triangle.push_back(temp);
    }

    //Printing the Pascal Triangle
    for(auto it : triangle) {
        for(auto ele : it) {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}