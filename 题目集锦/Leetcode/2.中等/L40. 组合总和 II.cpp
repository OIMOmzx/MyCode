#include <bits/stdc++.h>
#include <vector>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<vector<int>> &res, vector<int> &candidates, vector<int> &combine, int target, int sum, int start)
    {
        if(sum == target) 
        {
            res.push_back(combine);
            return;
        }
        if(start >= candidates.size()) 
            return;

        for(int i = start; i < candidates.size(); ++i) 
        {
            if(i != start && candidates[i] == candidates[i-1]) 
                continue;
            if(sum + candidates[i] <= target)
            {
                combine.push_back(candidates[i]);
                sum += candidates[i];
                backtrack(res, candidates, combine, target, sum, i+1); 
                sum -= candidates[i]; 
                combine.pop_back();
            }
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.empty() || target <= 0)
            return{} ;
        sort(candidates.begin(), candidates.end()); 
        vector<vector<int>> res; 
        vector<int> combine; 
        backtrack(res, candidates, combine, target, 0, 0); 
        return res; 
}
};  