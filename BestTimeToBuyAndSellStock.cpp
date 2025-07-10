#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<int> prices = { 12,23,20,87,102,1 };
	int maxProfit = 0;
	for (int i = 0; i < prices.size(); i++) {
		for (int j = i + 1; j < prices.size(); j++) {
			int profit = prices[j] - prices[i];
			if (profit > maxProfit) {
				maxProfit = profit;
			}
		}
	}
	cout << maxProfit;
}