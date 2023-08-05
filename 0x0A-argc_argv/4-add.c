#include <stdio.h>

int is_positive(char *number) {
  for (int i = 0; number[i] != '\0'; i++) {
    if (!isdigit(number[i])) {
      return 0;
    }
  }
  return 1;
}

int add_positive_numbers(char *numbers[]) {
  int sum = 0;
  for (int i = 0; numbers[i] != NULL; i++) {
    if (!is_positive(numbers[i])) {
      return 1;
    }
    sum += atoi(numbers[i]);
  }
  return sum;
}

int main() {
  char *numbers[] = {"123", "456", "789"};
  int result = add_positive_numbers(numbers);
  if (result == 1) {
    printf("Error\n");
  } else {
    printf("%d\n", result);
  }
  return 0;
}

