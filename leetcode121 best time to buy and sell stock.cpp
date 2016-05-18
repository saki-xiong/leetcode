#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Input:
prices = [1, 2, 3, 0, 2]

Output: maxProfit = 2
*/
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty() || prices.size() == 1)
			return 0;
		int n = prices.size();
		vector<int> profit(n);
		profit[0] = 0;
		int lowprices = prices[0];
		for (size_t i = 1; i < n; ++i){
			if (prices[i] < lowprices)
				lowprices = prices[i];
			profit[i] = max(profit[i - 1], prices[i] - lowprices);
		}
		return profit.back();
	}
};
int main(void){
	Solution answer;
	int a[5] = { 1,2,3,0,2 };
	vector<int> nums (a,a+5);
	cout <<"maxProfit:"<< answer.maxProfit(nums) << endl;
	system("Pause");
	return 0;
}