#include <type_traits>
# include <iostream>
# include <dirent.h>
# include <fstream>
# include <vector>

# define candidateAccuracyLimit 50
# define candidateAmountLimit 5
# define loaded true
# define log false

enum WordType {
    Invalid,
    NumANDLit,
    Numerical,
    Literal,
    Symbolic,
    Keyword
};

class LexicalAnalyser {
    private:
        //-- Input File Data
        int line, column, count;
        std::fstream code;
        std::string name;
        bool executable;
        bool findNear;
        int errors;
        //-- Character
        struct Character {
            char current;
            bool rvalue;
            int amount;
            char last;
        };
        Character character;
        //-- Word
        struct Word {
            std::string current;
            std::string last;
            bool begin;
            int count;
            bool etc;
            bool end;
            struct Type {
                int current;
                int last;
            };
            Type type;
        };
        Word word;
    public:
        //-- Constructor
        LexicalAnalyser();
        //-- Reader
        void Read();
        //-- Load File
        bool loadFile();
        //-- Check ID
        bool isID(const char &) const;
        //-- Check Separator
        bool isSeparator(const char &) const;
        //-- Check Character's Letter
        bool isLetter(const char &) const;
        //-- Check Digit
        template <typename _INPUT>
        bool isDigit(const _INPUT &) const;
        //-- Check Word's Letters and Finds Best Match
        bool isLegal(const std::string &) const;
        //-- Get Type of Word
        int getType(const std::string &) const;
        //-- Check Keyword
        bool isKeyword(const std::string &) const;
        //-- Check Operator
        bool isOperator(const std::string &) const;
        // //-- Destructor
        // ~LexicalAnalyser();
};

//-- Constructor
LexicalAnalyser::LexicalAnalyser() {
    std::cout << "Loading Code ..." << std::endl;
    if (loadFile() == loaded) {
        std::cout << "File Loaded Successfully" << std::endl;
        line = 1;
        count = 0;
        errors = 0;
        column = -1;
        findNear = false;
        executable = true;
        character.amount = 0;
        character.rvalue = false;
        word.current.clear();
        word.begin = false;
        word.last.clear();
        word.etc = false;
        word.end = false;
        word.count = 0;
        Read();
    } else {
        std::cout << "Can't Load File with Valid Types" << std::endl;
    }
}

//-- Load File
bool LexicalAnalyser::loadFile() {
    DIR *file;
    int flag = 0, flagAccepted = 0;
    std::string valid;
    struct dirent *action;
    file = opendir("File/");
    std::vector <std::string> validTypes;
    validTypes.push_back("txt");
    validTypes.push_back("cpp");
    validTypes.push_back("hpp");
    if (file) {
        while ((action = readdir(file)) != NULL) {
            flag = 0;
            name = action->d_name;
            if (name != ".") {
                if (name != "..") {
                    int index = name.find(".");
                    std::string type;
                    for (int i = index + 1; i < name.size(); i++) {
                        type.push_back(name[i]);
                    }
                    for (int i = 0; i < validTypes.size(); i++) {
                        if (type == validTypes[i]) {
                            flagAccepted++;
                            if (flagAccepted == 1) {
                                valid = name;
                                std::cout << "- File (" << name << ") Selected" << std::endl;
                                break;
                            }
                        } else {
                            flag++;
                        }
                    }
                }
            }
            if (flagAccepted == 1) {
                code = std::fstream("sss/b.cpp", std::fstream::in);
                break;
            }
            if (flag == validTypes.size()) {
                std::cout << "- Can't Accept File (" << name << ")'s Type" << std::endl;
            }
        }
    }
    if (code.is_open()) {
        return true;
    } else {
        return false;
    }
    // code = std::fstream ("b.cpp", std::fstream::in);
    // return true;
}

