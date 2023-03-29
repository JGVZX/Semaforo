 #include <stdio.h>

 #include <stdlib.h>
 
 #include <unistd.h>
 
 #include <semaphore.h>
 
 #include <fcntl.h>

int main() {
  sem_t *sem;
  pid_t pid;

  sem = sem_open("/mysem", O_CREAT, 0644, 1);
  if (sem == SEM_FAILED) {
    perror("Error semáforo");
    exit(EXIT_FAILURE);
  }


  pid = fork();
  if (pid < 0) {
    perror("Error al crear el proceso hijo");
    exit(EXIT_FAILURE);
  } else if (pid == 0) {




    printf("El Proceso hijo esperando al semáforo...\n");
    sem_wait(sem);
    printf("EL Proceso hijo dentro de la sección crítica\n");
    sleep(5);
    sem_post(sem);
    printf("El Proceso hijo ha liberado el semáforo\n");
    exit(EXIT_SUCCESS);
  } else {

    printf("EL Proceso padre esperando al semáforo...\n");
    sem_wait(sem);
    printf("El Proceso padre dentro de la sección crítica\n");
    sleep(5);
    sem_post(sem);
    printf("EL Proceso padre ha liberado el semáforo\n");
    exit(EXIT_SUCCESS);
  }
}