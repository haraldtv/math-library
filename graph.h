#define HEIGHT 40
#define WIDTH 150

struct dataPoints {
    int size;
    double *x;
    double *y;
}; typedef struct dataPoints dataPoints;


void plotGraph(dataPoints inputData);
dataPoints allocateDatapoints(int xSize, int ySize);
void normalizeData(dataPoints *inp);
double minValue(int size, double *datalist);
double maxValue(int size, double *datalist);