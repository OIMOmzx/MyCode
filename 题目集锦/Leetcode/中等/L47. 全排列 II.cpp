#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution 
{
public:
    vector<vector<int> > result;
    vector<int> path;
    vector<vector<int> > permuteUnique(vector<int>& nums) 
	{
        vector<bool> used(nums.size(), false);
		sort(nums.begin(), nums.end());
		a(used, nums);
        return result; 
    }
private:

	void a(vector<bool> &used, vector<int>& nums)
	{
		if(path.size() == nums.size())
		{
			result.push_back(path);
			return;
		}
		for(int i = 0; i < nums.size(); i++)
		{
			if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue;
            if(used[i] == false)
            {
				used[i] = true;
				path.push_back(nums[i]);
				a(used, nums);
				used[i] = false;
				path.pop_back();
            }
			
		}
	}
};