/*
    muestra el directorio actual

    funcion GetCurrentDirectory de la winAPI 
    https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-getcurrentdirectory
*/

#include <iostream>
#include <windows.h>

int main() {
    
    // definir variable
    // char buffer[MAX_PATH];
    wchar_t buffer[MAX_PATH];

    // resultado de funcion en variable
    //DWORD length = GetCurrentDirectory(MAX_PATH, buffer);
    DWORD length = GetCurrentDirectoryW(MAX_PATH, buffer);

    // si error
    if (length == 0) {
        //std::cerr << "Error. Código de error: " << GetLastError() << std::endl;
        std::wcerr << L"Error. Código de error: " << GetLastError() << std::endl;

        system("pause");
        return 0;
    }

    // imprimir el directorio actual
    //std::cout << "Directorio actual: " << buffer << std::endl;
    std::wcout << L"Directorio actual: " << buffer << std::endl;

    system("pause");
    return 0;
}