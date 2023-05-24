#include "BigInteger.cpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string compareBigFloat(BigInteger& intP1,BigInteger& floatP1, BigInteger& intP2, BigInteger& floatP2){

    string f1= floatP1.toString();
    string f2= floatP2.toString();
    
    if(intP1<intP2){
        return "Smaller";
    }
    if(intP1>intP2){
        return "Bigger";
    }else{
        BigInteger smaller("");
        if(floatP1.size()<floatP2.size()){
            smaller=floatP1.size();
        }else{
            smaller=floatP2.size();
        }

        for(int i=0; i< stoi(smaller.toString()); i++){
            if(f1[i]<f2[i]){
                return "Smaller";
            }
            if(f1[i]>f2[i]){
                return "Bigger";
            }
        }
    }

    return "equal";
}


string reverseString(string str) {
    std::string reversed;
    for (int i = str.length() - 1; i >= 0; i--) {
        reversed += str[i];
    }
    return reversed;
}

int main(){

    string input;
    string input2;
    string intPart;
    string floatPart;
    
    bool point;

    int cases=0;

    while (cases<20){
        cin>>input>>input2;
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
        //cout<<intPart<<endl;
        BigInteger numInt1(intPart);
        //cout<<numInt1.toString()<<endl;

        //cout<<floatPart<<endl;
        BigInteger numFloat1(floatPart);
        //cout<<numFloat1.toString()<<endl;

        
        intPart="";
        floatPart="";

        point=false;
        for(char c: input2){
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

        //cout<<intPart<<endl;
        BigInteger numInt2(intPart);
        //cout<<numInt1.toString()<<endl;

        //cout<<floatPart<<endl;
        BigInteger numFloat2(floatPart);
        //cout<<numFloat1.toString()<<endl;
    
        intPart="";
        floatPart="";

        cout<<"case "<<cases+1<< ": " <<compareBigFloat(numInt1, numFloat1, numInt2, numFloat2)<<endl;

        cases++;
    }

    return 0;
}