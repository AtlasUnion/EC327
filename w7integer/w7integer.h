// Copyright 2020 Zhiyuan Ruan zruan@bu.edu
#ifndef w7integer_H
#define w7integer_H
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <utility>

using std::string;
using std::stringstream;
class Integer {
 private:
  string number;
  bool sign;

 public:
  Integer();
  Integer(string s);
  Integer(int n);
  void setNumber(string s);
  const string& getNumber();
  void setSign(bool s);
  const bool& getSign();
  Integer absolute();
  void operator = (Integer b);
  bool operator == (Integer b);
  bool operator != (Integer b);
  bool operator > (Integer b);
  bool operator < (Integer b);
  bool operator >= (Integer b);
  bool operator <= (Integer b);
  Integer& operator ++();
  Integer  operator ++(int);
  Integer& operator --();
  Integer  operator --(int);

  friend Integer operator+(Integer a, Integer b);
  friend Integer operator+(int in, Integer b);
  friend Integer operator+(Integer b, int in);

  Integer operator - (Integer b);
  friend Integer operator-(int in, Integer b);
  friend Integer operator-(Integer b, int in);

  Integer operator -();     // unary subtract sign

  Integer operator* (Integer b);    // Done
  friend Integer operator*(int in, Integer b);    // Done
  friend Integer operator*(Integer b, int in);    // Done

  Integer operator/(Integer b);
  friend Integer operator/(int in, Integer b);
  friend Integer operator/(Integer b, int in);

  Integer operator % (Integer b);
  friend Integer operator%(int in, Integer b);
  friend Integer operator%(Integer b, int in);

  operator string();  // Done
  operator bool() const {   // Done
    if (number == "0") {
      return false;   // Or false!
    } else {
      return true;
    }
  }
  friend std::ostream& operator<<(std::ostream &, Integer);     // Done
  friend std::istream& operator>>(std::istream &, Integer &);     // Done
  static string DIVIDE(string number1, string number2) {
    int i, j, pos;

    string result = "";

    string tempstr = "";

    int length1 = number1.size();

    int length2 = number2.size();



    if ((COMPARE(number2, number1) > 0)) {
      return "0";
    }



    tempstr = number1.substr(0, length2);

    pos = length2 - 1;



    while (pos < length1) {
      int quotient = 0;

      while (COMPARE(tempstr, number2) >= 0) {
        quotient++;
        Integer a(tempstr);
        tempstr = a.subtract(tempstr, number2);
      }

      result = result + static_cast<char>(quotient + 48);
      pos++;

      if (pos < length1) {
        tempstr += number1[pos];
      }
    }



    j = result.size();

    for (i = 0; i < j; i++) {
      if (result[i] != '0') break;
    }

    result = result.substr(i, j);
    return result;
  }

  static string MOD(string number1, string number2) {
    if (COMPARE(number2, number1) > 0) {
      return number1;
    } else if (COMPARE(number2, number1) == 0) {
      return "0";
    } else {
      Integer a(number1);
      return a.subtract(number1, a.multiply(DIVIDE(number1, number2), number2));
    }
  }

  Integer& operator += (Integer b);
  Integer& operator -= (Integer b);
  Integer& operator *= (Integer b);
  Integer& operator /= (Integer b);
  Integer& operator %= (Integer b);

 private:
  bool equals(Integer n1, Integer n2);  // done
  bool less(Integer n1, Integer n2);  // done
  bool greater(Integer n1, Integer n2);   // done
  string add(string number1, string number2);   // done
  string subtract(string number1, string number2);  // Done
  string multiply(string n1, string n2);
  static int COMPARE(string number1, string number2) {
    int j;
    int length1 = number1.size();
    int length2 = number2.size();

    if (number1.size() == 0) number1 = "0";
    if (number2.size() == 0) number2 = "0";

    j = 0;
    for (int i = 0; i < length1; ++i) {
      if (number1[i] == '0') {
          ++j;
      } else {
        break;
      }
    }
    number1 = number1.substr(j);
    j = 0;

    for (int i = 0; i < length2; ++i) {
      if (number2[i] == '0') {
        ++j;
      } else {
        break;
      }
    }
    number2 = number2.substr(j);
    length1 = number1.size();
    length2 = number2.size();

    if (length1 > length2) {
      return 1;
    } else if (length1 == length2) {
      if (number1.compare(number2) > 0) {
        return 1;
      } else if (number1.compare(number2) == 0) {
        return 0;
      } else {
        return -1;
      }
    } else {
      return -1;
    }
    return 0;
  }
};
Integer::Integer() {  // empty constructor initializes zero
  number = "0";
  sign = false;
}

