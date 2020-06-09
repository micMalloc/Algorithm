#include <iostream>
#include <vector>

using namespace std;

const int MAX = 4 * 1e6;

vector<int> prime_number_sieve (int n) {
    vector<int> primes;
    vector<int> numbers(MAX + 1);
    
    for (int i = 2; i <= n; ++ i) {
        numbers[i] = i;
    }
    
    for (int i = 2; i <= n; ++ i) {
        if (numbers[i] == 0) continue;
        
        for (int j = 2 * i; j <= n; j += i) {
            numbers[j] = 0;
        }
    }
    
    for (int i = 2; i <= n; ++ i) {
        if (numbers[i]) {
            primes.push_back(numbers[i]);
        }
    }
    
    return primes;
}

int sliding_window (int n, vector<int> primes) {
    int cnt, sum;
    int left, right;
    
    cnt = left = right = 0;
    
    sum = left;
    
    while (true) {
        if (sum >= n) {
            sum -= primes[left ++];
        }
        else if (right == primes.size()) {
            break;
        }
        else {
            sum += primes[right ++];
        }
        
        if (sum == n) {
            cnt ++;
        }
    }
    
    return cnt;
}

int main (int argc, const char *argv[]) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int n;
    vector<int> primes;
    
    cin >> n;
    
    primes = prime_number_sieve(n);
    cout << sliding_window(n, primes) << '\n';
    
    return 0;
}

