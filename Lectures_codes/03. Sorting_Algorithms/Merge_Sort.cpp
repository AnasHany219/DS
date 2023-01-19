#include <iostream>
using namespace std;

void merge(int a[],int i1,int i2,int j1,int j2)
{
    int temp[50];               //array used for merging
    int i= i1, j = j1, k = 0;

    while(i <= i2 && j <= j2){  //while elements in both lists
        if(a[i] < a[j])
            temp[k++] = a[i++];
        else
        temp[k++] = a[j++];
    }

    while(i <= i2)              //copy remaining elements of the first list
        temp[k++] = a[i++];

    while(j <= j2)              //copy remaining elements of the second list
        temp[k++] = a[j++];

    for(i = i1, j = 0; i <= j2; i++, j++)
        a[i] = temp[j];        //Transfer elements from temp[] back to a[]
}

void MergeSort(int a[],int i,int j)
{
    int mid;
    if(i < j){
        mid=(i+j)/2;

        // left recursion
        MergeSort(a, i, mid);

        // right recursion
        MergeSort(a, mid+1, j);

        // merging of two sorted sub-arrays
        merge(a, i, mid, mid+1, j);
    }
}

// Main Function
int main(){
    int arr[] = {-56, 23, 43, -5, -3, 0, 123, -35, 87, 56, 75, 80};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "before: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    MergeSort(arr, 0, n-1);

    cout << "\nafter: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
//end main()

/*
--------------------Output-------------------
before: -56 23 43 -5 -3 0 123 -35 87 56 75 80
after: -56 -35 -5 -3 0 23 43 56 75 80 87 123
*/
