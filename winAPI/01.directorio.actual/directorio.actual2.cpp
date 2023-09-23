/*
    muestra el directorio actual
*/

#include <iostream>
#include <windows.h>

int main() {
    
    // definir un buffer
    char buffer[MAX_PATH];
    
    // obtener el directorio
    DWORD length = GetCurrentDirectory(MAX_PATH, buffer);

    // si error
    if (length == 0) {
        std::cerr << "Error. Código de error: " << GetLastError() << std::endl;
        system("pause");
        return 0;
    }

    // imprimir el directorio actual
    std::cout << "Directorio actual: " << buffer << std::endl;
    system("pause");

    return 0;
}