//-- Read File
void LexicalAnalyser::Read() {
    std::cout << std::endl;
    while (code >> std::noskipws >> character.current) {
        //-- Add Line
        if (character.current == '\n') {
            if (character.last != word.last[word.last.size()]) {
                word.etc = true;
            }
            word.count = 0;
            column = -1;
            count = 0;
            line++;
        }
        //-- Add Column
        column++;
        //-- Add Count
        if (character.current != ' ') {
            if (character.current != '\n') {
                count++;
            }
        }
        if (word.begin == false && word.end == false) {
            if (line > 1) {
                if (isSeparator(character.last) && isLetter(character.current)) {
                    word.begin = true;
                    word.current.push_back(character.current);
                } else if (isLetter(character.current)) {
                    word.begin = true;
                    word.current.push_back(character.last);
                    word.current.push_back(character.current);
                }
            } else if (line == 1) {
                if (isLetter(character.current)) {
                    word.begin = true;
                    word.current.push_back(character.current);
                }
            }
        } else if (word.begin == true && word.end == false) {
            if (!isSeparator(character.current) && isLetter(character.current)) {
                word.current.push_back(character.current);
            } else if (isSeparator(character.current) || !isdigit(character.current) || !isLetter(character.current) || isOperator(std::string(1, character.current))) {
                word.begin = false;
                word.end = true;
            }
        } else if (word.begin == false && word.end == true) {
            word.count++;
            if (isLegal(word.current)) {
                if (log) {
                    std::cout << "--> <" << word.current << "> is Legal" << std::endl;
                }
            } else {
                errors++;
                executable = false;
                findNear = true;
                isKeyword(word.last);
                findNear = false;
            }
            // std::cout << "curr : " << word.current << "- last : " << word.last << std::endl;
            word.last = word.current;
            word.current.clear();
            word.end = false;
        }
        //-- Check Characters
        if (isOperator(std::string(1, character.current))) {
            character.rvalue = true;
        }
        if (isID(character.current)) {
            //-- if Character is ID
            std::cout << "Error : Character <" << character.current << "> in Line : " << line << ", Column : " << column << ", Char Number : " << count << ", Type : <ID>" << std::endl;
            executable = false;
            errors++;
            if (line == 1 && count == 1) {
                std::cout << "--> <ID> Can't be in First of the Line 1" << std::endl;
            } else if (line != 1 && count == 1) {
                if (character.current == '"') {
                    //-- if Character is <">
                    if (word.type.current == Symbolic && word.type.last == Literal) {
                        if (!isKeyword(word.last) || !isOperator(word.current)) {
                            std::cout << "--> <" << character.current << "> Can't be After None-Keyword or None-Operator" << std::endl;
                        }
                    } else if (word.type.current == Symbolic && character.last != '=') {
                            std::cout << "--> Can't Assign String Without <=>" << std::endl;
                    }
                } else if (character.current == '!') {
                    //-- if Character is <!>
                    if (character.last != '(' || word.current != "&&" || word.current != "||") {
                        std::cout << "--> <" << character.current << "> is Illegal Because There is No Condition Symbols <(, &&, ||> Found Behind It" << std::endl;
                    }
                } else {
                    std::cout << "--> <" << character.current << "> is Illegal to be in First of the Line";
                }
            } else if (line != 1 && count > 1) {
                if (character.current == '"') {
                    //-- if Character is <">
                    if (word.type.current == Symbolic && word.type.last == Literal) {
                        if (!isKeyword(word.last) || !isOperator(word.current)) {
                            std::cout << "--> <" << character.current << "> Can't be After None-Keyword or None-Operator" << std::endl;
                        }
                    } else if (word.type.current == Symbolic && character.last != '=') {
                            std::cout << "--> Can't Assign String Without <=>" << std::endl;
                    }
                } else if (character.current == '!') {
                    //-- if Character is <!>
                    if (character.last != '(' || word.current != "&&" || word.current != "||") {
                        std::cout << "--> <" << character.current << "> is Illegal Because There is No Condition Symbols <(, &&, ||> Found Behind It" << std::endl;
                    }
                } else {
                    std::cout << "--> <" << character.current << "> is Illegal to be in First of the Line" << std::endl;
                }
            }
            std::cout << std::endl;
        } else if (isDigit(character.current)) {
            if (isdigit(character.last)) {
                //-- if Character is Digit
                if (count == 1) {
                    if (line == 1) {
                        std::cout << "Error : Digit <" << character.last << "> in Line : " << line << ", Column : " << column << ", Char Number : " << count << ", Type : <Digit>" << std::endl;
                        std::cout << "--> <" << character.last << "> Can't be in First of the Line 1" << std::endl << std::endl;
                        executable = false;
                        errors++;
                    } else {
                        if (!isLetter(character.last) || character.last == ' ') {
                            std::cout << "Error : Digit <" << character.last << "> in Line : " << line << ", Column : " << column << ", Char Number : " << count << ", Type : <Digit>" << std::endl;
                            std::cout << "--> <" << character.last << "> Can't be in First of the Word" << std::endl << std::endl;
                            executable = false;
                            errors++;
                        }
                    }
                } else {
                    if (!isLetter(character.last)) {
                        if (character.rvalue) {
                            character.rvalue = false;
                        } else {
                            if (character.last == ' ' || character.last != '=') {
                                std::cout << "Error : Digit <" << character.last << "> in Line : " << line << ", Column : " << column << ", Char Number : " << count << ", Type : <Digit>" << std::endl;
                                std::cout << "--> <" << character.last << "> Can't be in First of the Word" << std::endl << std::endl;
                                executable = false;
                                errors++;
                            } else if (!isDigit(character.last)) {
                                std::cout << "Error : Digit <" << character.last << "> in Line : " << line << ", Column : " << column << ", Char Number : " << count << ", Type : <Digit>" << std::endl;
                                std::cout << "--> <" << character.last << ">  Can't be in First of the Word" << std::endl << std::endl;
                                executable = false;
                                errors++;
                            }
                        }
                    }
                }
            }
        }
        //-- Set Last Values
        character.last = character.current;
        word.etc = false;
    }
    if (executable) {
        std::cout << "No Errors Found" << std::endl;
    } else {
        std::cout << std::endl;
        std::cout << "File has " << errors << " Error" << std::endl;
    }
    std::cout << std::endl;
}

