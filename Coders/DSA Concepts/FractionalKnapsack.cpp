#include <bits/stdc++.h>
using namespace std;

void maxProfit(vector<int> profit,
			vector<int> weight, int N)
{

	int numOfElements = profit.size();
	int i;
	multimap<double, int> ratio;
	double max_profit = 0;
	for (i = 0; i < numOfElements; i++) {
		ratio.insert(make_pair(
			(double)profit[i] / weight[i], i));
	}

	multimap<double, int>::reverse_iterator it;
	for (it = ratio.rbegin(); it != ratio.rend();
		it++) {
		double fraction = (double)N / weight[it->second];

	
		if (N >= 0
			&& N >= weight[it->second]) {
			max_profit += profit[it->second];

		
			N -= weight[it->second];
		}
		else if (N < weight[it->second]) {
			max_profit += fraction
						* profit[it->second];
			break;
		}
	}

	cout << "Maximum profit earned is:"
		<< max_profit;
}

// Driver Code
int main()
{
	int size;
  cin>>size;

	vector<int> profit(size), weight(size);

	profit[0] = 100, profit[1] = 280,
	profit[2] = 120, profit[3] = 120;
	weight[0] = 10, weight[1] = 40,
	weight[2] = 20, weight[3] = 24;

	int N = 60;
	maxProfit(profit, weight, N);
}
