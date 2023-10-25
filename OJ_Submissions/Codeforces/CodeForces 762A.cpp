#include<bits/stdc++.h>
using namespace std;

vector<long long int> divisors(long long int n) {
    vector<long long int> div;
    for (long long int i = 1; i * i <= n; ++i) {
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



int main ()
{
    long long int a,b;

    cin>>a>>b;

    vector <long long int> arr= divisors(a);

    if(b>arr.size())
        cout<<"-1"<<endl;
    else
        cout<<arr[b-1]<<endl;


    return 0;

}

