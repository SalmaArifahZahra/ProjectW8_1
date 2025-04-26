#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include "../header/boolean.h"
#include "../header/kota.h"
#include "../header/mainbody.h"

void InitKota(ListKota *L) {
    First(*L) = Nil;
    L->jumlahKota = 0;
}

boolean TambahKota(ListKota *L, char *namaKota) {
    if (L->jumlahKota >= MAX_KOTA) {
        printf("Batas maksimal kota (%d) tercapai\n", MAX_KOTA);
        return false;
    }
    
    if (SearchKota(*L, namaKota) != Nil) {
        printf("Kota %s sudah ada\n", namaKota);
        return false;
    }
    
    addresskota P = (addresskota)malloc(sizeof(Kota));
    if (P == Nil) {
        printf("Alokasi memori gagal\n");
        return false;
    }
    
    strncpy(P->nk, namaKota, MAX_KOTA-1);
    P->nk[MAX_KOTA-1] = '\0';
    P->head = Nil;
    P->next = Nil;
    
    if (First(*L) == Nil) {
        First(*L) = P;
    } else {
        addresskota last = First(*L);
        while (last->next != Nil) {
            last = last->next;
        }
        last->next = P;
    }
    
    L->jumlahKota++;
    return true;
}

addresskota SearchKota(ListKota L, char *namaKota) {
    addresskota P = First(L);
    while (P != Nil) {
        if (strcmp(P->nk, namaKota) == 0) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

void TampilkanKotaStatis(ListKota L) {
    addresskota P = First(L);
    int i = 1;

    while (i <= MAX_KOTA) {
        printf("Kota %d: ", i);
        if (P != NULL && i <= L.jumlahKota) {
            printf("%s\n", NamaKota(P));
            
            if (Head(P) == NULL) {
                printf("  Tidak ada orang\n");
            } else {
                addressorg Q = Head(P);
                printf("  Daftar Orang:\n");
                while (Q != NULL) {
                    printf("  - %s\n", Q->nm);
                    Q = Q->next;
                }
            }
            P = NextKota(P);
        } else {
            printf("(Kosong)\n");
        }
        printf("\n");
        i++;
    }
}

void HapusKota(ListKota *L, char *namaKota) {
    addresskota P = First(*L);
    addresskota Prec = NULL;

    while (P != NULL && strcmp(NamaKota(P), namaKota) != 0) {
        Prec = P;
        P = NextKota(P);
    }

    if (P == NULL) {
        printf("Kota tidak ditemukan\n");
    } else {
        if (Prec == NULL) {
            First(*L) = NextKota(P);
        } else {
            NextKota(Prec) = NextKota(P);
        }

        free(P);
        L->jumlahKota--;
        printf("Semua Data berhasil dihapus\n", namaKota);
    }
}

void TampilListOrang(Kota kota) {
    addressorg P = kota.head;
    if (P == Nil) {
        printf("  Tidak ada orang\n");
    } else {
        printf("  Daftar Orang:\n");
        while (P != Nil) {
            printf("  - %s\n", P->nm);
            P = P->next;
        }
    }
}

void prosesInputKota(char *input) {
    input[strcspn(input, "\n")] = '\0';
    
    char *space = strchr(input, ' ');
    if (space != NULL) {
        *space = '\0';
    }
    
    if (strlen(input) >= MAX_KOTA) {
        input[MAX_KOTA-1] = '\0';
    }
}