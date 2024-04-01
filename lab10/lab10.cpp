#include <iostream>
#include <Windows.h>

using namespace std;

const int MAX_TRANSISTORS = 4; 

struct Transistor {
    string name;
    string type; 
    float power;
    float maxCurrent;
    int count;
};

void printTransistorInfo(Transistor t) {
    setlocale(LC_ALL, "Ukrainian");
    cout << "  Name: " << t.name << endl;
    cout << "  Type: " << t.type << endl;
    cout << "  Power: " << t.power << " Вт" << endl;
    cout << "  Maximum operating current: " << t.maxCurrent << " А" << endl;
    cout << "  Quantity: " << t.count << endl << endl;
}

Transistor findMaxPowerTransistor(Transistor transistors[]) {
    Transistor maxPowerTransistor = transistors[0];
    for (int i = 1; i < MAX_TRANSISTORS; i++) {
        if (transistors[i].power > maxPowerTransistor.power) {
            maxPowerTransistor = transistors[i];
        }
    }
    return maxPowerTransistor;
}

int main() {
    setlocale(LC_ALL, "Ukrainian");

    Transistor transistors[MAX_TRANSISTORS];

    
    for (int i = 0; i < MAX_TRANSISTORS; i++) {
        cout << "Enter information about the transistor " << i + 1 << ":" << endl;
        cout << "  : ";
        cin >> transistors[i].name;
        cout << "  Type (npn/pnp): ";
        cin >> transistors[i].type;
        cout << "  Power (Вт): ";
        cin >> transistors[i].power;
        cout << "  Maximum operating current (А): ";
        cin >> transistors[i].maxCurrent;
        cout << "  Quantity: ";
        cin >> transistors[i].count;
    }

    
    cout << endl << "List of transistors:" << endl;
    for (int i = 0; i < MAX_TRANSISTORS; i++) {
        printTransistorInfo(transistors[i]);
    }

    
    Transistor maxPowerTransistor = findMaxPowerTransistor(transistors);

   
    cout << "Transistor with maximum power:" << endl;
    printTransistorInfo(maxPowerTransistor);

    return 0;
}