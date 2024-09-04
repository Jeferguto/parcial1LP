# Definición de patrones y tokens
BEGIN {
    patron_incremento = "\\+\\+"  # Patrón para incremento
    patron_suma = "\\+"           # Patrón para suma
    patron_real = "^[0-9]+\\.[0-9]+"  # Patrón para números reales
    patron_entero = "^[0-9]+"         # Patrón para números enteros
}

{
    # Remover espacios al inicio
    while (sub(/^[ \t]+/, "", $0)) {}

    while (length($0) > 0) {
        # Verificar si comienza con un número
        if (substr($0, 1, 1) ~ /[0-9]/) {
            if (match($0, patron_real)) {
                print "NUMERO_REAL"
                $0 = substr($0, RLENGTH + 1)
            } else if (match($0, patron_entero)) {
                print "NUMERO_ENTERO"
                $0 = substr($0, RLENGTH + 1)
            }
        }
        # Verificar si comienza con un operador
        else if (substr($0, 1, 1) ~ /[+]/) {
            if (match($0, patron_incremento)) {
                print "OPERADOR_INCREMENTO"
                $0 = substr($0, RLENGTH + 1)
            } else if (match($0, patron_suma)) {
                print "OPERADOR_SUMA"
                $0 = substr($0, RLENGTH + 1)
            }
        } 
        else {
            # Si no coincide con ningún patrón, eliminar el primer carácter
            $0 = substr($0, 2)
        }

        # Remover espacios después de procesar cada token
        while (sub(/^[ \t]+/, "", $0)) {}
    }
}
