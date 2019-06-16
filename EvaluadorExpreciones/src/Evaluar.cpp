#include "Evaluar.h"
#include <string>

Evaluar::Evaluar()
{
    //ctor

}
Evaluar::~Evaluar()
{
    //ctor

}
double Evaluar::eval(string p)
{
   stack<double> pila;
    double op1, op2;
    for (int i=0; i < p.size(); i+=2) {
        switch (p[i]) {
            case '^':
                op2 = pila.top(); pila.pop();
                op1 = pila.top(); pila.pop();
                pila.push(pow(op1, op2));
                break;
            case '*':
                op2 = pila.top(); pila.pop();
                op1 = pila.top(); pila.pop();
                pila.push(op1*op2);
                break;
            case '%':
                op2 = pila.top(); pila.pop();
                op1 = pila.top(); pila.pop();
                pila.push(fmod(op1, op2));
                break;
            case '/':
                op2 = pila.top(); pila.pop();
                op1 = pila.top(); pila.pop();
                pila.push(op1 / op2);
                break;
            case '+':
                op2 = pila.top(); pila.pop();
                op1 = pila.top(); pila.pop();
                pila.push(op1 + op2);
                break;
            case '-':
                op2 = pila.top(); pila.pop();
                op1 = pila.top(); pila.pop();
                pila.push(op1 - op2);
                break;
            default:
                string aux = "";
                while (p[i] != ' ')
                    aux += string(1, p[i++]);
                pila.push(atof(aux.c_str()));
                i--;
        }
    }
    return pila.top();

}

//valida si la expresion es valida
bool Evaluar::validar(string e)
{
    //validacion de parentesis
    regex digito("[-+]?([0-9]*\\.[0-9]+|[0-9]+)");
    regex operador("[\\-\\+\\/\\*\\%\\[\\^]");
    regex equacion("^[\\-\\(\\[\\+]?([0-9]*\\.[0-9]+|[0-9]+)+[\\]\\)]*([-+*/^%]+[\\-\\(\\[\\+]?([0-9]*\\.[0-9]+|[0-9]+)+[\\]\\)]*)*$");
    int abrep=0;//parentesis
    int cierrap =0;
    //corchetes
    int abrec=0;
    int cierrac =0;

    string operadores_sin_llaves="+-/%^*";
    //validar sintaxis de ecuacion
    if(regex_match(e,equacion)){
        //valida parentesis
        for (int i = 0; i < e.size() ; ++i) {
            if (e[i]=='(' ){
                abrep = abrep +1;
            }
        }
        for (int j = 0; j <e.size() ; ++j) {
            if (e[j]==')')
                cierrap=cierrap+1;
        }
        for (int i = 0; i < e.size() ; ++i) {
            if ( e[i]=='[' ){
                abrec = abrec +1;
            }
        }
        for (int j = 0; j <e.size() ; ++j) {
            if (e[j]==']')
                cierrac=cierrac+1;
        }

        if (abrep == cierrap && (abrec == cierrac)){
            for (int o = 0; o <=operadores_sin_llaves.size() ; ++o) {
                for (int a = 0; a <=e.size() ; ++a) {
                    if (e[a] == operadores_sin_llaves[o]){
                        for (int h = 0; h <=operadores_sin_llaves.size() ; ++h) {
                            if (e[a-1]==operadores_sin_llaves[h] | e[a+1]==operadores_sin_llaves[h] ){
                                cout<<"Error de expresion infija incorrecta"<<endl;
                                return false;
                            }
                            else{
                                return true;
                            }
                        }
                    }
                }
            }
        }
        else if (abrep != cierrap){
            cout<<"Error de parentesis incompleto"<<endl;
        }
        else{
            cout<<"Error de corchete incompleto"<<endl;
        }
    }
    else {
        cout << "Error de caracteres no permitidos" << endl;
    }
    return false;
}


