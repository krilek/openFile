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
	if(validateMode(m)) setParameters(modeBin);
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
// bool File::setFile()
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
		//cout << mode.size() << " wielkosc" << endl;
		bool trunc = false;
		bool app = false;
		bool out = false;
		for(unsigned int i = 0; i< mode.size();i++){
			if(mode[i] == "input" || mode[i] == "read" || mode[i] == "r" ) modeBin.push_back(8);
			else if(mode[i] == "output"||mode[i] == "write"||mode[i] == "w"){
				modeBin.push_back(16);
				out = true;
			}
			else if(mode[i] == "binary") modeBin.push_back(4);
			else if(mode[i] == "at end" || mode[i] == "atend") modeBin.push_back(2);
			else if(mode[i] == "append"){
				app = true;
				modeBin.push_back(1);
			}
			else if(mode[i] == "truncate"){
				trunc = true;
				modeBin.push_back(32);
			}
		}
		if(!modeBin.empty() && !(trunc && app) && (trunc && out)){
			correct = true;
		}else{
			correct = false;
			cout << "Wrong opening mode" << endl;
		}
	}
	return correct;
}
bool File::setParameters(vector<int> m){
	int endM = m[0];
	for(unsigned int i=0;i<m.size();i++){
		//cout << (int)m[i] << endl;
		endM = endM | m[i];
	}
	//cout << endM;
	// cout<< "in" << fstream::in << endl;
	// cout << "out" << fstream::out << endl;
	// cout << "binary"<< fstream::binary << endl;
	// cout << "ate"<< fstream::ate << endl;
	// cout << "app"<< fstream::app << endl;
	// cout << "trunc"<< fstream::trunc << endl;
	if(endM > 0){
		endMode = endM;
		return true;
	}else{
		return false;
	}
}
