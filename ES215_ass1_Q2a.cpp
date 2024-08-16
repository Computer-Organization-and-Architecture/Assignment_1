#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void Mat_Mul(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C) {
    int N = A.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}



int main() {
    vector<int> sizes = {64, 128, 256, 512, 1024};

    for (int size : sizes) {
        vector<vector<int>> Mat_A(size, vector<int>(size, 1.0));
        vector<vector<int>> Mat_B(size, vector<int>(size, 2.0));
        vector<vector<int>> Mat_C(size, vector<int>(size, 0.0));

        timespec start, end;

        // System time
        clock_gettime(CLOCK_MONOTONIC, &start);
        Mat_Mul(Mat_A, Mat_B, Mat_C);
        clock_gettime(CLOCK_MONOTONIC, &end);
        int system_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
        cout << "System time for N= " << size << ", integer matrix multiplication: " << system_time << " seconds" << endl;

        // CPU time
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
        Mat_Mul(Mat_A, Mat_B, Mat_C);
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
        int cpu_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
        cout << "CPU time for N= " << size << ", integer matrix multiplication: " << cpu_time << " seconds" << endl;
    }

    return 0;
}