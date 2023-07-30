#include <bits/stdc++.h>

using namespace std;

vector<int> parseInts(string str)
{
    stringstream s(str);
    vector <int> v;
    char ch;
    int t;
    while(s>>t) // loop will continue as long as we can read data from streamline
    {
        v.push_back(t); //reads an int
        s>>ch; //then reads a comma. then loop continues
    }
    /*while(s)
    {
        if(s.peek()!=',')
        {
            if(s>>t)
                a.push_back(t);
        }
        else
            s>>ch;
    }*/

    return v;
}

int main()
{
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++)
          cout << integers[i] << endl;

    return 0;
}
