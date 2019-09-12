/*
Design a DFA to accept all the strings over alphabet {0,1} which are divisible by 3
*/
#include<iostream>
using namespace std;

typedef struct Node{
        string name;
        bool isFinal = 0;
        struct Node *zeroInput  = NULL;
        struct Node *oneInput = NULL;
    } State;

class numberDivisibleBy3 {

    State q1,q2,q3,q4;

    public:
    numberDivisibleBy3(){
        q1.name = "q1";
        q2.name = "q2";
        q3.name = "q3";
        q4.name = "q4";
        q2.isFinal = 1;
        
        //q1 state
        q1.zeroInput = &q2;
        q1.oneInput = &q3;
        //q2 state
        q2.zeroInput = &q2;
        q2.oneInput = &q3;
        //q3 state
        q3.zeroInput = &q4;
        q3.oneInput = &q2;
        //q4 state
        q4.zeroInput = &q3;
        q4.oneInput = &q4;
    }
    //returns whether the string is in final state
    //Along with that it prints the transitions
    bool determine(string inputString) {
        State *presentState = &q1;
        cout<<presentState->name;
        for(char c:inputString){
            if(c == '0'){
                presentState = presentState->zeroInput;
                cout<<"-->"<<presentState->name;
            }else{
                presentState = presentState->oneInput;
                cout<<"-->"<<presentState->name;
            }
        }
        cout<<'\n';
        return presentState->isFinal;
    }

};


int main(){
    numberDivisibleBy3 fsm;
    bool accepted = fsm.determine("");
    if(accepted) cout<<"accepted";
    else cout<<"Not accepted";
    return 0;
}