class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> result;
        unordered_map<string, vector<string> > hash;
        for (const string& s : strs) {
            string sorted_s(s);
            sort(sorted_s.begin(), sorted_s.end());
            hash[sorted_s].emplace_back(s);
        }

        for (const auto& p : hash) {
            if (p.second.size() > 1) {
                for (const auto& s : p.second) {
                    result.emplace_back(s);
                }
            }
        }
        return result;
    }
};
