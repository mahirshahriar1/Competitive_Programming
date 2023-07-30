string multiplication(string s1,string s2){
    int n1=s1.size();
    int n2=s2.size();
    if(n1==0 || n2==0) return "0";
    vector<int> result(n1+n2,0);
    int i_n1=0;
    int i_n2=0;
    for(int i=n1-1;i>=0;i--){
        int carry=0;
        int n1=s1[i]-'0';
        i_n2=0;
        for(int j=n2-1;j>=0;j--){
            int n2=s2[j]-'0';
            int sum=n1*n2+result[i_n1+i_n2]+carry;
            carry=sum/10;
            result[i_n1+i_n2]=sum%10;
            i_n2++;
        }
        if(carry>0){
            result[i_n1+i_n2]+=carry;
        }
        i_n1++;
    }
    int i=result.size()-1;
    while(i>=0 && result[i]==0){
        i--;
    }
    if(i==-1) return "0";
    string s="";
    while(i>=0){
        s+=to_string(result[i--]);
    }
    return s;
}

----------------------------------------------
// Returns true if str1 is smaller than str2.
bool isSmaller(string str1, string str2)
{
    // Calculate lengths of both string
    int n1 = str1.length(), n2 = str2.length();
 
    if (n1 < n2)
       return true;
    if (n2 < n1)
       return false;
 
    for (int i=0; i<n1; i++)
       if (str1[i] < str2[i])
          return true;
       else if (str1[i] > str2[i])
          return false;
 
    return false;
}
 
// Function for find difference of larger numbers
string findDiff(string str1, string str2)
{
    // Before proceeding further, make sure str1
    // is not smaller
    if (isSmaller(str1, str2))
        swap(str1, str2);
 
    // Take an empty string for storing result
    string str = "";
 
    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();
 
    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
 
    int carry = 0;
 
    // Run loop till small string length
    // and subtract digit of str1 to str2
    for (int i=0; i<n2; i++)
    {
        // Do school mathematics, compute difference of
        // current digits
        int sub = ((str1[i]-'0')-(str2[i]-'0')-carry);
 
        // If subtraction is less then zero
        // we add then we add 10 into sub and
        // take carry as 1 for calculating next step
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }
 
    // subtract remaining digits of larger number
    for (int i=n2; i<n1; i++)
    {
        int sub = ((str1[i]-'0') - carry);
        carry = 0;
        str.push_back(sub + '0');
    }
 
    // reverse resultant string
    reverse(str.begin(), str.end());
 
    return str;
}
----------------------------------------------

string subtraction(string s1,string s2){
    if(isSmaller(s1,s2)){
        swap(s1,s2);
    }
    string s="";
    int n1=s1.size();
    int n2=s2.size();
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    int carry=0;
    for(int i=0;i<n2;i++){
        int sub=((s1[i]-'0')-(s2[i]-'0')-carry);
        if(sub<0){
            sub=sub+10;
            carry=1;
        }
        else{
            carry=0;
        }
        s.push_back(sub+'0');
    }
    for(int i=n2;i<n1;i++){
        int sub=((s1[i]-'0')-carry);
        carry=0;
        s.push_back(sub+'0');
    }
    reverse(s.begin(),s.end());
    return s;
}

-------------------
void omitleadingzeroes(string &s){
    int i=0;
    while(i<s.size() && s[i]=='0'){
        i++;
    }
    s=s.substr(i);
}

void addnumbers(string &a,string &b){
    int carry=0;
    string ans="";
    reverse(range(a));
    reverse(range(b));
    for(int i=0;i<max(a.size(),b.size());i++){       
        int x=0,y=0;
        if(i<a.size()) x=a[i]-'0';
        if(i<b.size()) y=b[i]-'0';
        int sum=x+y+carry;
        carry=sum/10;
        sum%=10;
        ans+=sum+'0';
    }
    if(carry) ans+=carry+'0';
    reverse(range(ans));
    omitleadingzeroes(ans);
    cout<<ans<<endl;
}
------------------------
string addition( string a, string b){
    if(a.size()<b.size()) swap(a,b);
    int n1=a.size(),n2=b.size();
    reverse(range(a));
    reverse(range(b));
    int carry=0;
    vector<int> result(n1+1);
    int i_n1=0,i_n2=0;
    while(i_n2<n2){
        int sum=(a[i_n1]-'0')+(b[i_n2]-'0')+carry;
        result[i_n1]=sum%10;
        carry=sum/10;
        i_n1++;
        i_n2++;
    }
    while(i_n1<n1){
        int sum=(a[i_n1]-'0')+carry;
        result[i_n1]=sum%10;
        carry=sum/10;
        i_n1++;
    }
    if(carry>0){
        result[i_n1]+=carry;
    }
    int i=result.size()-1;
    while(i>=0 && result[i]==0){
        i--;
    }
    if(i==-1) return "0";
    string s="";
    while(i>=0){
        s+=to_string(result[i--]);
    }
    return s;
}
------------------------------
