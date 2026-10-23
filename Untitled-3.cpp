#include <iostream>
#include <bitset>
#include <cstdint>
#include <cstring>
#include <limits>
using namespace std;

int main() {
    // Задание 1
    cout << "=== Задание 1 ===" << endl;
    cout << "bool: " << sizeof(bool) << " логический тип (True/False)" << endl;
    cout << "char: " << sizeof(char) << " один символ " << endl;
    cout << "short int: " << sizeof(short int) << " короткое целое число" << endl;
    cout << "int: " << sizeof(int) << " обычное целое число" << endl;
    cout << "long int: " << sizeof(long int) << " длинное целое число" << endl;
    cout << "long long   - " << sizeof(long long)   << " - очень длинное целое число" << endl;
    cout << "float: " << sizeof(float) << " дробное число одинарной точности" << endl;
    cout << "double: " << sizeof(double) << " дробное число двойной точности" << endl;
    cout << "long double: " << sizeof(long double) << " дробное число расширенной точности" << endl;
    cout << endl;

    // Задание 2
    cout << "=== Задание 2 ===" << endl;
    cout << "Введите int: ";
    int a;
    cin >> a;
 int order_i = sizeof(int) * 8;
    unsigned int mask_i = 1u << (order_i - 1);

    for (int i = 0; i < order_i; i++) {
        cout << ((a & (mask_i >> i)) ? '1' : '0');

        if (i == 0) {
            cout << "  ";
        }
    }
    cout << endl;

    // Задание 3
    cout << "=== Задание 3 ===" << endl;
    cout << "Введите float: ";
    float f;
    cin >> f;
    uint32_t fb;
    memcpy(&fb, &f, sizeof(f));
    cout << "Знак | Порядок | Мантисса\n";
    for (int i = 31; i >= 0; --i) {
        cout << ((fb >> i) & 1u);
        if (i == 31 || i == 23) cout << " | ";
    }
    cout << endl;;

    // Задание 4
    cout << "=== Задание 4 ===" << endl;
    cout << "Введите double: ";
    double d;
    cin >> d;
    uint64_t db;
    memcpy(&db, &d, sizeof(d));
    cout << "Знак | Порядок | Мантисса\n";
    for (int i = 63; i >= 0; --i) {
        cout << ((db >> i) & 1ull);
        if (i == 63 || i == 52) cout << " | ";
    }
    cout << "\n\n";
    // Задание 5
    cout << "=== Задание 5 ===\n";
    cout << "Тип числа (1 - int, 2 - float, 3 - double): ";
    int type, bit, op;
    cin >> type;
    cout << "Номер бита (для int/float 0..31, для double 0..63): ";
    cin >> bit;
    cout << "Операция: 1 - сбросить, 2 - установить, 3 - инвертировать: ";
    cin >> op;
if (op < 1 || op > 3) {
        cout << "Неверный номер операции.\n";
    } else if (type == 1) {
        int x;
        cout << "Введите int: ";
        cin >> x;
        if (bit < 0 || bit > 31) {
            cout << "Неверный номер бита.\n";
        } else {
            uint32_t xb;
            memcpy(&xb, &x, sizeof(x));
            uint32_t mask = uint32_t(1) << bit;
            if (op == 1) xb &= ~mask;
                        if (op == 2) xb |= mask;
            if (op == 3) xb ^= mask;
            cout << "Результат в битах: " << bitset<32>(xb) << "\n";
        }
    } else if (type == 2) {
        float x;
        cout << "Введите float: ";
        cin >> x;
        if (bit < 0 || bit > 31) {
            cout << "Неверный номер бита.\n";
        } else {
            uint32_t xb;
            memcpy(&xb, &x, sizeof(x));
            uint32_t mask = uint32_t(1) << bit;
            if (op == 1) xb &= ~mask;
            if (op == 2) xb |= mask;
            if (op == 3) xb ^= mask;
            memcpy(&x, &xb, sizeof(x));
            cout << "Результат в битах: " << bitset<32>(xb) << "\n";
            cout << "Новое значение float: " << x << "\n";
        }
    } else if (type == 3) {
        double x;
        cout << "Введите double: ";
        cin >> x;
        if (bit < 0 || bit > 63) {
            cout << "Неверный номер бита.\n";
        } else {
            uint64_t xb;
            memcpy(&xb, &x, sizeof(x));
            uint64_t mask = uint64_t(1) << bit;
            if (op == 1) xb &= ~mask;
            if (op == 2) xb |= mask;
            if (op == 3) xb ^= mask;
            memcpy(&x, &xb, sizeof(x));
            cout << "Результат в битах: " << bitset<64>(xb) << "\n";
            cout << "Новое значение double: " << x << "\n";
        }
    } else {
        cout << "Неверный тип числа.\n";
    }

    // Задание 6
    cout << "\n=== Задание 6 ===\n";
    cout << "int 13:  " << bitset<32>(uint32_t(13)) << "\n";
    int n = -13;
    uint32_t nb;
    memcpy(&nb, &n, sizeof(n));
    cout << "int -13: " << bitset<32>(nb) << "\n";

    f = 3.14f;
    memcpy(&fb, &f, sizeof(f));
    cout << "float 3.14: ";
    for (int i = 31; i >= 0; --i) {
        cout << ((fb >> i) & 1u);
        if (i == 31 || i == 23) cout << " | ";
    }
    cout << "\n";

    f = -2.5f;
    memcpy(&fb, &f, sizeof(f));
    cout << "float -2.5: ";
    for (int i = 31; i >= 0; --i) {
        cout << ((fb >> i) & 1u);
        if (i == 31 || i == 23) cout << " | ";
    }
    cout << "\n";

    f = 1.0e-40f;
    memcpy(&fb, &f, sizeof(f));
    cout << "Малое float: " << bitset<32>(fb) << "\n";
    f = numeric_limits<float>::infinity();
    memcpy(&fb, &f, sizeof(f));
    cout << "Бесконечность: " << bitset<32>(fb) << "\n";

    // ИДЗ — умножение на 2 сдвигом влево
    cout << "\n=== ИДЗ ===\n";
    cout << "Введите целое число: ";
    int number;
    cin >> number;

    if (number >= 0 && number <= 1073741823) {
        cout << "Число в двоичном виде: "
             << bitset<32>(static_cast<uint32_t>(number)) << endl;
        cout << "После сдвига влево:   "
             << bitset<32>(static_cast<uint32_t>(number) << 1) << endl;
        cout << "Результат: " << number << " * 2 = " << (number << 1) << endl;
    } else {
        cout << "Введите число от 0 до 1073741823." << endl;
    }

    return 0;
}