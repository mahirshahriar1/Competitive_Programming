#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int t,i=1,n,m,x;

    cin>>t;

    deque <int> arr;
    string s;

    while(t--)
    {
        cin>>n>>m;
        cin.ignore();
        cout<<"Case "<<i++<<":"<<endl;
        while(m--)
        {
            cin>>s;
            if(s=="pushLeft")
            {
                cin>>x;
                    cin.ignore();
                if(arr.size()==n)
                    cout<<"The queue is full"<<endl;
                else
                {
                    arr.push_front(x);
                    cout<<"Pushed in left: "<<x<<endl;
                }
            }
            else if(s=="pushRight")
            {
                    cin>>x;
                    cin.ignore();
                if(arr.size()==n)
                    cout<<"The queue is full"<<endl;
                else
                {
                    arr.push_back(x);
                    cout<<"Pushed in right: "<<x<<endl;
                }
            }
            else if(s=="popLeft")
            {
                if(arr.size()==0)
                    cout<<"The queue is empty"<<endl;
                else{
                    cout<<"Popped from left: "<<arr.front()<<endl;
                    arr.pop_front();
                }
            }
            else if(s=="popRight")
            {
                if(arr.size()==0)
                    cout<<"The queue is empty"<<endl;
                else{
                    cout<<"Popped from right: "<<arr.back()<<endl;
                    arr.pop_back();
                }
            }
            //for(int i=0;i<arr.size();i++)
                //cout<<arr[i]<<endl;
        }

        arr.clear();
    }
}

