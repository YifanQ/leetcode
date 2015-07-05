class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n == 0) return res;
        if(n == 1) {
            res.push_back("()");
            return res;
        }
        if(n == 2) {
            res.push_back("(())");
            res.push_back("()()");
            return res;
        }
        vector<string> aux = generateParenthesis(n-1);
        for(vector<string>::iterator i = aux.begin(); i != aux.end(); ++i) {
            res.push_back("("+ *i +")");
        }
        for(vector<string>::iterator i = aux.begin(); i != aux.end(); ++i) {
            res.push_back("()"+ *i);
        }
        return res;
    }
};

Wrong AnswerMore Details

Input:
3
Output:
["((()))","(()())","()(())","()()()"]
Expected:
["((()))","(()())","(())()","()(())","()()()"]
omitted that the 3rd ones
we cannot devide the problem into two catogories like the above.
f(n) = ( f(n-1) ) +
       ()( f(n-2) ) + ( f(n-2) )()
       ...
