/*
 *Description:
 ******************
 *Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


class Solution {
public:
    //自己实现的，Runtime: 超时
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if (nums.size() < 3)
            return ret;
            
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                for (int k = j + 1; k < nums.size(); ++k)
                {
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        vector<int> t;
                        t.push_back(nums[i]);
                        t.push_back(nums[j]);
                        t.push_back(nums[k]);
                        std::sort(t.begin(), t.end());
                        ret.push_back(t);
                    }
                }
            }
        }
        std::sort(ret.begin(), ret.end());
        auto iter = std::unique(ret.begin(), ret.end());
        if (iter == ret.end())
            cout << " == " << endl;
        ret.erase(iter, ret.end());
        return ret;
    }

    //leetCode上最好的回答 Runtime: 89ms
    vector<vector<int>> threeSum3(vector<int>& nums) 
    {        
        int size = nums.size();
        if(size < 3)
            return vector<vector<int>>{};
        
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> solutionSet;
        
        for(int targetIndex = 0; targetIndex < size - 2; ++targetIndex)
        {
            int target = -nums[targetIndex];
            int left = targetIndex + 1;
            int right = size - 1;
            
            while(left < right)
            {
                int sum = nums[left] + nums[right];
                
                if(sum < target)
                    ++left;
                else if (sum > target)
                    --right;
                else
                {
                    vector<int> solution({nums[targetIndex], nums[left], nums[right]});
                    solutionSet.push_back(solution);
                    
                    while(left < right && nums[left] == solution[1] ) ++left;
                    while(left < right && nums[right] == solution[2] ) --right;
                    
                }
            }
            
            while(targetIndex < size - 1 && nums[targetIndex + 1] == nums[targetIndex])
                ++targetIndex;
            
        }
        
        return solutionSet;
    }    
};

int main( int argc, char **argv )
{
    Solution s;
    vector<int> v = {-1, -1 ,2};
    auto a = s.threeSum2(v);
    for (int i=0; i<a.size(); ++i)
    {
        cout << "[";
        for (int j = 0; j < a[i].size(); ++j)
        {
            cout << a[i][j] << ",";
        }
        cout << "]" << endl;
    }
    getchar();
    return 0;
}