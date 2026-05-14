#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int c = 3;  // constant
    ofstream file("second.csv");

    file << "n,f(n)=3n^2+4n+3,c*g(n)=3n\n";

    cout << "n\tf(n)\tc*n\n";
    cout << "------------------------\n";

    for(int n = 10; n <= 30; n++) {
        int fn = 3*n*n + 4*n + 3;
        int gn = c*n;

        cout << n << "\t" << fn << "\t" << gn;

        file << n << "," << fn << "," << gn << "\n";
    }

    file.close();

    cout << "\nFile 'second.csv' created\n";
    cout << "c = 3, n0 = 1\n";

    return 0;
}