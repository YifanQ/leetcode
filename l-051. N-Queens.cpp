class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        int c=0; vector<int> col(n, 0);

        search(n, c, col, res);
        return res;
    }
    void search(int &n, int &c, vector<int> &col, vector<vector<string>> &res) {
        if(c==n) {
            for(int i=0;i<n;++i)
                printf("%d, ", col[i]);
            printf("\n");

            res.push_back(get_res(col));
            return ;
        }
        vector<bool> val(n, true);
        get_val(n, col, val);
        for(int i=0;i<n;++i) {
            if(val[i]) {
                ++c; for(int j=0;j<n;++j) if(col[j]>0) ++col[j]; col[i]=1;
                search(n, c, col, res);
                --c; for(int j=0;j<n;++j) if(col[j]>0) --col[j];
            }
        }
    }
    inline void get_val(int &n, vector<int> &col, vector<bool> &val) {
        for(int i=0;i<n;++i)
            if(col[i]>0) {
                val[i] = false;
                if(i-col[i] >= 0) val[i-col[i]]=false;
                if(i+col[i] <  n) val[i+col[i]]=false;
                // int pos=1<<i;
                // int posL = pos<<col[i];
                // int posR = pos>>col[i];
                // val |= pos+posL+posR; // 8>>4 or 8>>5 == 0
            }
    }


    vector<string> get_res(vector<int> &col) {
        vector<string> r;
        int n = col.size();
        string s0(n, '.');

        for(int i=0;i<n;++i) {
            string s(s0); s[col[i]-1] = 'Q'; r.push_back(s);
        }
        return r;
    }
};
