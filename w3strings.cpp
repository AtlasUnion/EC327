// Copyright 2017
// w3strings

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::stoi;
using std::islower;
using std::isupper;

bool is_palindrome(string num, bool & error) {
  string a = num;
  for (int i = 0; i < a.length(); i++) {
	if(a[i]<'0' || a[i]>'9') {
	error = true;
	return false;
   }
  }
int orig = stoi(num);
int digit, num1, rev = 0;
error = false;
  do {
         digit = orig % 10;
         rev = (rev * 10) + digit;
         num1 = orig / 10;
     } while (num1 != 0);
  if(orig == rev){

    return true;
  }

 return false;
}

bool valid(string s){
for(int i = 0;i<s.length();i++ ){
  if(!islower(s[i]) && !isupper(s[i])){
    return false;
}
}
return true;
}
bool allLowercase(string s){
for(int i = 1;i<s.length();i++ ){
  if(!islower(s[i])){
    return false;
}
}
return true;
}
bool is_word(string s) {
if(s.length()<1){
return false;
}
if(islower()
}

// leave this line and everything below as is
int main() {
  cout << std::boolalpha;

  if (not is_word("test")) cout << "we1\n";
  if (not is_word("Test")) cout << "we2\n";
  if (not is_word("TEST")) cout << "we3\n";
  if (not is_word("thisisaword")) cout << "we4\n";

  if (is_word("123")) cout << "we5\n";
  if (is_word("")) cout << "we6\n";
  if (is_word("abc123abc")) cout << "we7\n";
  if (is_word("tEst")) cout << "we8\n";
  if (is_word("tEst")) cout << "we9\n";
  if (is_word("TESTer")) cout << "we10\n";

  bool error;

  if (not is_palindrome("12321", error) or error) cout << "pe1\n";
  if (not is_palindrome("9009", error) or error) cout  << "pe2\n";
  if (not is_palindrome("9", error) or error)  cout << "pe3\n";
  if (not is_palindrome("123456777654321", error) or error) cout << "pe4\n";

  if (is_palindrome("abcba", error) or not error) cout << "pe5\n";
  if (is_palindrome("12321 a", error) or not error) cout << "pe6\n";
  if (is_palindrome("0012100", error) or not error) cout << "pe7\n";

  if (is_palindrome("123", error) or error) cout << "pe8\n";
  if (is_palindrome("123211", error) or error) cout << "pe9\n";

  cout << "Test Other Words. Ctrl-D to exit.\n";

  string s;
  bool pal;
  while (cin >> s) {
    pal = is_palindrome(s, error);
    cout << s << " " << pal << " " << error << " " << is_word(s) << '\n';
  }

  return 0;
}
