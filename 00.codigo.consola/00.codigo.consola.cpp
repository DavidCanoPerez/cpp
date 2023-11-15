#include <iostream>
#include <wchar.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
	SetConsoleTitleA("Programa consola");

    // normalmente en la terminal de win fallaran acentos o tildes y caracteres como la eñe, por su codificacion
    // se puede ver actual codificacion de cmd a traves de comando cmd: chcp
    // se puede establecer el formato de codificacion de la terminal cmd
    // https://docs.microsoft.com/en-us/windows/console/console-code-pages?redirectedfrom=MSDN

	// probar a comentar/descomentar
        // desde c++builder o codeblocks
                //SetConsoleCP(1252);
				//SetConsoleOutputCP(1252);
		// desde visual studio
				//SetConsoleCP(CP_UTF8);
				SetConsoleOutputCP(CP_UTF8);

    cout << "Buenos días, programa made in España\n";
    printf("Adiós con tilde\n");
    system("pause");
    return 0;
}
