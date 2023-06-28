#include <iostream>
#include <cstdio>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int tanya1()
{
    int baris;
    cout << "Di baris mana kapal tersebut? : ";
    cin >> baris;
    baris = baris - 1;
    return baris;
}

int tanya2()
{
    int kolom;
    cout << "Di kolom mana kapal tersebut? : ";
    cin >> kolom;
    kolom = kolom - 1;
    return kolom;
}

void jawaban(int lokasi[][4])
{
    for (int w = 0; w < 4; w++)
    {
        for (int v = 0; v < 4; v++)
        {
            cout << lokasi[w][v] << "\t";
        }
        cout << endl
             << endl;
    }
}

void pengarah(int hor, int ver)
{
    COORD coord;
    coord.X = hor;
    coord.Y = ver;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void waktu(void)
{
    int waktu = 1;
    while (waktu < 50000000)
    {
        waktu++;
    }
}
string opening()
{
    pengarah(5, 0);
    cout << endl
         << endl
         << "\t 000000    000300    000000    001000    00        000000          000000    00    oo    00    000000    000000      " << endl
         << "\t 00  00    00  00      00        00      00        00              00        00    00    00    00  00    00          " << endl
         << "\t 000000    000000      00        00      00        000000          000000    00000000    00    000000    000000      " << endl
         << "\t 00  00    00  00      00        00      00        00                  00    00    00    00    00            00      " << endl
         << "\t 000000    00  00      00        00      000000    000000          000000    00    00    00    00        000000      ";
    cout << endl
         << endl
         << endl
         << "\t                                           0000080000090000000000" << endl
         << "\t                                           000                000" << endl
         << "\t                                           000    00006000    000" << endl
         << "\t                                           000    00000000    000" << endl
         << "\t                                           000    00000000    000" << endl
         << "\t                                           000    00000000    000" << endl
         << "\t                                           000                000" << endl
         << "\t                                           0000000000000000000000"
         << endl
         << endl
         << endl;
    string on;
    cout << "\t\t\t\t\t\t\tmulai? (y/n) ";
    cin >> on;
    cout << endl
         << endl
         << endl;
    return on;
}

void peta()
{
    char tanda = 'X';
    int i, x;
    cout << endl
         << endl;
    for (i = 0; i <= 3; i++)
    {
        for (x = 0; x <= 3; x++)
        {
            cout << tanda << "\t";
        }
        cout << endl
             << endl;
    }
}

void rule()
{
    string lanjut;
    cout << "=================================================================================================" << endl
         << endl
         << "\tSELAMAT DATANG DI SIMPLE BATTLESHIPS"
         << endl
         << endl
         << "\tDi game ini, kamu cukup menebak di baris mana dan kolom mana kapal musuh berada.\n\tKamu akan diberikan 3 nyawa.\n\tJika kamu berhasil menebak 2 kali berturut - turut, kamu akan mendapatkan bonus 1 nyawa."
            << endl
            << endl
            << endl
            << "\tPOSISIMU SAAT INI : KAPTEN"
            << endl
            << endl
            << "@Hadid_Ganteng_dev"
            << endl;
    cout << "=================================================================================================" << endl
         << "\tKetik huruf apapun untuk melanjutkan  ";
    cin >> lanjut;
    system("cls");
}

int main()
{
    // cout << "\nWelcome to Battleships!" << endl;
    // cout << endl;
    string pilihan, pil2;
    int o = 0, bonus = 0;
    for (int q = 1; q <= 100; q++)
    {
        pengarah(5, 2);
        cout << "L  O  A  D  I  N  G    " << q << " %";
        waktu();
    }
    system("cls");

    do
    {
        system("cls");
        pilihan = opening();
        // program randomisasi kapal
        if (pilihan == "y")
        {
            system("cls");
            rule();
            int acak, acak1, acak2, batas = 0, kesempatan = 3;
            srand(time(0));
            acak = rand() % 2;
            acak1 = rand() % 2;
            acak2 = rand() % 2;
            int kapal[4][4] = {
                {0, acak1, acak, 0},
                {acak, 0, acak2, 1},
                {acak1, 0, acak, 0},
                {0, acak2, 1, acak1}};
            for (int a = 0; a < 4; a++)
            {
                for (int b = 0; b < 4; b++)
                {
                    if (kapal[a][b] == 1)
                        batas++;
                }
            }
            // sistem lain
            cout << endl
                 << endl
                 << "Sistem mendeteksi ada " << batas << " kapal musuh. Hanya ada " << kesempatan << " nyawa. Temukan dan hancurkan mereka semua, Kapten!" << endl
                 << endl;
            int kena = 0, jmlh = batas;
            peta();

            do
            {
                int horizontal = tanya1();
                int vertikal = tanya2();

                if (kapal[horizontal][vertikal] == 1)
                {
                    system("cls");
                    kapal[horizontal][vertikal] = 0;
                    cout << endl
                         << endl
                         << "Strike! tepat sasaran. Kini kapal yang tersisa yaitu " << (jmlh -= 1) << " kapal" << endl
                         << endl;

                    bonus++;
                    if (bonus == 2)
                    {
                        bonus = 0;
                        kesempatan++;
                        cout << "Combo 2x! Anda mendapat tambahan 1 nyawa" << endl
                             << endl;
                    }

                    int k, l, pen1 = horizontal, pen2 = vertikal;
                    for (k = 0; k <= 3; k++)
                    {
                        for (l = 0; l <= 3; l++)
                        {
                            if (k == pen1 && l == pen2)
                            {
                                cout << "O\t";
                            }
                            else
                            {
                                cout << "X\t";
                            }
                        }
                        cout << endl;
                        cout << endl;
                    }
                    kena++;
                    cout << endl
                         << endl
                         << "Sisa nyawa mu " << kesempatan << endl
                         << endl
                         << "Ketik huruf apapun untuk melanjutkan  ";
                    cin >> pil2;
                }
                else
                {
                    kesempatan--;
                    if (bonus == 1)
                    {
                        bonus--;
                    }
                    cout << endl
                         << "Tembakanmu meleset! Sisa nyawamu adalah " << kesempatan << endl
                         << "Coba tebak lagi. Cemungut ea!" << endl
                         << endl
                         << "Ketik huruf apapun untuk melanjutkan  ";
                    cin >> pil2;
                }
                system("cls");
                cout << "===================================== Kesempatan Berikutnya =====================================" << endl;
                peta();
            } while (kesempatan > 0 && kena < batas);

            if (kesempatan == 0 && kena < batas)
            {
                system("cls");
                cout << "=================================================================================================" 
                     << endl
                     << endl
                     << "GAME OVER!" << endl
                     << "Kapten BODOH, kamu turun pangkat jadi prajurit biasa!" << endl
                     << endl
                     << endl
                     << "PANGKAT MU SAAT INI : AWAK KAPAL" << endl
                     << endl
                     << endl
                     << "Lokasi musuh yang masih tersembunyi (tanda: angka 1)"
                     << endl
                     << endl;
                jawaban(kapal);
                cout << endl
                     << endl
                     << "=================================================================================================" << endl;
            }
            else if (kesempatan < 0 && kena == batas)
            {
                system("cls");
                cout << "================================================================================================="
                     << endl
                     << endl
                     << endl
                     << "GOOD JOB Kapten! Negara berhutang budi padamu." << endl
                     << endl
                     << endl
                     << endl
                     << "PANGKAT MU SAAT INI : AWAK KAPAL"
                     << endl
                     << endl
                     << "=================================================================================================" << endl;
            }
            cout << "Ketik y untuk kembali ke menu utama ";
            cin >> pilihan;
        }
        else
        {
            system("cls");
            cout << endl
                 << endl
                 << "\t\t\t\t\tApa kamu yakin keluar? (i/t) ";
            cin >> pilihan;
            if (pilihan == "i")
            {
                break;
            }
            else if (pilihan == "t")
            {
                o++;
            }
        }
    } while (pilihan == "y" || pilihan == "t");
}