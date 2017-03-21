#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#define COL 5
#define ROW 5
using std::vector;
using std::make_pair;

typedef std::pair<int, int> CellType;

typedef vector<CellType> PieceType;

const int DefaultTSize = 5;
// int COL;
// Error codes
const int BADCHAR = 1;
const int BADSIZE = 2;
const int NOTILE = 3;

// A function to check if a given cell (row, col) can be included in DFS
int isSafe(int M[][COL], int row, int col, bool visited[][COL])
{
    // row number is in range, column number is in range and value is 1
    // and not yet visited
    return (row >= 0) && (row < ROW) &&
           (col >= 0) && (col < COL) &&
           (M[row][col] && !visited[row][col]);
}

// A utility function to do DFS for a 2D boolean matrix. It only considers
// the 8 neighbours as adjacent vertices
void DFS(int M[][COL], int row, int col, bool visited[][COL])
{
    // These arrays are used to get row and column numbers of 8 neighbours
    // of a given cell
    static int rowNbr[] = {-1, -1, -1,  0, 0,  1, 1, 1};
    static int colNbr[] = {-1,  0,  1, -1, 1, -1, 0, 1};

    // Mark this cell as visited
    visited[row][col] = true;

    // Recur for all connected neighbours
    for (int k = 0; k < 8; ++k)
        if (isSafe(M, row + rowNbr[k], col + colNbr[k], visited) )
            DFS(M, row + rowNbr[k], col + colNbr[k], visited);
}

// The main function that returns count of islands in a given boolean
// 2D matrix
int countIslands(int M[][COL])
{
    // Make a bool array to mark visited cells.
    // Initially all cells are unvisited
    bool visited[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            visited[i][j] = 0;
        }
    }
    // memset(visited, 0, sizeof(visited));

    // Initialize count as 0 and travese through the all cells of
    // given matrix
    int count = 0;
    for (int i = 0; i < ROW; ++i)
        for (int j = 0; j < COL; ++j)
            if (M[i][j] && !visited[i][j]) // If a cell with value 1 is not
            {                         // visited yet, then new island found
                DFS(M, i, j, visited);     // Visit all cells in this island.
                ++count;                   // and increment island count
            }

    return count;
}

bool isBlank(std::string test) {
  for (int i = 0; i < test.size(); i++) {
    if (test[i] == '*') {
      return false;
    }
  }
  return true;
}

void rotate(std::vector<std::string> &test) {
  char temp('\0');
  std::string base(test.size(), '.');
  std::vector<std::string> mirror(test[0].size(), base);
  for (int i=0; i<test.size(); i++){
	for (int j=0;j<test[i].size(); j++){
		mirror [j][test.size()-1-i] = test[i][j];
    }
}
  test = mirror;
}

void mirror(std::vector<std::string> &test) {
  int ii, jj;
  std::vector<std::string> mirror1 = test;
  for(int i=0; i<test.size(); i++)
    {
       for(int j=0; j<test[i].size(); j++)
       {
          ii = i;
          jj = test[i].size() - 1 - j;
          mirror1[i][j]=test[ii][jj];
       }
    }
    test = mirror1;
}

void removeBlankLine(vector<std::string> &test) {
  for (int i = 0; i < test.size();) {
    if (isBlank(test.at(i))) {
      test.erase(test.begin()+i);
    }
    else {
        i++;
    }
  }
  rotate(test);
  for (int i = 0; i < test.size();) {
    if (isBlank(test.at(i))) {
      test.erase(test.begin()+i);
    }
    else {
        i++;
    }
  }
}

bool containOnlyOne(PieceType p, int TSize) {
  int a[5][5] = {{0}};
  for (auto const & loc : p){
    a[loc.first][loc.second] = 1;
}
  if (countIslands(a) > 1) {
    return false;
  }
  return true;
}

bool checkUnique(PieceType p1, PieceType p2 ,int TSize) {
    std::string base(TSize, '.');
    vector<std::string> compare1(TSize, base);
    vector<std::string> compare2(TSize, base);
    for (auto const & loc : p1){
      compare1[loc.first][loc.second] = '*';
  }
    for (auto const & loc : p2){
    compare2[loc.first][loc.second] = '*';
  }
  removeBlankLine(compare1);
  removeBlankLine(compare2);
  for (int i=0; i < 4; i++) {
    rotate(compare1);
    if (compare1 == compare2) {
      return false;
    }
  }
  mirror(compare1);
  for (int i=0; i < 4; i++) {
    rotate(compare1);
    if (compare1 == compare2) {
      return false;
    }
  }
  return true;
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
  // COL = TSize;
  vector<PieceType> result;
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

  for (auto const & e : p){
    if(containOnlyOne(e,TSize)) {
      result.push_back(e);
    }
  }
  bool unique[p.size()] = {{1}};
  for (int i = 0; i < p.size(); i++) {
    for (int j = i+1; j < p.size(); j++) {
      if (!checkUnique(p.at(i),p.at(j), int TSize)){
        unique[j] = false;
      }
    }
  }
  for (int i = 0; i < p.size(); i++) {
    if (unique[i] == true) {
      print_piece(e, out, TSize);
    }
  }
  // for (auto const & e : p)
  //   print_piece(e, out, TSize);

  return 0;
}
