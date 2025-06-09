/**
 * Given a matrix if an element in the matrix is 0 then you will have to set its 
 * entire column and row to 0 and then return the matrix.
 * 
 * Input: matrix=[[1,1,1],[1,0,1],[1,1,1]]
 * Output: [[1,0,1],[0,0,0],[1,0,1]]
 * Explanation: Since matrix[2][2]=0.Therfore the 2nd column and 2nd row wil 
 * be set to 0.
 * 
 * Input: matrix=[[0,1,2,0],[3,4,5,2],[1,3,1,5]]
 * Output:[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 * Explanation:Since matrix[0][0]=0 and matrix[0][3]=0. Therefore 1st row, 1st column 
 * and 4th column will be set to 0.
 * 
 */

#include <bits/stdc++.h>
using namespace std;

void setMatrix(vector<vector<int>> &matrix, int n, int m) {
    //for column - matrix[0][...]
    //for row - matrix[...][0]
    
    //Traversing the whole matrix and
    //marking 1st row and column respectively
    int col0 = 1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(matrix[i][j] == 0) {
                //marking i-th row:
                matrix[i][0] = 0;
                //marking j-th column:
                if(j != 0) {
                    matrix[0][j] = 0;
                } else {
                    col0 = 0;
                }
            }
        }
    }

    //Marking with 0 from (1,1) to (n-1, m-1)
    for(int i=1;i<n;i++) {
        for(int j=1;j<m;j++) {
            if(matrix[i][j] != 0) {
                //checking for row and column
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
    }

    //Finally marking the 1st col and then 1st row
    if(matrix[0][0] == 0) {
        for(int j=0;j<m;j++) {
            matrix[0][j] = 0;
        }
    }

    if(col0 == 0) {
        for(int i=0;i<n;i++) {
            matrix[i][0] = 0;
        }
    }
}

int main() {
    int n, m;
    cout << "Enter the number of rows and columns : ";
    cin >> n >> m;

    vector<vector<int>> matrix; //To store the matrix

    cout << "Enter the elements row-wise: ";
    for(int i=0;i<n;i++) {
        vector<int> vec; //Taking the input for a row in another vector
        for(int j=0;j<m;j++) {
            int temp;
            cin >> temp;
            vec.push_back(temp);
        }
        matrix.push_back(vec); //Push each row one at at time
    }

    setMatrix(matrix, n, m);

    cout << "The required matrix : ";
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

/**
 * Time Complexity: O(2*(N*M)), where N = no. of rows in the matrix and 
 * M = no. of columns in the matrix.Reason: 
 * In this approach, we are also traversing the entire matrix 2 times and each 
 * traversal is taking O(N*M) time complexity.
 * 
 * Space Complexity: O(1) as we are not using any extra space.
 * 
 */