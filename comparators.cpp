struct comp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second; 
    }
};

auto cmp = [](int a, int b) { return a < b; };

int main() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
    pq.push({1, 2});
    pq.push({2, 1});
    while (!pq.empty()) {
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }
    
    set<int, decltype(cmp)> s;
    s.insert(1);
    s.insert(2);

    for (auto& x : s) {
        cout << x << endl;
    }

    return 0;
}
