#include <iostream>

int a, b, c, d, e, f;
int main()
{
  scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e ,&f);
  printf("%d %d", (e*c-b*f)/(a*e-b*d), (a*f - c*d)/(a*e-b*d));
}