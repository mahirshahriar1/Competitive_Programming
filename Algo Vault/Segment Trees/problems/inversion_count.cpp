#include <bits/stdc++.h>
using namespace std;

/// comparator for sorting in descending order
// bool comp(int a, int b) {
//      return a > b;
// }

bool comp(int a, int b)
{
    // even first odd later
    /// 0 < 1
    //    return ( (a % 2) + 2) % 2 < ((b % 2) + 2) % 2;
    if ((a & 1) && (a & 1) == (b & 1))
        return a > b;
    else if (!(a & 1) && (a & 1) == (b & 1))
        return a < b;
    return (a & 1) < (b & 1);
}

struct cmp
{
    /// operator overloading
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        //        return a.second < b.second;
    }
};

bool compnew(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

struct cmpv
{
    /// operator overloading
    bool operator()(int a, int b)
    {
        return a > b; /// descending order
    }
};

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://x...content-available-to-author-only...i.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);

    //    vector<int> v = {-1, 4 , 2, 5, 3 }; /// 2 4 .. 5 3 -1
    //    sort(v.begin(), v.end(), cmpv() );
    //    for (auto &x: v) cout << x << ' '; cout << endl;

    /// set of integers {1, 2, ... n}
    /// STL -> set

    //   set<int> st;
    //   /// set is implemented using red black tree
    //   st.insert(2); /// O(logn)
    //   st.insert(1);
    //    st.insert(5);
    //    st.insert(-1);
    //    st.insert(-1);
    //   /// sorted list
    //
    //    auto itr1 = st.begin();
    ////    cout << *itr1 << endl;
    //    auto itr2 = st.end();
    //    /// 1 2 5 xx
    ////    cout << *prev(prev(itr2)) << endl;
    ////    itr2++/itr2--;
    ////    itr2--;
    ////    cout << *itr2 << endl;
    //    /// iterator
    //    for (auto itr = st.begin(); itr != st.end() ; itr++) {
    //        cout << *itr << endl;
    //    }
    //    for (auto &x: st) {
    //        cout << x << endl;
    //    }
    //
    //    cout << st.size() << endl; /// 4
    ////    if (st.size() == 0) set is empty

    //    if(st.empty()) set is empty

    //    set<char/ string / long long/ pair<int,int>> st
    //    set<int, greater<int>> st2;
    //    set<pair<int,int> , compnew> st; /// O(logn)
    //    st.insert({2,-1});
    //    st.insert({3, -5});
    //
    //    cout << st.size() << endl;
    //    for (auto &x: st)
    //    {
    //        cout << x.first << ' ' << x.second << endl;
    //    }

    //    st.erase(5);
    //    st.erase(st.find(5));

    //    if (st.find(5) != st.end()) { /// if(st.count(5))
    //        element is present;
    //    }

    //   multiset<string> ms;
    //   ms.insert("abc");
    //    ms.insert("db");
    //    ms.insert("c");
    //    ms.insert("ab");
    //   ms.insert("abc");
    //
    ////   st.clear()
    //
    //
    ////    ms.erase("abc"); /// deletes all occurence of abc
    //    ms.erase(ms.find("abc")); /// first occ of abc
    ///// vector erase function O(n)
    ///// set multiset erase O(logn)
    //
    //    for (auto &x: ms) {
    //        cout << x << endl;
    //    }

    /// map has a key and a value

    //    map<int, string> mp; /// logn insertion deletion find
    //
    //    mp[1] = "abc";
    //    mp[3] = "a";
    //
    //    mp[-1] ="c";
    //
    //    for (auto &x: mp) {
    //        cout << x.first << ' ' << x.second << endl;
    //    }
    //
    //
    //    map<int, int> mp;
    //    mp.insert({1 , 2});
    //    mp.insert({3 , 4});
    //
    ////    if (mp[2]) {
    ////        cout << "present\n";
    ////    }
    //
    //    if(mp.find(3) != mp.end()) {
    //        cout << " 3 is present\n";
    //    }

    //
    ///// Problem: Count the frequency (number of occurrences) of each word in
    //        /// a sentence
    //        string sentence = "hello world hello hello world";
    //
    //        map<string , int> mp;
    ////        mp["hello"]++;
    ////    cout << mp["hello"] << endl;
    //        stringstream ss(sentence);
    //        string word;
    //        while(ss >> word) mp[word]++;
    //        for (auto &x: mp) {
    //            cout << x.first << ' ' << x.second << endl;
    //        }

    //    vector<char> v;
    //    string s = "1 2 , 22 33 4 -1";
    //    stringstream ss(s);
    //    char num;
    //    while (ss >> num) v.push_back(num);
    //    for (auto &x: v) cout << x << endl;

    //    map<int, pair<int, string>> mp;
    //    mp[2] = {9, "hi"};
    //    mp[3] = {-1, "bye"};
    //    auto val = mp.begin() -> second;
    //    cout << val.first << ' ' << val.second << endl;
    //
    //    for (auto &x: mp) {
    //        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    //    }
    //
    ////    for (auto it = mp.begin(); it != mp.end(); ++it) {
    ////        cout << it->first << " " << it->second << " ";
    ////    }
    ////    cout << "\n";
    ////
    ////    vector<int> v={1,2,3};
    ////    auto arr = v;
    //
    //
    //    unordered_map<long long, int, custom_hash> safe_map;
    //

    /// upper_bound >
    /// lower_bound >=
    /// you can use it in vector and the vector must be sorted

    vector<long> v = {1, 2, 4, 5, 99, 99, 999};

    auto lb = lower_bound(v.begin(), v.end(), 99); /// O(logn)
    auto ub = upper_bound(v.begin(), v.end(), 99); /// O(logn)
    int uind = ub - v.begin();
    int ind = lb - v.begin();
    cout << uind << endl;

    cout << *lb << ' ' << *ub << endl;

    auto itr = lower_bound(v.begin(), v.end(), 1000);
    if (itr == v.end())
    {
        cout << "not present\n";
    }

    //        if (*itr == 955) {
    //            cout << 955 << ' ' << " is present\n";
    //        } else {
    //            cout << *itr << endl;
    //        }

    return 0;
}
