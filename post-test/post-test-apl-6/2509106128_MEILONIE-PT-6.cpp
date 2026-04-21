#include <iostream>
#include <iomanip>
using namespace std;

struct Kontak{
    string nama;
    string telepon;
    string alamat;
    string email;
    string kategori;
};

struct SistemKontak{
    Kontak daftar[100];
    int jumlah = 0;
};

struct User{
    string username;
    string nim;
};

SistemKontak dataKontak;
User user = {"meilonie","128"};

void header(string teks){
    cout << "\n==== " << teks << " ====\n";
}

bool login(string nama, string nim){
    return (nama == user.username && nim == user.nim);
}

int cariKontak(string nama, SistemKontak *kontak){
    for(int i = 0; i < kontak->jumlah; i++){
        if(kontak->daftar[i].nama == nama){
            return i;
        }
    }
    return -1;
}

void tampilRekursif(int index, SistemKontak *kontak){
    if(index == kontak->jumlah) return;

    cout << left << setw(5) << index + 1
         << setw(15) << kontak->daftar[index].nama
         << setw(15) << kontak->daftar[index].telepon
         << setw(20) << kontak->daftar[index].alamat
         << setw(25) << kontak->daftar[index].email
         << setw(20) << kontak->daftar[index].kategori << endl;

    tampilRekursif(index + 1, kontak);
}

void create_kontak(SistemKontak *kontak){
    cin.ignore();
    header("Tambah Kontak");

    cout << "Nama : ";
    getline(cin, kontak->daftar[kontak->jumlah].nama);

    cout << "Telepon : ";
    getline(cin, kontak->daftar[kontak->jumlah].telepon);

    cout << "Alamat : ";
    getline(cin, kontak->daftar[kontak->jumlah].alamat);

    cout << "Email : ";
    getline(cin, kontak->daftar[kontak->jumlah].email);

    cout << "Kategori : ";
    getline(cin, kontak->daftar[kontak->jumlah].kategori);

    kontak->jumlah++;
    cout << "Kontak berhasil disimpan\n";
}

void read_kontak(SistemKontak *kontak){
    header("DAFTAR KONTAK");

    if(kontak->jumlah == 0){
        cout << "Belum ada kontak\n";
        return;
    }

    cout << left << setw(5) << "No"
         << setw(15) << "Nama"
         << setw(15) << "Telepon"
         << setw(20) << "Alamat"
         << setw(25) << "Email"
         << setw(20) << "Kategori" << endl;

    cout << "--------------------------------------------------------------------------\n";
    tampilRekursif(0, kontak);
}

void update_kontak(SistemKontak *kontak){
    cin.ignore();
    string namaCari;

    cout << "Masukkan nama kontak : ";
    getline(cin, namaCari);

    int index = cariKontak(namaCari, kontak);

    if(index == -1){
        cout << "Kontak tidak ditemukan\n";
        return;
    }

    cout << "Nama baru : ";
    getline(cin, kontak->daftar[index].nama);

    cout << "Telepon baru : ";
    getline(cin, kontak->daftar[index].telepon);

    cout << "Alamat baru : ";
    getline(cin, kontak->daftar[index].alamat);

    cout << "Email baru : ";
    getline(cin, kontak->daftar[index].email);

    cout << "Kategori baru : ";
    getline(cin, kontak->daftar[index].kategori);

    cout << "Kontak berhasil diupdate\n";
}

void delete_kontak(SistemKontak *kontak){
    cin.ignore();
    string namaCari;

    cout << "Masukkan nama kontak : ";
    getline(cin, namaCari);

    int index = cariKontak(namaCari, kontak);

    if(index == -1){
        cout << "Kontak tidak ditemukan\n";
        return;
    }

    for(int i = index; i < kontak->jumlah - 1; i++){
        kontak->daftar[i] = kontak->daftar[i + 1];
    }

    kontak->jumlah--;
    cout << "Kontak berhasil dihapus\n";
}

void sortingNamaDescending(SistemKontak *kontak){
    for(int i = 0; i < kontak->jumlah - 1; i++){
        for(int j = 0; j < kontak->jumlah - i - 1; j++){
            if(kontak->daftar[j].nama < kontak->daftar[j + 1].nama){
                swap(kontak->daftar[j], kontak->daftar[j + 1]);
            }
        }
    }
    cout << "Data berhasil diurutkan nama Z-A\n";
}

