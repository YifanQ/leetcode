class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        // since words.size() <= 14, 2^14 = 16384, brute force! just visit all possibility
        // optimization: if 0101 is not possible, 0111 is also not.
        int len = words.size();
        int two_len = (1 << (len))-1;

        vector<int> letter_num(26, 0);
        for(int i = 0; i<letters.size(); ++i) ++letter_num[int(letters[i]-'a')];

        int score_i, max_score = 0;
        for(int i = 1/*0 <=> 00...00*/; i<=two_len; ++i) {
            vector<int> l_n(letter_num);
            score_i = 0;
            for(int j=0, two_j=1; j<len; ++j, two_j=(two_j<<1))
                if((i & two_j) == two_j)
                    for(int k=0;k<words[j].length();++k) {
                        int c = words[j][k] - 'a';
                        --l_n[c];
                        score_i += score[c];
                    }
            bool flag = true;
            for(int c=0;c<26;++c)
                if(l_n[c] < 0) flag = false;
            if(flag && score_i > max_score)
                max_score = score_i;
        }
        return max_score;
    }
};



// 36 ms
class Solution {
public:
   vector<string> words;
   vector<int> score;
   vector<int> count;
   int ans = 0, n;
   void dfs (int index, int sum) {
    if (index>=n) {  // looping below k<n this never gets called
      ans = max(ans,sum);
      return;
    }
    int cur[26] = {0};
    bool check = true;
    for (char c: words[index])
      cur[c-'a']++;
    for (int i = 0;i<26;i++) {
       if (cur[i]>count[i]) {
         check = false;
         break;
       }
    }
    if (!check)
      return;
    int loc = 0;
    for (int i = 0;i<26;i++) {
        count[i]-=cur[i];
        loc+=cur[i]*score[i];
    }
    ans = max(ans,sum+loc);   // limiting on index>=n never gets called
    for (int k = index+1;k<n;k++)
        dfs(k,sum+loc);
    for (int i = 0;i<26;i++)
        count[i]+=cur[i];
  }
    int maxScoreWords(vector<string>& _words, vector<char>& letters, vector<int>& _score) {
        words = _words; score = _score;
        count = vector<int> (26,0);
        for (auto c: letters)
            count[c-'a']++;
        n = words.size();
        for (int j = 0;j<n;j++)
            dfs(j,0);
        return ans;
    }
};


// 0 ms
class Solution {
public:
   vector<string> words;
   vector<int> score;
   vector<int> count;
   int ans = 0, n;
   void dfs (int index, int sum) {
    if (index>=n) {  // looping below k<n this never gets called
      ans = max(ans,sum);
      return;
    }
    int cur[26] = {0};
    bool check = true;
    for (char c: words[index])
      cur[c-'a']++;
    for (int i = 0;i<26;i++) {
       if (cur[i]>count[i]) {
         check = false;
         break;
       }
    }
    if (!check)
      return;
    int loc = 0;
    for (int i = 0;i<26;i++) {
        count[i]-=cur[i];
        loc+=cur[i]*score[i];
    }
    ans = max(ans,sum+loc);   // limiting on index>=n never gets called
    for (int k = index+1;k<n;k++)
        dfs(k,sum+loc);
    for (int i = 0;i<26;i++)
        count[i]+=cur[i];
  }
    int maxScoreWords(vector<string>& _words, vector<char>& letters, vector<int>& _score) {
        words = _words; score = _score;
        count = vector<int> (26,0);
        for (auto c: letters)
            count[c-'a']++;
        n = words.size();
        for (int j = 0;j<n;j++)
            dfs(j,0);
        return ans;
    }
};
