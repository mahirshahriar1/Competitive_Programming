#include<bits/stdc++.h>
using namespace std;

bool div(string str, int num)
{
    int rem=0;
    for(int i=0;i<str.length();i++)
    {
        int digit=str[i]-'0';
        rem=(rem*10)+digit;
        //cout<<rem<<endl;
        rem=rem%num;

    }
    if(rem==0)
        return true;
    else
        return false;
}

bool leap_year(string s)
{

    if(div(s,400))
        return true;
    else if(div(s,100))
        return false;
    else if(div(s,4))
        return true;
    else
        return false;
}


int main ()
{
   string year;
    int count=0;
   while(cin>>year)
   {
       if(count)
        cout<<endl;

       int flag=1;
       if(leap_year(year))
       {
           cout<<"This is leap year."<<endl;
           flag=0;
       }
       if(div(year,15))
       {
         cout<<"This is huluculu festival year."<<endl;
         flag=0;
       }
       if(div(year,55)&&leap_year(year))
       {
         cout<<"This is bulukulu festival year."<<endl;
         flag=0;
       }
       if(flag)
       {
         cout<<"This is an ordinary year."<<endl;
       }

       count=1;
   }


    return 0;

}
