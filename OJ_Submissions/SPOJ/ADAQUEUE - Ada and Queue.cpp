#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int t,x,flag=1;
    cin>>t;
    deque <int> arr;
    string ss;

    while(t--)
    {
        cin.ignore();
        cin>>ss;

        if(ss=="back")
        {
            if(arr.empty())
                cout<<"No job for Ada?"<<endl;
            else
            {
                if(flag%2)
                {
                    cout<<arr.back()<<endl;
                    arr.pop_back();
                }
                else
                {
                    cout<<arr.front()<<endl;
                    arr.pop_front();
                }


            }
        }

        else if(ss=="front")
        {
            if(arr.empty())
                cout<<"No job for Ada?"<<endl;
            else
            {
                if(flag%2)
                {
                    cout<<arr.front()<<endl;
                    arr.pop_front();
                }
                else
                {
                    cout<<arr.back()<<endl;
                    arr.pop_back();
                }
            }

        }
        else if(ss=="reverse")
        {
            flag++;
        }
        else if(ss=="push_back")
        {
            cin>>x;
            if(flag%2)
                arr.push_back(x);
            else
                arr.push_front(x);


        }
        else if(ss=="toFront")
        {
            cin>>x;
            if(flag%2)
                arr.push_front(x);
            else
                arr.push_back(x);
        }

        //for(int i=0;i<arr.size();i++)
        //cout<<arr[i]<<" ";
        //cout<<endl;


    }

    return 0;
}