Integer::Integer(string s) {  // "string" constructor
  if ( isdigit(s[0]) ) {   // if not signed
    if (s[0] == '0') {
      setNumber("0");
      sign = false;
    } else {
      setNumber(s);
      sign = false;
    }
  } else if (s == "") {
  } else {
    if (s[1] == '0') {
      setNumber("0");
      sign = false;
    } else {
      setNumber(s.substr(1, s.length()-1));
      sign = (s[0] == '-');
    }
  }
}

Integer::Integer(int n) {   // "int" constructor
  stringstream ss;
  string s;
  ss << n;
  ss >> s;


  if (isdigit(s[0])) {   // if not signed
    setNumber(s);
    setSign(false);
  } else {
    setNumber(s.substr(1));
    setSign(s[0] == '-');
  }
}

std::ostream& operator<<(std::ostream &a, Integer b) {
  string result = b;
  a << result;
  return a;
}

std::istream& operator>>(std::istream &a, Integer &b) {
  string s;
  a >> s;
  b = Integer(s);
  return a;
}

void Integer::setNumber(string s) {
  number = s;
}

const string& Integer::getNumber() {    // retrieves the number
  return number;
}

void Integer::setSign(bool s) {
  sign = s;
}

const bool& Integer::getSign() {
  return sign;
}

Integer Integer::absolute() {
  return Integer(getNumber());
}

void Integer::operator = (Integer b) {
  setNumber(b.getNumber());
  setSign(b.getSign());
}

bool Integer::operator == (Integer b) {
  return equals((*this), b);
}

