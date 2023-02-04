#include <stdio.h>
#include <time.h>

int main(void) {
    while (1) {
        printf("Pressione Enter para adicionar o horário atual à tabela:");
        getchar();

        time_t currentTime;
        struct tm *localTime;

        time(&currentTime);
        localTime = localtime(&currentTime);

        char buffer[80];
        strftime(buffer, 80, "%d-%m-%Y %H:%M", localTime);

        FILE *fp;
        fp = fopen("tabela_horarios.txt", "a");
        fprintf(fp, "%s\n", buffer);
        fclose(fp);
    }

    return 0;
}