//-- Check if Input is ID
bool LexicalAnalyser::isID(const char &input) const {
    std::vector<char> list;
        list.push_back('!');
        list.push_back('@');
        list.push_back('#');
        list.push_back('$');
        list.push_back('&');
        list.push_back('%');
        list.push_back('|');
        list.push_back('?');
        list.push_back('~');
        list.push_back('`');
        list.push_back('"');
    for (int i = 0; i < list.size(); i++) {
        if (input == list[i]) {
            return true;
        }
    }
    return false;
}

//-- Check if Input is Operator
bool LexicalAnalyser::isOperator(const std::string &input) const {
    std::vector<std::string> list ;
        list.push_back("+");
        list.push_back("++");
        list.push_back("-");
        list.push_back("--");
        list.push_back("=");
        list.push_back("==");
        list.push_back(">");
        list.push_back(">>");
        list.push_back(">=");
        list.push_back("<");
        list.push_back("<<");
        list.push_back("<=");
        list.push_back("*");
        list.push_back("/");
        list.push_back("%");
        list.push_back("*=");
        list.push_back("/=");
        list.push_back("-=");
        list.push_back("+=");
        list.push_back("%=");
    for (int i = 0; i < list.size(); i++) {
        if (input == list[i]) {
            return true;
        }
    }
    return false;
}

