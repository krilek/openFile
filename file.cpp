class File{
private:
  std::string path;
  std::string mode;
};
void File::openFile(std::string p, std::string m){
  path = p;
  mode = m;
}
