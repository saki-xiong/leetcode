#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<stack>
//string s;
void main()
{
	//cin >> s;
	vector<string> token{ "22", "-1", "+", "3", "*" };
	stack<int> mystack;
	for (auto c : token)  //·¶Î§forµÄÓÃ·¨
	{
		cout << c << endl ;
		if (isdigit(c[0])||c.size()>1)
		{
			mystack.push(atoi(c.c_str()));
			//cout << c <<" is  number"<< endl;
		}
		else
		{
			int num1, num2;
			num1 = mystack.top();
			mystack.pop();
			num2 = mystack.top();
			mystack.pop();
			switch (c[0])
			{
			case '+':
				mystack.push(num1 + num2);
				break;
			case '-':
				mystack.push(num1 - num2);
				break;
			case '*':
				mystack.push(num1 *num2);
				break;
			case '/':
				mystack.push(num1/ num2);	
				break;
			}
		}
	}
	int myresult = mystack.top();
	cout <<"myresult"<<myresult;
}