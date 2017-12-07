
//Functionalities to iterate through folders, checking if a folder exists or renaming a folder/file.
#include<iostream>
#define BOOST_NO_CXX11_SCOPED_ENUMS
#include <boost/filesystem.hpp>
#undef BOOST_NO_CXX11_SCOPED_ENUMS

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
    itr++;
  }
}

void testingFileSystem3(){
  fs::path originalFile("/home/abhi/advancedC/monteCarloTest.bin");
  fs::path copiedFile("/home/abhi/advancedC/TestFolder/monteCarloTestCopied.bin");
  fs::path newFilename("/home/abhi/advancedC/TestFolder/monteCarloTestRenamed.bin");

  fs::directory_iterator itr(copiedFile.parent_path());
  fs::directory_iterator end_itr;

  while(itr!=end_itr){
    std::cout<<"Directory files begin: "<<itr->path()<<std::endl;
    std::cout<<"-----------------------------"<<std::endl;
    itr++;
  }

  if(!fs::exists(copiedFile)){
    fs::copy_file(originalFile, copiedFile);
  }

  fs::directory_iterator itr1(copiedFile.parent_path());
  while(itr1!=end_itr){
    std::cout<<"Directory files after copy: "<<itr1->path()<<std::endl;
    std::cout<<"---------------------------------"<<std::endl;
    itr1++;
  }

  fs::rename(copiedFile, newFilename);

  fs::directory_iterator itr2(copiedFile.parent_path());
  while(itr2!=end_itr){
    std::cout<<"Directory files after rename: "<<itr2->path()<<std::endl;
    std::cout<<"---------------------------------"<<std::endl;
    itr2++;
  }

  fs::remove(newFilename);
  fs::directory_iterator itr3(copiedFile.parent_path());
  while(itr3!=end_itr){
    std::cout<<"Directory files after remove: "<<itr3->path()<<std::endl;
    std::cout<<"---------------------------------"<<std::endl;
    itr3++;
  }
}

int main(){
  testingFileSystem1();
  testingFileSystem2();
  testingFileSystem3();
  return 0;
}
