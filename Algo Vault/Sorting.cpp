//Counting Sort

#include <bits/stdc++.h>
using namespace std;


void countSort(vector<pair<int, int>> &v){
    int min = v[0].first, max = v[0].first;
    for(int i = 1; i < v.size(); i++){
        if(v[i].first < min) min = v[i].first;
        if(v[i].first > max) max = v[i].first;
    }

    int range = max - min + 1;

    vector<int> count(range);
    vector<pair<int, int>> output(v.size());
    for(int i = 0; i < v.size(); i++)
        count[v[i].first - min]++;
    for(int i = 1; i < count.size(); i++)
        count[i] += count[i-1];

    for(int i = count.size()-2; i >= 0; i--)
        count[i+1] = count[i];
    count[0] = 0;

        
    for(int i = 0; i < v.size(); i++){
        output[count[v[i].first - min]] = v[i];
        count[v[i].first - min]++;
    }

    for(int i = 0; i < v.size(); i++) 
        v[i] = output[i];      
}

int main(){
    vector<pair<int, int>> v;
    int n;
    int i = 0;
    while(cin >> n){
        v.push_back({n,++i});
    }
    countSort(v);
    for(auto x : v)
        cout << x.first << " " << x.second << endl;
    

    return 0;
}
void merge(vector<int> &v, int l, int m, int r){
    int n1 = m-l+1, n2 = r-m;
    vector<int> L(n1), R(n2);
    for(int i = 0; i < n1; i++)
        L[i] = v[l+i];
    for(int i = 0; i < n2; i++)
        R[i] = v[m+1+i];
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(L[i] <= R[j])
            v[k++] = L[i++];
        else
            v[k++] = R[j++];
    }
    while(i < n1)
        v[k++] = L[i++];
    while(j < n2)
        v[k++] = R[j++];
}


void mergeSort(vector<int> &v, int l, int r){
    if(l < r){
        int m = (l+r)/2;
        mergeSort(v, l, m);
        mergeSort(v, m+1, r);
        merge(v, l, m, r);
    }
}