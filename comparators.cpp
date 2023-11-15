#include <bits/stdc++.h>
using namespace std;

struct comp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second; 
    }
};

struct edge {
    int u, v, w;
    bool operator<(const edge& e) const {
        return w > e.w;
    }
};

struct node {
    int x;
    bool operator<(const node& n) const {
        return x > n.x;
    }
};

int main() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
    pq.push({1, 2});
    pq.push({2, 1});
    while (!pq.empty()) {
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }   
 

    set <edge > st;
    st.insert({1, 2, 3});
    st.insert({2, 3, 4});
    for (auto& x : st) {
        cout << x.u << " " << x.v << " " << x.w << endl;
    }
    
    set <node> st2;
    st2.insert({1});
    st2.insert({2});
    for (auto& x : st2) {
        cout << x.x << endl;
    }

    return 0;
}
