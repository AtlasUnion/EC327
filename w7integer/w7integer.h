#ifndef w7integer_H
#define w7integer_H
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#define MAX 1000000000 // for strings

using namespace std;
class Integer {
private:
    string number;
    bool sign;
public:
    Integer(); // empty constructor initializes zero
    Integer(string s); // "string" constructor
    Integer(string s, bool sin); // "string" constructor
    Integer(int n); // "int" constructor
    void setNumber(string s);
    const string& getNumber(); // retrieves the number
    void setSign(bool s);
    const bool& getSign();
    Integer absolute(); // returns the absolute value
    void operator = (Integer b);
    bool operator == (Integer b);
    bool operator != (Integer b);
    bool operator > (Integer b);
    bool operator < (Integer b);
    bool operator >= (Integer b);
    bool operator <= (Integer b);
    Integer& operator ++(); // prefix
    Integer  operator ++(int); // postfix
    Integer& operator --(); // prefix
    Integer  operator --(int); // postfix

    friend Integer operator+(Integer a, Integer b);
    friend Integer operator+(int in, Integer b);
    friend Integer operator+(Integer b, int in);
    Integer operator - (Integer b);
    friend Integer operator-(int in, Integer b);
    friend Integer operator-(Integer b, int in);
    Integer operator* (Integer b);
    friend Integer operator*(int in, Integer b);
    friend Integer operator*(Integer b, int in);
    Integer operator/(Integer b);
    friend Integer operator/(int in, Integer b);
    friend Integer operator/(Integer b, int in);
    Integer operator % (Integer b);
    friend Integer operator%(int in, Integer b);
    friend Integer operator%(Integer b, int in);
    Integer& operator += (Integer b);
    Integer& operator -= (Integer b);
    Integer& operator *= (Integer b);
    Integer& operator /= (Integer b);
    Integer& operator %= (Integer b);
    Integer& operator [] (int n);
    Integer operator -(); // unary minus sign
    operator string(); // for conversion from Integer to string
    operator bool() const
    {
        if(number == "0"){
        return false; // Or false!
      }
      else{
        return true;
      }
    }
    friend std::ostream& operator<<(std::ostream &, Integer);
    friend std::istream& operator>>(std::istream &, Integer &);
private:
    bool equals(Integer n1, Integer n2);
    bool less(Integer n1, Integer n2);
    bool greater(Integer n1, Integer n2);
    string add(string number1, string number2);
    string subtract(string number1, string number2);
    string multiply(string n1, string n2);
    pair<string, long long> divide(string n, long long den);
    string toString(long long n);
    long long toInt(string s);
};

std::ostream& operator<<(std::ostream &a, Integer b){
  string result = b;
  a << result;
  return a;
}
std::istream& operator>>(std::istream &a, Integer &b){
  string s;
  a >> s;
  b = Integer(s);
  return a;
}
//------------------------------------------------------------------------------

Integer::Integer() { // empty constructor initializes zero
    number = "0";
    sign = false;
}

Integer::Integer(string s) { // "string" constructor
    if( isdigit(s[0]) ) { // if not signed
      if(s[0] == '0'){
        setNumber("0");
        sign = false;
      }else{
        setNumber(s);
        sign = false; // +ve
      }
    } else if(s == ""){

    }
    else {
      if(s[1] == '0'){
        setNumber("0");
        sign = false;
      }
      else{
        setNumber( s.substr(1,s.length()-1) );
        sign = (s[0] == '-');
      }
    }
}

Integer::Integer(string s, bool sin) { // "string" constructor
    setNumber( s );
    setSign( sin );
}

Integer::Integer(int n) { // "int" constructor
    stringstream ss;
    string s;
    ss << n;
    ss >> s;


    if( isdigit(s[0]) ) { // if not signed
        setNumber( s );
        setSign( false ); // +ve
    } else {
        setNumber( s.substr(1) );
        setSign( s[0] == '-' );
    }
}

void Integer::setNumber(string s) {
    number = s;
}

const string& Integer::getNumber() { // retrieves the number
    return number;
}

void Integer::setSign(bool s) {
    sign = s;
}

const bool& Integer::getSign() {
    return sign;
}

Integer Integer::absolute() {
    return Integer( getNumber() ); // +ve by default
}

void Integer::operator = (Integer b) {
    setNumber( b.getNumber() );
    setSign( b.getSign() );
}

bool Integer::operator == (Integer b) {
    return equals((*this) , b);
}

bool Integer::operator != (Integer b) {
    return ! equals((*this) , b);
}

