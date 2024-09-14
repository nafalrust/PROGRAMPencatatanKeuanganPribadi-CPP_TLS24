### Tugas Pemrograman TLS 2024 - Muhammad Nafal Zakin Rustanto/Thevenin
# Program Pencatatan Keuangan Pribadi


## Latar Belakang dan Manfaat Program
Mengelola keuangan pribadi adalah salah satu hal penting yang harus dilakukan setiap orang agar setiap pemasukan dan pengeluaran keuangan dapat terpantau secara jelas. Di era digital, cara pencatatan keuangan pribadi telah berpindah dari metode manual ke metode digital. Program ini salah satu bentuk pencatatan keuangan digital yang dibuat dengan tujuan agar penggunanya dapat mencatatkan keuangannya dengan baik dan mudah, dan dengan manfaat sebagai berikut
1. Memantau arus keuangan pribadi
2. Organisir data keuangan
3. Mempermudah perhitungan
4. Visualisasi data

## Penjelasan Program
Program ini disusun dengan bahasa pemrograman C++, dengan penjelasan terkat kompenen dan fungsinya sebagai berikut:
* ### Library
```

#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>

```
1. library `<iostream>` digunakan untuk menyediakan fungsi input atau output dasar seperti `cout <<` atau `cin >>`
2. library `<ionmanip>` digunakan untuk manipulasi format output di terminal, contohnya untuk membuat tabel dengan beberapa contoh syntax '`setw()` dan `left`
3. library `<ctime>` digunakan untuk mendapatkan data waktu dan tanggal contoh pengunaan syntaxnya adalah `time()` untuk mendapatkan waktu saat ini (UTC)
4. library `<string>` digunakan untuk fungsi mengolah data bertipe string contohnya pada syntax 'to_string' untuk mengonversi angka menjadi string
* ### Struktur Data
Program ini menggunakan 5 array untuk menyimpan data transaksi keuangan pribadi, yaitu
1. `waktu[]` untuk menyimpan waktu transaksi, yang diisi dengan memanfaatkan library `<ctime>`
2. `keterangan[]` untuk menyimpan deskripsi transaksi
3. `pemasukan[]` untuk menyimpan jumlah pemasukan
4. `pengeluaran[]` untuk menyimpan jumalh pengeluaran
5. `total[]` untuk menyimpan saldo total tiap transaksi
* ### Alur Program
1. Program dimulai dengan inisialisasi variabel dan array, 
```
const int maxBaris = 1000; //batas maksimum baris
int baris = 0; //variabel awal untuk menghitung jumlah baris
string waktu[maxBaris]; //array untuk menyimpan waktu transaksi
string keterangan[maxBaris]; //array untuk menyimpan keterangan transaksi
int pemasukan[maxBaris]; //array untuk menyimpan transaksi pemasukan
int pengeluaran[maxBaris]; //array untuk menyimpan transaksi pengeluaran
int total[maxBaris]; //array untuk menyimpan saldo total
```
2. Program masuk ke loop untuk memproses konversi waktu pada library `<ctime>`, menampilkan menu, dan memproses input pengguna
```
while(true){
    total[baris] = 0.0;
        
    //dapatkan waktu saat transaksi
    time_t now = time(0);
    tm *ltm = localtime(&now); //konversi waktu ke localtime

    //konversi waktu untuk dimasukkan ke tabel [format hh.mm DD/MM/YYYY]
    waktu[baris] = to_string(ltm->tm_hour) + "." + to_string(ltm->tm_min) + "  " + to_string(ltm->tm_mday) + "/" + to_string(1 + ltm->tm_mon) + "/" + to_string(1900 + ltm->tm_year);

    //buat dashboard pengguna
    cout<<"\nSELAMAT DATANG DI PENCATATAN KEUANGAN\n1. Catat Pemasukan Anda\n2. Catat Pengeluaran Anda\n3. Tampilkan Tabel Keuangan\n4. Keluar\n";
    cout<<"Masukkan Pilihan Anda (1/2/3/4): ";
    int pilihan;
    cin>>pilihan;

    switch (pilihan)
    {
        ....
```
3. Berdasarkan pilihan pengguna:
    * Jika pengguna memilih opsi 1 atau 2, program akan meminta input keterangan transaksi dan jumlahnya, kemudian menyimpannya dalam array yang sesuai serta menghitung saldo total `total += (pemasukan-pengeluaran)`
    * Jika pengguna memilih opsi 3, program akan menampilkan tabel keuangan, sebagai berikut:
        1. library `<cmanip>` digunakan untuk mengatur format tabel, termasuk mengatur lebar dengan `setw()` dan membuat garis/kolom
        2. library `<ctime>`dan konversi waktunya pada array `waktu[baris]` digunakan untuk mengisi kolom waktu transaksi
        3. kolom pemasukan, pengeluaran, dan total diisi dengan array masing-masing
    * Jika pengguna memilih opsi 4, program akan keluar (dari loop)
    * Jika pengguna memilih opsi yang tidak tertera maka program akan mencetak `Pilihan Anda Tidak Valid, Silahkan Coba Lagi` dan mengulang loop kembali
4. Setelah selesai transaksi, program memperbarui saldo total dan kembali ke menu utama
* ### Potensi Pengembangan
Karena program ini dibuat untuk penugasan TETI Lab Skill (TLS) 2024, tentunya akan menjadi portofolio awal saya dan akan memiliki potensi untuk terus dikembangkan kedepannya seperti:
1. Menambahkan fitur penyimpanan data ke dalam file local
2. Menambahkan kategorisasi transaksi
3. Menambahkan analisis keuangan tertentu
4. Menambahkan fitur pencarian dan filtering
5. Meningkatkan keamanan
6. Pengembangan menjadi web atau apps, dll
