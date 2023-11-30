#include <ap_cint.h>

#define LN 6
#define LM 6
#define LP 6

#define N (1 << LN)
#define M (1 << LM)
#define P (1 << LP)


void MATRIX_MUL(uint8 A[N][M], uint8 B[M][P], unsigned int result[N][P]) {
#pragma HLS ARRAY_PARTITION variable=A complete dim=2
#pragma HLS ARRAY_PARTITION variable=B complete dim=1

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < P; j++) {
			result[i][j] = 0;
#pragma HLS PIPELINE II = 1
			for (int k = 0; k < M; k++) {
				result[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}
