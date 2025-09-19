#include <iostream>
#include <vector>
using namespace std;
void riempi (vector<int>&v) {
    for (int i = 0; i < 10; ++i) {
        v.push_back(rand()%101);
    }
}
void stampa(vector<int>&v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v.at(i) << "    ";
    }
    cout << endl;
}

void ordina (vector<int>&v) {
    int temp;
    for (int i = 0; i < v.size()-1; ++i) {
        for (int j = i+1; j < v.size(); ++j) {
            if (v.at(i)>v.at(j)) {
                temp=v.at(i);
                v.at(i)=v.at(j);
                v.at(j)=temp;

            }
        }
    }
}
int main() {
    vector<int>v;
    riempi(v);
    stampa(v);
    ordina(v);
    stampa(v);




    return 0;
}
