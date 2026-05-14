#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    int c1 = 5;
    int c2 = 9;

    ofstream file("graph10.csv");

    file << "n,f(n),c1*g(n),c2*g(n)\n";

    cout << "n\tf(n)\tc1*g(n)\tc2*g(n)\n";

    for(int n=10; n<=30; n++)
    {
        int fn = 5*n*n + 6*n + 3;
        int gn = n*n;

        file << n << "," << fn << "," << c1*gn << "," << c2*gn << "\n";

        cout << n << "\t"
             << fn << "\t"
             << c1*gn << "\t\t"
             << c2*gn << endl;
    }

    file.close();

    cout << "\nCSV file created successfully";

    return 0;
}