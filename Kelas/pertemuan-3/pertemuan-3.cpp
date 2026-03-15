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
    SistemKontak kontak;
};

User user = {"meilonie","128"};

void header(string teks){
    cout << "\n==== " << teks << " ====\n";
}

bool login(string nama, string nim){
    if(nama == user.username && nim == user.nim){
        return true;
    }
    return false;
}

int cariKontak(string nama){
    for(int i=0;i<user.kontak.jumlah;i++){
        if(user.kontak.daftar[i].nama == nama){
            return i;
        }
    }
    return -1;
}

int cariKontak(int index){
    if(index < user.kontak.jumlah){
        return index;
    }
    return -1;
}

void tampilRekursif(int i){

    if(i == user.kontak.jumlah)
        return;

    cout << left
    << setw(5) << i+1
    << setw(15) << user.kontak.daftar[i].nama
    << setw(15) << user.kontak.daftar[i].telepon
    << setw(20) << user.kontak.daftar[i].alamat
    << setw(25) << user.kontak.daftar[i].email
    << setw(20) << user.kontak.daftar[i].kategori
    << endl;

    tampilRekursif(i+1);
}

void create_kontak(SistemKontak &kontak){

    cin.ignore();

    header("Tambah Kontak");

    cout << "Nama : ";
    getline(cin,kontak.daftar[kontak.jumlah].nama);

    cout << "Nomor : ";
    getline(cin,kontak.daftar[kontak.jumlah].telepon);

    cout << "Alamat : ";
    getline(cin,kontak.daftar[kontak.jumlah].alamat);

    cout << "Email : ";
    getline(cin,kontak.daftar[kontak.jumlah].email);

    cout << "Kategori : ";
    getline(cin,kontak.daftar[kontak.jumlah].kategori);

    kontak.jumlah++;

    cout << "Kontak berhasil disimpan\n";
}

void read_kontak(SistemKontak kontak){

    header("DAFTAR KONTAK");

    if(kontak.jumlah == 0){
        cout << "Belum ada kontak\n";
        return;
    }

    cout << left
    << setw(5) << "No"
    << setw(15) << "Nama"
    << setw(15) << "Telepon"
    << setw(20) << "Alamat"
    << setw(25) << "Email"
    << setw(20) << "Kategori"
    << endl;

    cout << "----------------------------------------------------------------------------------------------------------\n";

    tampilRekursif(0);
}

void update_kontak(SistemKontak &kontak){

    cin.ignore();
    string cari;

    cout << "Input nama kontak : ";
    getline(cin,cari);

    int index = cariKontak(cari);

    if(index == -1){
        cout << "Kontak tidak ditemukan\n";
        return;
    }

    cout << "Nama baru : ";
    getline(cin,kontak.daftar[index].nama);

    cout << "Nomor baru : ";
    getline(cin,kontak.daftar[index].telepon);

    cout << "Alamat baru : ";
    getline(cin,kontak.daftar[index].alamat);

    cout << "Email baru : ";
    getline(cin,kontak.daftar[index].email);

    cout << "Kategori baru : ";
    getline(cin,kontak.daftar[index].kategori);

    cout << "Data berhasil diupdate\n";
}

void delete_kontak(SistemKontak &kontak){

    cin.ignore();
    string cari;

    cout << "Input nama kontak : ";
    getline(cin,cari);

    int index = cariKontak(cari);

    if(index == -1){
        cout << "Kontak tidak ditemukan\n";
        return;
    }

    for(int i=index;i<kontak.jumlah;i++){
        kontak.daftar[i] = kontak.daftar[i+1];
    }

    kontak.jumlah--;

    cout << "Kontak berhasil dihapus\n";
}

void menu(){

    int pilihan;

    do{

        header("MENU KONTAK");

        cout << "1. Tambah Kontak\n";
        cout << "2. Lihat Kontak\n";
        cout << "3. Ubah Kontak\n";
        cout << "4. Hapus Kontak\n";
        cout << "5. Keluar\n";

        cout << "Input pilihan : ";
        cin >> pilihan;

        if(pilihan == 1)
            create_kontak(user.kontak);

        else if(pilihan == 2)
            read_kontak(user.kontak);

        else if(pilihan == 3)
            update_kontak(user.kontak);

        else if(pilihan == 4)
            delete_kontak(user.kontak);

    }while(pilihan != 5);

}

int main(){

    string nama,nim;
    int percobaan = 0;
    bool berhasil = false;

    while(percobaan < 3){

        header("LOGIN");

        cout << "Nama : ";
        cin >> nama;

        cout << "NIM : ";
        cin >> nim;

        if(login(nama,nim)){
            berhasil = true;
            break;
        }

        cout << "Login gagal\n";
        percobaan++;
    }

    if(!berhasil){
        cout << "Anda gagal login 3 kali\n";
        return 0;
    }

    menu();

    cout << "Program selesai\n";
}