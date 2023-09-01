//#include "scanner.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

#define log false

int line = 1, cols = 0;
char ch;
std::string buffer, tmp;

bool isComment(const std::string &str)
{
  // if (str == "*/") {
  //   cout << str << " \033[0;31mis Wrong at Line :\033[0m " << line << endl;
  // }
  return str == "/*" || str == "//";
}

bool isDigit(const std::string &str)
{
  return std::all_of(str.begin(), str.end(), ::isdigit);
}

bool isString(const std::string &str)
{
  return str[0] == '"' && str[str.size() - 1] == '"';
}

bool isBool(const std::string &str)
{
  return str == "true" || str == "false";
}

bool isLiteral(const std::string &str)
{
  return isDigit(str) && isString(str) && isBool(str);
}

bool isKeyword(const std::string &str)
{
  const vector<std::string> keywords{"using", "iostream", "namespace", "std", "main", "cout", "cin", "int", "float", "auto", "double", "do", "switch", "return"};
  for (const auto &keyword : keywords)
    if (keyword == str)
      return true;

  return false;
}

bool isStatement(const std::string &str)
{
  const vector<std::string> statements{"for", "while"};
  for (const auto &statement : statements)
    if (statement == str)
      return true;

  return false;
}

bool isOperator(const std::string &str)
{
  const vector<std::string> operators{"<", ">", "<=", ">=", "* ", "+", "-", "/", "=", "-=", "*=", "+=", "/=", "++", "--", "=="};
  for (const auto &op : operators)
    if (op == str)
      return true;

  return false;
}

bool isSeparator(const std::string &str)
{
  const vector<std::string> Separators{"{", "}", ",", "(", ")", ";"};
  for (const auto &separate : Separators)
    if (separate == str)
      return true;

  return false;
}

bool isNotLegal(const std::string &str)
{
  return str == " " || str == "\n";
}

bool isID(const std::string &str)
{
  // const vector<std::string> bad{"@" ,"!" , "#","$","%","^","&","*","(",")","-","+","=","]","[","}","{","|"};
  // for (int j = 0; j < str.size(); j++)
  // for (int i = 0; i < str.size(); i++) {
  //   if (bad[j] == to_string(str[i])) {
  //     return false;
  //   }
  // }
  // std::cout << "\033[1;33m" << str << "\033[0m\n";
  //  for (int i = 0; i < str.size(); i++) {
  //   if (isdigit(str[i]) || isComment(str) || isKeyword(str) || isStatement(str) || isOperator(str) || isSeparator(str) || isNotLegal(str)) {
  //     return false;
  //   }
  //  }
  // return true;
  if(std::isdigit(str[0]))
    return false;
  int counter = 0;
  if(str[0] == '_')
    counter++;

  for(; counter < str.size(); counter++)
    if(!(isalnum(str[counter])))
      return false;

  return true;
}

void printRoleOfToken(const std::string &token)
{
  tmp = token;
  if (isOperator(token))
    cout << "(operator, " << token << ")" << endl;
  else if (isSeparator(token))
    cout << "(separator, " << token << ")" << endl;
  else if (isKeyword(token))
    cout << "(keyword, " << token << ")" << endl;
  else if (isStatement(token))
    cout << "(statement, " << token << ")" << endl;
  else if (isLiteral(token))
    cout << "(literal, " << token << ")" << endl;
  else if (isID(token))
    cout << "(identifier, " << token << ")" << endl;
  else if (isComment(token))
    cout << "(comment, " << token << ")" << endl;
  else {
    for (int i = 0; i < token.size() + tmp.size(); i++) {
      // if (isOperator(tmp) || isComment(tmp) || isKeyword(tmp) || isOperator(tmp) || isSeparator(tmp)) {
      //   continue;
      // } 
      // cout << "\033[0;36m" << tmp << "\033[0m" << endl;
      if (isStatement(tmp)) {
        cout << endl << token << " \033[0;31mis wrong at line \033[0m" << line  << " \033[0;31m, col \033[0m" << cols << endl;
      } else if (isDigit(tmp)) {
        cout << endl << token << " \033[0;31mis wrong at line \033[0m" << line  << " \033[0;31m, col \033[0m" << cols << endl;
      } else if (isBool(tmp)) {
        cout << endl << token << " \033[0;31mis wrong at line \033[0m" << line  << " \033[0;31m, col \033[0m" << cols << endl;
      } else if (isID(tmp)) {
        cout << endl << token << " \033[0;31mis wrong at line \033[0m" << line  << " \033[0;31m, col \033[0m" << cols << endl;
      } else if (isLiteral(tmp)) {
        cout << endl << token << " \033[0;31mis wrong at line \033[0m" << line  << " \033[0;31m, col \033[0m" << cols << endl;  
      }
    }
  }
}


void lexicalAnalyze(const std::string &nameOfFile)
{
  std::fstream file(nameOfFile, std::fstream::in);

  if (!file.is_open())
  {
    cout << "error while opening the file\n";
    exit(0);
  }

  bool miltiCm = false, singleCm = false;
  // cout << "line 1" << endl;;
  while (file >> std::noskipws >> ch)
  {
    cout << ch;
    // cout << "\033[0;33m" << buffer.size() << " " << buffer << " " << ch << "\033[0m" << endl;
  }
  file.close();
}

int main()
{
  lexicalAnalyze("File/input.txt");
  return 0;
}
