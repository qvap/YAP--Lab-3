#include <iostream>
#include <locale>
#include <windows.h>
#include <algorithm>
#include <random>

using namespace std;


class CSearch {
public:
    static int* linear_search (int* begin, int* end, const int value) {
        while (begin != end) {
            if (*begin == value) {
                return begin;
            }
            ++begin;
        }
        return end;
    }

    static int* binary_search (int* begin, int* end, const int value) {
        while (begin != end) {
            if (*begin >= value) {
                return begin;
            }
            ++begin;
        }
        return end;
    }
};

class Interface {
private:
    int N;
    int* arr;
public:
    Interface() {
        N = 0;
        arr = nullptr;
    }
    ~Interface() {
        delete[] arr;
    }
    void display_list() {
        if (this->arr == nullptr) {
            cout << "Массив пуст." << endl;
            return;
        }
        cout << "Массив: [ ";
        for (int i = 0; i < N; ++i) {
            cout << *(arr + i) << "; ";
        }
        cout << "]" << endl;
    }

    void create_list() {
        delete[] arr;

        cout << "Введите количество элементов N: ";
        cin >> this->N;

        this->arr = new int[N];

        // Заполнение случайными числами
        for (int i = 0; i < N; ++i) {
            *(arr + i) = rand() % 200 - 100;
        }

        menu();
    }

    void sort_list() {
        sort(arr, arr + N);
        menu();
    }

    void shuffle_list() {
        shuffle(arr, arr + N, mt19937(random_device()()));
        menu();
    }

    void linear_search() {
        int value = 0;
        cout << "Введите искомое число: ";
        cin >> value;
        int* found = CSearch::linear_search(arr, arr + N, value);
        cout << "Результат линейного поиска (индекс): " << (found - arr) << " по адресу: " << found << endl;
        menu();
    }

    void binary_search() {
        int value = 0;
        cout << "Введите искомое число: ";
        cin >> value;
        const int* found = CSearch::binary_search(arr, arr + N, value);
        cout << "Результат двоичного поиска (индекс): " << (found - arr) << " по адресу: " << found << endl;
        menu();
    }

    void menu() {
        display_list();
        int choice = 0;
        cout << "Выберите действие: " << endl;
        cout << "1. Создать новый массив" << endl;
        cout << "2. Линейный поиск по массиву" << endl;
        cout << "3. Отсортировать массив" << endl;
        cout << "4. Перемешать массив" << endl;
        cout << "5. Двоичный поиск по массиву" << endl;
        cout << "6. Выход (по умолчанию)" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                this->create_list();
                break;
            case 2:
                this->linear_search();
                break;
            case 3:
                this->sort_list();
                break;
            case 4:
                this->shuffle_list();
                break;
            case 5:
                this->binary_search();
                break;
            default:
                cout << "Выход из программы..." << endl;
                break;
        }
    }
};

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF8");

    auto* ui = new Interface();
    ui->create_list();

    delete ui; // Вызовется, когда ui выйдет из цикла

    return 0;
}