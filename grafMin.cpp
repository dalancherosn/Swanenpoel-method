#include <iostream>
#include <cmath>

double Minimos(double x);

int main(void)
{
  std::cout.precision(6);
  std::cout.setf(std::ios::scientific);

  double x = 540.0;
  while(x <= 1100.0)
    {
      std::cout << x << "\t" << Minimos(x) << std::endl;
      x += 0.01;
    }

  return 0;
}

double Minimos(double x)
{
  return -25.6715 + (0.131506*x) - (0.000246066*std::pow(x, 2)) + (2.03217e-07*std::pow(x, 3)) - (6.24503e-11*std::pow(x, 4));
}
