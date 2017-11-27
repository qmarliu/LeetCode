/*
 *Description:
 ******************
 *Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
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
    //自己实现的，Runtime: 9ms
    int threeSumClosest(vector<int>& nums, int target) {
       std::sort(nums.begin(), nums.end());
       int numsLen = nums.size();
       int closet = INT_MAX;
       int ret = 0;
       for (int i = 0; i < numsLen - 2; ++i)
       {
            int left = i + 1;
            int right = numsLen -1;
            int anotherTwoTarget = target - nums[i];
            while (left < right)
            {
                int tmp = nums[left] + nums[right];
                int absCloset = abs(anotherTwoTarget - tmp);
                if (closet > absCloset)
                {
                    closet = absCloset;
                    ret = nums[i] + tmp;
                }
                if (tmp > anotherTwoTarget)
                {
                    --right;
                }
                else if (tmp < anotherTwoTarget)
                {
                    ++left;
                }
                else
                    return ret;
            }
       }
       return ret;
    }

    //leetCode上最好的回答 Runtime: 6ms
    int threeSumClosest2(vector<int>& nums, int target) {
       if(nums.size()<3) return 0;
        int closet =nums[0]+nums[1]+nums[2];
        sort(nums.begin(), nums.end());
        for(int first=0; first<nums.size()-2; ++first) {
            if(first>0 && nums[first]==nums[first-1]) continue;
            int second=first+1;
            int third=nums.size()-1;
            while(second<third) {
                int tsum=nums[first]+nums[second]+nums[third];
                if(tsum==target) return tsum;
                if(abs(target-tsum)<abs(target-closet)) closet=tsum;
                if(tsum>target) --third;
                else ++second; 
            }
        }
        return closet;
    }
};

int main( int argc, char **argv )
{
    Solution s;
    vector v{1, 1, -1, -1, 3};
    s.threeSumClosest(v, -1);

    getchar();
    return 0;
}