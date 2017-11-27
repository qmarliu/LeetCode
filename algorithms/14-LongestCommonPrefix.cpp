/*
 *Description:
 ******************
 *Write a function to find the longest common prefix string amongst an array of strings.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    //自己实现的，Runtime: 6 ms
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        string &s = strs[0];
        string res;
        for (int i = 0; i < s.size(); ++i)
        {
            for (int j = 1; j < strs.size(); ++j)
            {
                if (strs[j].size() <= i || s[i] != strs[j][i])
                    return res;
            }
            res += s[i];
        }
        return res;
    }

    //leetCode上最好的回答 Runtime: 3ms
    string longestCommonPrefix2(vector<string>& strs) {
        if (strs.size() == 0)
        {
            return "";    
        }
        
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++)
        {
            while (0 != strs[i].compare(0, prefix.length(), prefix))
            {
                prefix = prefix.substr(0, prefix.length()-1);
            }
        }
        
        return prefix;
    }
};

int main( int argc, char **argv )
{
    getchar();
    return 0;
}