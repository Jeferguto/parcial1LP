#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 1024

// Función para contar cuántas veces aparece la palabra clave como una palabra completa en una línea
int count_keyword_occurrences_as_word(const char *line, const char *keyword) {
    int count = 0;
    const char *ptr = line;
    size_t keyword_len = strlen(keyword);

    while ((ptr = strstr(ptr, keyword)) != NULL) {
        // Verificar que la coincidencia está separada por delimitadores
        if ((ptr == line || !isalnum(*(ptr - 1))) && !isalnum(*(ptr + keyword_len))) {
            count++;
        }
        ptr += keyword_len;
    }

    return count;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <nombre_archivo> <palabra_clave>\n", argv[0]);
        return 1;
    }

    const char *file_name = argv[1];
    const char *search_word = argv[2];
    FILE *file = fopen(file_name, "r");

    if (file == NULL) {
        perror("No se pudo abrir el archivo");
        return 1;
    }

    char buffer[MAX_BUFFER_SIZE];
    int total_occurrences = 0;

    // Leer el archivo línea por línea
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        total_occurrences += count_keyword_occurrences_as_word(buffer, search_word);
    }

    fclose(file);

    // Mostrar el resultado
    printf("La palabra clave es: '%s'\n", search_word);
    printf("Esta palabra se repite %d veces en el texto.\n", total_occurrences);

    return 0;
}

