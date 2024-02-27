#include <iostream>
using namespace std;

void Swap (auto &a, auto&b) {

    auto temp = a;
    a = b;
    b = temp;

}

void InsertionSort (int arr[], int n) {

    for (int i =1; i<n; i++) {
        int j=i;
        while (j>0 && arr[j-1]>arr[j]) {
            Swap(arr[j-1], arr[j]);
            j--;
        }
    }


}

int main()
{
    int size = 9;
    int arr[size] = {5, 12, 7, 1, 13, 2 ,23, 11, 18};

    cout << "Unsorted array : ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    printf("\n");

    InsertionSort(arr, size);

    cout << "Sorted array : ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
