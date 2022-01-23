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

    int best_pos;
    vector<int> numlist;

    while(true) {
        genBestPosition(a, best_pos, numlist);
        // printf("%d, %d with %zd choices:\n", best_pos/9, best_pos%9, numlist.size());
        // for(int i = 0; i<numlist.size(); ++i)
        //     printf("%d ", numlist[i]);
        // printf("\n");

        if(numlist.size()>=1) {
            steps.push_back(step(best_pos, 1, numlist));
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
// outputPuzzle(a);


ii = 0;
for(int i = 0; i<9; ++i)
    for(int j = 0; j<9; ++j)
        board[i][j] = a[ii++] + '0';

    }

    int neighbor[9*9][8*3];
    deque< step > steps;
};
