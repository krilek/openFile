#include <string>
#include <iostream>

using namespace std;

class File{
private:
  string path;
  string mode;
public:
  void openFile(string p, string m);
  string getPath();
};
