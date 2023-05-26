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
    string input3;
    string intPart;
    string floatPart;
    
    bool point;

    int cases=0;

    while (getline(cin, input) && !cin.eof()) {
        input2="";
        input3="";

        point=false;
        for(char c: input){

            if(c!=' ' && !point){
                input2 += c;
            }else if(c!=' ' && point){
                input3 += c;
            }else if(c==' '){
                point=true;
            }
            
        }
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

        BigInteger numInt1(intPart);
        BigInteger numFloat1(floatPart);

        
        intPart="";
        floatPart="";

        point=false;
        for(char c: input3){
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

        BigInteger numInt2(intPart);


        BigInteger numFloat2(floatPart);
    
        intPart="";
        floatPart="";

        cout<<"Case "<<cases+1<< ": " <<compareBigFloat(numInt1, numFloat1, numInt2, numFloat2)<<endl;

        cases++;

    }

    return 0;
}

