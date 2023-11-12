#include <iostream>
//#include <wchar.h>
//#include <stdlib.h>
#include <windows.h>

#include <thread>
#include <chrono> // necesario para std::chrono::milliseconds

using namespace std;
using std::cout;
using std::endl;

void miFuncion(int id) {
    for (int i = 0; i < 5; ++i) {
        cout << "Hilo " << id << " ejecutando... Iteración " << i << endl;

        // pausar la ejecución durante 500 milisegundos (0.5 segundos)
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

int main() {

    // código de consola para acentos
    SetConsoleOutputCP(CP_UTF8);

    // crear dos hilos y ejecutar la función miFuncion en cada uno de ellos
    std::thread hilo1(miFuncion, 1);
    std::thread hilo2(miFuncion, 2);

    // esperar a que ambos hilos terminen
    hilo1.join();
    hilo2.join();

    cout << "Ambos hilos han terminado." << endl;

    return 0;
}
