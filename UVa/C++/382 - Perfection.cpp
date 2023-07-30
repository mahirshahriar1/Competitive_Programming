#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;

int summ(int n) {
    int sum=0;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            sum+=i;
            if (n / i != i) {
                  sum+=(n/i);
            }
        }
    }

    return sum-n;
}

int main()
{
    fastio;

    printf("PERFECTION OUTPUT\n");

    int num;

    while(cin>>num, num!=0)
    {
        int val=summ(num);
        if(val==num)
            printf("%5d  PERFECT\n",num);
        else if(val>num)
            printf("%5d  ABUNDANT\n",num);
        else
            printf("%5d  DEFICIENT\n",num);

    }
    printf("END OF OUTPUT\n");


    return 0;
}
