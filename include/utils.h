#ifndef UTILS_H_
#define UTILS_H_

#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstddef>
#include <cctype>

/**
   @brief Returns a vector where the first string is the
   name of the header, and the second is the value.
   @return vector of size 2 where 0 is the header name and
   1 is the actual value
*/
std::vector<std::string> parse_header(std::string &header);

/**
   @brief returns a new string with surrounding whitespace removed
   @reuturn new string w/ whitespace removed.
*/
std::string strip(std::string &s);

/**
   @brief split a string based on some character c
   @return vector of the strings
*/
std::vector<std::string> split(std::string &s, char c);

#endif // UTILS_H_
