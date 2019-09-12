/*
Design a DFA to accept all the strings over alphabet {a,b} , having "b" at
the starting and "aba" at the end
*/
#include<iostream>
using namespace std;

typedef struct Node{
        string name;
        bool isFinal = 0;
        struct Node *aInput  = NULL;
        struct Node *bInput = NULL;
    } State;

class b_At_start_aba_At_End {

    State q1,q2,q3,q4,q5,q6; //q6 = trap state

    public:
    b_At_start_aba_At_End(){
        q1.name = "q1";
        q2.name = "q2";
        q3.name = "q3";
        q4.name = "q4";
        q5.name = "q5";
        q6.name = "q6";

        q4.isFinal = 1;
        
        //q1 state
        q1.bInput = &q2;
        q1.aInput = &q6;
        //q2 state
        q2.aInput = &q3;
        q2.bInput = &q2;
        //q3 state
        q3.aInput = &q3;
        q3.bInput = &q4;
        //q4 state
        q4.aInput = &q4;
        q4.bInput = &q2;
        //q5 state
        q5.aInput = &q3;
        q5.bInput = &q4;
        //trap state
        q6.aInput = &q6;
        q6.bInput = &q6;
    }
    //returns whether the string is in final state
    //Along with that it prints the transitions
    bool determine(string inputString) {
        State *presentState = &q1;
        cout<<presentState->name;
        for(char c:inputString){
            if(c == 'a'){
                presentState = presentState->aInput;
                cout<<"-->"<<presentState->name;
            }else{
                presentState = presentState->bInput;
                cout<<"-->"<<presentState->name;
            }
        }
        cout<<'\n';
        return presentState->isFinal;
    }

};


int main(){
    b_At_start_aba_At_End fsm;
    bool accepted = fsm.determine("bbaabba");
    if(accepted) cout<<"accepted";
    else cout<<"Not accepted";
    return 0;
}