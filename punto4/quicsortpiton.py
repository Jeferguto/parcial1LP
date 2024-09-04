import random
import time

def ordenar_rapidamente(lista):
    """Ordena la lista utilizando el algoritmo Quicksort."""
    if len(lista) <= 1:
        # Caso base: Si la lista tiene uno o cero elementos, ya está ordenada.
        return lista
    else:
        pivote = lista[len(lista) // 2]  # Seleccionar el pivote (elemento del medio)
        
        # Dividir la lista en tres partes:
        izquierda = [x for x in lista if x < pivote]  # Elementos menores que el pivote
        centro = [x for x in lista if x == pivote]    # Elementos iguales al pivote
        derecha = [x for x in lista if x > pivote]    # Elementos mayores que el pivote
        
        # Ordenar recursivamente las partes izquierda y derecha, y combinarlas con el pivote
        return ordenar_rapidamente(izquierda) + centro + ordenar_rapidamente(derecha)

def ejecutar():
    cantidad = 10000  # Tamaño de la lista
    lista_numeros = [random.randint(0, 10000) for _ in range(cantidad)]  # Crear una lista de números aleatorios
    
    tiempo_inicio = time.time()  # Medir el tiempo de inicio
    lista_ordenada = ordenar_rapidamente(lista_numeros)  # Ordenar la lista usando Quicksort
    tiempo_fin = time.time()  # Medir el tiempo de finalización
    
    tiempo_transcurrido = tiempo_fin - tiempo_inicio  # Calcular el tiempo transcurrido
    print(f"Tiempo de ordenación: {tiempo_transcurrido:.6f} segundos")  # Mostrar el tiempo de ejecución

# Ejecutar la función principal si se ejecuta el script
if __name__ == "__main__":
    ejecutar()

