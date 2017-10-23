/*
 *Description:
 ******************
 *Implement regular expression matching with support for '.' and '*'
    '.' Matches any single character.
    '*' Matches zero or more of the preceding element.

    The matching should cover the entire input string (not partial).

    The function prototype should be:
    bool isMatch(const char *s, const char *p)

    Some examples:
    isMatch("aa","a") → false
    isMatch("aa","aa") → true
    isMatch("aaa","aa") → false
    isMatch("aa", "a*") → true
    isMatch("aa", ".*") → true
    isMatch("ab", ".*") → true
    isMatch("aab", "c*a*b") → true
 *******************
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
    //自己实现的，Runtime: 6ms
    bool isMatch(string s, string p)
    {
        if (p.empty())
            return s.empty();

        int i = 0, j = 0;
        vector<int> pointJ; //存储有*的前一个位置的p的下标j
        vector<int> pointI; //存储对应有*的位置的s的下标i
        while (i < s.size() && j < p.size())
        { //循环匹配i和j
            if (j + 1 >= p.size())
            {//j为最后的字符
                if (i + 1 >= s.size()) //不也为最后的字符
                    return s[i] == p[j] || p[j] == '.';
                else
                {
                    if (pointJ.size() != 0)
                    { //之前有*的字符，可回到*的位置进行更多的尝试
                        i = ++pointI.back();
                        j = pointJ.back() + 2;
                        if (p[j - 2] != '.')
                        {
                            if (p[j - 2] != s[i])
                            {
                                pointJ.pop_back();
                                pointI.pop_back();
                            }
                        }
                        continue;
                    }
                    return false;
                }
            }
            if (p[j + 1] == '*')
            {//若j的下个字符是*。
                if (s[i] == p[j] || p[j] == '.')
                {
                    if (j + 2 >= p.size())
                    {//*是最后的字符，则尽可能多的匹配
                        if (p[j] == '.')
                            return true;
                        else
                        {
                            ++i;
                            continue;
                        }
                    }
                    pointJ.push_back(j);
                    pointI.push_back(i);
                    ++j, ++j; //先尝试匹配0个的情况。,pointI,pointJ中记录了当前的位置，方便后续多次匹配
                    continue;
                }
                ++j, ++j; //只能匹配0个，不用记录。
                if (j >= p.size())
                {
                    if (pointJ.size() != 0)
                    {//之前有*的字符，可回到*的位置进行更多的尝试
                        i = ++pointI.back();
                        j = pointJ.back() + 2;
                        if (p[j - 2] != '.')
                        {
                            if (p[j-2] != s[i])
                            {
                                pointI.pop_back();
                                pointJ.pop_back();
                            }
                        }
                    }
                }
            }
            else
            {//下个字符不是*
                if (s[i] == p[j] || p[j] == '.')
                {
                    ++i; ++j;
                    continue;
                }
                else if (pointJ.size() != 0)
                {//之前有*的字符，可回到*的位置进行更多的尝试
                    i = ++pointI.back();
                    j = pointJ.back() + 2;
                    if (p[j - 2] != '.')
                    {
                        if (p[j-2] != s[i])
                        {
                            pointI.pop_back();
                            pointJ.pop_back();
                        }
                    }
                    continue;
                }
                return false;
            }
        }

        if (i >= s.size())
        { //s只有匹配完，才有可能匹配成功
            if (j >= p.size())
                return true;
            if (j + 1 == p.size())
            {
                return p[j + 1] == '*';
            }
            if (p[j + 1] == '*')
            {
                ++j, ++j;
                while (j < p.size())
                {
                    if (j + 1 < p.size() && p[j + 1] == '*')
                    {
                        ++j, ++j;
                        continue;
                    }
                    return false;
                }
                return true;
            }
        }
        return false;
    }

    //leetCode上最好的回答 Runtime: 3ms
    bool isMatch2(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] != '*')
                    dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.'); 
                else
                    dp[i][j] = dp[i][j - 2] || i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j];
            }
        }
        return dp[m][n];
    }
};

int main( int argc, char **argv )
{
    Solution s;
    cout << s.isMatch("ab", ".*a*a*") << s.isMatch2("ab", ".*a*a*") <<endl;
    cout << s.isMatch("abb", ".*b*") << s.isMatch2("abb", ".*b*") << endl;
    cout << s.isMatch("ab", ".*b*") << s.isMatch2("ab", ".*b*") << endl;
    cout << s.isMatch("aaba", "ab*a*c*a") << s.isMatch2("aaba", "ab*a*c*a") << endl;
    cout << s.isMatch("abcd", "ab*bcd") << s.isMatch2("abcd", "ab*bcd") << endl;
    cout << s.isMatch("a", "ab*a") << s.isMatch2("a", "ab*a") << endl;
    cout << s.isMatch("aaa", "ab*a*c*a") << s.isMatch2("aaa", "ab*a*c*a") << endl;
    cout << s.isMatch("ab", ".*") << s.isMatch2("ab", ".*") << endl;
    cout << s.isMatch("aa", ".*") << s.isMatch2("aa", ".*") << endl;
    cout << s.isMatch("aa", "aa") << s.isMatch2("aa", "aa") << endl;
    cout << s.isMatch("acc", "abc") << s.isMatch2("acc", "abc") << endl;
    cout << s.isMatch("abc", "ab*") << s.isMatch2("abc", "ab*") << endl;
    cout << s.isMatch("abcdabcdad", "a*da*d") << s.isMatch2("abcdabcdad", "a*da*d") << endl;
    cout << s.isMatch("aab", "c*a*b") << s.isMatch2("aab", "c*a*b") << endl;
    cout << s.isMatch("abcd", "d*") << s.isMatch2("abcd", "d*") << endl;
    cout << s.isMatch("aa", "a") << s.isMatch2("aa", "a") << endl;
    cout << s.isMatch("ab", ".*c") << s.isMatch2("ab", ".*c") << endl;
    cout << s.isMatch("abcccccc", "a.*c") << s.isMatch2("abcccccc", "a.*c") << endl;
    getchar();
    return 0;
}