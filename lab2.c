#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char Main[200], Src[30], Rep[30], Res[200], Copystr[200];
    int i = 0, j = 0, k = 0, l, istop, len, iMcnt, iNOC = 0;

    printf("Enter the Main String: ");
    scanf(" %[^\n]", Main);  // Added space before % to ignore trailing newline.

    printf("Enter the Pattern String: ");
    scanf(" %[^\n]", Src);

    printf("Enter the Replacement String: ");
    scanf(" %[^\n]", Rep);

    strcpy(Copystr, Main);
    for (i = 0; i <= (strlen(Main) - strlen(Src)); i++) {
        iMcnt = 0;
        for (j = 0; j < strlen(Src); j++) {
            if (Main[i + j] == Src[j]) {
                iMcnt++;
            } else {
                break;
            }
        }

        if (iMcnt == strlen(Src)) {
            iNOC++;
            for (k = 0; k < i; k++) {
                Res[k] = Main[k];
            }
            Res[k] = '\0'; // Null-terminate the intermediate result.
            strcat(Res, Rep);
            len = strlen(Res);

            for (k = i + strlen(Src), l = 0; Main[k] != '\0'; k++, l++) {
                Res[len + l] = Main[k];
            }
            Res[len + l] = '\0'; // Null-terminate the final result.

            strcpy(Main, Res);  // Update the main string.
            i += strlen(Rep) - 1; // Adjust loop index to skip over the replaced string.
        }
    }

    printf("\nInput Text: %s\n", Copystr);
    if (iNOC > 0) {
        printf("\n%d matches occurred\nText after replacing the pattern is:\n", iNOC);
        printf("%s\n", Res);
    } else {
        printf("String not found\n");
    }

    return 0;
}
