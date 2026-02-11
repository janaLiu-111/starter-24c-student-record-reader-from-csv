#include "solution.hpp"

Student ReadStudentRecFromStream(std::istream& is) {
  const std::string input_file_name("./data.input.txt"); // assumes this file is within our working directory
  std::ifstream ifs{input_file_name};
  if (!ifs.is_open()) {
    std::cerr << "Could not open " << input_file_name << std::endl;
    return 1;
  }


  while(ifs.good()) {
    unsigned int uin = 0;
    double gpa = 0.0;
    std::string full_name;
    char throw_away = '\0';
    
    ifs >> full_name >> throw_away >> uin >> throw_away >> gpa;
    if (ifs.fail()){
      break;
      return Student{};
    }
  }
  return Student{full_name, uin, gpa};
}
