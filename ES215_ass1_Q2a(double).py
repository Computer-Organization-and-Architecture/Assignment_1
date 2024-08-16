import time

def matrix_multiply(A, B):
    N = len(A)
    C = [[0] * N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            for k in range(N):
                C[i][j] += A[i][k] * B[k][j]
    return C

sizes = [64, 128, 256, 512, 1024]

for N in sizes:
    A = [[1.0] * N for _ in range(N)]
    B = [[2.0] * N for _ in range(N)]

    # System time
    start = time.time()
    C = matrix_multiply(A, B)
    end = time.time()
    system_time = end - start
    print(f"System time for N= {N}, double matrix multiplication: {system_time:.10f} seconds")

    # CPU time
    start = time.process_time()
    C = matrix_multiply(A, B)
    end = time.process_time()
    cpu_time = end - start
    print(f"CPU time for N= {N},  double matrix multiplication: {cpu_time:.10f} seconds")