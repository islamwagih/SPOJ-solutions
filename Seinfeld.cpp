#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (int)_s.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

/**Not part of the solution it's just a logger to help me debug quickly**/
class Logger{
    bool loggerIsWorking = 1;
public:
    void log(const char* msg, long double val = INT_MIN){
        if(loggerIsWorking){
            if(val != INT_MIN){
                cout<<msg<<" "<<val<<endl;
            }else{
                cout<<msg<<endl;
            }
        }
    }

    void log(char* msg, long double val = INT_MIN){
        if(loggerIsWorking){
            if(val != INT_MIN){
                cout<<msg<<" "<<val<<endl;
            }else{
                cout<<msg<<endl;
            }
        }
    }

    void log(string& msg, long double val = INT_MIN){
        if(loggerIsWorking){
            if(val != INT_MIN){
                cout<<msg<<" "<<val<<endl;
                cout<<msg<<endl;
            }
            }else{
        }
    }

    void log(string&& msg, long double val = INT_MIN){
        if(loggerIsWorking){
            if(val != INT_MIN){
                cout<<msg<<" "<<val<<endl;
            }else{
                cout<<msg<<endl;
            }
        }
    }

    void turnOf(){
        loggerIsWorking = 0;
    }

    void turnOn(){
        loggerIsWorking = 1;
    }

};

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

Logger screen;




int main(){

    fastInputOutput();
    screen.turnOf();

    string str;
    int test = 1;
    while(cin>>str){
        if(str[0] == '-'){
            break;
        }
        stack<char> corrector;
        int sz = getSize(str), ans = 0;
        if(str[0] == '}'){
            ans++, str[0] = '{';
        }
        if(sz > 1 && str[sz-1] == '{'){
            ans++, str[sz-1] = '}';
        }
        for(int i=0;i<sz;i++){
            if(str[i] == '{'){
                corrector.push('{');
            }else if(corrector.size() > 0){
                corrector.pop();
            }else{
                ans++;
                corrector.push('{');
            }
        }
        while(!corrector.empty()){
            ans++;
            corrector.pop();corrector.pop();
        }
        cout<<test++<<". "<<ans<<endl;
    }

    return 0;
}
