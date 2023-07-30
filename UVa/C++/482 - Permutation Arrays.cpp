
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;

    cin>>t;
    cin.ignore();

    while(t--)
    {
        cin.ignore();
        string a,b;
        stringstream a1,b1;
        getline(cin,a);
        getline(cin,b);

        a1<<a;
        vector <int> v1;
        int x;
        while(a1>>x)
            v1.push_back(x);

        b1<<b;
        vector <string> v2;
        string temp;
        while(b1>>temp)
            v2.push_back(temp);

        map <int, string> m;

        for(int i=0;i <v1.size();i++)
        {
            m[v1[i]]= v2[i];
        }
        for(auto i: m)
        {
            cout<<(i.second)<<endl;
        }

        if(t)
            cout<<endl;
    }



    return 0;
}


/*

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
}*/



