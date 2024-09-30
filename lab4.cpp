#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

// Структура Aeroflot, що представляє рейс
struct Aeroflot {
    string punkt;
    int number;
    string litak;
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    const int numAir = 5;  
    Aeroflot* flights = new Aeroflot[numAir];

    // Введення даних про рейси
    for (int i = 0; i < numAir; i++) {
        cout << "Введіть дані для рейсу " << i + 1 << ":" << endl;
        cout << "Назва пункту призначення: ";
        cin.ignore(); 
        getline(cin, flights[i].punkt);
        cout << "Номер рейсу: ";
        cin >> flights[i].number;
        cout << "Тип літака: ";
        cin.ignore(); 

        getline(cin, flights[i].litak);
    }

    // Впорядкування записів у масиві за зростанням номера рейсу
    for (int i = 0; i < numAir - 1; i++) {
        for (int j = i + 1; j < numAir; j++) {
            if (flights[i].number > flights[j].number) {
                // Обмін елементів місцями
                Aeroflot temp = flights[i];
                flights[i] = flights[j];
                flights[j] = temp;
            }
        }
    }

    // Введення назви пункту призначення для пошуку
    string Destination;
    cout << "\n";
    cout << "Введіть пункт призначення для пошуку рейсів: ";
    cin.ignore();  // Очищення буферу
    getline(cin, Destination);

    // Виведення номерів рейсів і типів літаків для заданого пункту призначення
    cout << "\n";
    cout << "Рейси, що вилітають до " << Destination << ":" << endl;
    bool found = false;
    for (int i = 0; i < numAir; i++) {
        if (flights[i].punkt == Destination) {
            cout << "\n";
            cout << "Номер рейсу: " << flights[i].number << ", Тип літака: " << flights[i].litak << endl;
            found = true;
        }
    }

    // Якщо не знайдено рейсів до зазначеного пункту призначення
    if (!found) {
        cout << "Немає рейсів до " << Destination << "." << endl;
    }

    return 0;
}