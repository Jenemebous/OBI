#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

struct Edge {
    int to;
    int length;
};

const int INF = numeric_limits<int>::max();

int main() {
    int N, M, C, K;
    cin >> N >> M >> C >> K;

    vector<int> people(N + 1, 0);
    for (int i = 0; i < C; ++i) {
        int room;
        cin >> room;
        people[room] = 1;
    }

    vector<vector<Edge>> graph(N + 1);
    for (int i = 0; i < M; ++i) {
        int A, B, D;
        cin >> A >> B >> D;
        graph[A].push_back({B, D});
    }

    vector<int> time(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    time[1] = 0;

    while (!pq.empty()) {
        int current_time = pq.top().first;
        int current_room = pq.top().second;
        pq.pop();

        if (current_room == N) {
            cout << current_time << endl;
            return 0;
        }

        if (current_time > time[current_room]) {
            continue;
        }

        for (const Edge& e : graph[current_room]) {
            int next_room = e.to;
            int next_time = current_time + e.length;
            
            if (people[next_room] && next_time <= K) {
                cout << next_time << endl;
                return 0;
            }
            
            if (next_time < time[next_room]) {
                time[next_room] = next_time;
                pq.push({next_time, next_room});
            }
        }
    }

    cout << -1 << endl;

    return 0;
}
