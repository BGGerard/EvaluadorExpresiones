#ifndef POSTFIJA_H
#define POSTFIJA_H

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <string>
using namespace std;

class PostFija
{
    public:
        PostFija();
        virtual ~PostFija();

        int orden(char var);
        string posti(string in);

    protected:

    private:
};

#endif // POSTFIJA_H
