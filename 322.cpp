#include <iostream>
using namespace std;

int main() {
    // Integer13
    int n;
    cout << "Vvedit tryznachne chyslo: ";
    cin >> n;

    int first = n / 100;
    int result = (n % 100) * 10 + first;

    cout << "Integer13 - Rezultat: " << result << endl;

    // Integer24
    int K;
    cout << "\nVvedit nomer dnia roku (1-365): ";
    cin >> K;

    int day = K % 7;

    cout << "Integer24 - Nomer dnia tyzhnia: "
         << day << endl;

    // Integer41
    int M;
    cout << "\nVvedit kilkist hryven: ";
    cin >> M;

    int coins = M / 5;
    int remainder = M % 5;

    cout << "Integer41 - Kilkist monet po 5 hrn: "
         << coins << endl;
    cout << "Integer41 - Reshta: "
         << remainder << " hrn" << endl;

    return 0;
}
