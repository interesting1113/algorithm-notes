#include <iostream>

using namespace std;

bool is_prime(int n) {
  if (n < 2) return false;
  for (int i = 2; i <= n / i; i ++) {
      if (n % i == 0) return false;
  }
  return true;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i ++) {
        int x;
        scanf("%d", &x);
        if (is_prime(x)) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}

