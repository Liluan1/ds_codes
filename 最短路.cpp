#include<iostream>
#include<vector>
using namespace std;
int K, N, R;	//kӵ�е�Ǯ��nĿ����У�r·������
struct Road
{
	int d, L, t;//d�յ� l���� t����
};
vector< vector<Road> > G(110);	//�ڽӱ���һάΪ��㣬�ڶ�ά���е��յ�

int minLen;	//ĿǰΪֹ�����·
int totalLen, totalCost;	//English
int visited[110];	//����
int minL[110][10010];	//ĳ���У�ĳ����ʱ����·

void DFS(int s)
{
	if (s == N)
	{
		minLen = min(minLen, totalLen);
		return;
	}
	for (int i = 0; i < G[s].size(); ++i)
	{
		Road r = G[s][i];
		if (totalCost + r.t > K)
			continue;
		if (totalLen + r.L >= minL[r.d][totalCost + r.t])
			continue;
		if (!visited[r.d])
		{
			totalLen += r.L;
			totalCost += r.t;
			visited[r.d] = 1;
			minL[r.d][totalCost + r.t] = totalLen + r.L;
			DFS(r.d);
			visited[r.d] = 0;
			totalLen -= r.L;
			totalCost -= r.t;
		}
	}
}
int main()
{
	cin >> K >> N >> R;
	for (int i = 0; i < R; ++i)
	{
		int s;
		Road r;
		cin >> s >> r.d >> r.L >> r.t;
		if (s != r.d)
			G[s].push_back(r);
	}
	minLen = 1 << 30;
	visited[1] = 1;
	for (int i = 0; i < 110;++i)
	for (int j = 0; j < 10010; ++j)
		minL[i][j] = 1 << 28;
	DFS(1);
	if (minLen < (1 << 30))
		cout << minLen << endl;
	else
		cout << "-1" << endl;
	return 0;
}
