/*
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k,m,input;
    char ch;

    cin>>n;

    while(n--)
    {
        string s,alpha;
        vector <int> money;
        long payment=0;

        cin>>k;

        while(k--)
        {
            cin>>ch;
            alpha.push_back(ch);
            cin>>input;
            money.push_back(input);
        }

            cin>>m;
            cin.ignore();


            while(m--)
            {
                getline(cin,s);

                for(int i=0; i<s.length(); i++)
                {
                    for(int j=0; j<alpha.length(); j++)
                    {
                        if(s[i]==alpha[j])
                        {
                            payment+=money[j];
                            break;
                        }
                    }

                }
            }


            if(payment%100<10)
                cout<<payment/100<<".0"<<payment%100<<"$"<<endl;
            else
                cout<<payment/100<<"."<<payment%100<<"$"<<endl;
        }



        return 0;
    }
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k,a;
    char b;

    cin>>n;
    while(n--)
    {
        map <char, double> list;
        cin>>k;
        while(k--)
        {
            cin>>b>>a;
            list[b]=a;
        }
        cin>>k;
        cin.ignore();

        string str;
        double price=0;
        for(int i=0;i<k;i++)
        {
            getline(cin,str);
            for(int i=0;i<str.size();i++)
            {
                auto it= list.find(str[i]);
                if(it!=list.end())
                    price+=it->second;
            }
          }
        cout<<fixed<<setprecision(2)<<price/100<<"$"<<endl;

    }


    return 0;
}




