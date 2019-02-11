#include <bits/stdc++.h> 
using namespace std;
set<string> st;
set<string> st1;
int main()
{
	int n,sum;
	string a, b;
	while (cin>>n&&n)
	{
		for (int i = 0; i < n; ++i)
		{
			cin >> a >> b;
			st.insert(a);
			st1.insert(b);
		}
		sum = st.size();
		for (auto it = st.begin(); it != st.end(); ++it)
			for (auto it1 = st1.begin(); it1 != st1.end(); ++it1)
				if (*it == *it1)
					sum--;
		if (sum == 1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
    return 0;
}
