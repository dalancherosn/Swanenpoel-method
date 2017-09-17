#include <iostream>
#include <cmath>

double Maximos(double x);

int main(void)
{
  std::cout.precision(6);
  std::cout.setf(std::ios::scientific);

  double x = 540.0;
  while(x <= 1100.0)
    {
      std::cout << x << "\t" << Maximos(x) << std::endl;
      x += 0.01;
    }

  return 0;
}

double Maximos(double x)
{
  if(540.0 <= x && x < 740.0)
    {
      return -35.8213 + (0.0811269*x) + (0.0000575861*std::pow(x, 2)) - (8.24222e-08*std::pow(x, 3)) - (1.99735e-10*std::pow(x, 4)) - (1.01387e-13*std::pow(x, 5)) + (2.77914e-16*std::pow(x, 6)) + (5.5642e-19*pow(x, 7)) - (5.81518e-22*pow(x, 8));
    }
  else if(740.0 <= x  && x < 1100.0)
    {
      return 0.911005 + (4.10085e-06*x);
    }
  else
    {
      return 0;
    }
}
