#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <cassert>
#include <cstdio>

using namespace std;

struct step {
    // unsigned char pos;
    int pos;
    int idx;
    int size;
    int arr[9];
    step(int pos_, int idx_, vector<int> &v): pos(pos_), idx(idx_) {
        size = v.size();
        for(int i = 0; i<v.size(); ++i)
            arr[i] = v[i];
    }
    bool tryNext(int a[9*9]) {
        if(idx==size) return false;
        a[pos] = arr[idx++];
        return true;
    }
    void clearStep(int a[9*9]) {
        a[pos] = 0;
        return ;
    }
};

class Solution {
public:
    void inputPuzzle(int a[9*9], vector< vector<char> > &board) {
        board.clear();
        int ii = 0;
        for(int i = 0; i<9; ++i) {
            vector<char> row;
            for(int j = 0; j<9; ++j) {
                char ch = (a[ii] == 0)? '.' : char('0'+a[ii]);
                row.push_back(ch);
                ++ii;
            }
            board.push_back(row);
        }
    }
    void outputPuzzle(int a[9*9]) {
        int ii = 0;
        for(int i = 0; i<9; ++i) {
            for(int j = 0; j<9; ++j)
                printf("%d ", a[ii++]);
            printf("\n");
        }
        return ;
    }

    void genNeighbors(int neighbor[9*9][8*3]) {
        for(int i = 0; i<9; ++i)
        for(int j = 0; j<9; ++j) {
            int pos = i*9+j;
            int ii = 0;
            for(int jp = 0; jp<9; ++jp)
                if(jp!=j) neighbor[pos][ii++] = i*9+jp;
            for(int ip = 0; ip<9; ++ip)
                if(ip!=i) neighbor[pos][ii++] = ip*9+j;

            {
                int i0 = i/3, j0 = j/3, i1 = i%3, j1 = j%3;
                for(int i1p = 0; i1p<3; ++i1p)
                for(int j1p = 0; j1p<3; ++j1p)
                    if(!(i1p == i1 && j1p == j1))
                        neighbor[pos][ii++] = (i0*3+i1p)*9 + j0*3+j1p;
            }

            assert(ii == 24);
        }

        return ;
    }

int genBestPosition(int a[9*9], int &best_pos, vector<int>& numlist) {
    int minNum = 9+1;

    for(int pos = 0; pos<9*9; ++pos) {
        if(a[pos] == 0) {
            vector<bool> num(10, true);
            vector<int> numlist0;

            for(int ii = 0; ii<8*3; ++ii)
                num[ a[ neighbor[pos][ii] ] ] = false;

            for(int ii = 1; ii<=9; ++ii)
                if(num[ii]) numlist0.push_back(ii);

            if(numlist0.size() < minNum) {
                minNum = numlist0.size();
                numlist = numlist0;
                best_pos = pos;
            }
        }
    }
    return minNum;
}
bool solve(int a[9*9]) {
    int blankNum = 0;
    for(int pos = 0; pos<9*9; ++pos)
        if(a[pos] == 0) ++blankNum;

    int cnt = 0;
    int best_pos;
    vector<int> numlist;

    while(true) {
        genBestPosition(a, best_pos, numlist);
        printf("%d, %d with %zd choices: ", best_pos/9, best_pos%9, numlist.size());
        for(int i = 0; i<numlist.size(); ++i)
            printf("%d ", numlist[i]);
        printf("\n");

        if(numlist.size()>=1) {
            steps.push_back(step(best_pos, 1, numlist));
            // printf("(%d, %d): %d\n", best_pos/9, best_pos%9, numlist[0]);
            a[best_pos] = numlist[0];

            --blankNum;
            if(blankNum == 0)
                return true;
        } else {
            while(!steps.empty()) {
                // outputPuzzle(a);
                if(steps.back().tryNext(a)) break;
                // printf("*****%zd\n", steps.size());
                steps.back().clearStep(a);
                steps.pop_back();
                ++blankNum;
            }
            if(steps.empty()) return false;
        }
    }
}

