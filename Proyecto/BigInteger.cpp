#include "BigData.h"
#include <iostream>

using namespace std;

BigInteger::BigInteger(string digits){

    if (!digits.empty() && digits[0] == '-') {
        isNegative = true;
        digits = digits.substr(1); 
    }

    for(char c : digits){
        if (isdigit(c)) {
            int digit = c - '0';
            this->digits.push_back(digit);
        }
    }

}

BigInteger::BigInteger(const BigInteger& other) {
    digits = other.digits;
    isNegative = other.isNegative;
}

bool BigInteger::equalOP(const BigInteger& other) {
    if (isNegative != other.isNegative) {
        return false;
    }

    if (digits.size() != other.digits.size()) {
        return false;
    }

    for (int i = digits.size() - 1; i >= 0; i--) {
        if (digits[i] != other.digits[i]) {
            return false;
        }
    }

    return true;
}

bool BigInteger::compareOP(const BigInteger& other) {
    // true = less than, false = more than

    if (isNegative && !other.isNegative) {
        return true;
    } else if (!isNegative && other.isNegative) {
        return false;
    }

    if (isNegative && other.isNegative) {
        // Both numbers are negative
        cout<<"works"<<endl;
        if (digits.size() == other.digits.size()) {
            for (int i = 0; i<digits.size(); i++) {
                if (digits[i] > other.digits[i]) {
                    return false; // Negative number with larger digits is smaller
                } else if (digits[i] < other.digits[i]) {
                    return true; // Negative number with smaller digits is larger
                }
            }
        } else {
            cout<<"works"<<endl;
            return digits.size() > other.digits.size(); // Negative number with fewer digits is larger
        }
    } else {
        // Both numbers are positive

        if (digits.size() == other.digits.size()) {
            for (int i = 0; i<digits.size(); i++) {
                if (digits[i] > other.digits[i]) {
                    return false; // Positive number with larger digits is smaller
                } else if (digits[i] < other.digits[i]) {
                    return true; // Positive number with smaller digits is larger
                }
            }
        } else {
            //return digits.size() > other.digits.size(); // Positive number with more digits is larger

            if(digits.size() > other.digits.size()){
                return false;
            }else if(digits.size() < other.digits.size()){
                return true;
            }
        }
    }
    return true; // Numbers are equal
}

bool BigInteger::operator==(const BigInteger& other){
    return equalOP(other);
}

bool BigInteger::operator!=(const BigInteger& other){
    return !equalOP(other);
}

bool BigInteger::operator<(const BigInteger& other){
    bool result = compareOP(other);
    if(equalOP(other)){
        result=false;
    }
    return result;
}

bool BigInteger::operator<=(const BigInteger& other){
    bool result=false;
    if(compareOP(other) || equalOP(other)){
        result= true;
    }
    return result;
}

bool BigInteger::operator>(const BigInteger& other){
    bool result=false;
    if(!(compareOP(other))){
        result= true;
    }

    if(equalOP(other)){
        result=false;
    }
    return result;
}

bool BigInteger::operator>=(const BigInteger& other){
    bool result=false;
    if(!(compareOP(other)) || equalOP(other)){
        result= true;
    }
    return result;
}

string BigInteger::SumOp(const BigInteger& other) {
    string result = "";
    int share = 0;

    for (int i = 0; i < this->digits.size() || i < other.digits.size(); i++) {
        int digit1;
        int digit2;
        
        if (i < this->digits.size()) {
            digit1 = this->digits[(this->digits.size()) - (i + 1)];
        } else {
            digit1 = 0;
        }

        if (i < other.digits.size()) {
            digit2 = other.digits[(other.digits.size()) - (i + 1)];
        } else {
            digit2 = 0;
        }

        int sum = digit1 + digit2 + share;

        if (sum > 9) {
            sum -= 10;
            share = 1;
        } else {
            share = 0;
        }

        result = to_string(sum) + result;
    }

    if (share > 0) {
        result = to_string(share) + result;
    }

    return result;
}

string BigInteger::RestOp(const BigInteger& other){
    string result="";
    int borrow=0;  

    for(int i=0; i<this->digits.size() || i<other.digits.size(); i++){

        int digit1;
        int digit2;
        

        if (i < this->digits.size()) {
        
            digit1 = this->digits[(this->digits.size())-(i+1)];
        }else{
            digit1 = 0;
        }

        if (i < other.digits.size()) {
        
            digit2 = other.digits[(other.digits.size())-(i+1)];
        }else{
            digit2 = 0;
        }

        int digit3;

        if (digits.size()>other.digits.size()){
            
            if (borrow) {
                digit1--;
                borrow = 0;
            }

            if (digit1 < digit2) {
                digit1 += 10;
                borrow = 1;
            }

            digit3 = digit1 - digit2;
        }else{

            if (borrow) {
                digit2--;
                borrow = 0;
            }

            if (digit2 < digit1) {
                digit2 += 10;
                borrow = 1;
            }

            digit3 = digit2 - digit1;
        }

        result= to_string(digit3) + result;
    }

    while (result.size() > 1 && result[0] == '0') {
        result.erase(0, 1);
    }

    if (compareOP(other)) {
        result = "-" + result;
    }
    return result;
}

