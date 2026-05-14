#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int c = 5;
    ofstream file("fifth.csv");

    file << "n,f(n)=5n+5,c*n\n";

    cout << "n\tf(n)\tc*n\n";
    cout << "------------------------\n";

    for(int n = 10; n <= 30; n++) {
        int fn = 5*n + 5;
        int gn = c*n;

        cout << n << "\t" << fn << "\t" << gn << endl;

        file << n << "," << fn << "," << gn << "\n";
    }

    file.close();

    cout << "\nc = 5, n0 = 1\n";

    return 0;
}