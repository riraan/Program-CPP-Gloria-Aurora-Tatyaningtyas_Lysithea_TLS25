#include <iostream>
#include <string>
using namespace std;
int main () {
	int t;
	cout << "Masukkan detik: ";
	cin >> t;
	cout << "Warna APIL adalah: ";
	if (0 < t && t < 45) {
		if (t < 21) {
			cout << "Merah";
		} else {
			cout << "Hijau";
		}
	} else if (t >= 45) {
		int x = (t-45)%103;
		if ((x == 0) || (23 <= x && x < 103)) {
			cout << "Merah";
		} else if (20 <= x && x < 23) {
			cout << "Kuning";
		} else if (0 <= x && x < 20) {
			cout << "Hijau";
		} else {
			cout<< "Error";
		}
	} else {
		cout << "Error, masukkan detik lebih dari 0.";
	}
	return 0;
}
