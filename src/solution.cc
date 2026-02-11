#include "solution.hpp"
#include <fstream>
#include <string>

Student ReadStudentRecFromStream(std::istream& is) {
    std::string first_name;
    std::string last_name;
    unsigned int uin;
    double gpa;
    char comma;

    // Read first name
    is >> first_name;
    if (is.fail()) {
        return Student{};
    }

    // Read last name (will include trailing comma)
    is >> last_name;
    if (is.fail()) {
        return Student{};
    }

    // Check that last name ends with comma
    if (last_name.empty() || last_name.back() != ',') {
        return Student{};
    }

    // Remove comma
    last_name.pop_back();

    // Read UIN
    is >> uin;
    if (is.fail()) {
        return Student{};
    }

    // Read comma after UIN
    is >> comma;
    if (is.fail() || comma != ',') {
        return Student{};
    }

    // Read GPA
    is >> gpa;
    if (is.fail()) {
        return Student{};
    }

    // Combine names
    std::string full_name = first_name + " " + last_name;

    return Student{full_name, uin, gpa};
}
