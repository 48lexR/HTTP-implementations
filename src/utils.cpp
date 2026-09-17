#include "include/utils.h"

/**
   @brief Returns a vector where the first string is the
   name of the header, and the second is the value.
   @return vector of size 2 where 0 is the header name and
   1 is the actual value
*/
std::vector<std::string> parse_header(std::string &header){

  if(header == nullptr){
    std::cerr << "Error: cannot parse NULL string" << std::endl;
    return NULL;
  } else if(header.empty()){
    std::cerr << "Error: cannot parse empty string" << std::endl;
    return NULL;
  }
  // read through and find where the colon is
  std::size_t colon_index = 0;
  std::size_t semicolon_index = 0;
  // then read through and find where the semicolon is
  for(std::size_t x = 0; x < header.length(); x++){
    if(header[x] == ':') colon_index = x;
    else if(header[x] == ';') semicolon_index = x;
  }
  if(colon_index > semicolon_index){
    std::cerr << "Error: not a proper header" << std::endl;
    return NULL;
  }

  std::string h = strip(header.substr(0, colon_index));
  std::string c = strip(header.substr(colon_index+1, header.length()));
  std::vector<std::string> res;
  res.push_back(h);
  res.push_back(c);
  return res;
}

/**
   @brief returns a new string with surrounding whitespace removed
   @reuturn new string w/ whitespace removed.
*/
std::string strip(std::string &s){
  if(s == nullptr){
    std::cerr << "Cannot strip null string" << std::endl;
    return NULL;
  } else if(s.empty()){
    std::cerr << "Cannot strip empty string" << std::endl;
  }

  std::size_t start = 0;
  std::size_t end = 0;
  std::size_t i = 0;
  while(i < s.length() && std::isspace(s[i])){
    i++;
  }

  if(i == s.length()){
    std::string a("");
    return a;
  } else {
    start = i;
  }

  std::size_t j = s.length() - 1;
  while(j > i + 1 && std::isspace(s[j])){
    j--;
  }
  end = j;
  std::string res(s.substr(i, j));
  return res;
}

/**
   @brief split a string based on some character c
   @return vector of the strings
*/
std::vector<std::string> split(std::string &s, char c){
  std::size_t start = 0;
  std::size_t end = 0;
  std::vector<std::string> res;
  while(start < s.length()){
    while(s[start] == c){
      start++;
      end++;
    }

    while(s[end] != c){
      end++;
    }
    res.push_back(s.substr(start,end));
  }
  return res;
}
