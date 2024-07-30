#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <stdbool.h>

#define maxn 100069
#define inf 0x3f3f3f3f

int *temp, *arr;

int random(int x, int y) {
    return x + rand()%(y-x+1);
}

void Merge(int *a, int l, int r) {
    int mid=(l+r)/2;
    int i=l, j=mid+1, index=l;
    while (i<=mid && j<=r) {
        if (a[i] <= a[j]) {
            temp[index] = a[i];
            i++;
        }
        else {
            temp[index] = a[j];
            j++;
        }
        index++;
    }
    while (i<=mid) {
        temp[index] = a[i];
        index++;
        i++;
    }
    while (j<=r) {
        temp[index] = a[j];
        index++;
        j++;
    }
    for (i=l; i<=r; i++) 
        a[i]=temp[i];
}

void MergeSort(int *a, int l, int r) {
    if (l==r)
        return;
    int mid=(l+r)/2;
    MergeSort(a, l, mid);
    MergeSort(a, mid+1, r);
    Merge(a, l, r);
}

int main() {
    srand(time(NULL));
    setvbuf(stdout, NULL, _IONBF, 0);
    temp = (int *) malloc(maxn * sizeof( int));
    arr = (int *) malloc(maxn * sizeof( int));
    int n;
    scanf("%d", &n);
    
    for (int i=0; i<n; i++) {
        arr[i] = random(-100, 100);
    }
    
    MergeSort(arr, 0, n-1);

    for (int i=0; i<n; i++)
        printf("%d ", arr[i]);
    free(arr);
    free(temp);
    return 0;
}