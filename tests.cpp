#include <iostream>
#include "file.h"
using namespace std;

int main(){
  File plik;
  plik.openFile("dokument.txt", "rw");
  cout << "elo";
  return 0;
}
