#ifndef EVALUAR_H
#define EVALUAR_H

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <vector>
#include <regex>// c++11
#include <auto_ptr.h>//c++11
using namespace std;

class Evaluar
{
    public:
        Evaluar();
        virtual ~Evaluar();

        double eval(string p);
        bool validar(string e);

    protected:

    private:
};

#endif // EVALUAR_H
