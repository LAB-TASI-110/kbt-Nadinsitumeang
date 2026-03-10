#include <stdio.h>  // Untuk fungsi input/output seperti printf dan scanf
#include <string.h> // Untuk fungsi manipulasi string seperti strcspn

int main() {
    char namaPemesan[100];    // Buffer untuk menyimpan nama pemesan
    int pilihanTipeBangku;    // Pilihan jenis bangku (1 untuk Ekonomi, 2 untuk Eksekutif)
    int jumlahPemesanan;      // Jumlah bangku yang dipesan
    double hargaSatuan;       // Harga per unit bangku
    double totalHarga;        // Total harga pemesanan

    // Menampilkan pesan selamat datang dan meminta nama pemesan
    printf("===============================================================\n");
    printf("    Selamat datang di Sistem Pemesanan Bangku Koperasi Bintang Tapanuli (KBT)\n");
    printf("===============================================================\n");
    printf("Masukkan nama pemesan: ");
    
    // Menggunakan fgets untuk input string yang lebih aman dan menghapus karakter newline
    fgets(namaPemesan, sizeof(namaPemesan), stdin);
    namaPemesan[strcspn(namaPemesan, "\n")] = 0; // Menghapus karakter newline '\n' jika ada

    // Menampilkan pilihan jenis bangku
    printf("\nPilih jenis bangku yang ingin dipesan:\n");
    printf("1. KBT Ekonomi (Harga: Rp 100.000 per bangku)\n");
    printf("2. KBT Eksekutif (Harga: Rp 140.000 per bangku)\n");
    printf("---------------------------------------------------------------\n");
    printf("Masukkan pilihan Anda (1 atau 2): ");
    scanf("%d", &pilihanTipeBangku);

    // Menentukan harga satuan berdasarkan pilihan
    switch (pilihanTipeBangku) {
        case 1:
            hargaSatuan = 100000.0;
            printf("Anda memilih KBT Ekonomi.\n");
            break;
        case 2:
            hargaSatuan = 140000.0;
            printf("Anda memilih KBT Eksekutif.\n");
            break;
        default:
            // Jika pilihan tidak valid, default ke KBT Ekonomi
            printf("Pilihan tidak valid. Sistem akan default ke KBT Ekonomi.\n");
            hargaSatuan = 100000.0; 
            pilihanTipeBangku = 1; // Mengatur ulang pilihan untuk tampilan output
            break;
    }

    // Meminta jumlah bangku yang ingin dipesan
    printf("Masukkan jumlah bangku yang ingin dipesan: ");
    scanf("%d", &jumlahPemesanan);

    // Validasi sederhana untuk jumlah pemesanan (harus positif)
    if (jumlahPemesanan <= 0) {
        printf("Jumlah pemesanan harus positif. Mengatur jumlah ke 1.\n");
        jumlahPemesanan = 1;
    }

    // Menghitung total harga
    totalHarga = hargaSatuan * jumlahPemesanan;

    // Menampilkan ringkasan pemesanan dengan rapi
    printf("\n===============================================================\n");
    printf("                   Detail Pemesanan Anda\n");
    printf("===============================================================\n");
    printf("Nama Pemesan     : %s\n", namaPemesan);
    printf("Jenis Bangku     : KBT %s\n", (pilihanTipeBangku == 1 ? "Ekonomi" : "Eksekutif"));
    printf("Harga Satuan     : Rp %.0f\n", hargaSatuan);
    printf("Jumlah Pesanan   : %d bangku\n", jumlahPemesanan);
    printf("---------------------------------------------------------------\n");
    printf("Total Harga      : Rp %.0f\n", totalHarga);
    printf("===============================================================\n");
    printf("Terima kasih atas pemesanan Anda di Koperasi Bintang Tapanuli!\n");
    printf("===============================================================\n");

    return 0; // Program berakhir dengan sukses
}