//-- Check if Input is Keyword
bool LexicalAnalyser::isKeyword(const std::string &input) const {
    std::vector<std::string> list;
        list.push_back("alignas");
        list.push_back("alignof");
        list.push_back("and");
        list.push_back("and_eq");
        list.push_back("asm");
        list.push_back("auto");
        list.push_back("bitand");
        list.push_back("bitor");
        list.push_back("bool");
        list.push_back("break");
        list.push_back("case");
        list.push_back("catch");
        list.push_back("char");
        list.push_back("char8_t");
        list.push_back("char16_t");
        list.push_back("char32_t");
        list.push_back("class");
        list.push_back("compl");
        list.push_back("concept");
        list.push_back("const");
        list.push_back("const_cast");
        list.push_back("consteval");
        list.push_back("constexpr");
        list.push_back("constinit");
        list.push_back("continue");
        list.push_back("cout");
        list.push_back("co_await");
        list.push_back("co_return");
        list.push_back("co_yield");
        list.push_back("decltype");
        list.push_back("default");
        list.push_back("delete");
        list.push_back("do");
        list.push_back("double");
        list.push_back("dynamic_cast");
        list.push_back("else");
        list.push_back("enum");
        list.push_back("explicit");
        list.push_back("export");
        list.push_back("extern");
        list.push_back("false");
        list.push_back("float");
        list.push_back("for");
        list.push_back("friend");
        list.push_back("goto");
        list.push_back("if");
        list.push_back("inline");
        list.push_back("int");
        list.push_back("long");
        list.push_back("main");
        list.push_back("mutable");
        list.push_back("namespace");
        list.push_back("new");
        list.push_back("noexcept");
        list.push_back("not");
        list.push_back("not_eq");
        list.push_back("nullptr");
        list.push_back("operator");
        list.push_back("or");
        list.push_back("or_eq");
        list.push_back("private");
        list.push_back("protected");
        list.push_back("public");
        list.push_back("register");
        list.push_back("reinterpret_cast");
        list.push_back("requires");
        list.push_back("return");
        list.push_back("short");
        list.push_back("signed");
        list.push_back("sizeof");
        list.push_back("static");
        list.push_back("static_assert");
        list.push_back("static_cast");
        list.push_back("struct");
        list.push_back("switch");
        list.push_back("template");
        list.push_back("this");
        list.push_back("thread_local");
        list.push_back("throw");
        list.push_back("true");
        list.push_back("try");
        list.push_back("typedef");
        list.push_back("typeid");
        list.push_back("typename");
        list.push_back("union");
        list.push_back("unsigned");
        list.push_back("using");
        list.push_back("using");
        list.push_back("virtual");
        list.push_back("void");
        list.push_back("volatile");
        list.push_back("wchar_t");
        list.push_back("while");
        list.push_back("xor");
        list.push_back("xor_eq");
    if (findNear) {
        int matchValue;
        double result;
        std::vector<std::string> proposedListAll;
        std::vector<std::string> proposedList;
        std::vector<double> percentageList;
        std::vector<int> amountDiff;
        std::vector<int> best;
        int letterAmountDiff = 0;
        proposedListAll.resize(0);
        percentageList.resize(0);
        proposedList.resize(0);
        amountDiff.resize(0);
        best.resize(0);
        for (int i = 0; i < list.size(); i++) {
            //-- Loop for Iterating Keyword List
            letterAmountDiff = list.at(i).size() -input.size();
            if (letterAmountDiff < 0) {
                letterAmountDiff *= -1;
            }
            if (letterAmountDiff >= 0 && letterAmountDiff <= 4) {
                matchValue = 0;
                for (int j = 0; j < list.at(i).size(); j++) {
                    //-- Loop for Iterating Each Keyword Letters
                    for (int k = 0; k < input.size(); k++) {
                        //-- Loop for Searching
                        if (list.at(i)[j] == input.at(k)) {
                            matchValue++;
                            if (matchValue > input.size()) {
                                matchValue--;
                            }
                        }
                    }
                }
                result = (matchValue * 100) / input.size();
                if (result > 0) {
                    percentageList.push_back(result);
                    proposedListAll.push_back(list.at(i));
                    amountDiff.push_back(letterAmountDiff);
                    if (log) {
                        std::cout << "--- Match Amount: " << matchValue << std::endl;
                        std::cout << "--- Result : " << result << " % Conformity" << std::endl;
                        std::cout << "--- Different Amount of Letters : " << letterAmountDiff << std::endl;
                    }
                }
            }
        }
        //-- Select Best Result
        double tmpBest;
        int tmpDiffAmount;
        double tmpPercentage;
        std::string tmpProposedList;
        for (int i = 0; i < proposedListAll.size() - 1; i++) {
            //- Sorting
            for (int j = 0; j < proposedListAll.size() - 1; j++) {
                //-- Bubble Sort Algorithm
                if (percentageList[j] < percentageList[j + 1]) {
                    tmpProposedList = proposedListAll[j + 1];
                    tmpPercentage = percentageList[j + 1];
                    tmpDiffAmount = amountDiff[j + 1];
                    proposedListAll[j + 1] = proposedListAll[j];
                    percentageList[j + 1] = percentageList[j];
                    amountDiff[j + 1] = amountDiff[j];
                    proposedListAll[j] = tmpProposedList;
                    percentageList[j] = tmpPercentage;
                    amountDiff[j] = tmpDiffAmount;
                }
            }
        }
        //-- Set Condidatess
        for (int i = 0; i < candidateAmountLimit; i++) {
            proposedList.push_back(proposedListAll[i]);
            best.push_back((percentageList[i] + ((proposedList.at(i).size() / input.size()) * 100)) / 2);
        }
        //-- Sort by Different Amount of Letters
        for (int i = 0; i < best.size() - 1; i++) {
            for (int j = 0; j < best.size() - 1; j++) {
                if (best[j] > best[j + 1]) {
                    tmpProposedList = proposedList[j + 1];
                    tmpPercentage = percentageList[j + 1];
                    tmpDiffAmount = amountDiff[j + 1];
                    tmpBest = best[j + 1];
                    proposedList[j + 1] = proposedList[j];
                    percentageList[j + 1] = percentageList[j];
                    amountDiff[j + 1] = amountDiff[j];
                    best[j + 1] = best[j];
                    proposedList[j] = tmpProposedList;
                    percentageList[j] = tmpPercentage;
                    amountDiff[j] = tmpDiffAmount;
                    best[j] = tmpBest;
                }
            }
        }
        //-- Show Best Condidates
        std::cout << "--> Did You Mean <" << proposedList[0] << "> with Probability of : " << best[0] << "%" << std::endl;
        std::cout << std::endl;
    } else {
        for (int i = 0; i < list.size(); i++) {
            if (input == list[i]) {
                return true;
            }
        }
    }
    return false;
} 

