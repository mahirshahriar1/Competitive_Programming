    #include <bits/stdc++.h>

    using namespace std;

    bool isNum(char x){
        return (x>='0' and x<='9');
    }

    bool isOperator(char x){
        return (x=='+'||x=='-'||x=='*'||x=='/');
    }

    int precedence(char op){
        if(op == '+'||op == '-')
            return 1;
        if(op == '*'||op == '/')
            return 2;
        return 0;
    }

    double evaluate(char x, double a, double b)
    {
        if     (x == '+') return a + b;    
        else if(x == '-') return a - b;
        else if(x == '*') return a * b;
        else if(x == '/') return a / b;       
    }

    void solve(string equation){
        string postfix="",temp="";
        bool unbalanced=false;

        stack<char> operands;
    
        for(auto x:equation){
            if(isNum(x)){                      
                temp+=x;
            }else{

                if(temp!=""){
                    postfix+=temp+'.';
                    temp="";                
                }

                if(isOperator(x)){
                    while(!operands.empty() and precedence(x)<=precedence(operands.top())){
                        postfix += operands.top();
                        operands.pop();
                    }
                    operands.push(x);
                }

                else if(x=='('){
                    operands.push(x);
                }

                else if(x==')'){
                    bool found=false;                
                
                    while(!operands.empty() and operands.top()!='('){                  
                        postfix+=operands.top();
                        operands.pop();

                        if(!operands.empty() and operands.top() == '('){                                         
                            found = true;
                        }      
                    }
                
                    if(!found){                    
                        unbalanced=true;
                        break;
                    }else{
                        operands.pop();
                    }
                }

                else{
                    continue;
                }
            }
        }

        if(unbalanced){
            cout<<"Invalid Expression."<<endl;
            return;
        }
        
        if(temp != ""){
            postfix += temp;
        }

        while(!operands.empty()){
            postfix+=operands.top();
            operands.pop();
        }

        double ans=0;
        stack<double> values;
        int ind=0;  

        while(ind<postfix.length()){

            if(isNum(postfix[ind])){
                string temp="";
                while(isNum(postfix[ind])){
                    temp+=postfix[ind++];
                }
                int num=stoi(temp);
                values.push(num);
            }

            else if(isOperator(postfix[ind])){

                if(values.empty()){              
                    unbalanced=true;
                    break;
                }

                double a=values.top();
                values.pop();
                
                if(values.empty()){                 
                    unbalanced=true;
                    break;
                }

                double b=values.top();
                values.pop();
                //cout<<b<<' '<<postfix[ind]<<' '<<a<<endl;  
                
                double c=evaluate(postfix[ind],b,a);
                values.push(c);
                ind++;
            
            }
            
            else{
                ind++;
            }
        }
        
        if(unbalanced or values.empty()){
            cout<<"Invalid Expression."<<endl;
        }else{
            cout<<values.top()<<endl;
        }

    }

    int main(){
        #ifndef ONLINE_JUDGE  
            freopen("input.txt", "r", stdin); 
            freopen("output.txt", "w",stdout);
        #endif
      /*10 + 3 * 5 / (16 - 4) 
      (5 + 3) * 12 / 3 
      3 + 4 / (2 - 3) * / 5 
      7 / 5 + (4 - (2) * 3 
      (5 + 3) * 12 / 3 )
      (5 + 3) * 12 / 3 + 3*/
        
        string line;
        while(getline(cin,line)){
            solve(line);
        }    

        return 0;
    }
