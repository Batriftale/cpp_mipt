#include "iostream"

using namespace std;
/#1
long long factorial(int n){
    if (n < 0)
        return 0;
    else if (n == 1)
        return n;
    return n * factorial(n-1);
}

int main(){
    int n;
    cout << "Type n" << endl;
    cin >> n;
    cout << "Factorial of " << n << " is " << factorial(n) << endl;
    return 0;
}
/#2
void Merge(int *A, int first, int mid, int last){
    int j;
    int *buf = new int[100];

    int start = first;
    int fin = mid + 1;

    for(j = first; j <= last; j++)

        if ((start <= mid) && ((fin > last) || (A[start] < A[fin]))){
            buf[j] = A[start];
            start++;
        }
        else{
            buf[j] = A[fin];
            fin++;
        }
        for (j = first; j <= last; j++)
            A[j] = buf[j];
    delete[]buf;
};

void mergeSort(int A[],int l,int r){
    {
    if(l < r){
    int mid = (l + r) / 2;

    mergeSort(A, l, mid);
    mergeSort(A, mid + 1, r);

    Merge(A, l, mid, r);
    }
}
};

int main(){
    int n;
    int *A = new int[100];

    cout << "The size of array is: " << endl;
    cin >> n;

    cout << "Type the elements" << endl;

    for (int i = 0; i < n; i++){
        cin >> A[i];
    }

    mergeSort(A, 0, n);

    for (int i = 0; i < n; i++){
        cout << A[i] << " ";
    }
    delete []A;
}
/#3





