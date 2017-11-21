#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  int READO = 0;
  int WRITO = 1;

  int papa[2];
  int lad[2];

  pipe(papa);
  pipe(lad);

  int f = fork();
  if(f){
    close(papa[WRITO]);
    close(lad[READO]);
    int namba;
    read(papa[READO],&namba, sizeof(int));
    printf("[the wee lad] doing maths on: %d\n", namba);
    namba = namba * 3 * 3 * 3;
    write(lad[WRITO], &namba, sizeof(int));
  }

  else{
    close(papa[READO]);
    close(lad[WRITO]);

    int numbah = 100;
    printf("[papa] sending: %d\n", numbah);
    write(papa[WRITO], &numbah, sizeof(int));
    int returno;
    read(lad[READO], &returno, sizeof(int));
    printf("[papa] recieved: %d\n", returno);
    

  }
}
    