bool Integer::operator > (Integer b) {
    return greater((*this) , b);
}

bool Integer::operator < (Integer b) {
    return less((*this) , b);
}

bool Integer::operator >= (Integer b) {
    return equals((*this) , b)
           || greater((*this), b);
}

bool Integer::operator <= (Integer b) {
    return equals((*this) , b)
           || less((*this) , b);
}

Integer& Integer::operator ++() { // prefix
    (*this) = (*this) + 1;
    return (*this);
}

Integer Integer::operator ++(int) { // postfix
    Integer before = (*this);
    (*this) = (*this) + 1;
    return before;
}

Integer& Integer::operator --() { // prefix
    (*this) = (*this) - 1;
    return (*this);

}

Integer Integer::operator --(int) { // postfix
    Integer before = (*this);

    (*this) = (*this) - 1;

    return before;
}

Integer operator+(Integer a, Integer b){
  Integer addition;
  if( a.getSign() == b.getSign() ) { // both +ve or -ve
      addition.setNumber( a.add(a.getNumber(), b.getNumber() ) );
      addition.setSign( a.getSign() );
  } else { // sign different
      if( a.absolute() > b.absolute() ) {
          addition.setNumber( a.subtract(a.getNumber(), b.getNumber() ) );
          addition.setSign( a.getSign() );
      } else {
          addition.setNumber( a.subtract(b.getNumber(), a.getNumber() ) );
          addition.setSign( b.getSign() );
      }
  }
  if(addition.getNumber() == "0") // avoid (-0) problem
      addition.setSign(false);

  return addition;
}
Integer operator+(int in, Integer b){
  Integer addition;
  Integer a(in);
  if( a.getSign() == b.getSign() ) { // both +ve or -ve
      addition.setNumber( a.add(a.getNumber(), b.getNumber() ) );
      addition.setSign( a.getSign() );
  } else { // sign different
      if( a.absolute() > b.absolute() ) {
          addition.setNumber( a.subtract(a.getNumber(), b.getNumber() ) );
          addition.setSign( a.getSign() );
      } else {
          addition.setNumber( a.subtract(b.getNumber(), a.getNumber() ) );
          addition.setSign( b.getSign() );
      }
  }
  if(addition.getNumber() == "0") // avoid (-0) problem
      addition.setSign(false);

  return addition;
}

Integer operator+(Integer b, int in){
  Integer addition;
  Integer a(in);
  if( a.getSign() == b.getSign() ) { // both +ve or -ve
      addition.setNumber( a.add(a.getNumber(), b.getNumber() ) );
      addition.setSign( a.getSign() );
  } else { // sign different
      if( a.absolute() > b.absolute() ) {
          addition.setNumber( a.subtract(a.getNumber(), b.getNumber() ) );
          addition.setSign( a.getSign() );
      } else {
          addition.setNumber( a.subtract(b.getNumber(), a.getNumber() ) );
          addition.setSign( b.getSign() );
      }
  }
  if(addition.getNumber() == "0") // avoid (-0) problem
      addition.setSign(false);

  return addition;
}
Integer Integer::operator- (Integer b) {
    b.setSign( ! b.getSign() ); // x - y = x + (-y)
    return (*this) + b;
}
Integer operator-(int in, Integer b){
  Integer a(in);
  b.setSign( ! b.getSign() );
  return a + b;
}
Integer operator-(Integer b, int in){
  Integer a(in);
  a.setSign( ! a.getSign() );
  return a + b;
}
Integer Integer::operator* (Integer b) {
    Integer mul;

    mul.setNumber( multiply(getNumber(), b.getNumber() ) );
    mul.setSign( getSign() != b.getSign() );

    if(mul.getNumber() == "0") // avoid (-0) problem
        mul.setSign(false);

    return mul;
}
Integer operator*(int in, Integer b){
  Integer mul;
  Integer a(in);
  mul.setNumber( a.multiply(a.getNumber(), b.getNumber() ) );
  mul.setSign( a.getSign() != b.getSign() );

  if(mul.getNumber() == "0") // avoid (-0) problem
      mul.setSign(false);

  return mul;
}
Integer operator*(Integer b, int in){
  Integer mul;
  Integer a(in);
  mul.setNumber( a.multiply(a.getNumber(), b.getNumber() ) );
  mul.setSign( a.getSign() != b.getSign() );

  if(mul.getNumber() == "0") // avoid (-0) problem
      mul.setSign(false);

  return mul;
}

