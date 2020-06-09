#include <vector>

vector<int> prime_number_sieve (int N) {
  vector<int> numbers(N + 1);
  vector<int> prime_numbers;
  
  for (int i = 2; i <= N; ++ i) {
    numbers[i] = i;
  }
  
  for (int i = 2; i <= N; ++ i) {
        if (numbers[i] == 0) continue;
    
    prime_numbers.push_back(numbers[i]);
    
    for (j = i * 2; j <= N; j += i) {
        numbers[j] = 0;
    }
  }
  
  return prime_numbers;
}
