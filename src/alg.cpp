// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double result = 1.0;
  for (uint16_t l = 1; l <= n; ++l) {
    result = result * value;
  }
  return result;
}

uint64_t fact(uint16_t n) {
  uint64_t result = 1;
  for (uint16_t l = 1; l <= n; ++l) {
    result = result * l;
  }
  return result;
}

double calcItem(double x, uint16_t n) {
  double result = x;
  return pown(result, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double result = 0;
  for (uint16_t l = 0; l <= count; ++l) {
    result = result + calcItem(x, l);
  }
  return result;
}

double sinn(double x, uint16_t count) {
  double result = 0;
  int h = 1;
  for (uint16_t g = 1; g < count * 2 + 1; g += 2) {
    result = result + h * calcItem(x, g);
    h = h * -1;
  }
  return result;
}

double cosn(double x, uint16_t count) {
  double result = 1;
  for (uint64_t i = 2; i <= count; i++) {
    result += calcItem(x, (2 * i) - 2) * pown((-1.0), i - 1);
  }
  return result;
}