// Warning: Denomerator must be within "long long" size not "Integer"
Integer Integer::operator / (Integer b) {
    long long den = toInt( b.getNumber() );
    Integer div;

    div.setNumber( divide(getNumber(), den).first );
    div.setSign( getSign() != b.getSign() );

    if(div.getNumber() == "0") // avoid (-0) problem
        div.setSign(false);

    return div;
}
Integer Integer::operator / (Integer b) {
    long long den = toInt( b.getNumber() );
    Integer div;

    div.setNumber( divide(getNumber(), den).first );
    div.setSign( getSign() != b.getSign() );

    if(div.getNumber() == "0") // avoid (-0) problem
        div.setSign(false);

    return div;
}
// Integer operator/(int in, Integer b){
//   long long den = b.toInt( b.getNumber() );
//   Integer a(in);
//   Integer div;
//
//   div.setNumber( a.divide(a.getNumber(), den).first );
//   div.setSign( a.getSign() != b.getSign() );
//
//   if(div.getNumber() == "0") // avoid (-0) problem
//       div.setSign(false);
//
//   return div;
// }
// Integer operator/(Integer b, int in){
//   Integer div;
//   Integer a(in);
//   div.setNumber( b.divide(b.getNumber(), in).first );
//   div.setSign( b.getSign() != a.getSign() );
//
//   if(div.getNumber() == "0") // avoid (-0) problem
//       div.setSign(false);
//
//   return div;
// }
// Warning: Denomerator must be within "long long" size not "Integer"
Integer Integer::operator % (Integer b) {
    long long den = toInt( b.getNumber() );

    Integer rem;
    long long rem_int = divide(number, den).second;
    rem.setNumber( toString(rem_int) );
    rem.setSign( getSign() != b.getSign() );

    if(rem.getNumber() == "0") // avoid (-0) problem
        rem.setSign(false);

    return rem;
}

Integer operator%(int in, Integer b){
  long long den = b.toInt( b.getNumber() );
  Integer a(in);

  Integer rem;
  long long rem_int = a.divide(a.number, den).second;
  rem.setNumber( a.toString(rem_int) );
  rem.setSign( a.getSign() != b.getSign() );

  if(rem.getNumber() == "0") // avoid (-0) problem
      rem.setSign(false);

  return rem;
}

Integer operator%(Integer b, int in){
  long long den = b.toInt( b.getNumber() );
  Integer a(in);
  Integer rem;
  long long rem_int = b.divide(b.number, in).second;
  rem.setNumber( b.toString(rem_int) );
  rem.setSign( a.getSign() != b.getSign() );

  if(rem.getNumber() == "0") // avoid (-0) problem
      rem.setSign(false);

  return rem;
}
Integer& Integer::operator += (Integer b) {
    (*this) = (*this) + b;
    return (*this);
}

Integer& Integer::operator -= (Integer b) {
    (*this) = (*this) - b;
    return (*this);
}

Integer& Integer::operator *= (Integer b) {
    (*this) = (*this) * b;
    return (*this);
}

Integer& Integer::operator /= (Integer b) {
    (*this) = (*this) / b;
    return (*this);
}

Integer& Integer::operator %= (Integer b) {
    (*this) = (*this) % b;
    return (*this);
}

Integer& Integer::operator [] (int n) {
    return *(this + (n*sizeof(Integer)));
}

Integer Integer::operator -() { // unary minus sign
    return (*this) * -1;
}

Integer::operator string() { // for conversion from Integer to string
    string signedString = ( getSign() ) ? "-" : ""; // if +ve, don't print + sign
    signedString += number;
    return signedString;
}

bool Integer::equals(Integer n1, Integer n2) {
    return n1.getNumber() == n2.getNumber()
           && n1.getSign() == n2.getSign();
}

bool Integer::less(Integer n1, Integer n2) {
    bool sign1 = n1.getSign();
    bool sign2 = n2.getSign();

    if(sign1 && ! sign2) // if n1 is -ve and n2 is +ve
        return true;

    else if(! sign1 && sign2)
        return false;

    else if(! sign1) { // both +ve
        if(n1.getNumber().length() < n2.getNumber().length() )
            return true;
        if(n1.getNumber().length() > n2.getNumber().length() )
            return false;
        return n1.getNumber() < n2.getNumber();
    } else { // both -ve
        if(n1.getNumber().length() > n2.getNumber().length())
            return true;
        if(n1.getNumber().length() < n2.getNumber().length())
            return false;
        return n1.getNumber().compare( n2.getNumber() ) > 0; // greater with -ve sign is LESS
    }
}

