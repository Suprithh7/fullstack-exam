#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

// Merge function
void merge(int arr[], int l, int m, int r) {
    int i = l, j = m + 1, k = 0;
    int temp[1000];

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= m)
        temp[k++] = arr[i++];

    while (j <= r)
        temp[k++] = arr[j++];

    for (int i = l, t = 0; i <= r; i++, t++)
        arr[i] = temp[t];
}

// Merge Sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[1000];

    // Generate random numbers
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }

    cout << "\nUnsorted Array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    // Start time
    clock_t start = clock();

    mergeSort(arr, 0, n - 1);

    // End time
    clock_t end = clock();

    cout << "\n\nSorted Array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";


double time_taken = double(end - start) / CLOCKS_PER_SEC;

cout << fixed << setprecision(6);
cout << "\n\nExecution Time: " << time_taken << " seconds\n";
cout << "Execution Time (microseconds): " 
     << time_taken * 1000000 << endl;
}