#include "../header/kota.h"
#include "../header/mainbody.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

boolean ListEmpty(Kota L) {
    return (L.head == Nil);
}

addressorg Alokasi(infotype X) {
    addressorg P = (addressorg)malloc(sizeof(ElmtList));
    if (P != Nil) {
        strcpy(Info(P), X);
        Next(P) = Nil;
    }
    return P;
}

void Dealokasi(addressorg P) {
    if (P != Nil) {
        free(P);
    }
}

void InsVLast(Kota *L, infotype X) {
    addressorg P = Alokasi(X);
    if (P != Nil) {
        if (L->head == Nil) {
            L->head = P;
        } else {
            addressorg temp = L->head;
            while (Next(temp) != Nil) {
                temp = Next(temp);
            }
            Next(temp) = P;
        }
    }
}

void DelAll(Kota *L) {
    addressorg PDel = L->head;
    addressorg temp;
    
    while (PDel != Nil) {
        temp = PDel;
        PDel = Next(PDel);
        Dealokasi(temp);
    }
    
    L->head = Nil;
}

int HitungJumlahOrang(Kota L) {
    int count = 0;
    addressorg P = L.head;
    
    while (P != Nil) {
        count++;
        P = Next(P);
    }
    
    return count;
}