#include <string>
#include <iostream>
#include "file.h"
using namespace std;
void File::openFile(string p, string m){
	path = p;
	mode = m;
}
string File::getPath(){
    cout << path;
    return path;
}