//-- Check if Input is ID
template <typename _INPUT>
bool LexicalAnalyser::isDigit(const _INPUT &input) const {
    char _char_etc;
    std::string _string_etc;
    if (typeid(input) == typeid(_string_etc)) {
        _string_etc = input;
        for (int i = 0; i < _string_etc.size(); i++) {
            if (_string_etc[i] >= 48 && _string_etc[i] <= 57) {
                return true;
            }
        }
    } else if (typeid(input) == typeid(_char_etc)) {
        if (character.current >= 48 && character.current <= 57) {
            return true;
        }
    }
    return false;
}

//-- Check if Input is Letter
bool LexicalAnalyser::isLetter(const char &input) const {
    return (input >= 65 && input <= 90) || (input >= 97 && input <= 122);
}

//-- Chck if Input is Letter
bool LexicalAnalyser::isLegal(const std::string &input) const {
    int type = getType(input);
    switch (type) {
        case Invalid: {
            if (!isKeyword(word.last) || (isKeyword(word.last) && word.etc)) {
                std::cout << "Error : Word <" << word.last << "> in Line : " << line - 1 << ", Column : " << column << ", Word Number : " << word.count << ", Type : <Invalid>" << std::endl;
                std::cout << "--> <" << word.last << "> is Illegal for Its Format" << std::endl;
                return false;
            } else {
                return true;
            }
            break;
        };
        case NumANDLit: {
            break;
        };
        case Numerical: {
            break;
        };
        case Literal: {
            break;
        };
        case Symbolic: {
            break;
        };
        case Keyword: {
            break;
        };
    };
    // best match
    // define match percentage
}

//-- Get Type of Word
int LexicalAnalyser::getType(const std::string &input) const {
    bool _isDigit, _isLit, _isSymbl;
    if (isKeyword(input)) {
        return Keyword;
    }
    for (int i = 0; i < input.size(); i++) {
        if (isDigit(input[i])) {
            _isDigit = true;
        } else if (isOperator(std::string(1, input[i])) || isID(input[i]) || isSeparator(input[i])) {
            _isSymbl = true;
        } else if (isLetter(input[i])) {
            _isLit = true;
        }
    }
    if (_isDigit && _isLit) {
        if (_isSymbl) {
            return Invalid;
        } else {
            return NumANDLit;
        }
    } else if (_isLit && !_isDigit && !_isSymbl) {
        return Literal;
    } else if (_isSymbl || !_isLit || !_isDigit) {
        return Symbolic;
    } else if (_isDigit || !_isLit || !_isSymbl) {
        return Numerical;
    } else {
        return Invalid;
    }
}

//-- Check If Character is Separator
bool LexicalAnalyser::isSeparator(const char &input) const {
    std::vector<char> list;
        list.push_back('{');
        list.push_back('}');
        list.push_back(',');
        list.push_back('.');
        list.push_back(';');
        list.push_back(':');
        list.push_back(' ');
        list.push_back('\n');
        list.push_back('<');
        list.push_back('>');
        list.push_back('[');
        list.push_back(']');
        list.push_back('(');
        list.push_back(')');
    for (int i = 0; i < list.size(); i++) {
        if (input == list[i]) {
            return true;
        }
    }
    return false;
}

//-- Main
int main() {
    LexicalAnalyser file;
}







