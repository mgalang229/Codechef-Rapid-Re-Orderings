#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		map<int, int> mp;
		vector<int> a(2 * n);
		for (int i = 0; i < 2 * n; i++) {
			cin >> a[i];
			// count the frequency of each number
			mp[a[i]]++;
		}
		// if n is equal to 1, then check if the two numbers are equal (prefix and suffix)
		if (n == 1) {
			int ans = -1;
			if (a[0] == a[1]) {
				ans = a[0];
			}
			cout << ans << '\n';
			continue;
		}
		// store the distinct numbers in a vector
		// sort the sequence in non-decreasing order
		// check if the size of the sequence is equal to n
		vector<int> vec;
		for (auto x : mp) {
			vec.push_back(x.first);
		}
		sort(vec.begin(), vec.end());
		bool ans = true;
		if ((int) vec.size() != n) {
			ans = false;
		}
		// calculate the middle index (depends on the parity of n)
		int mid = 0;
		if (n % 2 == 0) {
			mid = n / 2 - 1;
		} else {
			mid = n / 2;
		}
		// in this part, check the image in this repository for better understanding
		// the frequency of the middle element should be equal to 3
		if (ans && mp[vec[mid]] != 3) {
			ans = false;
		}
		// the frequency of the last element should equal to 1
		if (ans && mp[vec[n - 1]] != 1) {
			ans = false;
		}
		// the frequency of every remaining number should equal to 2
		for (int i = 0; i < n - 1; i++) {
			if (i != mid && mp[vec[i]] != 2) {
				ans = false;
			}
		}
		// output
		if (ans) {
			for (int i = 0; i < n; i++) {
				cout << vec[i] << " ";
			}
		} else {
			cout << -1;
		}
		cout << '\n';
	}
	return 0;
}
