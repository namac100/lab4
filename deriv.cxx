#include <iostream>
#include <cmath>

using namespace std;


void print(double* p, const int N, const double dx,
           const double xmin)
{
   for(int i=0; i<N; i++)
       cout << i*dx + xmin << "\t" << p[i] << endl;
}

void func(double*p, const int N, const double xmin, const double dx)
{ double x;
  for(int i = 0; i < N; i++){
    x = xmin + i*dx;
    p[i] = exp(-x*x);
  }
}
  
void deriva(double* p, const int N, const double dx)
{ 
  double pold = 0.0;	
  double abhilfe;
  for(int i = 0; i < N-1; i++){
    abhilfe = p[i];
    p[i] = (p[i+1] - pold)/(2.0*dx);    
    pold = abhilfe;
  }
  p[N-1] = pold/(2.0*dx);  
}


int main(){
  const int N = 256;
  double p[N];
  const double xmax = 15;
  const double xmin = -15;
  const double dx = (xmax-xmin)/(N-1);

  func(p, N, xmin, dx);
  deriva(p, N, dx);
  print(p,N,dx,xmin);

  return 0;
}
