#include <iostream>
#include <omp.h>    // API de OpenMP: Necesaria para gestionar hilos y directivas de paralelismo.
#include <vector>
#include <ctime>    // Provee funciones de tiempo para generar semillas aleatorias dinámicas.

int main() {
    // Definición de la constante N para determinar el tamaño de la muestra (1000 elementos).
    const int N = 1000;

    // Declaración de arreglos estáticos de tipo flotante para almacenar los datos y el resultado.
    float A[N], B[N], R[N];

    // INICIALIZACIÓN DE DATOS 
    // Se utiliza el tiempo actual como semilla (seed) para que rand() genere números distintos cada ejecución.
    srand(time(0));

    // Llenado secuencial de arreglos. Nota: Esta parte no suele paralelizarse si el costo de
    // inicialización es menor que el costo de gestionar los hilos.
    for (int i = 0; i < N; i++) {
        // Generamos números entre 0 y 99 y los convertimos explícitamente a float.
        A[i] = static_cast<float>(rand() % 100);
        B[i] = static_cast<float>(rand() % 100);
    }

    std::cout << "--- Realizando suma de arreglos en paralelo ---\n";

    //  COMPUTACIÓN PARALELA CON OPENMP 

    // omp_get_max_threads() consulta al sistema operativo cuántos hilos lógicos tiene el CPU.
    // Esto es útil para auditar el hardware antes de lanzar la carga de trabajo.
    std::cout << "Cantidad de hilos disponibles: " << omp_get_max_threads() << std::endl;

    // DIRECTIVA PRAGMA: Es la instrucción clave para el compilador.
    // 'omp parallel for' le indica que el siguiente bucle for debe ser repartido entre los hilos disponibles.
    // Cada hilo se encargará de una fracción del rango total (N=1000).
#pragma omp parallel for
    for (int i = 0; i < N; i++) {
        // Dado que cada iteración de la suma depende de un índice 'i' único, no hay dependencias
        // de datos entre hilos, lo que permite una ejecución paralela segura y eficiente.
        R[i] = A[i] + B[i];
    }

    // VERIFICACIÓN Y SALIDA 

    // Cabecera de la tabla para facilitar la lectura de los resultados.
    std::cout << "Indice\tArreglo A\tArreglo B\tResultado (R)\n";

    // Se imprimen solo los primeros 15 elementos como muestra representativa para validar
    // que la aritmética se realizó correctamente en el bloque paralelo anterior.
    for (int i = 0; i < 15; i++) {
        std::cout << i << "\t" << A[i] << "\t+\t" << B[i] << "\t=\t" << R[i] << "\n";
    }

    // Finalización exitosa del proceso.
    return 0;
}