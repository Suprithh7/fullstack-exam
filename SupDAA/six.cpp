#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int c = 9;
    ofstream file("six.csv");

    file << "n,f(n)=8n^2+3n+3,c*n^2\n";

    cout << "n\tf(n)\tc*n^2\n";
    cout << "------------------------\n";

    for(int n = 10; n <= 30; n++) {
        int fn = 8*n*n + 3*n + 3;
        int gn = c*n*n;

        cout << n << "\t" << fn << "\t" << gn << endl;

        file << n << "," << fn << "," << gn << "\n";
    }

    file.close();

    cout << "\nc = 9, n0 = 3\n";

    return 0;
}