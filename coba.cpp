#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

int main() {
    int x;
    while (true) {
        cout << "THE PASSWORD PROGRAM\n";
        cout << "(0) Exit program\n";
        cout << "(1) Konversi kata => password\n";
        cout << "(2) Konversi password => kemungkinan kata asli\n";
        cout << "Pilih program: ";
        cin >> x;

        if (x == 0) {
            cout << "Program selesai dijalankan.";
            break;
        } 
        else if (x == 1) {
            string kata;
            cout << "Masukkan kata: ";
            cin >> kata;

            char huruf = kata[0];
            int ascii = huruf;

            string sisa = "";
            for (int i = 0; i < kata.length(); i++) {
                char c = kata[i];
                char cl = tolower(c);
                if (cl!='a' && cl!='i' && cl!='u' && cl!='e' && cl!='o') {
                    sisa += c;
                }
            }

            string reverse = "";
            for (int i = sisa.length()-1; i >= 0; i--) {
                reverse += sisa[i];
            }

            stringstream ss;
            ss << ascii;
            string kode = ss.str();
            int tengah = (reverse.length()+1)/2;
            string pass = reverse.substr(0, tengah) + kode + reverse.substr(tengah);

            cout << "Password: " << pass << endl;
        } 
        else if (x == 2) {
            string pass;
            cout << "Masukkan password: ";
            cin >> pass;

            string kiri="", kanan="", angka="";
            bool chr_ascii=false;

            for (int i = 0; i < pass.length(); i++) {
                if (isdigit(pass[i])) {
                    chr_ascii=true;
                    angka+=pass[i];
                } else {
                    if (!chr_ascii) {
                    	kiri+=pass[i];
					} else {
						kanan+=pass[i];
					}
                }
            }
			int kode;
            stringstream conv(angka);
            conv >> kode;
            char huruf = (char)kode;
            
            string gabung = kiri+kanan;
            string gabung_lagi = "";
            for (int i = gabung.length()-1; i >= 0; i--) {
                gabung_lagi += gabung[i];
            }
			if (gabung_lagi.length() > 0) {
			    if (gabung_lagi[0] != huruf) {
    			    gabung_lagi = huruf + gabung_lagi;  
  				}
			} else {
 			   gabung_lagi = huruf + gabung_lagi;
			}
			cout << "Kemungkinan kata: " << gabung_lagi << endl;
        } 
        else {
            cout << "Pilihan tidak ada, coba lagi.\n";
        }
    }
    return 0;
}
