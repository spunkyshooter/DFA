/*
Design a DFA for accepting L = {ab^(5)a^(2) : w belongs to {a,b}^*}
*/
#include<iostream>
using namespace std;

typedef struct Node{
        string name;
        bool isFinal = 0;
        struct Node *aInput  = NULL;
        struct Node *bInput = NULL;
    } State;

class FA {

    State q1,q2,q3,q4,q5,q6,q7,q8,q9,q10; 

    public:
    FA(){
        q1.name = "q1";
        q2.name = "q2";
        q3.name = "q3";
        q4.name = "q4";
        q5.name = "q5";
        q6.name = "q6";
        q7.name = "q7";
        q8.name = "q8";
        q9.name = "q9"; //final state
        q10.name = "q10"; //q10 is trap state

      

        q9.isFinal = 1;
        
        //q1 state
        q1.aInput = &q2;
        q1.bInput = &q10;
       
        //q2 state
        q2.aInput = &q10;
        q2.bInput = &q3;
        //q3 state
        q3.aInput = &q10;
        q3.bInput = &q4;
        //q4 state
        q4.aInput = &q10;
        q4.bInput = &q5;
        //q5 state
        q5.aInput = &q10;
        q5.bInput = &q6;
        
        //q6 state
        q6.aInput = &q10;
        q6.bInput = &q7;
        //q7 state
        q7.aInput = &q7;
        q7.bInput = &q8;
        //q8 state
        q8.aInput = &q7;
        q8.bInput = &q9;
        //q9 state
        q9.aInput = &q7;
        q9.bInput = &q9;
        //q10 state
        q10.aInput = &q10;
        q10.bInput = &q10;
   

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
    FA fsm;
    string ip; cout<<"Enter String: "; cin>>ip;
    bool accepted = fsm.determine(ip);
    if(accepted) cout<<"accepted";
    else cout<<"Not accepted";
    return 0;
}