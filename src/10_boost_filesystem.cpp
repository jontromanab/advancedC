
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

void testingFileSystem2(){
  fs::path myPath("/home/abhi/advancedC/");
  fs::directory_iterator itr(myPath);
  fs::directory_iterator end_itr;

  std::cout<<myPath.root_path()<<std::endl;
  std::cout<<myPath.parent_path()<<std::endl;

  while(itr!=end_itr && !fs::is_directory(itr->path())){
    std::cout<<"---------------------------------------------------"<<std::endl;
    std::cout<<"Path: "<<itr->path()<<std::endl;
    std::cout<<"Filename: "<<itr->path().filename()<<std::endl;
    std::cout<<"Is file: "<<fs::is_regular_file(itr->path())<<std::endl;
    std::cout<<"File Size :"<<fs::file_size(itr->path())<<std::endl;
    std::cout<<"----------------------------------------------------"<<std::endl;
    ++itr;
  }
}

int main(){
  testingFileSystem1();
  testingFileSystem2();
  return 0;
}
