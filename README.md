# Semaforo

# Jose Junior Guzman Veloz 
## 2021-0348

# Explicacion

Primrero la clase SemaphoreExample inicciara el semaforo con  límite máximo de hilos activos, que se especifica al crear una instancia de la clase. El método access_resource intenta acceder al recurso protegido por el semáforo llamando al método acquire() del semáforo. Si el límite máximo de hilos activos ya ha sido alcanzado, el método acquire() bloqueará el hilo que lo llama hasta que uno de los hilos activos termine y libere el semáforo. Una vez que se ha accedido al recurso protegido, se llama al método release() del semáforo para liberarlo.

El  principal main(), se crean 5 hilos que intentarán acceder al recurso protegido por el semáforo, pero como el límite máximo de hilos activos es de 3, algunos de los hilos se pondrán en espera hasta que los hilos activos terminen y liberen el semáforo. Al ejecutar el programa, se puede observar cómo los hilos van accediendo al recurso protegido por el semáforo, respetando el límite máximo de hilos activos.
