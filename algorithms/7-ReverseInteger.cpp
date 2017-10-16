/*
 *Description:
 ******************
 *Reverse digits of an integer.

    Example1: x = 123, return 321
    Example2: x = -123, return -321

 *******************
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    //自己实现的，Runtime: 19ms
    //偷赖的做法，当是巩固下C++的泛型算法
    int reverse(int x) {
        string s = to_string(x);
        std::reverse(s.begin(), s.end());
        int ans = atoi(s.c_str());
        string s2 = to_string(ans);
        if (s[s.size() - 1] == '-')
        {
            s.pop_back();
            ans = -ans;
        }
        while (s[0] == '0' && s.size() > 1)
        {
            s = s.substr(1, s.size() - 1);
        }
        if (s2 != s)
            return 0;
        return ans;
    }

    //leetCode上最好的答案
    int reverse2(int x) {
        int flag = (x < 0) ? -1 : 1;
		x = (x < 0) ? (-1 * x) : x;
		queue<int> q;
		while (x != 0) {
			int mod = x % 10;
			x = x / 10;
			q.push(mod);
		}
		int t_result = 0;
		while (!q.empty()) {
			int temp = t_result * 10 + q.front();
			if (t_result == (temp - q.front()) / 10) {//判断有没有溢出
				t_result = temp;
			}
			else {
				return 0;
			}
			q.pop();
		}
		return t_result * flag;
    }
};

int main( int argc, char **argv )
{
    Solution s;
    cout << s.reverse(-1240567899) << endl;
    getchar();
    return 0;
}