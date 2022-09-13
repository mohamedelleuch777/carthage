
#include <iostream>
#include <regex>
#include <vector>
#include <fstream>

using namespace std;
string source = "const x = 45;";

// int main_old()
// {
//     regex rg(R"()");
//     cmatch match;
//     regex_match(source.c_str(), match, rg);
//     cout << "this is a test program\n";
// }

struct stComment {
    string opening;
    string ending;
};
vector<stComment> CommentList = {
    {"//","\n"}, // inline comment
    {"/*","*/"}  // block comment
};

string RemoveComments(string source);
string LoadSourceFile(string path);

int main() {
    cout << "Compiling..." << endl;
    int i = 0;
    source = LoadSourceFile("example/test.js");
    source = RemoveComments(source);
// cout << source << endl;
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
    for(int cmt=0; cmt<CommentList.size(); cmt++) {
        int i = 0;
        bool insideBlock = false;
        while (i<source.size())
        {
            char currentChar = source[i];
            if(!insideBlock && currentChar=='/' && source.size()>(i+1)) {
                if(source[i+1]=='/' || source[i+1]=='*') {
                    insideBlock=true;
                }
            }
            else if(insideBlock && currentChar=='/' && source[i-1]=='*') {

            }
            else if(!insideBlock) {
                newSource += currentChar;
            }
            i++;
        }
    }
    return newSource;
}
