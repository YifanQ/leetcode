/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".
*/
class Solution {
public:
    /*
    things to note:
        How to copy an immutable string into c-string
        How to realize the isVowel()...
    */
    string reverseVowels(string s) {
        int n=s.length();
        if(n==0)
            return string("");


        char *str= new char[n+1];
        strcpy(str, s.c_str());
        str[n] = '\0'; // is this necessary? or strcpy already did this for me

        int pA=0, pB=n-1;
        while(true) {
            while(pA< n && !isVowel(str[pA])) ++pA;
            while(pB>=0 && !isVowel(str[pB])) --pB;
            if(pA >= pB) break;


            char ch = str[pA];
            str[pA] = str[pB];
            str[pB] = ch;
            ++pA;
            --pB;
        }
        string res(str, n);
        return res;
    }
    bool isVowel(char ch) {
        switch(ch) {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u': return true;
            default : return false;
        }
    }
};
