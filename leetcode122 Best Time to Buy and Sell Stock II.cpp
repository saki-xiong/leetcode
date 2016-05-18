#include<iostream>
#include<vector>
using namespace std;
/*buy one and sell one share of the stock multiple times,you must sell the stock before you buy again*/

class Solution{
	public:
	int maxProfit(vector <int>& prices){
		if (prices.empty() || prices.size() == 1)
			return 0;
		int maxprofit = 0;
		for (int i=1; i<prices.size();i++){
			int profit = prices[i]-prices[i-1];
			if (profit>0)
				maxprofit+=profit;
		}
		return maxprofit;	
	}
};

int main(){
	Solution answer;
	int a[5] = { 1,2,3,0,2 };
	vector<int> nums (a,a+5);
	cout<< "maxprofit:" << answer.maxProfit(nums) << endl;
	return 0;
}