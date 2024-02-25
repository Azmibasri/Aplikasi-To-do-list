#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Tugas {
public:
    string nama, deskripsi, prioritas, deadline, status;
    vector<vector<string>> simpan;
    int input;
    
    void TambahTugas();
    void LihatTugas();
    void UbahTugas();
    void HapusTugas();
};

void Tugas::TambahTugas() {
    cout << "Buat tugas baru" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Masukan nama tugas: ";
    cin.ignore();
    getline(cin, nama);
    cout << "Masukan deskripsi tugas: ";
    cin.ignore();
    getline(cin, deskripsi);
    cout << "Masukan prioritas tugas (rendah, sedang, tinggi): ";
    cin >> prioritas;
    cout << "Masukan deadline tugas (format: dd/mm/yyyy): ";
    cin >> deadline;
    status = "Belum Selesai";
    simpan.push_back({nama, deskripsi, prioritas, deadline, status});
    cout << "Tugas berhasil ditambahkan" << endl;
}

void Tugas::LihatTugas() {
    if (simpan.size() > 0) {
        cout << "Daftar tugas" << endl;
        for (int i = 0; i < simpan.size(); i++) {
            cout << "Tugas[" << i << "]: ";
            for (int j = 0; j < simpan[i].size(); j++) {
                cout << simpan[i][j] << " || ";
            }
            cout << endl;
        }
    } else {
        cout << "Anda belum memiliki tugas" << endl;
    }
}

void Tugas::UbahTugas() {
    if (simpan.size() > 0) {
        cout << "Daftar tugas" << endl;
        for (int i = 0; i < simpan.size(); i++) {
            cout << "Tugas[" << i << "]: ";
            for (int j = 0; j < simpan[i].size(); j++) {
                cout << simpan[i][j] << " || ";
            }
            cout << endl;
        }
        int opsi, opsi2 = 0;
        cout << "Masukan index tugas yang ingin diubah: ";
        cin >> opsi;
        if (opsi >= 0 && opsi < simpan.size()) {
            cout << "Apa yang ingin anda ubah? " << endl;
            cout << "0. Nama" << endl;
            cout << "1. Deskripsi" << endl;
            cout << "2. Prioritas" << endl;
            cout << "3. Deadline" << endl;
            cout << "4. Status" << endl;
            cout << "Masukan pilihan anda: ";
            cin >> opsi2;
            if (opsi2 >= 0 && opsi2 <= 4) {
                cout << "Masukan nilai baru: ";
                cin >> simpan[opsi][opsi2];
                cout << "Tugas berhasil diubah" << endl;
            } else {
                cout << "Pilihan tidak valid" << endl;
            }
        } else {
            cout << "Indeks tugas tidak valid" << endl;
        }
    } else {
        cout << "Anda belum memiliki tugas" << endl;
    }
}

void Tugas::HapusTugas() {
    if (simpan.size() > 0) {
        LihatTugas();
        int opsi;
        cout << "Masukkan index tugas yang ingin dihapus: ";
        cin >> opsi;
        if (opsi >= 0 && opsi < simpan.size()) {
            simpan.erase(simpan.begin() + opsi);
            cout << "Tugas berhasil dihapus" << endl;
        } else {
            cout << "Indeks tugas tidak valid" << endl;
        }
    } else {
        cout << "Anda belum memiliki tugas" << endl;
    }
}

int main() {
    int ulang;
    Tugas tugas;
    do {
        cout << "--------------------------------------------------" << endl;
        cout << "Selamat datang di aplikasi ToDoList" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "Menu: " << endl;
        cout << "1. Tambah tugas" << endl;
        cout << "2. Lihat tugas" << endl;
        cout << "3. Ubah tugas" << endl;
        cout << "4. Hapus tugas" << endl;
        cout << "5. Keluar" << endl;
        cout << "Masukkan pilihan Anda: ";
        cin >> tugas.input;

        switch (tugas.input) {
            case 1:
                tugas.TambahTugas();
                ulang = 1;
                break;
            case 2:
                tugas.LihatTugas();
                ulang = 1;
                break;
            case 3:
                tugas.UbahTugas();
                ulang = 1;
                break;
            case 4:
                tugas.HapusTugas();
                ulang = 1;
                break;
            case 5:
                ulang = 0;
                break;
            default:
                ulang = 0;
                break;
        }
    } while (ulang != 0);
    return 0;
}
