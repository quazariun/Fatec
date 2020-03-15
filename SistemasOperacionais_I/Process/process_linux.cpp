#include <unistd.h> //Aqui fica a função exec()
#include <stdio.h>
#include <sys/types.h> //Aqui fica a função fork()
#include <sys/wait.h>

using namespace std;

int main( ){
   //pid_t é um tipo inteiro, usado para conseguir usar o getpid() e o getppid()
   pid_t child_pid;

   // Cria um processo filho que é a cópia do pai, inclusive está cópia executa com o ponteiro no mesmo lugar em que o fork() foi executado
   child_pid = fork ();

   //Essa estrutura de If's consegue identificar se o comando falhou ou se é o filho pelo Return do fork(), pois no processo filho ele retorna 0 ou negativo caso de erro.
   if (child_pid < 0) {
      printf("O programa falhou em executar o comando fork()");
      return 1;

   } else if (child_pid == 0) {
      //Fiz um sleep para que seja possível enxergar que o processo pai está esperando o processo filho
      sleep(5);

      //Aqui eu irei abrir o Google Chrome, usando o $PATH (O caminho do Google Chrome está guardado lá), assim eu só tenho que passar o nome do programa
      char *args[]={"google-chrome","www.facebook.com",NULL}; 
      
      //Da família Exec (existem muitas variações), o 'v' significa que eu vou passar um vector, que é o *args[] e o 'p' é de path, ou seja terá um caminho para o novo programa.
      execvp(args[0],args);
      
   } else {
      wait(NULL);
   }
   return 0;
}