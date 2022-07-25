#include <iostream>

using namespace std;

int menu_input;
char ya_tidak;
bool keluar = false;
string isi_data;
int posisi;

void menu_keluar ();
void menu_lanjut ();
void menu ();
int main ();

struct fauipang
{
	fauipang * prev;
	string data;
	fauipang * next;
};

fauipang * head;
fauipang * tail;
fauipang * simpul;

void inisialisasi()
{
	head = NULL;
	tail = NULL;
}

bool dLinkKosong()
{
	if (head == NULL && tail == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*          DOUBLE LINKED LIST NON CIRCULAR         */

void tambahDepan(string dataUser)
{
	if (dLinkKosong() == true)
	{
		simpul = new fauipang;
		simpul->data = dataUser;
		simpul->prev = NULL;
		simpul->next = NULL;
		head = simpul;
		tail = simpul;
	}
	else
	{
		simpul = new fauipang;
		simpul->data = dataUser;
		simpul->prev = NULL;
		simpul->next = NULL;
		simpul->next = head;
		head->prev = simpul;
		head = simpul;
	}
}

void tambahBelakang(string dataUser)
{
	if (dLinkKosong() == true)
	{
		simpul = new fauipang;
		simpul->data = dataUser;
		simpul->prev = NULL;
		simpul->next = NULL;
		head = simpul;
		tail = simpul;
	}
	else
	{
		simpul = new fauipang;
		simpul->data = dataUser;
		simpul->prev = NULL;
		simpul->next = NULL; 
		tail->next = simpul;
		simpul->prev = tail;
		tail = simpul;
	}
}

void hapusDepan()
{
	if (dLinkKosong() == true)
	{
		cout << "Kosong...!!!" << endl;
	}
	else
	{
		fauipang * helper;
		helper = head;
		if (head == tail)
		{
			head = NULL;
			tail = NULL;
			delete helper;
		}
		else
		{
			head = head->next;
			head->prev = NULL;
			helper->next = NULL;
			delete helper;
		}
	}
}

void hapusBelakang()
{
	if (dLinkKosong() == true)
	{
		cout << "Data masih kosong" << endl;
	}
	else
	{
		if (head == tail)
		{
			fauipang * helper;
			helper = head;
			head = NULL;
			tail = NULL;
			delete helper;
		}
		else
		{
			fauipang * helper;
			helper = tail;
			tail = tail->prev;
			tail->next = NULL;
			helper->prev = NULL;
			delete helper;
		}
	}
}

void tampilData()
{
	if (dLinkKosong() == true)
	{
		cout << "Data masih kosong" << endl;
	}
	else
	{
		fauipang * helper;
		helper = head;
		while (helper != NULL)
		{
			cout << helper->data << " ";
			helper = helper->next;
		}
	}
}

void tampilData_belakang ()
{
    if (dLinkKosong() == true)
	{
		cout << "Data masih kosong" << endl;
	}
	else
	{
		fauipang * helper;
		helper = tail;
		while (helper != NULL)
		{
			cout << helper->data << " ";
			helper = helper->prev;
		}
	}
}


int hitungList()
{
	fauipang * hitung;
	hitung = head;
	int jumlah = 0;
	while (hitung != NULL)
	{
		jumlah++;
		hitung = hitung->next;
	}
	return jumlah;
}

void tambahTengah(string data, int posisi)
{
	if (posisi < 1 || posisi > hitungList())
	{
		cout << "Posisi tidak tersedia" << endl;
	}
	else if (posisi == 1)
	{
		cout << "Posisi salah, bukan di tengah" << endl;
	}
	else
	{
		fauipang *baru, *bantu;
		baru = new fauipang();
		baru->data = data;
		baru->next = NULL;
		baru->prev = NULL;

		// tranversing
		bantu = head;
		int nomor = 1;
		while (nomor < posisi - 1)
		{
			bantu = bantu->next;
			nomor++;
		}
		baru->next = bantu->next;
		bantu->next = baru;
		baru->prev = bantu;

		cout << "Data berhasil ditambahkan" << endl;
	}
}

void hapusTengah(int posisi)
{
	fauipang *hapus, *bantu, *bantu2;
	if (dLinkKosong() == false)
	{
		if (posisi < 1 || posisi > hitungList())
		{
			cout << "Posisi tidak tersedia" << endl;
		}
		else if (posisi == 1)
		{
			cout << "Posisi salah, bukan di tengah" << endl;
		}
		else
		{
			bantu = head;
			int nomor = 1;
			while (nomor <= posisi)
			{
				if (nomor == posisi - 1)
				{
					bantu2 = bantu;
				}
				if (nomor == posisi)
				{
					hapus = bantu;
				}
				bantu = bantu->next;
				nomor++;
			}
			bantu2->next = bantu;
			bantu->prev = bantu2;
			cout << "Data terhapus" << endl;
			delete hapus;
		}
	}
}

/*          MAIN PROGRAM NON CIRCULAR       */

void menu () {
    cout << "Linked List Non Circular" << endl;
    cout << "1. Tambah Depan" << endl;
    cout << "2. Tambah Belakang" << endl;
    cout << "3. Tambah Tengah" << endl;
    cout << "4. Hapus Depan" << endl;
    cout << "5. Hapus Belakang" << endl;
    cout << "6. Hapus Tengah" << endl;
    cout << "7. Tampil Data Ascending" << endl;
    cout << "8. Tampil Data Descending" << endl;
    cout << "9. Keluar" << endl;
    cout << "Silahkan inputkan : ";
    cin >> menu_input;

    if (menu_input == 1)
    {
        cout << "Tambah Depan" << endl;
        cout << "Silahkan masukkan data : ";
        cin >> isi_data;
        tambahDepan(isi_data);
        menu_lanjut ();
    }
    else if (menu_input == 2)
    {
        cout << "Tambah Belakang" << endl;
        cout << "Silahkan masukkan data : ";
        cin >> isi_data;
        tambahBelakang(isi_data);
        menu_lanjut ();
    }
    else if (menu_input == 3)
    { 
        cout << "Tambah Tengah" << endl;
        cout << "Silahkan masukkan posisi data : ";
        cin >> posisi;
        cout << "Silahkan masukkan data : ";
        cin >> isi_data;
        tambahTengah (isi_data, posisi);
        menu_lanjut ();
    }
    else if (menu_input == 4)
    {
        cout << "Hapus Depan" << endl;
        hapusDepan();
        cout << "Data terhapus" << endl;
        menu_lanjut ();
    }
    else if (menu_input == 5)
    {
        cout << "Hapus Belakang" << endl;
        hapusBelakang();
        cout << "Data terhapus" << endl;
        menu_lanjut ();
    }
    else if (menu_input == 6)
    {
        cout << "Hapus Tengah" << endl;
        cout << "Silahkan masukkan posisi yang akan dihapus : ";
        cin >> posisi;
        hapusTengah (posisi);
        cout << "Data terhapus" << endl;
        menu_lanjut ();
    }
    else if (menu_input == 7)
    {
        cout << "Tampil Data Ascending" << endl;
        tampilData();
        cout << endl;
        menu_lanjut ();
    }
    else if (menu_input == 8)
    {
        cout << "Tampil Data Descending" << endl;
        tampilData_belakang ();
        cout << endl;
        menu_lanjut ();
    }
    else if (menu_input == 9)
    {
        system("clear");
        main();
    }
    else
    {
        cout << "Pilihan tidak ada" << endl;
    }
}


/*          MAIN OTHER          */

void menu_keluar () {
    cout << "Keluar (y/t) ?";
    cin >> ya_tidak;
    if (ya_tidak == 'y' || ya_tidak == 'Y') {
        cout << "Sampai Jumpa Kembali" << endl;
        keluar = true;
    } else {
        system ("clear");
    }
}

void menu_lanjut () {
    cout << "Lanjut (y/t) ? : ";
    cin >> ya_tidak;
    if (ya_tidak == 'y' || 'Y') {
        keluar = true;
        if (keluar == true) {
            system("clear");
            menu ();
        }
    }
}

/*          MAIN PROGRAM        */

int main () {
	cout << endl;
    inisialisasi ();

    cout << "Linked List" << endl;
    cout << "1. Linked List" << endl;
    cout << "0. Keluar" << endl;
    cout << "Masukkan inputan : ";
    cin >> menu_input;

    system ("clear");
    switch (menu_input)
    {
    case 1:
        menu ();
        break;
    case 0:
        menu_keluar ();
        system ("clear");
        break;
    
    default:
        break;
    }

    return 0;
}