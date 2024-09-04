%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


%}

%option noyywrap

%%

"lambda"                  { printf("ACEPTA\n"); exit(0); }
"print"                   { printf("ACEPTA\n"); exit(0); }
"="                       { /* Ignorar */ }
"("                       { /* Ignorar */ }
")"                       { /* Ignorar */ }
":"                       { /* Ignorar */ }
"**"                      { /* Ignorar */ }
[a-zA-Z_][a-zA-Z0-9_]*    { /* Ignorar identificadores */ }
[ \t\n]+                  { /* Ignorar espacios en blanco */ }

.                         { /* Ignorar otros caracteres */ }

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <archivo>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("No se pudo abrir el archivo");
        return 1;
    }

    yyin = file;
    yylex();
    fclose(file);

    printf("NO ACEPTA\n");
    return 0;
}
