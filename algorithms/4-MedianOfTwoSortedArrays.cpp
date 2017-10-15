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
    *自己实现的66ms
    */
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
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

        if (nums1.size() % 2 == 0)
        {
            return static_cast<double>(nums1[nums1.size() / 2] + nums1[nums1.size() / 2 - 1]) / 2;
        }
        return static_cast<double>(nums1[nums1.size() / 2]);
    }

    //Approach on leetcode
    double findMedianSortedArrays2(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n)
        { // to ensure m<=n
            swap(nums1, nums2);
        }
        int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
        while (iMin <= iMax)
        {
            int i = (iMin + iMax) / 2;
            int j = halfLen - i;
            if (i < iMax && nums2[j - 1] > nums1[i])
            {
                iMin = iMin + 1; // i is too small
            }
            else if (i > iMin && nums1[i - 1] > nums2[j])
            {
                iMax = iMax - 1; // i is too big
            }
            else
            { // i is perfect
                int maxLeft = 0;
                if (i == 0)
                {
                    maxLeft = nums2[j - 1];
                }
                else if (j == 0)
                {
                    maxLeft = nums1[i - 1];
                }
                else
                {
                    maxLeft = max(nums1[i - 1], nums2[j - 1]);
                }
                if ((m + n) % 2 == 1)
                {
                    return maxLeft;
                }

                int minRight = 0;
                if (i == m)
                {
                    minRight = nums2[j];
                }
                else if (j == n)
                {
                    minRight = nums1[i];
                }
                else
                {
                    minRight = min(nums2[j], nums1[i]);
                }

                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
    }

    //LeetCode上最好的实现 26ms
    double findMedianSortedArrays3(vector<int> &nums1, vector<int> &nums2)
    {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int s = size1 + size2;
        int t = (s - 1) / 2;
        if (size1 == 0 && size2 == 0)
        {
            return 0;
        }
        if (size1 == 0)
        {
            if (size2 % 2 == 0)
            {
                return (nums2.at(t) + nums2.at(t + 1)) / 2.0;
            }
            else
                return nums2.at(t);
        }
        if (size2 == 0)
        {
            if (size1 % 2 == 0)
            {
                return (nums1.at(t) + nums1.at(t + 1)) / 2.0;
            }
            else
                return nums1.at(t);
        }

        for (int i = 0; i < t; i++)
        {
            if (nums1.back() > nums2.back())
            {
                nums1.pop_back();
            }
            else
            {
                nums2.pop_back();
            }
        }
        if (s % 2 == 1)
        {
            double r = nums1.back() > nums2.back() ? nums1.back() : nums2.back();
            return r; //cout<<"The median is "<< r << endl;
        }
        else
        {
            if (nums1.back() > nums2.back())
            {
                double r1 = nums1.back();
                nums1.pop_back();
                double r2 = nums1.back() > nums2.back() ? nums1.back() : nums2.back();
                return (r1 + r2) / 2.0;
            }
            else
            {
                double r1 = nums2.back();
                nums2.pop_back();
                double r2 = nums1.back() > nums2.back() ? nums1.back() : nums2.back();
                return (r1 + r2) / 2.0;
            }
        }
        //cout<<"The median is ("<<nums1.back()<<" + "<<nums2.back()<<")/2 = "<<(nums1.back()+nums2.back())/2.0<<endl;
        return 0;
    }
};

int main( int argc, char **argv )
{
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {1, 4};
    Solution s;
    cout << s.findMedianSortedArrays3(nums1, nums2) << endl;
    return 0;
}