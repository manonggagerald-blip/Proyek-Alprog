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
    printf("%-10s %-25s %-5s %-12s %-9s\n", "KODE_MK", "NAMA_MK", "SKS", "NILAI_ANGKA", "NILAI_SKS");
    for (int i = 0; i < n; i++) {
        printf("%-10s %-25s %-5d %-12.2f %-9d\n",
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

// MENGURUTKAN DATA BERDASARKAN KODE MK (WAJIB UNTUK BINARY SEARCH)
void urutkanData(Data data[], int n) {
    Data temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(data[j].kode_matakuliah, data[j + 1].kode_matakuliah) > 0) {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

// PENCARIAN DATA DENGAN BINARY SEARCH BERDASARKAN KODE MK
int binarySearch(Data data[], int n, char cari[]) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int res = strcmp(data[mid].kode_matakuliah, cari);
        
        if (res == 0) {
            return mid;
        }
        if (res < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
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
        
        getchar();
        
        printf("Masukkan nama mk : ");
        fgets(khs[i].nama_matakuliah,sizeof(khs[i].nama_matakuliah),
        stdin);
        
        khs[i].nama_matakuliah[
            strcspn(khs[i].nama_matakuliah,"\n")
            ] = '\0';
        
        printf("Masukkan sks/mk : ");
        scanf("%d", &khs[i].sks);
        
        printf("Masukkan nilai angka : ");
        scanf("%f", &khs[i].nilai_angka);
        
        printf("Masukkan nilai sks : ");
        scanf("%d", &khs[i].nilai_sks);

        printf("\n");
    }

    // MEMANGGIL FUNGSI URUTKAN DATA SEBELUM DITAMPILKAN DAN DICARI
    urutkanData(khs, n);

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

    // PROSES INPUT DAN EKSEKUSI BINARY SEARCH
    char cari_kode[20];
    printf("\nMasukkan Kode MK yang dicari : ");
    scanf("%s", cari_kode);

    int hasil = binarySearch(khs, n, cari_kode);

    if (hasil != -1) {
        printf("Kode MK %s merupakan mata kuliah %s\n", khs[hasil].kode_matakuliah, khs[hasil].nama_matakuliah);
       
    } else {
        printf("Data tidak ditemukan.\n");
    }

    return 0;
}
