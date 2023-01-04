//generate a pair of cpp and hpp files for a given cpp class
//existing files are NOT overwritten

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <algorithm>

void print_usage(){
#ifndef WIN32
  std::cout << "USAGE:\n  makeclass classname" << std::endl;
#else
  std::cout << "USAGE:\n  makeclass.exe classname" << std::endl;
#endif 
}



int main(int argn, char** argv){
  if(argn !=2){print_usage(); return 0;}
  
  const std::string classname=argv[1];
  
  std::filesystem::path path_cpp = std::string(classname+".cpp");
  std::filesystem::path path_hpp = std::string(classname+".hpp");
  

  std::cout << "hpp:" << path_hpp << std::endl;
  
  
  //generate cpp file
  if(  std::filesystem::exists(path_cpp) ) {
    std::cout << "Skip cpp, file exists. File=" << path_cpp.c_str() <<std::endl;
  }else{
    std::ofstream out(path_cpp);
    if(!out){
        std::cerr << "ERROR cpp, cannot open file. File=" << path_cpp <<std::endl;
    }else{
      std::cout << "Create cpp. File=" << path_cpp << std::endl;
      out << "#include \"" << path_hpp.c_str() << "\"\n\n";
    }
  }
  
  
  //generate hpp file
  if(  std::filesystem::exists(path_hpp) ) {
    std::cout << "Skip hpp, file exists. File=" << path_hpp <<std::endl;
  }else{
    std::ofstream out(path_hpp);
    if(!out){
        std::cerr << "ERROR hpp, cannot open file. File=" << path_hpp <<std::endl;
    }else{
      std::cout << "Create hpp. File=" << path_hpp << std::endl;
      std::string def = classname;
      std::transform(def.begin(), def.end(), def.begin(), ::toupper);
      def=def + "_HPP";
      out << "#ifndef " << def <<"\n";
      out << "#define " << def <<"\n\n";
      out << "struct "<<classname<<"\n  \n};\n\n";
      out << "#endif //" << def <<"\n\n";
    }
  }
  
  
  
}
