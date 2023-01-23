#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Brak pliku! Podaj ścieżke jako argument!");
        return 1;
    }

    char password[64];
    int passwordLength;

    printf("Podaj hasło: ");
    scanf("%s", password);
    passwordLength = strlen(password);

    FILE *file1;
    if (NULL == (file1 = fopen(argv[1], "rb"))) {
        printf("Błąd! Nie udało się otworzyć pliku wejściowego.");
        return 1;
    }

    char temporaryFile[] = "temp_file.txt";
    FILE *file2;
    if (NULL == (file2 = fopen(temporaryFile, "wb"))) {
        printf("Błąd! Nie udało się otworzyć pliku tymczasowego.");
        return 1;
    }

    int i = 0;
    char character;

    // szyfrowanie pliku
    while ((character = getc(file1)) != EOF) {
        character ^= password[i % passwordLength];
        putc(character, file2);
        i++;
    }

    fclose(file1);
    fclose(file2);

    // usunięcie pliku wejściowego i zmiana nazwy pliku tymczasowego na nazwę pliku wejściowego
    remove(argv[1]);
    rename(temporaryFile, argv[1]);

    return 0;
}