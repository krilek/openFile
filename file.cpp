#include <string>
#include <iostream>
#include "file.h"
#include <fstream>
#include <vector>

using namespace std;
File::File(){
	startupSet = false;
	cout << "Path and opening mode required.\nPlease use openFile method!" << endl;
}
File::File(string p, string m){
	File::openFile(p, m);
}
File::~File(){
	//
}
void File::openFile(string p, string m){
	startupSet = false;
	if(validatePath(p)) path = p;
	if(validateMode(m)) setParameters(&modeBin);
}
string File::getPath(){
    return path;
}
bool File::validatePath(string in){
	bool correct = false;
	if(!in.empty()) correct = true;
	size_t found = in.rfind('.');
	if(found != string::npos) ext = in.substr(found+1);
	else correct = false;
	cout << in.substr(found+1);

	return correct;
}
bool File::explode(string in, vector<string> *output, char delimeter){
	for(unsigned int i = 0; i < in.length(); i++){
		string part = "";

		for(unsigned int j = i; j< in.length();j++){
      if(j == in.length()-1) i = j;
      if(in[j] != delimeter){
        part += in[j];
      }else{
        i = j;
        break;
      }
    }
    if(part != "") output->push_back(part);
	}
	if(output->empty())  return false;
	else return true;
}
bool File::validateMode(string in){
	bool correct = false;
	correct = File::explode(in, &mode, '/');
	if(correct){
		cout << mode.size() << " wielkosc" << endl;
		for(unsigned int i = 0; i< mode.size();i++){
			if(mode[i] == "input" || mode[i] == "read" || mode[i] == "r" ) modeBin.push_back(1);
			else if(mode[i] == "output"||mode[i] == "write"||mode[i] == "w") modeBin.push_back(2);
			else if(mode[i] == "binary") modeBin.push_back(4);
			else if(mode[i] == "append") modeBin.push_back(8);
			else if(mode[i] == "truncate") modeBin.push_back(16);
		}
		if(!modeBin.empty()){
			correct = true;
		}else{
			correct = false;
			cout << "Wrong opening mode" << endl;
		}
	}
	return correct;
}
void File::setParameters(vector<unsigned char> *m){

}
