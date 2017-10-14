/*
 *Question
 ***************
 There are two sorted arrays nums1 and nums2 of size m and n respectively.

 Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 
 Example 1:
    nums1 = [1, 3]
    nums2 = [2]

    The median is 2.0
 Example 2:
    nums1 = [1, 2]
    nums2 = [3, 4]

    The median is (2 + 3)/2 = 2.5
 */

 #include <vector>
 #include <iostream>
 #include <string>
 using namespace std;

class Solution {
public:
    /*
    *自己实现的
    */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() == 0 && nums2.size() == 0)
            return 0;
        auto ite1 = nums1.begin();
        auto ite2 = nums2.begin();
        for (; ite1 != nums1.end() && ite2 != nums2.end(); ite1++)
        {
            if (*ite1 > *ite2)
            {
                ite1 = nums1.insert(ite1, *ite2);
                ite2++;
            }
        }
        if (ite1 == nums1.end())
        {
            nums1.insert(nums1.end(), ite2, nums2.end());
        }

        for (auto i : nums1)
        {
            cout << i << endl;
        }
        if (nums1.size() % 2 == 0)
        {
            return static_cast<double>(nums1[nums1.size() / 2] + nums1[nums1.size() / 2 - 1]) / 2;
        }
        return static_cast<double>(nums1[nums1.size() / 2]);
    }
};

int main( int argc, char **argv )
{
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {1, 1};
    Solution s;
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}