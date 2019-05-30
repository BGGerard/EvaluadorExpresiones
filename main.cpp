#include <iostream>
#include <utility>
#include <regex> //feathur c++11
#include <string>
using namespace std;
int main()
{
// variable en la que se escriben las operasiones
    string cmd="";
    regex integer("[0-9]?([0-9]*[.])?[0-9]+|[\\-\\+\\\\\\\\(\\\\)\\\\/\\\\*]");
// Inicia el comandLine
    while (true) {
        getline(cin, cmd);

        if (cmd.compare("exit") == 0) {
            break;
        }

        if(regex_match(cmd,integer)){
            cout<<"integer"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}