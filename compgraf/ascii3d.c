#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#define PI 3.14159265
#define RESOLUTION 45


char depth[] = {'@', '0', 'O', 'o', '.'};


char setDepthChar(int zindex) {
  if(zindex < 20) return depth[0];
  if(zindex < 25) return depth[1];
  if(zindex < 30) return depth[2];
  if(zindex < 100) return depth[3];
  return depth[4];
}

int main() {

  int visionPoint[] = {22, 22, 0};
  int depthCoeficient = 15;

  float cubo[8][3] = {
    {2, 2, 20},
    {22, 2, 20},
    {2, 22, 20},
    {22, 22, 20},
    {2, 2, 40},
    {22, 2, 40},
    {2, 22, 40},
    {22, 22, 40},
  };

  for(int i = 0; i < 8; i++){
    cubo[i][0] += 10;
    cubo[i][1] += 10;
  }

  int halfSide = (cubo[1][0] - cubo[0][0])/2;
  int center[] = {
    cubo[0][0] + halfSide,
    cubo[0][1] + halfSide,
    cubo[0][2] + halfSide
  };

  int maxX = center[0] + (halfSide * pow(2, 1/2));
  int maxY = center[1] + (halfSide * pow(2, 1/2));
  int maxZ = center[2] + (halfSide * pow(2, 1/2));

  char display[RESOLUTION][RESOLUTION];


  int angle = 1;
  float theta = PI/180;
  while(angle <= 180) {
    usleep(100000);
    system("clear");

    for(int i = 0; i < RESOLUTION; i++){
      for(int j = 0; j < RESOLUTION; j++){
        display[i][j] = ' ';
      }
    }

    for(int i = 0; i < 8; i++) {

      char ch = setDepthChar(cubo[i][2]);

      int multX = visionPoint[0] < cubo[i][0] ? -1 : 1;
      int multY = visionPoint[1] < cubo[i][1] ? -1 : 1;

      int depthDiff = abs(cubo[i][2] - visionPoint[2]);

      int posX = (int) cubo[i][0] + (depthDiff * multX / depthCoeficient);
      int posY = (int) cubo[i][1] + (depthDiff * multY / depthCoeficient);

      if(posX < RESOLUTION && posX >= 0 && posY < RESOLUTION && posY >= 0){
        display[posY][posX] = ch;
      }

      /* Rotacao do cubo em torno de Y */

      int sentidoZ = cubo[i][0] <= center[0] ? 1 : -1;
      int sentidoX = cubo[i][2] <= center[2] ? -1 : 1;

      cubo[i][0] += cos(theta) * sentidoX;
      cubo[i][2] += cos(theta) * sentidoZ;
    }

    for(int i = 0; i < RESOLUTION; i++){
      for(int j = 0; j < RESOLUTION; j++){
        printf(" %c", display[i][j]);
      }
      printf("\n");
    }

    angle++;
  }

  return 0;

}
