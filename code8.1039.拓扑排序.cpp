#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct Node {
	int v;
	Node* next;
	Node() { v = 0; next = nullptr;}
	Node(int vv) :v(vv) { next = nullptr; }
};

int main() {
	int t, n, m, u, v;
	Node* p;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		vector<Node> adjlist(n + 1);
		vector<int> indegree(n + 1, 0);
		vector<bool> processed(n + 1, false);
		vector<int> res;
		queue<int> que;
		while (m--) {
			scanf("%d%d", &u, &v);
			p = new Node(v);
			p->next = adjlist[u].next;
			adjlist[u].next = p;
			indegree[v]++;
		}
		for (int i = 1; i < processed.size(); i++) {
			if (processed[i] == false && indegree[i] == 0) {
				que.push(i);
			}
		}
		v = 0;
		while (1) {
			if (que.empty())break;
			u = que.front();
			que.pop();
			for (p = adjlist[u].next; p != nullptr; p = p->next) {
				if (--indegree[p->v] == 0)que.push(p->v);
			}
			res.push_back(u);
			processed[u] = true;
			v++;
		}
		if (v != n) {
			printf("0\n");
			continue;
		}
		for (int point : res)printf("%d ", point);
		printf("\n");

		for (int i = 1; i <= n; i++) {
			while (adjlist[i].next != nullptr) {
				Node* temp = adjlist[i].next;
				adjlist[i].next = temp->next;
				delete temp;
				temp = nullptr;
			}
		}
	}
}