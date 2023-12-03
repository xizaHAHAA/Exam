#include <iostream>

using namespace std;
const int MAX_ROWS = 3; 
const int MAX_COLS = 3;

// введення масиву
void inputArray(int arr[MAX_ROWS][MAX_COLS]) {
    cout << "Enter elements of mas: " << MAX_ROWS << "x" << MAX_COLS << ":\n";
    for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = 0; j < MAX_COLS; ++j) {
            cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> arr[i][j];
        }
    }
}

// пошук макс числа масиву
int findingmax(int arr[MAX_ROWS][MAX_COLS], int col) {
    int maxElement = arr[0][col];
    for (int i = 1; i < MAX_ROWS; ++i) {
        if (arr[i][col] > maxElement) {
            maxElement = arr[i][col];
        }
    }
    return maxElement;
}

// пошук мін числа масиву
int findingmin(int arr[MAX_ROWS][MAX_COLS], int col) {
    int minElement = arr[0][col];
    for (int i = 1; i < MAX_ROWS; ++i) {
        if (arr[i][col] < minElement) {
            minElement = arr[i][col];
        }
    }
    return minElement;
}

// зміна макс і мінімального числа масиву
void swap_max_min(int arr[MAX_ROWS][MAX_COLS], int col) {
    int maxElement = findingmax(arr, col);
    int minElement = findingmin(arr, col);

    for (int i = 0; i < MAX_ROWS; ++i) {
        if (arr[i][col] == maxElement) {
            arr[i][col] = minElement;
        }
        else if (arr[i][col] == minElement) {
            arr[i][col] = maxElement;
        }
    }
}

// вивід масиву
void printArray(int arr[MAX_ROWS][MAX_COLS]) {
   cout << "Done massive: " << MAX_ROWS << "x" << MAX_COLS << ":\n";
    for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = 0; j < MAX_COLS; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int array[MAX_ROWS][MAX_COLS];

    inputArray(array);

    // перевірка кожного стовпця
    for (int j = 0; j < MAX_COLS; j++) {
        int maxInColumn = findingmax(array, j);
        int minInColumn = findingmin(array, j);

        cout << "Max element in colum " << j + 1 << ": " << maxInColumn << "\n";
        cout << "Min element in colum " << j + 1 << ": " << minInColumn << "\n";

        swap_max_min(array, j);
    }

    printArray(array);

    return 0;
}
