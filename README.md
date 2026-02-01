# SumaParalelaOpenMP

Este proyecto implementa la suma de dos arreglos de gran tamaño utilizando programación paralela en C++. La solución aprovecha la arquitectura multinúcleo del procesador mediante la librería OpenMP para optimizar el tiempo de ejecución.

# Tecnologías Utilizadas
Lenguaje: C++

Librería de Paralelismo: OpenMP

IDE: Visual Studio 2022

Control de Versiones: Git / GitHub

# Descripción del Proyecto
El programa genera dos arreglos de 1000 elementos con valores aleatorios. Utilizando la directiva #pragma omp parallel for, el bucle de suma se distribuye entre los hilos disponibles del CPU.

En la ejecución actual, el sistema detectó y utilizó 12 hilos para procesar la información de manera simultánea.

# Configuración del Entorno
Para ejecutar este proyecto en Visual Studio, es necesario habilitar el soporte de OpenMP:

Click derecho en el proyecto -> Propiedades.

Navegar a Propiedades de configuración > C/C++ > Lenguaje.

Cambiar Soporte para OpenMP a Sí (/openmp).

# Ejemplo de Salida

--- Realizando suma de arreglos en paralelo ---

Cantidad de hilos disponibles: 12

Indice  Arreglo A  +  Arreglo B  =  Resultado (R)

0       70         +  85         =  155

1       25         +  44         =  69

...

# Reflexión Técnica
Este ejercicio demuestra los principios de computación de alto rendimiento (HPC) que son fundamentales en áreas de especialización del autor, como el entrenamiento de redes neuronales (LSTMs, XGBoost) y la automatización de flujos de datos a gran escala. La capacidad de reducir la complejidad temporal mediante el paralelismo es una competencia clave para el desarrollo de Inteligencia Artificial aplicada.
