
#include <iostream>
#include <regex>
#include <vector>
#include <fstream>

using namespace std;
string source;

// int main_old()
// {
//     regex rg(R"()");
//     cmatch match;
//     regex_match(source.c_str(), match, rg);
//     cout << "this is a test program\n";
// }

string RemoveComments(string source);
string LoadSourceFile(string path);

/****************************************************************************
*                               MAIN FUNCTION
****************************************************************************/
int main() {
    cout << "Compiling..." << endl;
    int i = 0;
    source = LoadSourceFile("example/test.js");
    source = RemoveComments(source);
    cout << source << endl;
return 0;
    while (i<source.size())
    {
        char currentChar = source[i];
        i++;
    }
    return 0;
}

string LoadSourceFile(string path) {
    string file, line;
    ifstream sourceFile (path);
    if (sourceFile.is_open()) {
    while ( getline (sourceFile,line) )
    {
        file += line + '\n';
    }
    sourceFile.close();
    }
    return file;
}

string RemoveComments(string source) {
    string newSource;
    int i = 0;
    bool insideInlineComment = false;
    bool insideBlockComment = false;
    while (i<source.size())
    {
        char currentChar = source[i];
        if(!insideInlineComment && currentChar=='/' && source.size()>(i+1)) {
            if(source[i+1]=='/') {
                insideInlineComment=true;
            }
            else if(source[i+1]=='*') {
                insideBlockComment=true;
            }
        }
        else if(insideBlockComment && currentChar=='/' && source[i-1]=='*') {
            insideBlockComment=false;
        }
        else if(insideInlineComment && currentChar=='\n') {
            insideInlineComment=false;
        }
        else if(!insideInlineComment && !insideBlockComment) {
            newSource += currentChar;
        }
        i++;
    }
    return newSource;
}
