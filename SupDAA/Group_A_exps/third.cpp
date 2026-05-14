#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int c1 = 7, c2 = 8;
    ofstream file("q3_theta.csv");

    file << "n,f(n)=7n^2+7n+5,7n^2,8n^2\n";

    cout << "n\tf(n)\t7n^2\t8n^2\n";
    cout << "--------------------------------\n";

    for(int n = 10; n <= 30; n++) {
        int fn = 7*n*n + 7*n + 5;
        int lower = c1*n*n;
        int upper = c2*n*n;

        cout << n << "\t" << fn << "\t" << lower << "\t" << upper << endl;

        file << n << "," << fn << "," << lower << "," << upper << "\n";
    }

    file.close();

    cout << "\nc1 = 7, c2 = 8, n0 = 3\n";

    return 0;
}