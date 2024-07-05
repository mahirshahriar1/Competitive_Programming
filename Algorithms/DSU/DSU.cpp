struct DSU
{
    vector<int> rep; 
    int cc;
    DSU(int sz){ rep = vector<int>(sz, -1); cc = sz - 1; }
    
    int get(int x) { return rep[x] < 0 ? x : rep[x] = get(rep[x]); }
    bool same_set(int x, int y) { return get(x) == get(y); }
    int size(int x) { return -rep[get(x)]; }

    bool unite(int x, int y)
    { 
        x = get(x), y = get(y);
        if (x == y) return false;
        if (rep[x] > rep[y]) swap(x, y); 
        rep[x] += rep[y];
        cc--;
        rep[y] = x;
        return true;
    }
};

