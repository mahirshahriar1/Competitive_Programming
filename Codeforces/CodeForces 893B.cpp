#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define endl '\n'

vector<bool> check(1e8,false);

vector<int> divisors(int n) {
    vector<int> div;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            div.push_back(i);
            if (n / i != i) {
                div.push_back(n / i);
            }
        }
    }
    sort(div.begin(), div.end());
    return div;
}

int bin_to_dec(string s) {
    int ret = 0;
    for (int i = 0; i < s.size(); i++)
        ret = (2*ret) + s[i] - '0';
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   check[1]=check[6]=check[28]=check[120]=check[496]=check[2016]=check[8128]=true;
   check[32640]=check[130816]=check[523776]=check[2096128]=check[8386560]=true;

    int n;
    cin>>n;
    vector<int> div=divisors(n);
    reverse(div.begin(),div.end());
    for(auto x:div){
        if(check[x])
        {
            cout<<x<<endl;
            return 0;
        }
    }


}
