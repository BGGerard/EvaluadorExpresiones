#include "PostFija.h"

PostFija::PostFija()
{
//ctor

}
PostFija::~PostFija()
{
    //dtor
}



int PostFija::orden(char op)
{
    switch (op) {
        case '^': return 3;
        case '*':
        case '%':
        case '/': return 2;
        case '+':
        case '-': return 1;
        case ')':
        case ']': return -1;
        default: return 0;
    }

}

string PostFija::posti(string in)
{
    stack<char> pila;
    string posf = "";
    for (int i=0; i < in.size(); i++) {
        switch (in[i]) {
            case '(':
                pila.push('(');
                break;
            case '[':
                pila.push('[');
                break;
            case '+':
                while (!pila.empty() && orden(in[i]) <= orden(pila.top())) {
                    posf += string(1,pila.top()) + " ";
                    pila.pop();
                }
                pila.push(in[i]);
                break;
            case '-':
                while (!pila.empty() && orden(in[i]) <= orden(pila.top())) {
                    posf += string(1,pila.top()) + " ";
                    pila.pop();
                }
                pila.push(in[i]);
                break;
            case '*':
                while (!pila.empty() && orden(in[i]) <= orden(pila.top())) {
                    posf += string(1,pila.top()) + " ";
                    pila.pop();
                }
                pila.push(in[i]);
                break;
            case '/':
                while (!pila.empty() && orden(in[i]) <= orden(pila.top())) {
                    posf += string(1,pila.top()) + " ";
                    pila.pop();
                }
                pila.push(in[i]);
                break;
            case '^':
                while (!pila.empty() && orden(in[i]) <= orden(pila.top())) {
                    posf += string(1,pila.top()) + " ";
                    pila.pop();
                }
                pila.push(in[i]);
                break;
            case '%':
                while (!pila.empty() && orden(in[i]) <= orden(pila.top())) {
                    posf += string(1,pila.top()) + " ";
                    pila.pop();
                }
                pila.push(in[i]);
                break;
            case ')':
                while (!pila.empty() && pila.top() != '(') {
                    posf += string(1,pila.top()) + " ";
                    pila.pop();
                }
                pila.pop();
                break;
            case ']':
                while (!pila.empty() && pila.top() != '[') {
                    posf += string(1,pila.top()) + " ";
                    pila.pop();
                }
                pila.pop();
                break;
            default:
                while (isdigit(in[i]) || in[i] == '.')
                    posf += string(1, in[i++]);
                posf += " ";
                i--;
        }
    }
    while (!pila.empty()) {
        posf += string(1, pila.top()) + " ";
        pila.pop();
    }
    return posf;
}
