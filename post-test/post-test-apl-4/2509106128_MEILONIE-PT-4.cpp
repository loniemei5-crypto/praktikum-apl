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
    SistemKontak *kontak;
};

SistemKontak dataKontak;
User user = {"meilonie","128",&dataKontak};

void header(string teks){
    cout << "\n==== " << teks << " ====\n";
}

bool login(string nama,string nim){
    return (nama==user.username && nim==user.nim);
}

int cariKontak(string nama,SistemKontak *kontak){
    for(int i=0;i<kontak->jumlah;i++){
        if(kontak->daftar[i].nama==nama)
            return i;
    }
    return -1;
}

void tampilRekursif(int i,SistemKontak *kontak){
    if(i==kontak->jumlah) return;

    cout<<left<<setw(5)<<i+1
        <<setw(15)<<kontak->daftar[i].nama
        <<setw(15)<<kontak->daftar[i].telepon
        <<setw(20)<<kontak->daftar[i].alamat
        <<setw(25)<<kontak->daftar[i].email
        <<setw(20)<<kontak->daftar[i].kategori<<endl;

    tampilRekursif(i+1,kontak);
}

void create_kontak(SistemKontak *kontak){
    cin.ignore();
    header("Tambah Kontak");

    cout<<"Nama : ";
    getline(cin,(*kontak).daftar[(*kontak).jumlah].nama);

    cout<<"Nomor : ";
    getline(cin,kontak->daftar[kontak->jumlah].telepon);

    cout<<"Alamat : ";
    getline(cin,kontak->daftar[kontak->jumlah].alamat);

    cout<<"Email : ";
    getline(cin,kontak->daftar[kontak->jumlah].email);

    cout<<"Kategori : ";
    getline(cin,kontak->daftar[kontak->jumlah].kategori);

    (*kontak).jumlah++;
    cout<<"Kontak berhasil disimpan\n";
}

void read_kontak(SistemKontak *kontak){
    header("DAFTAR KONTAK");
    if(kontak->jumlah==0){
        cout<<"Belum ada kontak\n";
        return;
    }

    cout<<left<<setw(5)<<"No"<<setw(15)<<"Nama"
        <<setw(15)<<"Telepon"<<setw(20)<<"Alamat"
        <<setw(25)<<"Email"<<setw(20)<<"Kategori"<<endl;

    cout<<"--------------------------------------------------------------------------\n";
    tampilRekursif(0,kontak);
}

void update_kontak(SistemKontak *kontak){
    cin.ignore();
    string cari;
    cout<<"Masukkan nama kontak : ";
    getline(cin,cari);

    int index=cariKontak(cari,kontak);
    if(index==-1){
        cout<<"Kontak tidak ditemukan\n";
        return;
    }

    cout<<"Nama baru : ";
    getline(cin,kontak->daftar[index].nama);

    cout<<"Nomor baru : ";
    getline(cin,kontak->daftar[index].telepon);

    cout<<"Alamat baru : ";
    getline(cin,kontak->daftar[index].alamat);

    cout<<"Email baru : ";
    getline(cin,kontak->daftar[index].email);

    cout<<"Kategori baru : ";
    getline(cin,kontak->daftar[index].kategori);

    cout<<"Kontak berhasil diupdate\n";
}

void delete_kontak(SistemKontak *kontak){
    cin.ignore();
    string cari;
    cout<<"Masukkan nama kontak : ";
    getline(cin,cari);

    int index=cariKontak(cari,kontak);
    if(index==-1){
        cout<<"Kontak tidak ditemukan\n";
        return;
    }

    for(int i=index;i<kontak->jumlah;i++)
        kontak->daftar[i]=kontak->daftar[i+1];

    kontak->jumlah--;
    cout<<"Kontak berhasil dihapus\n";
}

void menu(SistemKontak *kontak){
    int pilihan;
    do{
        header("MENU KONTAK");
        cout<<"1. Tambah Kontak\n";
        cout<<"2. Lihat Kontak\n";
        cout<<"3. Update Kontak\n";
        cout<<"4. Hapus Kontak\n";
        cout<<"5. Keluar\n";
        cout<<"Pilihan : ";
        cin>>pilihan;

        if(pilihan==1) create_kontak(kontak);
        else if(pilihan==2) read_kontak(kontak);
        else if(pilihan==3) update_kontak(kontak);
        else if(pilihan==4) delete_kontak(kontak);

    }while(pilihan!=5);
}

int main(){
    string nama,nim;
    int percobaan=0;
    bool berhasil=false;

    while(percobaan<3){
        header("LOGIN");
        cout<<"Username : "; cin>>nama;
        cout<<"NIM : "; cin>>nim;

        if(login(nama,nim)){
            berhasil=true;
            break;
        }
        cout<<"Login gagal\n";
        percobaan++;
    }

    if(!berhasil){
        cout<<"Gagal login 3x\n";
        return 0;
    }

    menu(user.kontak);
    cout<<"Program selesai\n";
}