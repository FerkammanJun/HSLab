#include <stdio.h>
#include <stdlib.h>
#include <ap_cint.h>

#define LN 6
#define LM 6
#define LP 6

#define N (1 << LN)
#define M (1 << LM)
#define P (1 << LP)

void MATRIX_MUL(uint8 A[N][M], uint8 B[M][P], unsigned int result[N][P]);

void ground_truth_matrix_mult(uint8 A[N][M], uint8 B[M][P], unsigned int result[N][P]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < P; j++) {
			result[i][j] = 0;
			for (int k = 0; k < M; k++) {
				result[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}

bool compare_matrices(unsigned int result[N][P], unsigned int gt_result[N][P]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < P; j++) {
			if (result[i][j] != gt_result[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void print_matrix(uint8 matrix[N][P]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < P; ++j) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void print_unsigned_matrix(unsigned int matrix[N][P]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < P; ++j) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // example matrices A and B
    uint8 A[N][M];
    for (int i = 0; i < N; i++) {
    	for (int j = 0; j < M; j++) {
    		A[i][j] = rand() % 256;
    	}
    }

    uint8 B[M][P];
    for (int k = 0; k < M; k++) {
    	for (int l = 0; l < P; l++) {
    		B[k][l] = rand() % 256;
    	}
    }

    unsigned int result[N][P];

    // multiply matrices A and B
    MATRIX_MUL(A, B, result);

    unsigned int gt_result[N][P];
    ground_truth_matrix_mult(A, B, gt_result);

    printf("TEST ");
    if (compare_matrices(result, gt_result)) {
    	printf("PASSED");
    } else {
    	printf("FAILED");
    }
    printf("\n");

    return 0;
}
