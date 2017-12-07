
//Functionalities to iterate through folders, checking if a folder exists or renaming a folder/file.
#include<iostream>
#include<boost/filesystem.hpp>

namespace fs  = boost::filesystem;

void testingFileSystem1(){
  fs::path myPath("/home/abhi/advancedC/");
  bool pathExists = fs::exists(myPath);
  std::cout<<pathExists<<std::endl;

  fs::path newPath = myPath / "test.txt";
  pathExists = fs::exists(newPath);
  std::cout<<pathExists<<std::endl;

  fs::path myPathCreated = myPath/"TestFolder";
  fs::create_directory(myPathCreated);
  pathExists = fs::exists(myPathCreated);
  std::cout<<pathExists<<std::endl;
}

int main(){
  testingFileSystem1();
  return 0;
}
