#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <conio.h>

#define SQ struct Queue

int NumQuery, Num=0;

struct Queue{
    int x;
    SQ *next, *pre; 
}*First_InQueue, *Last_InQueue;

SQ *Append_Node(int x) {
    SQ *TempNode;
    TempNode = (SQ *) malloc(sizeof(SQ));
    
    TempNode -> x = x;
    TempNode -> pre = TempNode -> next =NULL;
    First_InQueue = Last_InQueue = TempNode;

    return TempNode;
}

SQ *Insert_Head(SQ *First, int x) {
    SQ *TempNode;
    TempNode = (SQ *) malloc(sizeof(SQ));
    
    TempNode -> x = x;
    TempNode -> next = First;
    TempNode -> pre = NULL;
    First -> pre = TempNode;
    First = TempNode;

    return TempNode;    
}

SQ *Insert_Last(SQ *Last, int x) {
    SQ *TempNode;
    TempNode = (SQ *) malloc(sizeof(SQ));
    
    TempNode -> x = x;
    TempNode -> next = NULL;
    TempNode -> pre = Last;
    Last -> next = TempNode;
    Last = TempNode;

    return TempNode;    
}

void MakeNull() {
    SQ *TempNode;
    TempNode = First_InQueue;

    free(TempNode);
}

SQ *Delete_Head(SQ *First) {
    SQ *TempNode;
    TempNode = (SQ *) malloc(sizeof(SQ));
    TempNode = First;

    First -> next -> pre = NULL;
    First = First -> next;
    free(TempNode);

    return First;
}

SQ *Delete_Last(SQ *Last) {
    SQ *TempNode;
    TempNode = (SQ *) malloc(sizeof(SQ));
    TempNode = Last;

    Last -> pre -> next = NULL;
    Last = Last -> pre;
    free(TempNode);

    return Last;    
}

void Print_First(SQ *First) {
    int x = First -> x;
    printf("%d\n", x);
}

void Print_Last(SQ *Last) {
    int x = Last -> x;
    printf("%d\n", x);
}

void Print_Query(SQ *First) {
    SQ *TempNode;
    TempNode = First;
    while (TempNode) {
        printf("%d ", TempNode -> x);
        TempNode = TempNode -> next;
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    scanf("%d", &NumQuery);
    while (NumQuery--) {
        int Class;
        scanf("%d", &Class);
        if (Class==1) {
            int x;
            scanf("%d", &x);
            
            if (Num==0)
                Append_Node(x);
            
            else {
                First_InQueue = Insert_Head(First_InQueue, x);
                if (!Last_InQueue)
                    Last_InQueue = First_InQueue;
            }
            Num++;

        }
        if (Class==2) {
            int x;
            scanf("%d", &x);

            if (Num==0)
                Append_Node(x);
            
            else {
                Last_InQueue = Insert_Last(Last_InQueue, x);
                if (!First_InQueue)
                    First_InQueue = First_InQueue;
            }
            Num++;
        }

        if (Class==3) {
            if (Num==1) 
                MakeNull();
            
            else 
                First_InQueue = Delete_Head(First_InQueue);

            Num--;
        }

        if (Class==4) {
            if (Num==1) 
                MakeNull();
            
            else 
                Last_InQueue = Delete_Last(Last_InQueue);

            Num--;
        }

        if (Class==5)
            Print_Query(First_InQueue);
    }
    return 0;
}