#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int c = 8;

    ofstream file("graph1.csv");
    file << "n,f(n)=7n+5,c*g(n)=8n\n";

    cout << "n\tf(n)\tc*g(n)\n";
    cout << "------------------------\n";

    for(int n = 10; n <= 30; n++) {
        int fn = 7*n + 5;
        int gn = c * n;

        cout << n << "\t" << fn << "\t" << gn << endl;

        // write to file
        file << n << "," << fn << "," << gn << "\n";
    }

    file.close();

    cout << "\nCSV file 'graph1.csv' created.\n";
    return 0;
}