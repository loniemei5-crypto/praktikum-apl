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

void create_kontak(){

    cin.ignore();

    cout << "\n=== Tambah Kontak ===\n";

    cout << "Nama : ";
    getline(cin,user.kontak.daftar[user.kontak.jumlah].nama);

    cout << "Nomor : ";
    getline(cin,user.kontak.daftar[user.kontak.jumlah].telepon);

    cout << "Alamat : ";
    getline(cin,user.kontak.daftar[user.kontak.jumlah].alamat);

    cout << "Email : ";
    getline(cin,user.kontak.daftar[user.kontak.jumlah].email);

    cout << "Kategori : ";
    getline(cin,user.kontak.daftar[user.kontak.jumlah].kategori);

    user.kontak.jumlah++;

    cout << "Kontak berhasil disimpan\n";
}

void read_kontak(){

    cout << "\n========== DAFTAR KONTAK ==========\n";

    if(user.kontak.jumlah == 0){
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

    cout << "--------------------------------------------------------------------\n";

    for(int i=0;i<user.kontak.jumlah;i++){

        cout << left
        << setw(5) << i+1
        << setw(15) << user.kontak.daftar[i].nama
        << setw(15) << user.kontak.daftar[i].telepon
        << setw(20) << user.kontak.daftar[i].alamat
        << setw(25) << user.kontak.daftar[i].email
        << setw(20) << user.kontak.daftar[i].kategori
        << endl;
    }
}

void update_kontak(){

    string cari;
    bool ditemukan = false;

    cin.ignore();

    cout << "Input nama kontak yang dicari : ";
    getline(cin,cari);

    for(int i=0;i<user.kontak.jumlah;i++){

        if(user.kontak.daftar[i].nama == cari){

            cout << "Kontak ditemukan\n";

            cout << "Nama baru : ";
            getline(cin,user.kontak.daftar[i].nama);

            cout << "Nomor baru : ";
            getline(cin,user.kontak.daftar[i].telepon);

            cout << "Alamat baru : ";
            getline(cin,user.kontak.daftar[i].alamat);

            cout << "Email baru : ";
            getline(cin,user.kontak.daftar[i].email);

            cout << "Kategori baru : ";
            getline(cin,user.kontak.daftar[i].kategori);

            cout << "Data berhasil diupdate\n";

            ditemukan = true;
            break;
        }
    }

    if(!ditemukan){
        cout << "Kontak tidak ada\n";
    }
}

void delete_kontak(){

    string cari;
    bool ditemukan = false;

    cin.ignore();

    cout << "Input nama kontak yang dicari : ";
    getline(cin,cari);

    for(int i=0;i<user.kontak.jumlah;i++){

        if(user.kontak.daftar[i].nama == cari){

            for(int j=i;j<user.kontak.jumlah;j++){
                user.kontak.daftar[j] = user.kontak.daftar[j+1];
            }

            user.kontak.jumlah--;

            cout << "Kontak berhasil dihapus\n";

            ditemukan = true;
            break;
        }
    }

    if(!ditemukan){
        cout << "Kontak tidak ada\n";
    }
}

int main(){

    string nama,nim;
    int percobaan = 0;
    bool login = false;

    while(percobaan < 3){

        cout << "===== LOGIN =====\n";

        cout << "Nama : ";
        cin >> nama;

        cout << "NIM : ";
        cin >> nim;

        if(nama == user.username && nim == user.nim){

            login = true;
            break;
        }

        else{
            cout << "Login gagal\n";
            percobaan++;
        }
    }

    if(!login){

        cout << "Anda gagal login 3 kali\n";
        return 0;
    }

    int pilihan;

    do{

        cout << "\n===== MENU KONTAK TEMAN =====\n";
        cout << "1. Tambah Kontak\n";
        cout << "2. Lihat Kontak\n";
        cout << "3. Ubah Kontak\n";
        cout << "4. Hapus Kontak\n";
        cout << "5. Keluar\n";

        cout << "Input pilihan menu : ";
        cin >> pilihan;

        if(pilihan == 1){
            create_kontak();
        }

        else if(pilihan == 2){
            read_kontak();
        }

        else if(pilihan == 3){
            update_kontak();
        }

        else if(pilihan == 4){
            delete_kontak();
        }

    }while(pilihan != 5);

    cout << "Program selesai\n";

}
