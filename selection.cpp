#include <iostream>
using namespace std;

void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int mini = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[mini]) {
                mini = j;
            }
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int n;
    cout << "Enter the number of books in the library: ";
    cin >> n;

    int unique_numbers[n];
    cout << "Enter the unique identification numbers of the books:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Unique number of book " << i + 1 << ": ";
        cin >> unique_numbers[i];
    }

    cout << "\nUnique identification numbers of the books before sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << unique_numbers[i] << " ";
    }
    cout << endl;

    selection_sort(unique_numbers, n);

    cout << "\nUnique identification numbers of the books after sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << unique_numbers[i] << " ";
    }
    cout << endl;

    return 0;
}
