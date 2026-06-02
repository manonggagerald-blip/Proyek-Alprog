#include <stdio.h>
#include <string.h>

typedef struct {
    char kode_matakuliah[20];
    char nama_matakuliah[50];
    int sks;
    float nilai_angka;
} Data;

void tampilkanKHS(Data data[], int n) {
    printf("KODE_MK\tNAMA_MK\tSKS\tNILAI_ANGKA\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%s\t%d\t%.2f\n",
            data[i].kode_matakuliah,
            data[i].nama_matakuliah,
            data[i].sks,
            data[i].nilai_angka);
    }
}

int main() {
    int n;
    printf("Masukkan jumlah data : ");
    scanf("%d", &n);
    
    Data khs[n];
    
    for (int i = 0; i < n; i++) {
        printf("Masukkan kode mk : ");
        scanf("%s", khs[i].kode_matakuliah);
        
        printf("Masukkan nama mk : ");
        scanf("%s", khs[i].nama_matakuliah);
        
        printf("Masukkan sks/mk : ");
        scanf("%d", &khs[i].sks);
        
        printf("Masukkan nilai angka : ");
        scanf("%f", &khs[i].nilai_angka);
    }
    
    tampilkanKHS(khs, n);

    return 0;
}
