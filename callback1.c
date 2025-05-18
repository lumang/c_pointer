#include <stdio.h>

// Callback functions
int add(int a, int b) {
    return a + b;
}
int sub(int a, int b) {
    return a - b;
}
int mul(int a, int b) {
    return a * b;
}
int div(int a, int b) {
    return a / b;
}

// General calculator function that accepts a callback
void calc(int a, int b, int (*op)(int, int)) {
  
  	// Call the callback function
    printf("%d\n", op(a, b));
}

int main() {
    int n1 = 10, n2 = 5;

    // Using the calculator with addition
    printf("Addition: ");
    calc(n1, n2, add);

    // Using the calculator with subtraction
    printf("Subtraction: ");
    calc(n1, n2, sub);

    return 0;
}