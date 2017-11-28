/*
 *Description:
 ******************
 *Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.
Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <stdlib.h>
using namespace std;


class Solution {
public:
    //自己实现的，Runtime: 3ms
    map<char, string> m;
    vector<string> letterCombinations(string digits)
    {
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        vector<string> res;
        if (digits.empty())
            return res;
        getCombinations(res, digits, 0, "");
        return res;
    }

    void getCombinations(vector<string> &res, string &digits, int pos, string s)
    {
        if (pos >= digits.size())
        {
            res.push_back(s);
            return ;
        }
        for (int i = 0; i < m[digits[pos]].size(); ++i)
        {
            string t = s;
            t.push_back(m[digits[pos]][i]);
            getCombinations(res, digits, pos+1, t);
        }
    }

    //leetCode上最好的回答 Runtime: 0ms
    vector<string> letterCombinations2(string digits) {
        if (digits == "")
            return {};
        
        vector<string> d_map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        dfs(digits, 0, "", res, d_map);
        return res;
    }
    
    void dfs(string digits, int pos, string letters, vector<string>& res, vector<string>& d_map) {
        if (pos == digits.size()) {
            res.push_back(letters);
            return;
        } // if
        
        for (char c : d_map[digits[pos] - '0'])
            dfs(digits, pos + 1, letters + c, res, d_map);
    } // dfs
};

int main( int argc, char **argv )
{
    Solution s;
    vector<string> v = s.letterCombinations("23");
    for ( int i=0; i<v.size(); ++i)
    {
        cout << v[i] << endl;
    }

    getchar();
    return 0;
}