#include <iostream>
#include<conio.h>
using namespace std;

struct biodata_mahasiswa{
	int nomor;
	string nama, nim, prodi, fakultas, alamat;
	float ipk;
	char gender;
	
	biodata_mahasiswa *next;
};

biodata_mahasiswa *newData, *head=NULL, *tail=NULL, *tampil, *temp;


void input_data(){
	int nomor_nilai;
	float ipk_nilai;
	char gender_nilai;
	string nama_nilai, nim_nilai, prodi_nilai, fakultas_nilai, alamat_nilai;
	biodata_mahasiswa bio_mhs;
	
	cout << "\nMasukkan nomor mahasiswa: ";
	(cin >> nomor_nilai).get();
	
	cout << "Masukkan nama mahasiswa: ";
	getline(cin, nama_nilai);
	
	cout << "Masukkan NIM mahasiswa: ";
	getline(cin, nim_nilai);

	cout << "Masukkan gender mahasiswa [P/L] : ";
	(cin >> gender_nilai).get();
	
	cout << "Masukkan program studi mahasiswa: ";
	getline(cin, prodi_nilai);
	
	cout << "Masukkan fakultas mahasiswa: ";
	getline(cin, fakultas_nilai);
	
	cout << "Masukkan alamat mahasiswa: ";
	getline(cin, alamat_nilai);
	cout << endl;
	
	newData = new biodata_mahasiswa;
	newData->nomor = nomor_nilai;
	newData->nama = nama_nilai;
	newData->nim = nim_nilai;
	newData->gender = gender_nilai;
	newData->prodi = prodi_nilai;
	newData->fakultas = fakultas_nilai;
	newData->alamat = alamat_nilai;
	
	cout << "Terima kasih telah menambahkan data!";
	
}

// fungsi tambah data (dari belakang)
void tambahdata(){
	input_data();
	if(head == NULL){
		head = newData;
		tail = newData;
		newData->next = head;
	}
	else{
		tail->next = newData;
		tail = newData;
		tail->next = head;
	}
}

// fungsi tampil data
void cetak_data(){
	tampil = head;
	if(head==NULL){
		cout<<"Data biodata mahasiswa kosong!";
	}
	else{
		cout << "\n-----------List Biodata Mahasiswa -----------\n";
		do{
			cout << "Nomor           :" << tampil->nomor << endl;
			cout << "Nama Mahasiswa  : " << tampil->nama << endl;
			cout << "NIM             : " << tampil->nim << endl;
			cout << "Jenis Kelamin   : " << tampil->gender << endl;
			cout << "Program Studi   : " << tampil->prodi << endl;
			cout << "Fakultas        : " << tampil->fakultas << endl;
			cout << "Alamat          : " << tampil->alamat << endl;
			cout << endl;
			tampil = tampil->next;
		}
		while(tampil != head);
	}
}

int main(){
	cout << "Program Biodata Mahasiswa - Noviyana\n";
	cout << "------------------------------------ \n\n";
	
	int pilih;
	char jawab;
	
	do{
		cout << "Pilih menu yang ada: \n";
		cout << "1. Tambah Data\n";
		cout << "2. Cetak Data\n";
		cout << "3. Exit\n";
	
		cout << "Kamu memilih nomor [1-4]: ";
		cin >> pilih;
		
		if (pilih==1){
			tambahdata();
			getch();
		}
		else if (pilih==2){
			cetak_data();
			getch();
		}
		else{
			exit(1);
		}
		system("cls");
    } 
	while(1);
}
