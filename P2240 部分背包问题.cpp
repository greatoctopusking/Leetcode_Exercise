#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 110;

struct coin {
    int weight = 0;
    double value = 0;

    coin(int w, double v) :weight(w), value(v) {}
};

struct cmp {
    bool operator()(const coin& p, const coin& q) const {
        return p.value < q.value;
    }
};

priority_queue <coin, vector<coin>, cmp> q;
int n, t;

int main() {
    cin >> n >> t;
    int w; double v;
    for (int i = 0; i < n; i++) {
        cin >> w >> v;
        v /= w;
        q.push(coin(w, v));
    }

    double toweight = 0;
    double tovalue = 0;
    while (toweight < t && !q.empty()) {
        coin c = q.top();
        q.pop();
        if (toweight + c.weight > t) {
            tovalue += (t - toweight) * c.value;
            break;
        }
        else {
            tovalue += c.weight * c.value;
            toweight += c.weight;
        }
    }
    cout << tovalue;
    return 0;
}