#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class File{
private:
  string path;
  bool startupSet;
  vector<string> mode;
  vector<unsigned char> modeBin;
  string ext;
  fstream f;
  bool validatePath(string in);
  bool validateMode(string in);
  void setParameters(vector<unsigned char> *m);
public:
  File(string p, string m);
  File();
  ~File();
  void openFile(string p, string m);
  string getPath();
  string getMode();
  string getExtension();
  bool explode(string in, vector<string> *output, char delimeter);
};
