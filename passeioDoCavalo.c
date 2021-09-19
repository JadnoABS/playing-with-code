#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  int iJogada;
  int* pos;
  int deslocamentoX[8];
  int deslocamentoY[8];
} Cavalo;

int** tabuleiro;

Cavalo* initCavalo(int posX, int posY) {
  Cavalo* cavalo = (Cavalo*) malloc(sizeof(Cavalo));
  cavalo->iJogada = 0;
  cavalo->pos = (int*) malloc(sizeof(int) * 2);
  cavalo->pos[0] = posX; cavalo->pos[1] = posY;

  int deslocamentoX[] = {2, 1, -2, -1, 2, 1, -2, -1};
  int deslocamentoY[] = {-1,-2, 1, 2, 1, 2, -1, -2};
  int i;
  for(i = 0; i < 8; i++){
    cavalo->deslocamentoX[i] = deslocamentoX[i];
    cavalo->deslocamentoY[i] = deslocamentoY[i];
  }

  return cavalo;
}

bool passoValido(int deslocX, int deslocY, int* pos) {
  if((deslocX < -2 || deslocX > 2 ) && (deslocY < -2 || deslocY > 2)) return false;

  if(tabuleiro[pos[0] + deslocX][pos[1] + deslocY]) return false;

  if((pos[0] + deslocX >= 0 && pos[0] + deslocX < 8) &&
     (pos[1] + deslocY >= 0 && pos[1] + deslocY < 8)){
    return true;
  }
  else return false;
}

int passeio(Cavalo* cavalo) {
  int passo = 0;
  int desloc[2];
  bool sucesso = false;

  do {
    desloc[0] = cavalo->deslocamentoX[passo];
    desloc[1] = cavalo->deslocamentoY[passo];

    if(passoValido(desloc[0], desloc[1], cavalo->pos)){
      tabuleiro[desloc[0]][desloc[1]] = cavalo->iJogada;

      if(cavalo->iJogada < 63) {
        cavalo->iJogada++;
        if(!passeio(cavalo)){
          cavalo->iJogada--;
        } else sucesso = true;
      } else sucesso = true;
    } else {
      passo++;
    }
  } while (!(passo >= 8 || sucesso));

  if(sucesso) return 1;
  else return 0;

}

int main() {
  Cavalo* cavalo = initCavalo(0, 0);
  tabuleiro = (int**) malloc(sizeof(int*) * 8);

  int i;
  for(i = 0; i < 8; i++){
    tabuleiro[i] = (int*) calloc(8, sizeof(int));
  }

  if(passeio(cavalo)){
    printf("SOLUCAO ALCANCADA!\n");
    free(cavalo);
    free(tabuleiro);
    return 1;
  }

  printf("SEM SOLUCAO!\n");
  free(cavalo);
  free(tabuleiro);
  return 0;
}
