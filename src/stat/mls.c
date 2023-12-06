#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct Circle{
  double a;
  double b;
  double r;
} circle;

double populationMean(double *inp, int n) {
  int i;
  double sum;
  for (i=0; i<n; i++) {
    sum += inp[i];
  }
  return (sum / n);
}

// Function to calculate sample varience in an array inp
double variance(double *inp, int n) {
  int i;
  double sum;
  double mean = populationMean(inp, n);
  for (i=0; i<n; i++) {
    sum += (inp[i] - mean);
  }
  sum = pow(sum, 2);
  return (sum / (n-1));
}

// Function to calculate sample covariance between two variables (x, y)
double covariance(double *x, double *y, int n) {
  int i;
  double sum;

  double xmean = populationMean(x, n);
  double ymean = populationMean(y, n);

  for (i=0; i<n; i++) {
    sum += ((x[i] - xmean) * (y[i] * ymean)); 
  } 

  return (sum / (n-1)); 
}

// Remove the defining of individual x and y variables to optimize a bit. Not a very expensive operation, but should probably be removed
circle mls(double **inp, int n) {
  int i;

  double *x, *x2, *y, *y2;
  x = malloc(n*sizeof(double));
  x2 = malloc(n*sizeof(double));
  y2 = malloc(n*sizeof(double));
  y = malloc(n*sizeof(double));

  circle cval;

  for (i=0; i<n; i++) {
    x[i] = inp[0][i];
    x2[i] = pow(inp[0][i], 2);
    y[i] = inp[1][i];
    y2[i] = pow(inp[1][i], 2);
  }
  
  int n1 = (n * (n-1));
  double n2 = n1*0.5;

  double a = n1 * variance(x, n);
  double b = n1 * covariance(x, y, n);
  double c = n1 * variance(y, n);
  double d = n2 * (covariance(x, y2, n) + covariance(x, y2, n));
  double e = n2 * ((covariance(y, x2, n)) + covariance(y, y2, n));

  cval.a = ( ((d*c) - (b*e)) / ((a*c) - (b*b)) );
  cval.b = ( ((a*e) - (b*d)) / ((a*c) - (b*b)) );

  cval.r = 0;
  for (i=0; i<n; i++) {
    cval.r += ( sqrt( pow((x[i]-cval.a), 2) + (pow((y[i]-cval.b), 2)) ) / 2 );
  }

  return cval;
}
