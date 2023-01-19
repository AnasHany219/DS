#include <iostream>
using namespace std;

int insertUnsorted(int arr[], int n, int key, int size){
    arr[n] = key;
    return (n+1);
}
int main(){
    int arr[5] = {12, 16, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    int n = 3;
    int key = 26;
    cout << "Before Insertion: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    if(n < size)
    n = insertUnsorted(arr, n, key, size);
    cout << "\nAfter Insertion: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " " ;
    return 0;
}
//end main()
/*
-----------Output-----------
Before Insertion: 12 16 20
After Insertion: 12 16 20 26
*/