bool Integer::greater(Integer n1, Integer n2) {
    return ! equals(n1, n2) && ! less(n1, n2);
}

string Integer::add(string number1, string number2) {
    string add = (number1.length() > number2.length()) ?  number1 : number2;
    char carry = '0';
    int differenceInLength = abs( (int) (number1.size() - number2.size()) );

    if(number1.size() > number2.size())
        number2.insert(0, differenceInLength, '0'); // put zeros from left

    else// if(number1.size() < number2.size())
        number1.insert(0, differenceInLength, '0');

    for(int i=number1.size()-1; i>=0; --i) {
        add[i] = ((carry-'0')+(number1[i]-'0')+(number2[i]-'0')) + '0';

        if(i != 0) {
            if(add[i] > '9') {
                add[i] -= 10;
                carry = '1';
            } else
                carry = '0';
        }
    }
    if(add[0] > '9') {
        add[0]-= 10;
        add.insert(0,1,'1');
    }
    return add;
}

string Integer::subtract(string number1, string number2) {
    string sub = (number1.length()>number2.length())? number1 : number2;
    int differenceInLength = abs( (int)(number1.size() - number2.size()) );

    if(number1.size() > number2.size())
        number2.insert(0, differenceInLength, '0');

    else
        number1.insert(0, differenceInLength, '0');

    for(int i=number1.length()-1; i>=0; --i) {
        if(number1[i] < number2[i]) {
            number1[i] += 10;
            number1[i-1]--;
        }
        sub[i] = ((number1[i]-'0')-(number2[i]-'0')) + '0';
    }

    while(sub[0]=='0' && sub.length()!=1) // erase leading zeros
        sub.erase(0,1);

    return sub;
}

string Integer::multiply(string n1, string n2) {
    if(n1.length() > n2.length())
        n1.swap(n2);

    string res = "0";
    for(int i=n1.length()-1; i>=0; --i) {
        string temp = n2;
        int currentDigit = n1[i]-'0';
        int carry = 0;

        for(int j=temp.length()-1; j>=0; --j) {
            temp[j] = ((temp[j]-'0') * currentDigit) + carry;

            if(temp[j] > 9) {
                carry = (temp[j]/10);
                temp[j] -= (carry*10);
            } else
                carry = 0;

            temp[j] += '0'; // back to string mood
        }

        if(carry > 0)
            temp.insert(0, 1, (carry+'0'));

        temp.append((n1.length()-i-1), '0'); // as like mult by 10, 100, 1000, 10000 and so on

        res = add(res, temp); // O(n)
    }

    while(res[0] == '0' && res.length()!=1) // erase leading zeros
        res.erase(0,1);

    return res;
}

int strComp(string &s1,string &s2)
{
    int len1=s1.length();
    int len2=s2.length();
    if(len1>len2)
    return 0;
    else if(len1<len2)
    return 1;
    else{
        if(s1>=s2)
        return 0;
        else
        return 1;
    }
}
string Sub(string s1,string s2)
{
        if(strComp(s1,s2)==1)
        return "-1";
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        string s(1000,'0');
        for(int i=0;i<s1.length();i++)
        s[i]=s1[i];
        for(int i=0;i<s2.length();i++)
        {
            if(s[i]>=s2[i])
            s[i]=s[i]-'0'-(s2[i]-'0')+'0';
            else{
                s[i+1]=s[i+1]-'0'-1+'0';
                s[i]=s[i]-'0'+10-(s2[i]-'0')+'0';
            }
        }
        reverse(s.begin(),s.end());
        if(s.find_first_not_of('0')==string::npos)
        return "0";
        else
        return s.substr(s.find_first_not_of('0'));
}

pair<string, long long> Integer::divide(string n, long long den) {
    long long rem = 0;
    string result;
    result.resize(MAX);

    for(int indx=0, len = n.length(); indx<len; ++indx) {
        rem = (rem * 10) + (n[indx] - '0');
        result[indx] = rem / den + '0';
        rem %= den;
    }
    result.resize( n.length() );

    while( result[0] == '0' && result.length() != 1)
        result.erase(0,1);

    if(result.length() == 0)
        result = "0";

    return make_pair(result, rem);
}

string Integer::toString(long long n) {
    stringstream ss;
    string temp;

    ss << n;
    ss >> temp;

    return temp;
}

long long Integer::toInt(string s) {
    long long sum = 0;

    for(int i=0; i<s.length(); i++)
        sum = (sum*10) + (s[i] - '0');

    return sum;
}
#endif
