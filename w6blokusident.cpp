#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using std::vector;
using std::make_pair;

typedef std::pair<int, int> CellType;

typedef vector<CellType> PieceType;

const int DefaultTSize = 5;

// Error codes
const int BADCHAR = 1;
const int BADSIZE = 2;
const int NOTILE = 3;

bool isBlank(String test) {
  for (int i = 0; i < test.size(); i++) {
    if (test[i] == '*') {
      return false
    }
  }
  return true;
}

std::vector<std::string> rotate(vector<std::string> test) { //tested
    std::string base(test.size(), '.');
    std::vector<std::string> mirror(test[0].size(), base);
    for (int i=0; i<test.size(); i++){
      for (int j=0;j<test[i].size(); j++){
          mirror [j][test.size()-1-i] = test[i][j];
      }
   }
    return mirror;
}

std::vector<std::string> mirror(std::vector<std::string> test) { //have not test for MxN matrix
  int ii, jj;
  std::string base(5, '.');
  std::vector<std::string> mirror(5, base);
  for(int i=0; i<test.size(); i++)
    {
       for(int j=0; j<test.size(); j++)
       {
          ii = i;
          jj = test.size() - 1 - j;
          mirror[i][j]=test[ii][jj];
       }
    }
    return mirror;
}

vector<std::string> removeBlankLine(vector<std::string> test) {
  for (int i = 0; i < test.size(); i++) {
    if (isBlank(test.at(i))) {
      test.erase(i);
    }
  }
  vector<std::string> test2 = rotate(test);
  for (int i = 0; i < test2.size(); i++) {
    if (isBlank(test2.at(i))) {
      test2.erase(i);
    }
  }
  return test2;
}

void print_piece(PieceType p, std::ostream *out, int TSize) {
  std::string base(TSize, '.');

  vector<std::string> e(TSize, base);

  for (auto const & loc : p)
    e[loc.first][loc.second] = '*';

  for (int y = TSize - 1; y >= 0; y--) {
    for (int x = 0; x < TSize; x++)
      *out << e[x][y];
    *out << std::endl;
  }
  *out << std::endl;
}


vector<PieceType> get_tileset(std::istream* in, int TSize, int * errorcode) {
  vector<PieceType> pieces;
  std::string row;
  PieceType p;

  *errorcode = 0;
  int npieces;

  vector<std::string> filelines;
  while (getline(*in, row)) {
    filelines.push_back(row);
  }

  if (filelines.size() % (TSize + 1) != 0) {
    *errorcode = BADSIZE;
    return pieces;
  }

  for (int i = 0 ; i < filelines.size() ; i++) {
    if (i % (TSize + 1) == TSize) {
      if (filelines[i].size() != 0)
        *errorcode = BADSIZE;
    } else  {
      if (filelines[i].size() != TSize)
        *errorcode = BADSIZE;
    }
  }
  if (*errorcode)
    return pieces;

  npieces = filelines.size() / (TSize + 1);

  for (int i = 0; i < npieces; i++) {
    p.clear();
    for (int y = 0; y < TSize ; y++) {
      row = filelines[i * (TSize + 1) + y];

      for (int x = 0; x < TSize; x++)
        if (row[x] == '*') {
          p.push_back(make_pair(x, TSize - 1 - y));
        } else if (row[x] != '.') {
          *errorcode = BADCHAR;
          return pieces;
        }
    }
    if (p.empty()) {
      *errorcode = NOTILE;
      return pieces;
    }
    pieces.push_back(p);
  }

  return pieces;
}


int main(int argc, char const *argv[]) {
  int TSize;
  std::istream * in = &std::cin;
  std::ostream * out = &std::cout;
  std::ifstream infile;
  std::ofstream outfile;
  TSize = (argc == 1) ? DefaultTSize : std::stoi(argv[1]);

  if (argc > 2) {
    infile.open(argv[2]);
    in = &infile;
  }
  if (argc > 3) {
    outfile.open(argv[3]);
    out = &outfile;
  }

  int errorcode;

  vector<PieceType> p = get_tileset(in, TSize, &errorcode);
  if (errorcode)
    return errorcode;

  for (auto const & e : p)
    print_piece(e, out, TSize);

  return 0;
}