BigInteger BigInteger::operator+(const BigInteger& other) {
    BigInteger result("");

    // Case 1: Both operands are positive
    if (!isNegative && !other.isNegative) {
        result = BigInteger(SumOp(other));
    }
    // Case 2: Both operands are negative
    else if (isNegative && other.isNegative) {
        result = BigInteger(SumOp(other));
        result.isNegative = true;
    }
    // Case 3: One operand is positive, the other is negative
    else {
        // If this operand is negative, swap the operands
        if (isNegative) {
            BigInteger copy = *this;
            result = copy.RestOp(other);
            if(other.digits.size()<copy.digits.size()){
                result.isNegative=true;
            }
        }
        else {
            BigInteger copy = other;
            copy.isNegative=false;
            result = BigInteger(RestOp(copy));
        }
    }

    return result;
}

BigInteger BigInteger::operator-(const BigInteger& other){
    
    BigInteger result("");

    // Case 1: Both operands are positive
    if (!isNegative && !other.isNegative) {
        result = BigInteger(RestOp(other));
    }
    // Case 2: Both operands are negative
    else if (isNegative && other.isNegative) {
        BigInteger copy = other;
        copy.isNegative=false;
        result = BigInteger(RestOp(copy));
        if(digits.size()>other.digits.size()){
            result.isNegative = true;
        }else{
            result.isNegative=false;
        }
    }
    // Case 3: One operand is positive, the other is negative
    else {
        // If this operand is negative, swap the operands
        if (isNegative) {
            BigInteger copy = *this; //non const copy
            result = copy.SumOp(other);
            result.isNegative = true;
        }
        else {
            result = BigInteger(SumOp(other));
        }
    }

    return result;
}

BigInteger BigInteger::operator*(const BigInteger& other){
    BigInteger result("");
    BigInteger copy = *this;
    BigInteger copy2 = other;
    copy2.isNegative=false;
    copy.isNegative=false;

    for(BigInteger i("0"); i.compareOP(copy2) && !i.equalOP(copy2); i= i+BigInteger("1")){
        result= result.SumOp(copy);
    }

    if((isNegative && !other.isNegative) || (!isNegative && other.isNegative)){
        result.isNegative=true;
    }

    return result;
}

BigInteger BigInteger::operator/(const BigInteger& other){
    BigInteger result("0");
    BigInteger copy = *this;
    BigInteger copy2 = other;
    copy2.isNegative=false;
    copy.isNegative=false;

    while (copy>BigInteger("0")){
        copy= copy-copy2;
        if(copy>=BigInteger("0")){
            result = result + BigInteger("1");
        }
    }
    

    if((isNegative && !other.isNegative) || (!isNegative && other.isNegative)){
        result.isNegative=true;
    }

    return result;
}

BigInteger BigInteger::operator%(const BigInteger& other){
    BigInteger result("0");
    BigInteger copy = *this;
    BigInteger copy2 = other;
    copy2.isNegative=false;
    copy.isNegative=false;

    if(copy==copy2){
        return BigInteger("0");
    }

    while (copy>BigInteger("0")){
        if(copy-copy2<=BigInteger("0")){
            result = copy;
        }
        copy= copy-copy2;
    }
    

    if((isNegative && !other.isNegative) || (!isNegative && other.isNegative)){
        result.isNegative=true;
    }

    
    return result;
}

BigInteger BigInteger::operator^(const int& exponent){
    BigInteger result("");
    BigInteger copy = *this;
    int copy2 = exponent;
    copy.isNegative=false;

    for(int i=0; i<copy2; i++){
        result= result*result;
    }

    if(isNegative && copy2%2!=0 && copy%BigInteger("0")!=BigInteger("0")){
        result.isNegative=true;
    }

    return result;
}

BigInteger BigInteger::sumarListaValores(const std::vector<BigInteger>& values) {
    BigInteger sum("0");

    for (const BigInteger& value : values) {
        sum = sum + value;
    }

    return sum;
}

BigInteger BigInteger::multiplicarListaValores(const std::vector<BigInteger>& values) {
    BigInteger result("1");

    for (const BigInteger& value : values) {
        result = result * value;
    }

    return result;
}

string BigInteger::toString(){
    string toString;
    
    for(int i : digits){
        toString+= to_string(i);
    }
    if(isNegative){
        toString="-" + toString;
    }
    return toString;
}


