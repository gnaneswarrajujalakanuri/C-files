#include <stdio.h>
int main() {
    int size;
    printf("Enter the number of rows: ");
    scanf("%d", &size);
    for (int i = 1; i <= size; i++) {
        int value = i % 2 ;
        for (int j = 1; j <= i; j++) {
            printf("%d ", value);
            value = 1- value;
        }
        printf("\n");
    }

    return 0;
}