    void solveSudoku(vector< vector<char> >& board) {
        int a[9*9], ii;
        ii = 0;
        for(int i = 0; i<9; ++i)
            for(int j = 0; j<9; ++j)
                if(board[i][j] != '.') a[ii++] = board[i][j] - '0';
                else a[ii++] = 0;

        outputPuzzle(a);
        genNeighbors(neighbor);
        // for(int i = 0; i<9; ++i) {
        //     for(int j = 0; j<9; ++j) {
        //         for(int ii = 0; ii<24; ++ii)
        //             printf("%d ", neighbor[i*9+j][ii]);
        //         printf("\n");
        //     }
        //     printf("\n");
        // }

        solve(a);
        outputPuzzle(a);


        ii = 0;
        for(int i = 0; i<9; ++i)
            for(int j = 0; j<9; ++j)
                board[i][j] = a[ii++] + '0';
    }

    int neighbor[9*9][8*3];
    deque< step > steps;
};


int main() {
    // Solution a;
    // vector< vector<char> > board = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    // printf("%d, %d\n\n", board.size(), board[0].size());
    // a.solveSudoku(board);

    Solution a;
    vector< vector<char> > board;
    int num[9*9];

    FILE *fp; fp = fopen("sudoku.txt", "r");
    int ii = 0;
    for(int i = 0; i<9; ++i)
        for(int j = 0; j<9; ++j)
            fscanf(fp, "%d", &(num[ii++]));
    fclose(fp);

    a.inputPuzzle(num, board);
    a.solveSudoku(board);

    return 0;
}


/*
9, 9

5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9
4, 4 with 1 choices: 5
4, 1 with 1 choices: 2
4, 7 with 1 choices: 9
4, 2 with 1 choices: 6
4, 6 with 1 choices: 7
5, 3 with 1 choices: 9
3, 3 with 1 choices: 7
6, 4 with 1 choices: 3
2, 4 with 1 choices: 4
2, 5 with 1 choices: 2
0, 3 with 1 choices: 6
0, 5 with 1 choices: 8
2, 0 with 1 choices: 1
2, 3 with 1 choices: 3
2, 6 with 1 choices: 5
2, 8 with 1 choices: 7
3, 6 with 1 choices: 4
3, 5 with 1 choices: 1
3, 1 with 1 choices: 5
3, 2 with 1 choices: 9
3, 7 with 1 choices: 2
5, 1 with 1 choices: 1
5, 2 with 1 choices: 3
5, 5 with 1 choices: 4
5, 6 with 1 choices: 8
1, 6 with 1 choices: 3
1, 7 with 1 choices: 4
0, 7 with 1 choices: 1
0, 6 with 1 choices: 9
0, 8 with 1 choices: 2
0, 2 with 1 choices: 4
1, 1 with 1 choices: 7
1, 2 with 1 choices: 2
1, 8 with 1 choices: 8
5, 7 with 1 choices: 5
6, 0 with 1 choices: 9
6, 3 with 1 choices: 5
6, 5 with 1 choices: 7
6, 2 with 1 choices: 1
6, 8 with 1 choices: 4
7, 1 with 1 choices: 8
7, 2 with 1 choices: 7
7, 6 with 1 choices: 6
7, 7 with 1 choices: 3
7, 0 with 1 choices: 2
8, 0 with 1 choices: 3
8, 1 with 1 choices: 4
8, 2 with 1 choices: 5
8, 3 with 1 choices: 2
8, 5 with 1 choices: 6
8, 6 with 1 choices: 1
5 3 4 6 7 8 9 1 2
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9
[Finished in 1.1s]

*/

