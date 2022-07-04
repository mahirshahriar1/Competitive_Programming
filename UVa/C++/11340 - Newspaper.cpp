// need to update this one

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



