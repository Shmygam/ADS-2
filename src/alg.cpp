// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
  double temp = value;
    if (n == 0) {
        return 1;
    }
    for (int i = 1; i < n; i++) {
        value = value * temp;
    }
    return value;
}

uint64_t fact(uint16_t n) {
  uint64_t result = 1;
    for (uint64_t i = 1; i <= n; i++) {
        result = result * i;
    }
    return result;
}

double calcItem(double x, uint16_t n) {
  double result = (pown(x, n) / fact(n));
  return result;
}

double expn(double x, uint16_t count) {
  double result = 0;
  uint64_t i = 1;
    while (i <= count) {
        result = result + calcItem(x, i);
        i++;
    }
    return result + 1;
}

double sinn(double x, uint16_t count) {
  double result = 0;
  uint64_t i = 1;
    while (i <= count) {
        result += pown(-1, (i - 1)) * calcItem(x, (2 * i - 1));
        i++;
    }
    return result;
}

double cosn(double x, uint16_t count) {
  double result = 0;
  uint64_t i = 1;
    while (i <= count) {
        result += pown(-1, (i - 1)) * calcItem(x, (2 * i - 2));
        i++;
    }
    return result;
}
