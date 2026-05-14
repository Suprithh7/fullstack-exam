#include <iostream>
using namespace std;

#define N 3

// Check if woman prefers new man over current man
bool prefers(int prefer[2*N][N], int w, int m, int m1) {
    for (int i = 0; i < N; i++) {
        if (prefer[w][i] == m)
            return true;
        if (prefer[w][i] == m1)
            return false;
    }
    return false;
}

void stableMarriage(int prefer[2*N][N]) {
    int womenPartner[N]; // women matched with men
    bool menFree[N];     // free men

    for (int i = 0; i < N; i++) {
        womenPartner[i] = -1;
        menFree[i] = false;
    }

    int freeCount = N;

    while (freeCount > 0) {
        int m;
        for (m = 0; m < N; m++)
            if (!menFree[m])
                break;

        for (int i = 0; i < N && !menFree[m]; i++) {
            int w = prefer[m][i];

            // if woman is free
            if (womenPartner[w - N] == -1) {
                womenPartner[w - N] = m;
                menFree[m] = true;
                freeCount--;
            }
            else {
                int m1 = womenPartner[w - N];

                if (prefers(prefer, w, m, m1)) {
                    womenPartner[w - N] = m;
                    menFree[m] = true;
                    menFree[m1] = false;
                }
            }
        }
    }

    cout << "Woman   Man\n";
    for (int i = 0; i < N; i++)
        cout << i + N << "       " << womenPartner[i] << endl;
}

int main() {
    int prefer[2*N][N] = {
        {3,4,5}, // Man 0
        {3,4,5}, // Man 1
        {3,4,5}, // Man 2

        {0,1,2}, // Woman 3
        {0,1,2}, // Woman 4
        {0,1,2}  // Woman 5
    };

    stableMarriage(prefer);

    return 0;
}