#ifndef w7integer_H
#define w7integer_H
#include <string>
#include <iostream>
class Integer{
    public:
        int data;
        Integer(){

        }
        Integer(int input){
            data = input;
        };
        Integer(std::string input){
            data = std::stoi(input);
        };
         friend std::ostream& operator<<(std::ostream &output, const Integer &out); //done
         friend std::istream& operator>>(std::istream &output, Integer &out); //done
         friend Integer operator+(const Integer &input, const int &in); //done
         friend Integer operator+(const Integer &input,const Integer &input2); //
         friend Integer operator+(const int &in, const Integer &input); //done
         friend Integer operator-(const Integer &input, const int &in); //done
         friend Integer operator-(const Integer &input,const Integer &input2); //
         friend Integer operator-(const int &in, const Integer &input); //done
         friend Integer operator-(const Integer &input); //done
         friend Integer operator*(const Integer &input, const int &in); //done
         friend Integer operator*(const Integer &input,const Integer &input2); //
         friend Integer operator*(const int &in, const Integer &input); //done
        //  Integer operator/(const Integer &input); //done
        //  Integer operator%(const Integer &input); //done
        //  Integer operator++(int); //done
        //  Integer operator--(int); //done
        //  Integer& operator++(); //done
        //  Integer& operator--(); //done
        //  bool operator==(const Integer &input); //done
        //  bool operator!=(const Integer &input); //done
        //  bool operator>(const Integer &input); //done
        //  bool operator<(const Integer &input); //done
        //  bool operator>=(const Integer &input); //done
        //  bool operator<=(const Integer &input); //done
        //  Integer operator+=(const Integer &input); //done
        //  Integer operator-=(const Integer &input); //done
        //  Integer operator*=(const Integer &input); //done
        //  Integer operator/=(const Integer &input); //done
        //  Integer operator%=(const Integer &input); //done
};
    std::ostream& operator<<(std::ostream &output, const Integer &out){
        output << out.data;
        return output;
    }
    std::istream& operator>>(std::istream &output, Integer &out){
        output >> out.data;
        return output;
    }
    Integer operator+(const Integer &input, const int &in) {
        Integer result;
        result.data = input.data + in;
        return result;
    }
    Integer operator+(const Integer &input,const Integer &input2) {
        Integer result;
        result.data = input.data + input2.data;
        return result;
    }
    Integer operator+(const int &input, const Integer &in) {
        Integer result;
        result.data = in.data + input;
        return result;
    }
    Integer operator-(const Integer &input, const int &in) {
        Integer result;
        result.data = input.data - in;
        return result;
    }
    Integer operator-(const Integer &input,const Integer &input2) {
        Integer result;
        result.data = input.data - input2.data;
        return result;
    }
    Integer operator-(const int &input, const Integer &in) {
        Integer result;
        result.data = input - in.data;
        return result;
    }
    Integer operator-(const Integer &input) {
        Integer result;
        result.data = -input.data;
        return result;
    }
    Integer operator*(const Integer &input, const int &in) {
        Integer result;
        result.data = input.data * in;
        return result;
    }
    Integer operator*(const Integer &input,const Integer &input2) {
        Integer result;
        result.data = input.data * input2.data;
        return result;
    }
    Integer operator*(const int &input, const Integer &in) {
        Integer result;
        result.data = input * in.data;
        return result;
    }
    // Integer Integer::operator*(const Integer &input) {
    //     Integer result = new Integer(this->data * input.data)
    //     return result;
    // }
    // Integer Integer::operator/(const Integer &input) {
    //     Integer result = new Integer(this->data / input.data)
    //     return result;
    // }
    // Integer Integer::operator%(const Integer &input) {
    //     Integer result = new Integer(this->data % input.data)
    //     return result;
    // }
    // Integer Integer::operator++(int) {
    //     Integer result = *this;
    //     ++*this->data;
    //     return result;
    // }
    // Integer& Integer::operator++() {
    //     data++;
    //     return *this;
    // }
    // Integer Integer::operator--(int) {
    //     Integer result = *this;
    //     --*this->data;
    //     return result;
    // }
    // Integer& Integer::operator--() {
    //     data--;
    //     return *this;
    // }
    // bool Integer::operator==(const Integer &input) {
    //     if (this->data == input.data){
    //         return true;
    //     }
    //     return false;
    // }
    // bool Integer::operator!=(const Integer &input) {
    //     if (this->data != input.data){
    //         return true;
    //     }
    //     return false;
    // }
    // bool operator>=(const Integer &input) {
    //     if (this->data >= input.data){
    //         return true;
    //     }
    //     return false;
    // }
    // bool operator<=(const Integer &input) {
    //     if (this->data <= input.data){
    //         return true;
    //     }
    //     return false;
    // }
    // bool operator>(const Integer &input) {
    //     if (this->data > input.data){
    //         return true;
    //     }
    //     return false;
    // }
    // bool operator<(const Integer &input) {
    //     if (this->data < input.data){
    //         return true;
    //     }
    //     return false;
    // }
    // Integer operator+=(const Integer &input) {
    //     this->data += input.data;
    //     return *this;
    // }
    // Integer operator-=(const Integer &input) {
    //     this->data -= input.data;
    //     return *this;
    // }
    // Integer operator*=(const Integer &input) {
    //     this->data *= input.data;
    //     return *this;
    // }
    // Integer operator/=(const Integer &input) {
    //     this->data /= input.data;
    //     return *this;
    // }
    // Integer operator%=(const Integer &input) {
    //     this->data %= input.data;
    //     return *this;
    // }
#endif