void sortingTeleponAscending(SistemKontak *kontak){
    for(int i = 0; i < kontak->jumlah - 1; i++){
        int indexTerkecil = i;

        for(int j = i + 1; j < kontak->jumlah; j++){
            if(stoi(kontak->daftar[j].telepon) < stoi(kontak->daftar[indexTerkecil].telepon)){
                indexTerkecil = j;
            }
        }

        swap(kontak->daftar[i], kontak->daftar[indexTerkecil]);
    }
    cout << "Data berhasil diurutkan telepon kecil-besar\n";
}

void sortingKategoriAscending(SistemKontak *kontak){
    for(int i = 1; i < kontak->jumlah; i++){
        Kontak dataSementara = kontak->daftar[i];
        int posisi = i - 1;

        while(posisi >= 0 && kontak->daftar[posisi].kategori > dataSementara.kategori){
            kontak->daftar[posisi + 1] = kontak->daftar[posisi];
            posisi--;
        }

        kontak->daftar[posisi + 1] = dataSementara;
    }

    cout << "Data berhasil diurutkan kategori A-Z\n";
}

int linearSearchNama(string namaCari, SistemKontak *kontak){
    for(int i = 0; i < kontak->jumlah; i++){
        if(kontak->daftar[i].nama == namaCari){
            return i;
        }
    }
    return -1;
}

int binarySearchTelepon(string teleponCari, SistemKontak *kontak){
    int low = 0;
    int high = kontak->jumlah - 1;

    while(low <= high){
        int mid = (low + high) / 2;

        if(kontak->daftar[mid].telepon == teleponCari)
            return mid;
        else if(stoi(kontak->daftar[mid].telepon) < stoi(teleponCari))
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

void searchingMenu(SistemKontak *kontak){
    int pilihan;
    cin.ignore();

    header("MENU SEARCHING");
    cout << "1. Cari berdasarkan Nama (Linear Search)\n";
    cout << "2. Cari berdasarkan Telepon (Binary Search)\n";
    cout << "Pilihan : ";
    cin >> pilihan;
    cin.ignore();

    if(pilihan == 1){
        string namaCari;
        cout << "Masukkan nama : ";
        getline(cin, namaCari);

        int index = linearSearchNama(namaCari, kontak);

        if(index != -1)
            cout << "Kontak ditemukan: " << kontak->daftar[index].nama << endl;
        else
            cout << "Kontak tidak ditemukan\n";
    }
    else if(pilihan == 2){
        sortingTeleponAscending(kontak);
        string teleponCari;
        cout << "Masukkan telepon : ";
        getline(cin, teleponCari);

        int index = binarySearchTelepon(teleponCari, kontak);

        if(index != -1)
            cout << "Kontak ditemukan: " << kontak->daftar[index].nama << endl;
        else
            cout << "Kontak tidak ditemukan\n";
    }
}

void menu(SistemKontak *kontak){
    int pilihan;

    do{
        header("MENU KONTAK");
        cout << "1. Tambah Kontak\n";
        cout << "2. Lihat Kontak\n";
        cout << "3. Update Kontak\n";
        cout << "4. Hapus Kontak\n";
        cout << "5. Sorting Nama Descending\n";
        cout << "6. Sorting Telepon Ascending\n";
        cout << "7. Sorting Kategori Ascending\n";
        cout << "8. Searching Kontak\n";
        cout << "9. Keluar\n";
        cout << "Pilihan : ";
        cin >> pilihan;

        if(pilihan == 1) create_kontak(kontak);
        else if(pilihan == 2) read_kontak(kontak);
        else if(pilihan == 3) update_kontak(kontak);
        else if(pilihan == 4) delete_kontak(kontak);
        else if(pilihan == 5) sortingNamaDescending(kontak);
        else if(pilihan == 6) sortingTeleponAscending(kontak);
        else if(pilihan == 7) sortingKategoriAscending(kontak);
        else if(pilihan == 8) searchingMenu(kontak);

    } while(pilihan != 9);
}

int main(){
    string nama, nim;
    int percobaan = 0;
    bool berhasil = false;

    while(percobaan < 3){
        header("LOGIN");
        cout << "Username : ";
        cin >> nama;
        cout << "NIM : ";
        cin >> nim;

        if(login(nama, nim)){
            berhasil = true;
            break;
        }

        cout << "Login gagal\n";
        percobaan++;
    }

    if(!berhasil){
        cout << "Gagal login 3x\n";
        return 0;
    }

    menu(&dataKontak);
    cout << "Program selesai\n";
}