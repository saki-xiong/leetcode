#include<iostream>
#include<vector>
using namespace std;

class NumArray {

vector<int> sum;
public:
	NumArray(vector<int> &nums) {
		sum.push_back(0);
		for (auto n : nums)
			sum.push_back(sum.back() + n);
		for (int i = 0; i < sum.size(); i++)
			cout << sum[i] << "  ";
	}

	int sumRange(int i, int j) {
		return sum[j + 1] - sum[i];
	}
};

void main()
{
	vector<int> nums = { -2, 0, 3, -5, 2, -1 };
	NumArray numArray(nums);
	cout<<numArray.sumRange(1, 2)<<endl;
}


