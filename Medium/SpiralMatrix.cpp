/**
 * Given a Matrix, print the given matrix in spiral order.
 * 
 * Example 1:
 * Input: Matrix[][] = { { 1, 2, 3, 4 },
 *             	         { 5, 6, 7, 8 },
 *                       { 9, 10, 11, 12 },
 *                       { 13, 14, 15, 16 } }
 * 
 * Output: 1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.
 * Explanation: The output of matrix in spiral form.
 * 
 * Example 2:
 * Input: Matrix[][] = { { 1, 2, 3 },
 *                       { 4, 5, 6 },
 *                       { 7, 8, 9 } }
 *  Output: 1, 2, 3, 6, 9, 8, 7, 4, 5.
 * Explanation: The output of matrix in spiral form.
 * 
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> printSpiral(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    //Initializing pointers to keep track
    //of the matrix
    int top = 0, bottom = n-1;
    int left = 0, right = m-1;

    vector<int> ans; //vector to store the output

    while(top <= bottom && left <= right) {
        for(int i=left;i<=right;i++) {
            ans.push_back(matrix[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++) {
            ans.push_back(matrix[i][right]);
        }
        right--;
        if(top<=bottom) {
            for(int i=right;i>=left;i--) {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if(left<=right) {
            for(int i=bottom;i>=top;i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int main() {
    int n,m;
    cout << "Enter the number of rows and columns : ";
    cin >> n >> m;

    vector<vector<int>> matrix;

    cout << "Enter the elements row-wise : " << endl;
    for(int i=0;i<n;i++) {
        vector<int> vec;
        for(int j=0;j<m;j++) {
            int temp;
            cin >> temp;
            vec.push_back(temp);
        }
        matrix.push_back(vec);
    }

    vector<int> spiral = printSpiral(matrix);

    cout << "The spiral is : " << endl;
    for(int i=0;i<spiral.size();i++) {
        cout << spiral[i] << " ";
    }
    return 0;
}

/**
 * Time Complexity: O(m x n) { Since all the elements are being traversed once 
 * and there are total n x m elements ( m elements in each row and total n rows) 
 * so the time complexity will be O(n x m)}.
 * 
 * Space Complexity: O(n) { Extra Space used for storing traversal in the ans array }.
 */