#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    string nama, password;
    int percobaan = 0;
    string nama_benar = "Meilonie";
    string password_benar = "128";

    while (percobaan < 3) {
        cout << "====================================\n";
        cout << "         LOGIN PROGRAM              \n";
        cout << "====================================\n";
        cout << "Masukkan Nama     : ";
        cin >> nama;
        cout << "Masukkan Password (3 digit NIM): ";
        cin >> password;

        if (nama == nama_benar && password == password_benar) {
            cout << "\nLogin Berhasil!\n";
            break;
        } else {
            percobaan++;
            cout << "\nLogin Gagal! Percobaan ke-" << percobaan << endl;
        }

        if (percobaan == 3) {
            cout << "\nAnda salah 3 kali. Program berhenti.\n";
            return 0;
        }
    }

    int pilihan;
    double nilai;

    do {
        cout << "\n====================================\n";
        cout << "        MENU KONVERSI PANJANG       \n";
        cout << "====================================\n";
        cout << "1. Meter ? Kilometer & Centimeter\n";
        cout << "2. Kilometer ? Meter & Centimeter\n";
        cout << "3. Centimeter ? Meter & Kilometer\n";
        cout << "4. Keluar\n";
        cout << "====================================\n";
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "\nMasukkan nilai dalam Meter: ";
                cin >> nilai;
                cout << fixed << setprecision(2);
                cout << "Hasil: \n";
                cout << nilai << " meter = "
                     << nilai / 1000 << " kilometer\n";
                cout << nilai << " meter = "
                     << nilai * 100 << " centimeter\n";
                break;

            case 2:
                cout << "\nMasukkan nilai dalam Kilometer: ";
                cin >> nilai;
                cout << fixed << setprecision(2);
                cout << "Hasil: \n";
                cout << nilai << " kilometer = "
                     << nilai * 1000 << " meter\n";
                cout << nilai << " kilometer = "
                     << nilai * 100000 << " centimeter\n";
                break;

            case 3:
                cout << "\nMasukkan nilai dalam Centimeter: ";
                cin >> nilai;
                cout << fixed << setprecision(2);
                cout << "Hasil: \n";
                cout << nilai << " centimeter = "
                     << nilai / 100 << " meter\n";
                cout << nilai << " centimeter = "
                     << nilai / 100000 << " kilometer\n";
                break;

            case 4:
                cout << "\nTerima kasih telah menggunakan program ini\n";
                break;

            default:
                cout << "\nPilihan tidak valid\n";
        }

    } while (pilihan != 4);

    return 0;
}
