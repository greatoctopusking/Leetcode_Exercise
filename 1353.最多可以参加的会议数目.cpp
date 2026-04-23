#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
    struct Event {
        int st; int ed;
        Event(int s, int e) : st(s), ed(e) {}
    };

    struct cmp {
        bool operator()(const Event& a, const Event& b) {
            return a.ed > b.ed;
        }
    };

    priority_queue<Event, vector<Event>, cmp> heap;

    static bool comp(vector<int> a, vector<int> b) {
        return a[0] < b[0];
    }

    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), comp);
        auto nn = *max_element(events.begin(), events.end(), [](vector<int> a, vector<int> b) {return a[1] < b[1]; });
        int n = nn[1];
        int idx = 0;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            while (idx < events.size() && events[idx][0] == i) {
                heap.push(Event(events[idx][0], events[idx][1]));
                idx++;
            }
            if (heap.empty())continue;
            heap.pop();
            res++;
            while (!heap.empty() && heap.top().ed <= i)heap.pop();
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<vector<int>> events = { {1, 2}, {2, 3}, {3, 4} };
    cout << S.maxEvents(events);
}