#ifndef MAINBODY_H
#define MAINBODY_H

#include "boolean.h"
#include <stdio.h>
#include <string.h>

#define Nil NULL
#define Info(P) (P)->nm
#define Next(P) (P)->next
#define MAX_NAMA_ORANG 100

typedef char infotype[MAX_NAMA_ORANG + 1];

typedef struct tElmtList *addressorg;
typedef struct tElmtList {
    infotype nm;
    addressorg next;
} ElmtList;

typedef struct tKota Kota;

boolean ListEmpty(Kota L);
addressorg Alokasi(infotype X);
void Dealokasi(addressorg P);
void InsVLast(Kota *L, infotype X);
void DelAll(Kota *L);
int HitungJumlahOrang(Kota L);

#endif