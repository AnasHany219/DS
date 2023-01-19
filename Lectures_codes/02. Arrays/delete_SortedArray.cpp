#include <iostream>
using namespace std;

int BinarySearch(int arr[], int low, int high, int key){

    if(high < low)
        return -1;
    int mid = (high + low) / 2;
    if(arr[mid] == key)
        return mid;
    if(arr[mid] < key)
        return BinarySearch(arr, mid + 1, high, key);
    else
        return BinarySearch(arr, low, mid - 1, key);
}

int deleteElement(int arr[], int n, int key){
    int pos = BinarySearch(arr, 0, n-1, key);

    if(pos == -1){
        cout << "Element not found";
        return n;
    }

    for(int i = pos; i < n-1; i++)
        arr[i] = arr[i+1];

    return n - 1;
}

int main(){
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30;

    cout << "Array before deletion: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    n = deleteElement(arr, n, key);

    cout << "\nArray after deletion: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
//end main()
/*
----------------Output---------------
Array before deletion: 10 20 30 40 50
Array after deletion: 10 20 40 50
*/
