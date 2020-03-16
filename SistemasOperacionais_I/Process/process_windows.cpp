#include <Windows.h>

//LPCSTR significa Long Pointer to Const String, ou seja, constant null-terminated string of CHAR.
void startup(LPCSTR nome_aplicacao)
{
    // Variáveis para informação adicional
    STARTUPINFOA si;
    PROCESS_INFORMATION pi;

    // Aloco o tanto de memória que as estruturas vão precisar
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Crio o Processo
    CreateProcessA
    (
        nome_aplicacao,   // Caminho que eu passei como parâmetro para a função
        argv[1],                // Argumento da linha de comando
        NULL,                   // O Gerenciamento do processo não é herdável
        NULL,                   // O Gerenciamento da Thread não é herdável
        FALSE,                  // Gerenciamento de heranças FALSE
        CREATE_NEW_CONSOLE,     // Abra os arquivos em um console diferente
        NULL,           // Uso do ambiente do pai
        NULL,           // Uso do diretório primário do pai 
        &si,            // Ponteiro para a estrutura STARTUPINFO
        &pi           // Ponteiro para a estrutura PROCESS_INFORMATION
    );
        // Espera o processo filho terminar
        WaitForSingleObject( pi.hProcess, INFINITE );

        // Fecha o processo e seus gerenciadores. 
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
}