#include <iostream>
#include <set>
#include <vector>
using namespace std;
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> tree;  
        for(int i = 0; i< nums.size(); i++)  
        {  
			cout<<"nums["<<i<<"]:"<<nums[i]<<endl;
            if(tree.size() > k) 
				tree.erase(nums[i-k-1]);  //只维护一个长度为k的树
            auto p = tree.lower_bound(nums[i]-t); //找到一个不小于nums[i]的值
			
			if (p != tree.end() && *p - nums[i] <= t) //与nums[i]比较 如果符合要求返回真
			{
				cout <<"lower bound:"<< *p<<endl;
				return true;
			}

            tree.insert(nums[i]);
        }  
        return false;  
    }
	void main(){
		vector<int> nums = { 5, 8, 10,9,10 };
		bool flag=containsNearbyAlmostDuplicate(nums, 1, 1);
		cout << "final result:"<<flag<<endl;
	}
	