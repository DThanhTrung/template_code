#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <stdbool.h>

#define maxn 100069

int *temp;

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
 
int main() {
    srand(time(NULL));
    setvbuf(stdout, NULL, _IONBF, 0);
    temp = (int *) malloc(maxn * sizeof( int));
    return 0;
}