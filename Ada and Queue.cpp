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
deque<int> adaQue;
int main(){

    fastInputOutput();
    screen.turnOf();

    int q;cin>>q;
    bool rev = 0;
    while(q--){
        string command;cin>>command;
        if(command == "toFront"){
            int val;cin>>val;
            if(!rev)
                adaQue.push_front(val);
            else
                adaQue.push_back(val);
        }else if(command == "push_back"){
            int val;cin>>val;
            if(!rev)
                adaQue.push_back(val);
            else
                adaQue.push_front(val);
        }else if(command == "front"){
            if(adaQue.size() > 0){
                if(!rev){
                    cout<<adaQue.front()<<endl;
                    adaQue.pop_front();
                }else{
                    cout<<adaQue.back()<<endl;
                    adaQue.pop_back();
                }
            }else{
                cout<<"No job for Ada?\n";
            }
        }else if(command == "back"){
            if(adaQue.size() > 0){
                if(!rev){
                    cout<<adaQue.back()<<endl;
                    adaQue.pop_back();
                }else{
                    cout<<adaQue.front()<<endl;
                    adaQue.pop_front();
                }
            }else{
                cout<<"No job for Ada?\n";
            }
        }else{
            rev = (rev == 0) ? 1:0;
        }
    }


    return 0;
}
