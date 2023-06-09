#define HEIGHT 40
#define WIDTH 150

struct dataPoints {
    double *x;
    double *y;
}; typedef struct dataPoints dataPoints;


void plotGraph(dataPoints inputData);
dataPoints allocateDatapoints(int xSize, int ySize);