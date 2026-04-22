#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
int n, d;

struct Island {
    int x; int y;
    double l, r;
    int idx;

    Island(int xx, int yy, int id) :x(xx), y(yy), idx(id) {
        double len = pow(d * d - y * y, 0.5);
        l = x - len; r = x + len;
    }
};

struct left_cmp {
    bool operator()(const Island& a, const Island& b)const {
        return a.l > b.l;
    }
};

struct right_cmp {
    bool operator()(const Island& a, const Island& b)const {
        return a.r > b.r;
    }
};

int main() {
    cin >> n >> d;

    priority_queue<Island, vector<Island>, left_cmp> left_min_heap;
    priority_queue<Island, vector<Island>, right_cmp> right_min_heap;
    vector<bool> covered(n, false);

    int xx, yy;
    for (int i = 0; i < n; i++) {
        cin >> xx >> yy;
        if (yy > d) {
            cout << -1;
            return 0;
        }
        left_min_heap.push(Island(xx, yy, i));
        right_min_heap.push(Island(xx, yy, i));
    }

    int res = 0;
    while (!right_min_heap.empty()) {
        if (covered[right_min_heap.top().idx]) { right_min_heap.pop(); continue; }
        else {
            res++;
            covered[right_min_heap.top().idx] = true;
            double right = right_min_heap.top().r;
            right_min_heap.pop();
            while (!left_min_heap.empty() && left_min_heap.top().l <= right) {
                covered[left_min_heap.top().idx] = true;
                left_min_heap.pop();
            }
        }
    }
    printf("%d", res);
    return 0;
}