#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

long long using_recursion(int n) {
    if(n==0) return 0;
    else if(n==1) return 1;
    else {
        return using_recursion(n-1)+using_recursion(n-2);
    }
}

void using_loop(int n) {
    long long prev = 0, cur = 1, c;
    for (int i = 0; i < n; i++) {
        cout << prev << " ";
        c = prev + cur;
        prev = cur;
        cur = c;
    }
    cout << endl;
}

long long using_rec_and_memo(int n, vector<long long>& dp) {
    if(dp[n]!=-1) {
        return dp[n];
    }
    if(n<=1) {
        return n;
    }
    return dp[n] = using_rec_and_memo(n-1,dp)+using_rec_and_memo(n-2,dp);
}

void using_loop_and_memo(int n) {
    vector<long long> arr(n);
    arr[0]=0;
    arr[1]=1;
    for(int i=2;i<=n;i++) {
        arr[i]=arr[i-1]+arr[i-2];
    }
}

int main(){

    auto start = high_resolution_clock::now();
    cout << "Fibonacci using Recursion: ";
    for (int i = 0; i < 50; i++) {
        cout << using_recursion(i) << " ";
    }
    cout << endl;
    auto stop = high_resolution_clock::now();
    auto duration_recursion = duration_cast<nanoseconds>(stop - start);
    cout << "time using recursion: " << duration_recursion.count() * 1e-9 << " seconds" << endl << endl;

    start = high_resolution_clock::now();
    cout << "Fibonacci using Loop: ";
    using_loop(50);
    stop = high_resolution_clock::now();
    auto duration_loop = duration_cast<nanoseconds>(stop - start);
    cout << "time using loop: " << duration_loop.count() * 1e-9 << " seconds" << endl << endl;

    
    vector<long long> dp(50, -1);
    start = high_resolution_clock::now();
    cout << "Fibonacci using Recursion and Memoization: ";
    for (int i = 0; i < 50; i++) {
        cout << using_rec_and_memo(i, dp) << " ";
    }
    cout << endl;
    stop = high_resolution_clock::now();
    auto duration_memo_recursion = duration_cast<nanoseconds>(stop - start);
    cout << "time using Recursion and Memoization: " << duration_memo_recursion.count() * 1e-9 << " seconds" << endl << endl;


    start = high_resolution_clock::now();
    cout << "Fibonacci using Loop with Memoization: ";
    using_loop_and_memo(50);
    stop = high_resolution_clock::now();
    auto duration_memo_loop = duration_cast<nanoseconds>(stop - start);
    cout << "time using Loop and Memoization: " << duration_memo_loop.count() * 1e-9 << " seconds" << endl << endl;


    cout << "Speedup of Loop over Recursion: " << duration_recursion.count() / duration_loop.count() << "x" << endl;
    cout << "Speedup of Recursion and Memoization over Recursion: " << duration_recursion.count() / duration_memo_recursion.count() << "x" << endl;
    cout << "Speedup of Loop and Memoization over Recursion: " << duration_recursion.count() / duration_memo_loop.count() << "x" << endl;
 

    
    return 0;
}