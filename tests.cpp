#include <iostream>
#include <vector>
#include "file.h"

using namespace std;

int main(){

  File plik("dokument.txt", "/truncate/w/binary/");
  // plik.openFile("dokument.txt", "/read/write/binary/");
  //plik.getPath();
  cout << "elo";
  return 0;
}
