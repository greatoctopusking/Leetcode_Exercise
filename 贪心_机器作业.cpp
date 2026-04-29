#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

struct Job {
    int profit;
    int deadline;
    int id;
};

struct DSU {
    vector<int> parent;
    DSU(int n) : parent(n + 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        parent[x] = y;
        return true;
    }
};

int main() {
    int n;
    cout << "请输入作业数量: ";
    cin >> n;
    
    vector<Job> jobs(n);
    for (int i = 0; i < n; i++) {
        int p, d;
        cout << "请输入作业" << i + 1 << "的收益和截止时间: ";
        cin >> p >> d;
        jobs[i] = {p, d, i + 1};
    }
    
    sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
        return a.profit > b.profit;
    });
    
    int maxDeadline = 0;
    for (const auto& job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }
    
    DSU dsu(maxDeadline);
    vector<int> schedule(maxDeadline + 1, -1);
    long long totalProfit = 0;
    
    for (const auto& job : jobs) {
        int availableTime = dsu.find(job.deadline);
        if (availableTime > 0) {
            schedule[availableTime] = job.id;
            totalProfit += job.profit;
            dsu.unite(availableTime, availableTime - 1);
        }
    }
    
    cout << "\n最大收益: " << totalProfit << endl;
    cout << "作业安排:" << endl;
    for (int t = 1; t <= maxDeadline; t++) {
        if (schedule[t] != -1) {
            cout << "时间" << t << ": 作业" << schedule[t] << endl;
        }
    }
    
    return 0;
}