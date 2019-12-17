#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int>& min = nums1.size() <= nums2.size() ? nums1 : nums2;
		vector<int>& max = nums1.size() > nums2.size() ? nums1 : nums2;

		int halflen = (min.size() + max.size() + 1) / 2;
		
		int left = 0;
		int right = min.size();

		while (left <= right)
		{
			int minmid = (left + right) / 2;
			int maxmid = halflen - minmid;
			if (minmid > left && min[minmid - 1] > max[maxmid])
				right = minmid - 1;
			else if (minmid < right  && min[minmid] < max[maxmid - 1])
				left = minmid + 1;
			else
			{
				int maxleft = 0;
				if (minmid == 0)
					maxleft = max[maxmid - 1];
				else if (maxmid == 0)
					maxleft = min[minmid - 1];
				else
					maxleft = min[minmid - 1] > max[maxmid - 1] ? min[minmid - 1] : max[maxmid - 1];
				if ((min.size() + max.size()) % 2 == 1)
					return maxleft;

				int minright = 0;
				if (minmid == min.size())
					minright = max[maxmid];
				else if (maxmid == max.size())
					minright = min[minmid];
				else
					minright = max[maxmid] < min[minmid] ? max[maxmid] : min[minmid];

				return (maxleft + minright) / 2.0;
			}
		}
		return 0;
	}
};
