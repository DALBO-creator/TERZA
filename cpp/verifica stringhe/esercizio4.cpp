#include <iostream>
using namespace std;
int main() {
    string t, p, copia_p, c;
    cout << "inserisci testo: ";
    getline (cin, t);
    cout << "inserisci parola: ";
    getline (cin, p);
    for (int i = 0; i < p.size(); ++i) {
        c+='*';
    }
    for (int i = 0; i < p.size(); ++i) {
        if(p.at(i)>='a'&&p.at(i)<='z') {
            copia_p+=p.at(i)-'a'+'A';
        }
        else if(p.at(i)>='A'&&p.at(i)<='Z') {
            copia_p+=p.at(i)-'A'+'a';
        }
        else {
            copia_p+=p.at(i);
        }
    }
    int pos=0;
    while ((pos=t.find(copia_p,pos))!=string::npos) {
        t.replace(pos,p.size(),c);
        pos+=p.size();
    }
    pos=0;
    while((pos=t.find(p,pos))!=string::npos) {
        t.replace(pos,p.size(), c);
        pos+=p.size();
    }
    cout<< endl;
    cout << t;
    return 0;

}
