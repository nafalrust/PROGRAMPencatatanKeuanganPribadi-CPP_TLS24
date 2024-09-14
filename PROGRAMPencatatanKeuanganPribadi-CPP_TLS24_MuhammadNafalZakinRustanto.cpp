/* 
TUGAS TLS Pemograman (Muhammad Nafal Zakin Rustanto - Thevenin)
Sistem Pencatatan Keuangan Pribadi
*/

#include <iostream> //library untuk basic input-output dan operator
#include <iomanip> //library untuk pembuatan tabel
#include <ctime> //library untuk waktu
#include <string> //library untuk menggunakan data string

using namespace std;

int main(){
    const int maxBaris = 1000; //batas maksimum baris
    int baris = 0; //variabel awal untuk menghitung jumlah baris
    string waktu[maxBaris]; //array untuk menyimpan waktu transaksi
    string keterangan[maxBaris]; //array untuk menyimpan keterangan transaksi
    int pemasukan[maxBaris]; //array untuk menyimpan transaksi pemasukan
    int pengeluaran[maxBaris]; //array untuk menyimpan transaksi pengeluaran
    int total[maxBaris]; //array untuk menyimpan saldo total

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
        case 1: //jika pengguna ingin menambahkan data pemasukan (1)
            //mendapatkan input keterangan transasksi dari pengguna
            {
            cout<<"Masukkan keterangan transaksi: ";
            cin.ignore();
            getline(cin, keterangan[baris]); 

            cout<<"Masukkan jumlah pemasukan: Rp";
            cin >> pemasukan[baris]; //mendapatkan input jumlah pemasukan dari pengguna

            pengeluaran[baris] = 0;

            total[baris] = total[baris-1] + pemasukan[baris]; //menghitung jumlah total uang tersisa yang dimiliki pengguna
            baris++; //penambahan baris
            continue;
            }

        case 2: //jika pengguna ingin menambahkan data pengeluaran (2)
            //mendapatkan input keterangan transaksi dari pengguna
            {
            cout<<"Masukkan keterangan transaksi: ";
            cin.ignore();
            getline(cin, keterangan[baris]);

            cout<<"Masukkan jumlah pengeluaran: Rp";
            cin >> pengeluaran[baris]; //mendapatkan input jumlah pengeluaran dari pengguna

            pemasukan[baris] = 0;

            total[baris] = total[baris-1] - pengeluaran[baris]; //menghitung jumlah total uang tersisa yang dimiliki pengguna
            baris++; //penambahan baris
            continue;
            }

        case 3: //jika pengguna ingin menampilkan tabel keuangan (3)
            {
            cout<<"\nTABEL KEUANGAN\n"; //judul
            //memberi output berupa header tabel
            cout<< "--------------------------------------------------------------------------------------------------------" << endl;
            cout<< left << setw(20) << "Waktu" << setw(25) << "Keterangan" << setw(25) << "Pemasukan" << setw(25) << "Pengeluaran" << setw(25) << "Total" << endl;
            cout<< "---------------------------------------------------------------------------------------------------------" << endl;

            //memberi output berupa isi tabel pada setiap baris ke i
            for(int i = 0; i<baris; i++){
                cout << left << setw(20) << waktu[i] << setw(25) << keterangan[i] << setw(25) << "Rp" << pemasukan[i] << setw(25) << "Rp" << pengeluaran[i] << setw(25) << "Rp" << total[i] << endl;
                cout<< "......................................................................................................." << endl;

            break;
            }

        case 4: //jika pengguna ingin keluar dari sistem
            {
            break;
            }
            
        default:
            {
                cout << "Pilihan Anda Tidak Valid, Silahkan Coba Lagi\n";
            continue;
            }
        }
    }

    return 0;

}