/*

0 0 2 3 1 0 0 8 0
8 5 0 6 0 0 0 0 0
0 0 0 0 0 0 2 0 6
7 3 0 0 0 5 6 0 0
0 0 1 0 0 0 8 0 7
2 0 9 0 0 0 0 0 0
1 0 0 0 0 0 0 7 0
0 0 0 0 0 7 1 0 0
0 0 0 8 9 0 0 0 0
0, 5 with 2 choices: 4 9
0, 0 with 2 choices: 6 9
0, 1 with 2 choices: 7 9
0, 6 with 2 choices: 5 9
0, 8 with 1 choices: 9
1, 2 with 2 choices: 3 4
2, 2 with 1 choices: 4
2, 0 with 1 choices: 9
2, 1 with 1 choices: 1
2, 5 with 1 choices: 8
2, 7 with 1 choices: 3
3, 2 with 1 choices: 8
1, 4 with 2 choices: 2 7
1, 5 with 1 choices: 9
3, 4 with 1 choices: 4
1, 6 with 2 choices: 4 7
1, 7 with 1 choices: 1
1, 8 with 0 choices:
1, 7 with 2 choices: 1 4
1, 8 with 1 choices: 4
2, 3 with 2 choices: 5 7
2, 4 with 1 choices: 7
3, 7 with 2 choices: 2 9
3, 8 with 1 choices: 1
3, 3 with 1 choices: 9
4, 3 with 1 choices: 2
6, 3 with 1 choices: 4
7, 3 with 0 choices:
3, 3 with 2 choices: 1 2
3, 8 with 1 choices: 2
5, 3 with 1 choices: 7
4, 0 with 2 choices: 4 5
4, 1 with 1 choices: 6
5, 1 with 0 choices:
4, 7 with 1 choices: 4
4, 1 with 1 choices: 6
4, 4 with 1 choices: 3
4, 5 with 1 choices: 2
4, 3 with 1 choices: 9
5, 1 with 1 choices: 4
5, 5 with 1 choices: 6
5, 4 with 1 choices: 8
5, 6 with 1 choices: 3
5, 7 with 1 choices: 5
5, 8 with 1 choices: 1
6, 5 with 1 choices: 3
8, 1 with 1 choices: 2
8, 5 with 1 choices: 1
8, 6 with 1 choices: 4
6, 6 with 1 choices: 9
6, 1 with 1 choices: 8
6, 8 with 1 choices: 5
6, 2 with 1 choices: 6
6, 4 with 0 choices:
3, 8 with 1 choices: 1
4, 3 with 1 choices: 9
6, 3 with 1 choices: 4
7, 3 with 0 choices:
2, 4 with 1 choices: 5
5, 3 with 1 choices: 1
3, 3 with 2 choices: 2 9
3, 7 with 1 choices: 9
3, 8 with 1 choices: 1
4, 3 with 1 choices: 9
4, 0 with 2 choices: 4 5
4, 1 with 1 choices: 6
5, 1 with 0 choices:
4, 1 with 2 choices: 4 6
4, 7 with 1 choices: 2
5, 1 with 1 choices: 6
5, 5 with 1 choices: 3
4, 4 with 1 choices: 6
4, 5 with 0 choices:
4, 4 with 1 choices: 3
4, 5 with 0 choices:
3, 7 with 1 choices: 2
3, 8 with 1 choices: 1
4, 3 with 1 choices: 2
4, 0 with 2 choices: 4 5
4, 1 with 1 choices: 6
5, 1 with 0 choices:
4, 1 with 2 choices: 4 6
4, 7 with 1 choices: 9
5, 1 with 1 choices: 6
5, 5 with 1 choices: 3
4, 4 with 1 choices: 6
4, 5 with 0 choices:
4, 4 with 1 choices: 3
4, 5 with 0 choices:
1, 8 with 1 choices: 1
3, 8 with 1 choices: 2
2, 3 with 2 choices: 5 7
2, 4 with 1 choices: 7
3, 3 with 2 choices: 1 9
3, 7 with 1 choices: 9
4, 7 with 1 choices: 5
4, 0 with 1 choices: 4
4, 1 with 1 choices: 6
5, 1 with 0 choices:
3, 7 with 1 choices: 1
4, 3 with 1 choices: 2
5, 7 with 1 choices: 5
4, 7 with 1 choices: 9
6, 3 with 1 choices: 4
7, 3 with 0 choices:
2, 4 with 1 choices: 5
5, 3 with 1 choices: 1
3, 3 with 1 choices: 9
3, 7 with 1 choices: 1
4, 3 with 1 choices: 2
5, 7 with 1 choices: 5
4, 7 with 1 choices: 9
4, 0 with 2 choices: 4 5
4, 1 with 1 choices: 6
5, 1 with 0 choices:
4, 1 with 2 choices: 4 6
5, 1 with 1 choices: 6
5, 5 with 1 choices: 3
4, 4 with 1 choices: 6
4, 5 with 0 choices:
4, 4 with 1 choices: 3
4, 5 with 0 choices:
1, 6 with 1 choices: 4
1, 7 with 1 choices: 1
1, 8 with 0 choices:
2, 2 with 1 choices: 3
2, 0 with 1 choices: 9
2, 1 with 1 choices: 1
2, 5 with 1 choices: 8
2, 7 with 1 choices: 4
3, 2 with 1 choices: 8
1, 4 with 2 choices: 2 7
1, 5 with 1 choices: 9
3, 4 with 1 choices: 4
1, 6 with 2 choices: 3 7
1, 7 with 1 choices: 1
1, 8 with 0 choices:
1, 7 with 2 choices: 1 3
1, 8 with 1 choices: 3
2, 3 with 2 choices: 5 7
2, 4 with 1 choices: 7
3, 7 with 2 choices: 2 9
3, 8 with 1 choices: 1
3, 3 with 1 choices: 9
4, 3 with 1 choices: 2
6, 3 with 1 choices: 4
7, 3 with 0 choices:
3, 3 with 2 choices: 1 2
3, 8 with 1 choices: 2
5, 3 with 1 choices: 7
4, 0 with 2 choices: 4 5
4, 1 with 1 choices: 6
5, 1 with 0 choices:
4, 7 with 1 choices: 3
4, 4 with 1 choices: 6
4, 1 with 1 choices: 4
4, 5 with 1 choices: 2
4, 3 with 1 choices: 9
5, 1 with 1 choices: 6
5, 5 with 1 choices: 3
5, 4 with 1 choices: 8
5, 6 with 1 choices: 4
5, 7 with 1 choices: 5
5, 8 with 1 choices: 1
6, 5 with 1 choices: 6
6, 2 with 1 choices: 5
6, 4 with 1 choices: 3
6, 6 with 1 choices: 9
7, 2 with 1 choices: 6
7, 4 with 1 choices: 5
7, 7 with 1 choices: 2
7, 3 with 1 choices: 4
6, 3 with 1 choices: 2
6, 1 with 1 choices: 8
6, 8 with 1 choices: 4
7, 0 with 1 choices: 3
7, 1 with 1 choices: 9
7, 8 with 1 choices: 8
8, 0 with 1 choices: 4
8, 1 with 1 choices: 2
8, 2 with 1 choices: 7
8, 5 with 1 choices: 1
8, 6 with 1 choices: 3
8, 7 with 1 choices: 6
8, 8 with 1 choices: 5
6 7 2 3 1 4 5 8 9
8 5 4 6 2 9 7 1 3
9 1 3 5 7 8 2 4 6
7 3 8 1 4 5 6 9 2
5 4 1 9 6 2 8 3 7
2 6 9 7 8 3 4 5 1
1 8 5 2 3 6 9 7 4
3 9 6 4 5 7 1 2 8
4 2 7 8 9 1 3 6 5
[Finished in 1.1s]

*/
