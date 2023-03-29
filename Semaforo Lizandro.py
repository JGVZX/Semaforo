import threading

class SemaphoreExample:
    def __init__(self, max_threads):
        self.semaphore = threading.Semaphore(max_threads)

    def access_resource(self):
        self.semaphore.acquire()
        try:
            # Acceder al recurso protegido por el semáforo
            print(f"Hilo {threading.current_thread().name} accediendo al recurso protegido por el semáforo.")
        finally:
            self.semaphore.release()

# Ejemplo de uso del semáforo
def main():
    semaphore_example = SemaphoreExample(max_threads=3)  # Límite máximo de 3 hilos activos
    threads = []

    # Creamos 5 hilos que intentarán acceder al recurso protegido por el semáforo
    for i in range(5):
        thread = threading.Thread(target=semaphore_example.access_resource, name=f"Hilo-{i}")
        threads.append(thread)

    # Iniciamos los hilos
    for thread in threads:
        thread.start()

    # Esperamos a que terminen todos los hilos
    for thread in threads:
        thread.join()

if __name__ == "__main__":
    main()
