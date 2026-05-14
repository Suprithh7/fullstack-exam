#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    int c = 1;

    ofstream file("graph11.csv");

    file << "n,f(n),c*g(n)\n";

    cout << "n\tf(n)\tc*g(n)\n";

    for(int n=10; n<=30; n++)
    {
        int fn = 8*n*n + 3*n + 3;
        int gn = n;

        file << n << "," << fn << "," << c*gn << "\n";

        cout << n << "\t" << fn << "\t" << c*gn << endl;
    }

    file.close();

    cout << "\nCSV file created successfully";

    return 0;
}