#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DSU {
public:
	vector<int> parent;
	DSU(){
		for (int i = 0; i < 50001; i++) {
			parent.push_back(i);
		}
	}

	int find(int x) {
		while (parent[x] != x) {
			int temp = parent[x];
			parent[x] = parent[temp];
			x = temp;
		}
		return x;
	}

	void merge(int x, int y) {
		int rx = find(x);
		int ry = find(y);
		parent[ry] = rx;
	}
};

struct Job {
	int d = 0; long long p = 0;
	Job() :d(0), p(0){}
	Job(int dd, long long pp):d(dd), p(pp){}
};

bool cmp(const Job& a, const Job& b) {
	return a.p > b.p;
}

int main() {
	int m, n;
	int d;
	long long p;
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &n);
		vector<Job> jobs(n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &d);
			scanf("%lld", &p);
			Job j(d, p);
			jobs[i] = j;
		}
		sort(jobs.begin(), jobs.end(), cmp);
		DSU dsu;
		long long res = 0;
		for (int i = 0; i < n; i++) {
			int available = dsu.find(jobs[i].d);
			if (available > 0) {
				res += jobs[i].p;
				dsu.merge(available - 1, available);
			}	
		}
		printf("%lld\n", res);
	}
	return 0;
}