bool Integer::operator != (Integer b) {
  return !equals((*this) , b);
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

Integer& Integer::operator ++() {     // prefix
  (*this) = (*this) + 1;
  return (*this);
}

Integer Integer::operator ++(int) {   // postfix
  Integer before = (*this);
  (*this) = (*this) + 1;
  return before;
}

Integer& Integer::operator --() {   // prefix
  (*this) = (*this) - 1;
  return (*this);
}

Integer Integer::operator --(int) {   // postfix
  Integer before = (*this);

  (*this) = (*this) - 1;

  return before;
}

Integer operator+(Integer a, Integer b) {
  Integer addition;
  if (a.getSign() == b.getSign()) {
    addition.setNumber(a.add(a.getNumber(), b.getNumber()));
    addition.setSign(a.getSign());
  } else {    // sign different
    if (a.absolute() > b.absolute()) {
      addition.setNumber(a.subtract(a.getNumber(), b.getNumber()));
      addition.setSign(a.getSign());
    } else {
      addition.setNumber(a.subtract(b.getNumber(), a.getNumber()));
      addition.setSign(b.getSign());
    }
  }
  if (addition.getNumber() == "0")    // avoid (-0) problem
    addition.setSign(false);
  return addition;
}
Integer operator+(int in, Integer b) {
  Integer addition;
  Integer a(in);
  if (a.getSign() == b.getSign()) {
    addition.setNumber(a.add(a.getNumber(), b.getNumber()));
    addition.setSign(a.getSign());
  } else {    // sign different
    if (a.absolute() > b.absolute()) {
      addition.setNumber(a.subtract(a.getNumber(), b.getNumber()));
      addition.setSign(a.getSign());
    } else {
      addition.setNumber(a.subtract(b.getNumber(), a.getNumber()));
      addition.setSign(b.getSign());
    }
  }
  if (addition.getNumber() == "0")    // avoid (-0) problem
    addition.setSign(false);
  return addition;
}

Integer operator+(Integer b, int in) {
  Integer addition;
  Integer a(in);
  if (a.getSign() == b.getSign()) {
    addition.setNumber(a.add(a.getNumber(), b.getNumber()));
    addition.setSign(a.getSign());
  } else {      // sign different
    if (a.absolute() > b.absolute()) {
      addition.setNumber(a.subtract(a.getNumber(), b.getNumber()));
      addition.setSign(a.getSign());
    } else {
      addition.setNumber(a.subtract(b.getNumber(), a.getNumber()));
      addition.setSign(b.getSign());
    }
  }
  if (addition.getNumber() == "0")    // avoid (-0) problem
    addition.setSign(false);
  return addition;
}

Integer Integer::operator- (Integer b) {
  b.setSign(!b.getSign());     // x - y = x + (-y)
  return (*this) + b;
}
Integer operator-(int in, Integer b) {
  Integer a(in);
  b.setSign(!b.getSign());
  return a + b;
}
Integer operator-(Integer b, int in) {
  Integer a(in);
  a.setSign(!a.getSign());
  return a + b;
}

Integer Integer::operator -() {     // unary subtract sign
  return (*this) * -1;
}

Integer Integer::operator* (Integer b) {
  Integer mul;

  mul.setNumber(multiply(getNumber(), b.getNumber()));
  mul.setSign(getSign() != b.getSign());

  if (mul.getNumber() == "0")     // avoid (-0) problem
    mul.setSign(false);

  return mul;
}
Integer operator*(int in, Integer b) {
  Integer mul;
  Integer a(in);
  mul.setNumber(a.multiply(a.getNumber(), b.getNumber()));
  mul.setSign(a.getSign() != b.getSign());

  if (mul.getNumber() == "0")     // avoid (-0) problem
    mul.setSign(false);

  return mul;
}
Integer operator*(Integer b, int in) {
  Integer mul;
  Integer a(in);
  mul.setNumber(a.multiply(a.getNumber(), b.getNumber()));
  mul.setSign(a.getSign() != b.getSign());

  if (mul.getNumber() == "0")     // avoid (-0) problem
    mul.setSign(false);

  return mul;
}

Integer Integer::operator / (Integer b) {
  Integer div;
  string a = getNumber();
  string c = b.getNumber();
  string result = Integer::DIVIDE(a, c);
  div.setNumber(result);
  div.setSign(getSign() != b.getSign());

  if (div.getNumber() == "0")     // avoid (-0) problem
    div.setSign(false);
  if (getSign()  != b.getSign()) {
    div = div - 1;
  }
  return div;
}

Integer operator/(int in, Integer b) {
  Integer a(in);
  Integer div;

  string d = a.getNumber();
  string c = b.getNumber();
  string result = Integer::DIVIDE(d, c);

  div.setNumber(result);
  div.setSign(a.getSign() != b.getSign());

  if (div.getNumber() == "0")     // avoid (-0) problem
    div.setSign(false);
  if (a.getSign()  != b.getSign()) {
    div = div - 1;
  }
  return div;
}
Integer operator/(Integer b, int in) {
  Integer div;
  Integer a(in);

  string d = a.getNumber();
  string c = b.getNumber();
  string result = Integer::DIVIDE(c, d);

  div.setNumber(result);
  div.setSign(b.getSign() != a.getSign());
  if (div.getNumber() == "0")    // avoid (-0) problem
    div.setSign(false);
  if (a.getSign()  != b.getSign()) {
    div = div - 1;
  }
  return div;
}

Integer Integer::operator % (Integer b) {
  Integer result;
  if (getSign() != b.getSign()) {
    Integer a(*this);
    if (a.getSign()) {
      string mul = Integer::DIVIDE(a.getNumber(), b.getNumber());
      Integer mull(mul);
      result = a + b*(mull+1);
      return result;
    } else {
      string mul = Integer::DIVIDE(a.getNumber(), b.getNumber());
      Integer mull(mul);
      result = a + b*(mull+1);
      return result;
    }
  }
  Integer rem;
  string rem_int = Integer::MOD(getNumber(), b.getNumber());
  rem.setNumber(rem_int);
  rem.setSign(getSign() != b.getSign());

  if (rem.getNumber() == "0")     // avoid (-0) problem
    rem.setSign(false);
  if (getSign() && b.getSign()) {
    rem.setSign(true);
  }
  return rem;
}

Integer operator%(int in, Integer b) {
  Integer a(in);
  Integer result;
  if (a.getSign() != b.getSign()) {
    if (a.getSign()) {
      string mul = Integer::DIVIDE(a.getNumber(), b.getNumber());
      Integer mull(mul);
      result = a + b*(mull+1);
      return result;
    } else {
      string mul = Integer::DIVIDE(a.getNumber(), b.getNumber());
      Integer mull(mul);
      result = a - b*(mull+1);
      return result;
    }
  }
  Integer rem;
  string rem_int = Integer::MOD(a.getNumber(), b.getNumber());
  rem.setNumber(rem_int);
  rem.setSign(a.getSign() != b.getSign());

  if (rem.getNumber() == "0")     // avoid (-0) problem
    rem.setSign(false);
  if (a.getSign() && b.getSign()) {
    rem.setSign(true);
  }
  return rem;
}

Integer operator%(Integer b, int in) {
  Integer a(in);
  Integer rem;
  string rem_int = Integer::MOD(b.getNumber(), a.getNumber());
  rem.setNumber(rem_int);
  rem.setSign(a.getSign() != b.getSign());

  if (rem.getNumber() == "0")     // avoid (-0) problem
    rem.setSign(false);
  if (a.getSign() && b.getSign()) {
    rem.setSign(true);
  }
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

Integer::operator string() {    // for conversion from Integer to string
  string signedString = (getSign()) ? "-" : "";     // if +, don't print + sign
  signedString += number;
  return signedString;
}

string Integer::add(string number1, string number2) {
  string add = (number1.length() > number2.length()) ?  number1 : number2;
  char carry = '0';
  int a = abs(static_cast<int>(number1.size() - number2.size()));
  int differenceInLength = a;

  if (number1.size() > number2.size())
    number2.insert(0, differenceInLength, '0');     // put zeros from left

  else    // if(number1.size() < number2.size())
    number1.insert(0, differenceInLength, '0');

  for (int i=number1.size()-1; i >= 0; --i) {
    add[i] = ((carry-'0')+(number1[i]-'0')+(number2[i]-'0')) + '0';

    if (i != 0) {
      if (add[i] > '9') {
        add[i] -= 10;
        carry = '1';
      } else {
        carry = '0';
      }
    }
  }
  if (add[0] > '9') {
    add[0]-= 10;
    add.insert(0, 1, '1');
  }
  return add;
}

string Integer::subtract(string number1, string number2) {
  string sub = (number1.length() > number2.length())? number1 : number2;
  int a = abs(static_cast<int>(number1.size() - number2.size()));
  int differenceInLength = a;

  if (number1.size() > number2.size())
    number2.insert(0, differenceInLength, '0');

  else
    number1.insert(0, differenceInLength, '0');

  for (int i=number1.length()-1; i >= 0; --i) {
    if (number1[i] < number2[i]) {
      number1[i] += 10;
      number1[i-1]--;
    }
    sub[i] = ((number1[i]-'0')-(number2[i]-'0')) + '0';
  }

  while (sub[0] == '0' && sub.length() != 1)     // erase leading zeros
    sub.erase(0, 1);

  return sub;
}

string Integer::multiply(string n1, string n2) {
  if (n1.length() > n2.length())
    n1.swap(n2);

  string res = "0";
  for (int i=n1.length()-1; i >= 0; --i) {
    string temp = n2;
    int currentDigit = n1[i]-'0';
    int carry = 0;

    for (int j=temp.length()-1; j >= 0; --j) {
      temp[j] = ((temp[j]-'0') * currentDigit) + carry;

      if (temp[j] > 9) {
        carry = (temp[j]/10);
        temp[j] -= (carry*10);
      } else {
        carry = 0;
      }
      temp[j] += '0';     // back to string mood
    }

    if (carry > 0)
      temp.insert(0, 1, (carry+'0'));
    int len = n1.length()-i-1;
    temp.append(len, '0');

    res = add(res, temp);
  }

  while (res[0] == '0' && res.length() != 1)     // erase leading zeros
    res.erase(0, 1);

  return res;
}

bool Integer::equals(Integer n1, Integer n2) {
  return n1.getNumber() == n2.getNumber()
         && n1.getSign() == n2.getSign();
}

bool Integer::less(Integer n1, Integer n2) {
  bool sign1 = n1.getSign();
  bool sign2 = n2.getSign();

  if (sign1 && !sign2) {
    return true;
} else if (!sign1 && sign2) {
    return false;
} else if (!sign1) {
    if (n1.getNumber().length() < n2.getNumber().length() )
      return true;
    if (n1.getNumber().length() > n2.getNumber().length() )
      return false;
    return n1.getNumber() < n2.getNumber();
  } else {
    if (n1.getNumber().length() > n2.getNumber().length())
      return true;
    if (n1.getNumber().length() < n2.getNumber().length())
      return false;
    bool res = n1.getNumber().compare(n2.getNumber()) > 0;
    return res;
  }
}

bool Integer::greater(Integer n1, Integer n2) {
  return !equals(n1, n2) && !less(n1, n2);
}
#endif
