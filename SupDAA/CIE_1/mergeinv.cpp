#include <iostream>
using namespace std;

// Merge function to count inversions
int merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid, k = left;
    int inv_count = 0;

    while (i <= mid - 1 && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            inv_count += (mid - i);  // key line
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (int i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

// Merge Sort with inversion count
int mergeSort(int arr[], int temp[], int left, int right) {
    int mid, inv_count = 0;

    if (right > left) {
        mid = (left + right) / 2;

        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);

        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

int main() {
    int arr[8] = {3, 1, 2, 8, 6, 5, 7, 4};
    int temp[8];

    int inv = mergeSort(arr, temp, 0, 7);

    cout << "Number of inversions: " << inv << endl;

    return 0;
}