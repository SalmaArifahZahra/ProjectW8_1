#ifndef KOTA_H
#define KOTA_H

#include "../header/mainbody.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h> 

#define Nil NULL
#define NamaKota(P) (P)->nk
#define NextKota(P) (P)->next
#define Head(P) (P)->head
#define First(L) (L).First
#define MAX_KOTA 10


typedef struct tKota *addresskota;
typedef struct tKota {
    char nk[MAX_KOTA];
    addressorg head;
    addresskota next;
} Kota;

typedef struct {
    addresskota First;
    int jumlahKota;
} ListKota;

void prosesInputKota(char *input);
void InitKota(ListKota *L);
addresskota SearchKota(ListKota L, char *namaKota);
boolean TambahKota(ListKota *L, char *namaKota);
void TampilkanKotaStatis(ListKota L);
void HapusKota(ListKota *L, char *namaKota);
void TampilListOrang(Kota kota);

#endif