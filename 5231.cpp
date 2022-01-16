5231. Remove Sub-Folders from the Filesystem

User Accepted:1279
User Tried:1578
Total Accepted:1288
Total Submissions:2394
Difficulty:Medium

Given a list of folders, remove all sub-folders in those folders and return in any order the folders after removing.

If a folder[i] is located within another folder[j], it is called a sub-folder of it.

The format of a path is one or more concatenated strings of the form: / followed by one or more lowercase English letters. For example, /leetcode and /leetcode/problems are valid paths while an empty string and / are not.



Example 1:

Input: folder = ["/a","/a/b","/c/d","/c/d/e","/c/f"]
Output: ["/a","/c/d","/c/f"]
Explanation: Folders "/a/b/" is a subfolder of "/a" and "/c/d/e" is inside of folder "/c/d" in our filesystem.
Example 2:

Input: folder = ["/a","/a/b/c","/a/b/d"]
Output: ["/a"]
Explanation: Folders "/a/b/c" and "/a/b/d/" will be removed because they are subfolders of "/a".
Example 3:

Input: folder = ["/a/b/c","/a/b/ca","/a/b/d"]
Output: ["/a/b/c","/a/b/ca","/a/b/d"]


Constraints:

1 <= folder.length <= 4 * 10^4
2 <= folder[i].length <= 100
folder[i] contains only lowercase letters and '/'
folder[i] always starts with character '/'
Each folder name is unique.

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int num = folder.size();

        sort(folder.begin(), folder.end());
        // => ["/a","/a/b","/c/d","/c/d/e","/c/f"]
        vector<string> f;

        if( num>=1 ) {
            f.push_back(folder[0]);
            int pos = 0;
            for(int i=1; i<num; ++i)
                if(!isPrefix(folder[pos], folder[i])) { // folder[pos] is not prefix of folder[i]
                    f.push_back(folder[i]);
                    pos = i;
                }
        }
        return f;
    }
    bool isPrefix(string &a, string &b) {
        int pos = b.find(a);
        if(pos == 0 && b[a.length()] == '/') {
            // cout << a << " " << b << endl;
            return true;
        }

        return false;
    }
};
