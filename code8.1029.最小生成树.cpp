#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;

struct Edge {
	int u; int v;
	int weight;
	Edge() { u = 0; v = 0; weight = 0; }
	Edge(int uu, int vv, int w):u(uu), v(vv), weight(w){}
};

struct cmp {
	bool operator()(const Edge& a, const Edge& b) {
		return a.weight > b.weight;
	}
};

struct Node {
	int v;
	Edge edge;
	Node* next;
	Node() { v = 0; next = nullptr; edge = Edge(); }
	Node(int vv, const Edge& ed) :v(vv), edge(ed) { next = nullptr; }
};

int main() {
	int m, n, e;
	scanf("%d", &m);
	while (m--) {
		priority_queue<Edge, vector<Edge>, cmp> heap;
		scanf("%d%d", &n, &e);
		if (e < n - 1) {
			cin.ignore();
			string buf;
			while (e--) {
				getline(cin, buf);
			}
			printf("%d\n", -1);
			continue;
		}
		vector<bool> isInTree(n + 1, false);
		vector<Node> alist(n + 1);
		int u, v, w;
		Node* temp;
		while (e--) {
			scanf("%d%d%d", &u, &v, &w);
			temp = new Node(u, Edge(u, v, w));
			temp->next = alist[v].next;
			alist[v].next = temp;

			temp = new Node(v, Edge(u, v, w));
			temp->next = alist[u].next;
			alist[u].next = temp;
		}

		int i = 1, count = 1;
		long long res = 0;
		isInTree[1] = true;
		do {
			Node* j = alist[i].next;
			while (j != nullptr) {
				if (!isInTree[j->v]) {
					heap.push(j->edge);
				}
				j = j->next;
			}
			if (heap.empty())break;

			Edge edge;
			do {
				edge = heap.top();
				heap.pop();
			} while ((isInTree[edge.u] && isInTree[edge.v]) && !heap.empty());
			if (isInTree[edge.u] && isInTree[edge.v])break;

			res += edge.weight;
			if (isInTree[edge.u]) {
				isInTree[edge.v] = true; i = edge.v;
			}
			else {
				isInTree[edge.u] = true; i = edge.u;
			}
			count++;
		} while (count < n);

		if (count < n)printf("%d\n", -1);
		else printf("%lld\n", res);

		for (int i = 1; i <= n; i++) {
			Node* x = alist[i].next;
			Node* y;
			while (x != nullptr) {
				y = x->next;
				delete x;
				x = y;
			}
		}
	}
	return 0;

}