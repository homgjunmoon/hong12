#include <stdio.h>

// Á¤¹æ Çà·Ä °ö¼À ÇÔ¼ö
void square_matrix_multiply(int A[3][3], int B[3][3], int C[3][3]) {
    int i, j, k;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            C[i][j] = 0;
            for (k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// ºñÁ¤¹æ Çà·Ä °ö¼À ÇÔ¼ö
void non_square_matrix_multiply(int A[2][3], int B[3][2], int C[2][2]) {
    int i, j, k;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            C[i][j] = 0;
            for (k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Çà·Ä Ãâ·Â ÇÔ¼ö
void print_matrix(int rows, int cols, int matrix[rows][cols]) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Á¤¹æ Çà·Ä
    int A_square[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B_square[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int C_square[3][3];

    // ºñÁ¤¹æ Çà·Ä
    int A_non_square[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int B_non_square[3][2] = {{9, 8}, {7, 6}, {5, 4}};
    int C_non_square[2][2];

    // Á¤¹æ Çà·Ä °ö¼À
    printf("\nÁ¤¹æ Çà·Ä °ö¼À:\n");
    square_matrix_multiply(A_square, B_square, C_square);
    print_matrix(3, 3, C_square);

    // ºñÁ¤¹æ Çà·Ä °ö¼À
    printf("\nºñÁ¤¹æ Çà·Ä °ö¼À:\n");
    non_square_matrix_multiply(A_non_square, B_non_square, C_non_square);
    print_matrix(2, 2, C_non_square);

    return 0;
}
