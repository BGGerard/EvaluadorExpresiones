#include <iostream>
#include <cstdlib>
#include <cmath>
#include <stack>
#include "PostFija.h"
#include "Evaluar.h"
#include <utility>
int main()
{
    // variables de imgreso de expresiones
    string  p;
    string cmd = "";
    bool existe = true;

    PostFija *post = new PostFija();
    Evaluar *ev = new Evaluar();

// mario estupido
    cout <<"EVALUADOR DE EXPRESIONES ==> Ingrese  una expresion valida"<<endl;


    while (true) {
        getline(cin, cmd);

        if (cmd.compare("exit") == 0) {
            break;
        }
        if (true){
            existe = ev->validar(cmd);
            if (existe == true){
                p = post->posti(cmd);
                double c = ev->eval(p);
                cout<<"Expresion valida "<<endl;
                cout << "Evaluada: " << c << endl;
                cout << "Posfija: " << p << endl;
                continue;
            }
            else {
                cout << "Exprecion invalida Escriba bien " << endl;
                continue;
            }
        }

        return 0;
    }
}
