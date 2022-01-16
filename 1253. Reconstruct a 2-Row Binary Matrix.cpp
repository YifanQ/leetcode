1253. Reconstruct a 2-Row Binary Matrix

User Accepted:2029
User Tried:2364
Total Accepted:2081
Total Submissions:6207
Difficulty:Medium

Given the following details of a matrix with n columns and 2 rows :

The matrix is a binary matrix, which means each element in the matrix can be 0 or 1.
The sum of elements of the 0-th(upper) row is given as upper.
The sum of elements of the 1-st(lower) row is given as lower.
The sum of elements in the i-th column(0-indexed) is colsum[i], where colsum is given as an integer array with length n.
Your task is to reconstruct the matrix with upper, lower and colsum.

Return it as a 2-D integer array.

If there are more than one valid solution, any of them will be accepted.

If no valid solution exists, return an empty 2-D array.



Example 1:

Input: upper = 2, lower = 1, colsum = [1,1,1]
Output: [[1,1,0],[0,0,1]]
Explanation: [[1,0,1],[0,1,0]], and [[0,1,1],[1,0,0]] are also correct answers.

Example 2:

Input: upper = 2, lower = 3, colsum = [2,2,1,1]
Output: []

Example 3:

Input: upper = 5, lower = 5, colsum = [2,1,2,0,1,0,1,2,0,1]
Output: [[1,1,1,0,1,0,0,1,0,0],[1,0,1,0,0,0,1,1,0,1]]


class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int col_num = colsum.size();
        vector<int> row1(col_num, -1), row2(col_num, -1);
        vector<vector<int>> ans;
        for(int i=0; i<col_num; ++i) {
            if(colsum[i] == 0) {
                row1[i] = row2[i] = 0;
            }
            if(colsum[i] == 2) {
                row1[i] = row2[i] = 1;
                upper--;
                lower--;
            }
        }
        if(upper < 0 || lower < 0) return ans;

        for(int i=0; i<col_num; ++i)
            if(row1[i] == -1 && row2[i] == -1) {
                if(upper > 0) {
                    row1[i] = 1; row2[i] = 0;
                    upper--;
                } else {
                    if(lower > 0) {
                        row1[i] = 0; row2[i] = 1;
                        lower--;
                    } else {
                        return ans;
                    }
                }
            }
        if(upper != 0 || lower != 0) return ans;

        ans.push_back(row1); ans.push_back(row2);
        return ans;
    }
};
/*
2
1
[1,1,1]
5
5
[2,1,2,0,1,0,1,2,0,1]
1
4
[2,1,2,0,0,2]
4
7
[2,1,2,2,1,1,1]



[[1,1,0],[0,0,1]]
[[1,1,1,0,1,0,0,1,0,0],[1,0,1,0,0,0,1,1,0,1]]
[]
[]
*/
