#include <stdio.h>
#include <string.h>

int main() {
    char namaPemesan[100];
    int pilihanTipeBangku;
    int jumlahPemesanan;
    double hargaSatuan;
    double totalHarga;

    printf("===============================================================\n");
    printf("    Selamat datang di Sistem Pemesanan Bangku Koperasi Bintang Tapanuli (KBT)\n");
    printf("===============================================================\n");
    printf("Masukkan nama pemesan: ");
    
    fgets(namaPemesan, sizeof(namaPemesan), stdin);
    namaPemesan[strcspn(namaPemesan, "\n")] = 0;

    printf("\nPilih jenis bangku yang ingin dipesan:\n");
    printf("1. KBT Ekonomi (Harga: Rp 100.000 per bangku)\n");
    printf("2. KBT Eksekutif (Harga: Rp 140.000 per bangku)\n");
    printf("---------------------------------------------------------------\n");
    printf("Masukkan pilihan Anda (1 atau 2): ");
    scanf("%d", &pilihanTipeBangku);

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
            printf("Pilihan tidak valid. Sistem akan default ke KBT Ekonomi.\n");
            hargaSatuan = 100000.0; 
            pilihanTipeBangku = 1;
            break;
    }

    printf("Masukkan jumlah bangku yang ingin dipesan: ");
    scanf("%d", &jumlahPemesanan);

    if (jumlahPemesanan <= 0) {
        printf("Jumlah pemesanan harus positif. Mengatur jumlah ke 1.\n");
        jumlahPemesanan = 1;
    }

    totalHarga = hargaSatuan * jumlahPemesanan;

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

    return 0;
}
