#include<iostream>
using namespace std;

int insertsorted(int arr[], int n, int key, int size){
    if(n >= size)
        return n;
    int i;
    for(i = n - 1; (i >= 0 && arr[i] > key); i--)
        arr[i+1] = arr[i];

    arr[i+1] = key;
    return n+1;
}
int main(){

    int arr[20] = {12, 16, 20, 40, 50, 70};
    int size = sizeof(arr)/sizeof(arr[0]);
    int n = 6;
    int key = 26;

    cout << "Before Insertion: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    n = insertsorted(arr, n, key, size);

    cout << "\nAfter Insertion: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " " ;
    return 0;
}
//end main()

/*
----------------Output---------------
Before Insertion: 12 16 20 40 50 70
After Insertion: 12 16 20 26 40 50 70
*/
