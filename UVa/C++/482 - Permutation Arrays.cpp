//Brute force implementation. need to learn a better algorithm

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    char c;
    string a,b;
    vector <int> num;
    stringstream s;
    cin.ignore();
    while(n--)
    {
        cin.ignore();
        getline(cin,a);
        getline(cin,b);

        int x;
        s<<a;
        while(s>>x)
            num.push_back(x);

        int count=1;

        while(1)
        {
            if(count>num.size())
                break;

            int i=0;
            while(num[i]!=count)
                i++;

            int space_count=0;


            for(int j=0; j<b.size(); j++)
            {
                if(b[j]==' ')
                {
                    space_count++;
                }
                if(space_count>i)
                    break;
                if(space_count==i)
                {
                    if(b[j]==' ')
                        continue;
                    cout<<b[j];
                }


            }

                cout<<endl;

            count++;
        }
        if(n>=1)
            cout<<endl;
        

        a.erase();
        b.erase();
        num.clear();
        s.clear();


    }



    return 0;
}



