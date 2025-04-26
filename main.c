#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/boolean.h"
#include "../header/kota.h"
#include "../header/mainbody.h"

int main() {
    int pilih, nomorKota, current;
    char nama[MAX_NAMA_ORANG + 1];
    char inputKota[MAX_KOTA * 2]; 
    ListKota daftarKota;
    addresskota P;

    InitKota(&daftarKota);

    do {
        printf("\n========== Menu ===========\n");
        printf("1. Entry Data\n");
        printf("2. Tambah Orang\n");
        printf("3. Hapus Kota\n");
        printf("4. Tampilkan Data\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilih);
        printf("\n==========================\n");
        getchar();

        switch (pilih) {
            case 1: 
                printf("\nMasukkan Nama Kota: ");
                fgets(inputKota, sizeof(inputKota), stdin);
                
                prosesInputKota(inputKota);
                
                if (strlen(inputKota) == 0) {
                    printf("Nama kota tidak valid\n");
                    break;
                }
                
                if (TambahKota(&daftarKota, inputKota)) {
                    printf("Kota %s berhasil ditambahkan\n", inputKota);
                }
                break;

            case 2: 
                TampilkanKotaStatis(daftarKota);
                    
                printf("Masukkan nomor kota: ");
                scanf("%d", &nomorKota);
                getchar();
                
                if (nomorKota < 1 || nomorKota > MAX_KOTA) {
                    printf("Nomor kota tidak valid!\n");
                    break;
                }
                
                P = First(daftarKota);
                current = 1;
                while (P != NULL && current < nomorKota) {
                    P = P->next;
                    current++;
                }
                
                if (P == NULL) {
                    printf("Kota tidak ditemukan!\n");
                } else {
                    printf("Masukkan nama orang: ");
                    fgets(nama, sizeof(nama), stdin);
                    nama[strcspn(nama, "\n")] = '\0';
                    
                    InsVLast(P, nama);
                    printf("Orang berhasil ditambahkan\n");
                }
                break;
             

            case 3: 
                TampilkanKotaStatis(daftarKota);
                    
                printf("Masukkan nomor kota yang akan dihapus: ");
                scanf("%d", &nomorKota);
                getchar();
                
                if (nomorKota < 1 || nomorKota > MAX_KOTA) {
                    printf("Nomor kota tidak valid!\n");
                    break;
                }
                
                P = First(daftarKota);
                current = 1;
                while (P != NULL && current < nomorKota) {
                    P = P->next;
                    current++;
                }
                
                if (P == NULL) {
                    printf("Kota tidak ditemukan!\n");
                } else {
                    HapusKota(&daftarKota, P->nk);
                }
                break;

            case 4: 
                TampilkanKotaStatis(daftarKota);
                break;

            case 0:
                printf("Program selesai.\n");
                break;

            default:
                printf("Pilihan tidak valid!\n");
                break;
        }
    } while (pilih != 0);

   
    return 0;
}