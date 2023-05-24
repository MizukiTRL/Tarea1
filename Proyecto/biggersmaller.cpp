#include "BigData.h"
#include <iostream>
#include <vector>

using namespace std;

string reverseString(string str) {
    std::string reversed;
    for (int i = str.length() - 1; i >= 0; i--) {
        reversed += str[i];
    }
    return reversed;
}

int main(){

    string input;
    string intPart;
    string floatPart;
    
    bool point;

    int cases=0;

    while (cases<1){
        cin>>input;
        point=false;
        for(char c: input){
            if(c!=' '){
                if(c!='.' && !point){
                    intPart += c;
                }else if(c!='.' && point){
                    floatPart += c;
                }else{
                    point=true;
                }
            }
        }
        cout<<intPart<<endl;
        BigInteger numInt1(intPart);

        //BigInteger numFloat1(reverseString(floatPart));

        //cout<<numInt1.toString()<<endl;
        cout<<floatPart<<endl;
        //cout<<numFloat1.toString()<<endl;
        
        intPart="";
        floatPart="";

        cin>>input;
        point=false;
        for(char c: input){
            if(c!=' '){
                if(c!='.' && !point){
                    intPart += c;
                }else if(c!='.' && point){
                    floatPart += c;
                }else{
                    point=true;
                }
            }
        }

        

        cout<<intPart<<endl;
        cout<<floatPart<<endl;

        intPart="";
        floatPart="";

        cases++;
    }

    return 0;
}