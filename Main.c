#include <stdio.h>
#include <string.h>

typedef struct {
    char kode_matakuliah[20];
    char nama_matakuliah[50];
    int sks;
    float nilai_angka;
    int nilai_sks;
} Data;

// MENAMPILKAN DATA KARTU HASIL STUDI
void tampilkanKHS(Data data[], int n) {
    printf("KODE_MK\tNAMA_MK\tSKS\tNILAI_ANGKA\tNILAI_SKS\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%s\t%d\t%.2f\t%d\n",
            data[i].kode_matakuliah,
            data[i].nama_matakuliah,
            data[i].sks,
            data[i].nilai_angka,
            data[i].nilai_sks);
    }
}

// MENGHITUNG JUMLAH SKS
int hitungJumlahSKS(Data hitung[], int n) {
    int hasil = 0;
    for (int i = 0; i < n; i++) {
        hasil = hasil + hitung[i].sks;
    }
    return hasil;
}

// MENGHITUNG JUMLAH NILAI SKS
int hitungJumlahNilaiSKS(Data hitung[], int n) {
    int hasil = 0;
    for (int i = 0; i < n; i++) {
        hasil = hasil + hitung[i].nilai_sks;
    }
    return hasil;
}

// MENGHITUNG RATA NILAI ANGKA
float rataRataNilaiAngka(Data rata[], int n) {
    float hasil = 0;
    for (int i = 0; i < n; i++) {
        hasil = hasil + rata[i].nilai_angka;
    }
    return hasil / n;
}

// FUNGSI UTAMA
int main() {
    int n;
    printf("Masukkan jumlah data : ");
    scanf("%d", &n);
    
    Data khs[n];
    
    // MEMASUKKAN DATA KARTU HASIL STUDI DARI USER DENGAN PERULANGAN ARRAY
    for (int i = 0; i < n; i++) {
        printf("Input data ke %d\n", i + 1);

        printf("Masukkan kode mk : ");
        scanf("%s", khs[i].kode_matakuliah);
        
        printf("Masukkan nama mk : ");
        scanf("%s", khs[i].nama_matakuliah);
        
        printf("Masukkan sks/mk : ");
        scanf("%d", &khs[i].sks);
        
        printf("Masukkan nilai angka : ");
        scanf("%f", &khs[i].nilai_angka);
        
        printf("Masukkan nilai sks : ");
        scanf("%d", &khs[i].nilai_sks);

        printf("\n");
    }

    tampilkanKHS(khs, n);

    int jumlah_sks = hitungJumlahSKS(khs, n);
    printf("\nTotal SKS : %d\n", jumlah_sks);
    int jumlah_nilai_sks = hitungJumlahNilaiSKS(khs, n);
    printf("Total Nilai SKS : %d\n", jumlah_nilai_sks);

    // MENGHITUNG NILAI AKHIR INDEKS PRESTASI SEMESTER (IPS)
    float hitungIPS = (float) jumlah_nilai_sks / jumlah_sks;
    printf("Indeks Prestasi Semester : %.2f\n", hitungIPS);

    float rataRata = rataRataNilaiAngka(khs, n);
    printf("Rata Rata Nilai angka : %.2f\n", rataRata);

    return 0;
}
