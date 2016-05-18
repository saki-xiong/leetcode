#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*You may complete at most two transactions,You may not engage in multiple transactions 
at the same time (ie, you must sell the stock before you buy again)*/

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty() || prices.size() == 1)
			return 0;
		int n = prices.size();
		vector <int> leftprofit(n, 0);
		int lowprices = prices[0];
		for (int i = 1; i < n; i++){
			if (prices[i] < lowprices)
				lowprices = prices[i];
			leftprofit[i] = max(leftprofit[i - 1], prices[i] - lowprices);
		}
		
		vector <int> rightprofit(n,0);
		int maxprices = prices[n-1];
		for (int i = n-2; i >= 0; i--){
			if (prices[i] > maxprices)
				maxprices = prices[i];
			rightprofit[i] = max(maxprices - prices[i], rightprofit[i + 1]);
		}
		int maxprofit =0 ;
		for (int i=0; i < n-1; i++)
			maxprofit = max(maxprofit, leftprofit[i]+rightprofit[i]);
		return maxprofit;
    }
};

int main(){
	Solution answer;
	int a[5] = { 1,2,4 };
	vector<int> nums (a,a+5);
	cout<< "maxprofit:" << answer.maxProfit(nums) << endl;
	return 0;
}