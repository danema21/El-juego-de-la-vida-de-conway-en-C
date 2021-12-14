#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <time.h>
#include <conio.h>

int msleep(long tms){
	struct timespec ts;
	int ret;
	
	if(tms < 0){
		errno = EINVAL;
		return -1;
	}
	
	ts.tv_sec = tms / 1000;
	ts.tv_nsec = (tms % 1000) * 1000000;
	
	do {
		ret = nanosleep(&ts, &ts);
	}while(ret && errno == EINTR);
	
	return ret;
}

void imprimirMatriz(char m[30][70]){
	int i;
	int j;/*
	printf("*=============================================================================*\n");
	printf("|***** *   * *****   ****  ***  *    * *****   ***  *****  *     * ***** *****|\n");
	printf("|  *   *   * *      *     *   * **  ** *      *   * *      *     * *     *    |\n");
	printf("|  *   ***** ***    *  *  ***** * ** * ***    *   * ***    *     * ***   ***  |\n");
	printf("|  *   *   * *      *   * *   * *    * *      *   * *      *     * *     *    |\n");
	printf("|  *   *   * *****   ***  *   * *    * *****   ***  *      ***** * *     *****|\n");
	printf("*=============================================================================*\n\n");*/
	printf("    *----------------------------------------------------------------------*\n");
	
	for(i = 0; i < 30; i++){
		printf("    |");
		for(j = 0; j < 70; j ++)
			printf("%c", m[i][j]);
		printf("|\n");
	}
	printf("    *----------------------------------------------------------------------*\n\n");
}

int cantidadDeVecinos(char m[30][70], int fil, int col){
	int vecinos = 0;
	if(fil == 0 && col == 0){
		
		if(m[fil+1][69] == '0')
			vecinos++;
		
		if(m[fil+1][col] == '0')
			vecinos++;
		
		if(m[fil+1][col+1] == '0')
			vecinos++;
			
		if(m[fil][col+1] == '0')
			vecinos++;
			
		if(m[fil][69] == '0')
			vecinos++;
			
		if(m[29][col+1] == '0')
			vecinos++;
			
		if(m[29][col] == '0')
			vecinos++;
			
		if(m[29][69] == '0')
			vecinos++;
		
	}else if(fil == 0 && col == 69){
		
		if(m[fil+1][col-1] == '0')
			vecinos++;
		
		if(m[fil+1][col] == '0')
			vecinos++;
			
		if(m[fil+1][0] == '0')
			vecinos++;
			
		if(m[fil][col-1] == '0')
			vecinos++;
			
		if(m[fil][0] == '0')
			vecinos++;
			
		if(m[29][col-1] == '0')
			vecinos++;
			
		if(m[29][col] == '0')
			vecinos++;
			
		if(m[29][0] == '0')
			vecinos++;
		
	}else if(fil == 29 && col == 0){
		
		if(m[fil-1][69] == '0')
			vecinos++;
			
		if(m[fil-1][col] == '0')
			vecinos++;
			
		if(m[fil-1][col+1] == '0')
			vecinos++;
		
		if(m[fil][69] == '0')
			vecinos++;
		
		if(m[fil][col+1] == '0')
			vecinos++;
		
		if(m[0][69] == '0')
			vecinos++;
			
	    if(m[0][col] == '0')
			vecinos++;
		
		if(m[0][col+1] == '0')
			vecinos++;
		
	}else if(fil == 29 && col == 69){
		
		if(m[fil-1][col-1] == '0')
			vecinos++;
			
		if(m[fil][col] == '0')
			vecinos++;
			
		if(m[fil][0] == '0')
			vecinos++;
		
		if(m[fil][col-1] == '0')
			vecinos++;
		
		if(m[fil][0] == '0')
			vecinos++;
		
		if(m[0][col-1] == '0')
			vecinos++;
		
		if(m[0][col] == '0')
			vecinos++;
			
		if(m[0][0] == '0')
			vecinos++;
		
	}else if(fil == 0){
		
		if(m[29][col-1] == '0')
			vecinos++;
			
		if(m[29][col] == '0')
			vecinos++;
			
		if(m[29][col+1] == '0')
			vecinos++;
		
		if(m[fil][col-1] == '0')
			vecinos++;
			
		if(m[fil][col+1] == '0')
			vecinos++;
			
		if(m[fil+1][col-1] == '0')
			vecinos++;
			
		if(m[fil+1][col] == '0')
			vecinos++;
			
		if(m[fil+1][col+1] == '0')
			vecinos++;
		
	}else if(fil == 29){
		
		if(m[fil-1][col-1] == '0')
			vecinos++;
			
		if(m[fil-1][col] == '0')
			vecinos++;
			
		if(m[fil-1][col+1] == '0')
			vecinos++;
		
		if(m[fil][col-1] == '0')
			vecinos++;
			
		if(m[fil][col+1] == '0')
			vecinos++;
			
		if(m[0][col-1] == '0')
			vecinos++;
		
		if(m[0][col] == '0')
			vecinos++;
			
		if(m[0][col+1] == '0')
			vecinos++;
		
	}else if(col == 0){
		
		if(m[fil-1][69] == '0')
			vecinos++;
			
		if(m[fil][69] == '0')
			vecinos++;
			
		if(m[fil+1][69] == '0')
			vecinos++;	
		
		if(m[fil-1][col] == '0')
			vecinos++;
			
		if(m[fil+1][col] == '0')
			vecinos++;
			
		if(m[fil-1][col+1] == '0')
			vecinos++;
			
		if(m[fil][col+1] == '0')
			vecinos++;
			
		if(m[fil+1][col+1] == '0')
			vecinos++;		
		
	}else if(col == 69){
		
		if(m[fil-1][col-1] == '0')
			vecinos++;
			
		if(m[fil][col-1] == '0')
			vecinos++;
			
		if(m[fil+1][col-1] == '0')
			vecinos++;
		
		if(m[fil-1][col] == '0')
			vecinos++;
			
		if(m[fil+1][col] == '0')
			vecinos++;
			
		if(m[fil-1][0] == '0')
			vecinos++;
			
		if(m[fil][0] == '0')
			vecinos++;
			
		if(m[fil+1][0] == '0')
			vecinos++;
			
	}else{
		if(m[fil-1][col-1] == '0')
			vecinos++;
		
		if(m[fil-1][col] == '0')
			vecinos++;
			
		if(m[fil-1][col+1] == '0')
			vecinos++;
			
		if(m[fil][col-1] == '0')
			vecinos++;
			
		if(m[fil][col+1] == '0')
			vecinos++;
			
		if(m[fil+1][col-1] == '0')
			vecinos++;
			
		if(m[fil+1][col] == '0')
			vecinos++;
			
		if(m[fil+1][col+1] == '0')
			vecinos++;
	}
		
	return vecinos;
}

void simular(char m[30][70]){
	bool vida[30][70];
	int i;
	int j;
	
	for(i = 0; i < 30; i++){
		for(j = 0; j < 70; j++){
			if(m[i][j] == '0'){
				if(cantidadDeVecinos(m, i, j) < 2)
					//Muerte por soledad
					vida[i][j] = false;
				else if(cantidadDeVecinos(m, i, j) > 3)
					//Muerte por sobrepoblacion
					vida[i][j] = false;
				else
					//Supervivencia
					vida[i][j] = true;
			}else{
				if(cantidadDeVecinos(m, i, j) == 3)
					//Nacimiento
					vida[i][j] = true;
				else
					//Vecinos insuficientes para nacer
					vida[i][j] = false;
			}
		}
	}
	
	for(i = 0; i < 30; i++){
		for(j = 0; j < 70; j++){
			if(vida[i][j])
				m[i][j] = '0';
			else
				m[i][j] = ' ';
		}
	}
}

void generarMatriz(char m[30][70], int cantidad){
	int i;
	int j;
	int aleatorio;
	for(i = 0; i < 30; i++){
		for(j = 0; j < 70; j++){
			aleatorio = rand()%cantidad;
			if(aleatorio == 1)
				m[i][j] = '0';
			else
				m[i][j] = ' ';
		}
	}
	simular(m);
}

void generarPatron(char m[30][70], int patron){
	//vacia la matriz
	if(patron != 0)
		generarMatriz(m, 1);
	
	//genera el patron elegido
	if(patron == 1){
		//block
		m[10][30] = '0';
		m[10][31] = '0';
		m[11][30] = '0';
		m[11][31] = '0';
		
	}else if(patron == 2){
		//bee-hive
		m[10][31] = '0';
		m[10][32] = '0';
		m[11][30] = '0';
		m[11][33] = '0';
		m[12][31] = '0';
		m[12][32] = '0';
		
	}else if(patron == 3){
		//loaf
		m[10][31] = '0';
		m[10][32] = '0';
		m[11][30] = '0';
		m[11][33] = '0';
		m[12][31] = '0';
		m[12][33] = '0';
		m[13][32] = '0';
		
	}else if(patron == 4){
		//boat
		m[10][30] = '0';
		m[10][31] = '0';
		m[11][30] = '0';
		m[11][32] = '0';
		m[12][31] = '0';
		
	}else if(patron == 5){
		//tub
		m[10][31] = '0';
		m[11][30] = '0';
		m[11][32] = '0';
		m[12][31] = '0';
		
	}else if(patron == 6){
		//blinker
		m[10][31] = '0';
		m[11][31] = '0';
		m[12][31] = '0';
		
	}else if(patron == 7){
		//toad
		m[10][31] = '0';
		m[10][32] = '0';
		m[10][33] = '0';
		m[11][30] = '0';
		m[11][31] = '0';
		m[11][32] = '0';
		
	}else if(patron == 8){
		//beacon
		m[10][30] = '0';
		m[10][31] = '0';
		m[11][30] = '0';
		m[11][31] = '0';
		m[12][32] = '0';
		m[12][33] = '0';
		m[13][32] = '0';
		m[13][33] = '0';
		
	}else if(patron == 9){
		//pulsar
		m[5][32] = '0';
		m[5][33] = '0';
		m[5][34] = '0';
		m[5][38] = '0';
		m[5][39] = '0';
		m[5][40] = '0';
		m[7][30] = '0';
		m[7][35] = '0';
		m[7][37] = '0';
		m[7][42] = '0';
		m[8][30] = '0';
		m[8][35] = '0';
		m[8][37] = '0';
		m[8][42] = '0';
		m[9][30] = '0';
		m[9][35] = '0';
		m[9][37] = '0';
		m[9][42] = '0';
		m[10][32] = '0';
		m[10][33] = '0';
		m[10][34] = '0';
		m[10][38] = '0';
		m[10][39] = '0';
		m[10][40] = '0';
		m[12][32] = '0';
		m[12][33] = '0';
		m[12][34] = '0';
		m[12][38] = '0';
		m[12][39] = '0';
		m[12][40] = '0';
		m[13][30] = '0';
		m[13][35] = '0';
		m[13][37] = '0';
		m[13][42] = '0';
		m[14][30] = '0';
		m[14][35] = '0';
		m[14][37] = '0';
		m[14][42] = '0';
		m[15][30] = '0';
		m[15][35] = '0';
		m[15][37] = '0';
		m[15][42] = '0';
		m[17][32] = '0';
		m[17][33] = '0';
		m[17][34] = '0';
		m[17][38] = '0';
		m[17][39] = '0';
		m[17][40] = '0';
		
	}else if(patron == 10){
		//pentadecathlon
		m[7][30] = '0';
		m[7][31] = '0';
		m[7][32] = '0';
		m[8][30] = '0';
		m[8][32] = '0';
		m[9][30] = '0';
		m[9][31] = '0';
		m[9][32] = '0';
		m[10][30] = '0';
		m[10][31] = '0';
		m[10][32] = '0';
		m[11][30] = '0';
		m[11][31] = '0';
		m[11][32] = '0';
		m[12][30] = '0';
		m[12][31] = '0';
		m[12][32] = '0';
		m[13][30] = '0';
		m[13][32] = '0';
		m[14][30] = '0';
		m[14][31] = '0';
		m[14][32] = '0';
		
	}else if(patron == 11){
		//glider
		m[7][32] = '0';
		m[8][30] = '0';
		m[8][32] = '0';
		m[9][31] = '0';
		m[9][32] = '0';
		
	}else if(patron == 12){
		//light-weitght spaceship
		m[10][31] = '0';
		m[10][32] = '0';
		m[11][30] = '0';
		m[11][31] = '0';
		m[11][32] = '0';
		m[11][33] = '0';
		m[12][30] = '0';
		m[12][31] = '0';
		m[12][33] = '0';
		m[12][34] = '0';
		m[13][32] = '0';
		m[13][33] = '0';
		
	}else if(patron == 13){
		//middle-weight spaceship
		m[10][31] = '0';
		m[10][32] = '0';
		m[10][33] = '0';
		m[11][30] = '0';
		m[11][31] = '0';
		m[11][32] = '0';
		m[11][33] = '0';
		m[11][34] = '0';
		m[12][30] = '0';
		m[12][31] = '0';
		m[12][32] = '0';
		m[12][34] = '0';
		m[12][35] = '0';
		m[13][33] = '0';
		m[13][34] = '0';
		
	}else if(patron == 14){
		//heavy-weight spaceship
		m[10][31] = '0';
		m[10][32] = '0';
		m[10][33] = '0';
		m[10][34] = '0';
		m[11][30] = '0';
		m[11][31] = '0';
		m[11][32] = '0';
		m[11][33] = '0';
		m[11][34] = '0';
		m[11][35] = '0';
		m[12][30] = '0';
		m[12][31] = '0';
		m[12][32] = '0';
		m[12][33] = '0';
		m[12][35] = '0';
		m[12][36] = '0';
		m[13][34] = '0';
		m[13][35] = '0';
		
	}else if(patron == 15){
		//copperhead
		m[15][31] = '0';
		m[15][32] = '0';
		m[15][35] = '0';
		m[15][36] = '0';
		m[16][33] = '0';
		m[16][34] = '0';
		m[17][33] = '0';
		m[17][34] = '0';
		m[18][30] = '0';
		m[18][32] = '0';
		m[18][35] = '0';
		m[18][37] = '0';
		m[19][30] = '0';
		m[19][37] = '0';
		m[21][30] = '0';
		m[21][37] = '0';
		m[22][31] = '0';
		m[22][32] = '0';
		m[22][35] = '0';
		m[22][36] = '0';
		m[23][32] = '0';
		m[23][33] = '0';
		m[23][34] = '0';
		m[23][35] = '0';
		m[25][33] = '0';
		m[25][34] = '0';
		m[26][33] = '0';
		m[26][34] = '0';
		
	}else if(patron == 16){
		//lobster
		m[14][31] = '0';
		m[14][44] = '0';
		m[15][31] = '0';
		m[15][44] = '0';
		m[16][30] = '0';
		m[16][32] = '0';
		m[16][43] = '0';
		m[16][45] = '0';
		m[17][31] = '0';
		m[17][44] = '0';
		m[18][31] = '0';
		m[18][44] = '0';
		m[19][32] = '0';
		m[19][36] = '0';
		m[19][37] = '0';
		m[19][38] = '0';
		m[19][39] = '0';
		m[19][43] = '0';
		m[20][36] = '0';
		m[20][37] = '0';
		m[20][38] = '0';
		m[20][39] = '0';
		m[21][32] = '0';
		m[21][33] = '0';
		m[21][34] = '0';
		m[21][35] = '0';
		m[21][40] = '0';
		m[21][41] = '0';
		m[21][42] = '0';
		m[21][43] = '0';
		m[23][34] = '0';
		m[23][41] = '0';
		m[24][35] = '0';
		m[24][36] = '0';
		m[24][39] = '0';
		m[24][40] = '0';
		
	}else if(patron == 17){
		//the r-pentomino
		m[7][31] = '0';
		m[7][32] = '0';
		m[8][30] = '0';
		m[8][31] = '0';
		m[9][31] = '0';
		
	}else if(patron == 18){
		//diehard
		m[10][36] = '0';
		m[11][30] = '0';
		m[11][31] = '0';
		m[12][31] = '0';
		m[12][35] = '0';
		m[12][36] = '0';
		m[12][37] = '0';
		
	}else if(patron == 19){
		//acorn
		m[10][31] = '0';
		m[11][33] = '0';
		m[12][30] = '0';
		m[12][31] = '0';
		m[12][34] = '0';
		m[12][35] = '0';
		m[12][36] = '0';
		
	}else if(patron == 20){
		//gosper glider gun
		m[10][55] = '0';
		m[11][53] = '0';
		m[11][55] = '0';
		m[12][43] = '0';
		m[12][44] = '0';
		m[12][51] = '0';
		m[12][52] = '0';
		m[13][42] = '0';
		m[13][46] = '0';
		m[13][51] = '0';
		m[13][52] = '0';
		m[13][65] = '0';
		m[13][66] = '0';
		m[14][41] = '0';
		m[14][47] = '0';
		m[14][51] = '0';
		m[14][52] = '0';
		m[14][65] = '0';
		m[14][66] = '0';
		m[15][31] = '0';
		m[15][32] = '0';
		m[15][41] = '0';
		m[15][45] = '0';
		m[15][47] = '0';
		m[15][48] = '0';
		m[15][53] = '0';
		m[15][55] = '0';
		m[16][31] = '0';
		m[16][32] = '0';
		m[16][41] = '0';
		m[16][47] = '0';
		m[16][55] = '0';
		m[17][42] = '0';
		m[17][46] = '0';
		m[18][43] = '0';
		m[18][44] = '0';
		
	}else if(patron == 21){
		//simikin glider gun
		m[5][30] = '0';
		m[5][31] = '0';
		m[5][37] = '0';
		m[5][38] = '0';
		m[6][30] = '0';
		m[6][31] = '0';
		m[6][37] = '0';
		m[6][38] = '0';
		m[8][34] = '0';
		m[8][35] = '0';
		m[9][34] = '0';
		m[9][35] = '0';
		m[14][52] = '0';
		m[14][53] = '0';
		m[14][55] = '0';
		m[14][56] = '0';
		m[15][51] = '0';
		m[15][57] = '0';
		m[16][51] = '0';
		m[16][58] = '0';
		m[16][61] = '0';
		m[16][62] = '0';
		m[17][51] = '0';
		m[17][52] = '0';
		m[17][53] = '0';
		m[17][57] = '0';
		m[17][61] = '0';
		m[17][62] = '0';
		m[18][56] = '0';
		m[22][50] = '0';
		m[22][51] = '0';
		m[23][50] = '0';
		m[24][51] = '0';
		m[24][52] = '0';
		m[24][53] = '0';
		m[25][53] = '0';
		
	}else if(patron == 22){
		
		m[10][36] = '0';
		m[11][34] = '0';
		m[11][36] = '0';
		m[11][37] = '0';
		m[12][34] = '0';
		m[12][36] = '0';
		m[13][34] = '0';
		m[14][32] = '0';
		m[15][30] = '0';
		m[15][32] = '0';
		
	}else if(patron == 23){
		
		m[10][30] = '0';
		m[10][31] = '0';
		m[10][32] = '0';
		m[10][34] = '0';
		m[11][30] = '0';
		m[12][33] = '0';
		m[12][34] = '0';
		m[13][31] = '0';
		m[13][32] = '0';
		m[13][34] = '0';
		m[14][30] = '0';
		m[14][32] = '0';
		m[14][34] = '0';
		
	}else if(patron == 24){
		
		m[15][15] = '0';
		m[15][16] = '0';
		m[15][17] = '0';
		m[15][18] = '0';
		m[15][19] = '0';
		m[15][20] = '0';
		m[15][21] = '0';
		m[15][22] = '0';
		m[15][24] = '0';
		m[15][25] = '0';
		m[15][26] = '0';
		m[15][27] = '0';
		m[15][28] = '0';
		m[15][32] = '0';
		m[15][33] = '0';
		m[15][34] = '0';
		m[15][41] = '0';
		m[15][42] = '0';
		m[15][43] = '0';
		m[15][44] = '0';
		m[15][45] = '0';
		m[15][46] = '0';
		m[15][47] = '0';
		m[15][49] = '0';
		m[15][50] = '0';
		m[15][51] = '0';
		m[15][52] = '0';
		m[15][53] = '0';
		
	}
}

int main(){
	srand(time(NULL));
	system("mode 80");


	char cuadricula[30][70] = 
    	{
   		//0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33  34  35  36  37  38  39  40  41  42  43  44  45  46  47  48  49  50  51  52  53  54  55  56  57  58  59  60  61  62  63  64  65  66  67  68  69
/*0*/   {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
/*1*/	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
/*2*/	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
/*3*/	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
/*4*/	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
/*5*/	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
/*6*/	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
/*7*/	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
/*8*/	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
/*9*/	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
/*10*/	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','0',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
/*11*/	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','0',' ','0',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
/*12*/	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','0','0',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
/*13*/	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','0','0',' ',' ',' ',' ','0','0',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','0','0',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
/*14*/	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','0','0',' ',' ',' ',' ','0','0',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','0','0',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
/*15*/	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','0',' ','0',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
/*16*/	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','0',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
/*17*/	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
/*18*/	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
/*19*/	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
/*20*/	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
/*21*/	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
/*22*/	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
/*23*/	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
/*24*/	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
/*25*/	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
/*26*/	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
/*27*/	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
/*28*/	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
/*29*/	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
	
		};
	
	int ciclo = 0;
	int generadorDeCelulas = 2;
	int velocidad = 90;
	int submenu = -1;
	int patron = 0;
	char opcion = '0';

	imprimirMatriz(cuadricula);
	printf("Ciclo: %d\n", ciclo);
	
	printf("\n*Opciones*\n");
	printf("-(G)enerar un patron aleatorio\n");
	printf("-(E)legir un patron predefinido\n");
	printf("-(A)vanzar manualmente un paso en la simulacion\n");
	printf("-(V)elocidad de la simulacion\n");
	printf("-(C)omenzar con la simulacion automatica\n");
	printf("-(S)alir\n");
	
	scanf("%c", &opcion);
	while(opcion != 'g' && opcion != 'e' && opcion != 'a' && opcion != 'v' && opcion != 'c' && opcion != 's'){
		printf("{Error: no puede ingresar esa tecla}\n");
		scanf(" %c", &opcion);
	}
	if(opcion == 's'){
		system("cls||clear");
		imprimirMatriz(cuadricula);
		printf("Ciclo: %d\n", ciclo);
		printf("\nSeguro/a que quiere terminar?\n\n");
		printf("    (S)i              (N)o\n");
		scanf(" %c", &opcion);
		while(opcion != 's' && opcion != 'n'){
			printf("{Error: solo puede ingresar (s) o (n)}\n");
			scanf(" %c", &opcion);
		}
		system("cls||clear");
		imprimirMatriz(cuadricula);
		printf("Ciclo: %d\n", ciclo);
	}
	
	while(opcion != 's'){
		if(opcion == 'g'){
			
			system("cls||clear");
			imprimirMatriz(cuadricula);
			ciclo = 0;
			printf("Ciclo: %d\n", ciclo);
			
			printf("\nIngrese un numero entre 1 y 8\n");
			scanf("%d", &generadorDeCelulas);
			while(generadorDeCelulas < 1 || generadorDeCelulas > 8){
				printf("{Error: no puede ingresar ese numero}\n");
				scanf(" %d", &generadorDeCelulas);
			}
			
			system("cls||clear");
			generarMatriz(cuadricula, 10-generadorDeCelulas);
			imprimirMatriz(cuadricula);
			printf("Ciclo: %d\n", ciclo);
			
		}else if(opcion == 'e'){
			
			while(submenu != 0 && patron == 0){
			
				system("cls||clear");
				imprimirMatriz(cuadricula);
				printf("Ciclo: %d\n", ciclo);
				
				printf("\nElija un sub-menu ingresando el numero correspondiente:\n\n");
				printf("0.Volver\n");
				printf("1.Vidas estaticas\n");
				printf("2.Osciladores\n");
				printf("3.Naves espaciales\n");
				printf("4.Methuselahs\n");
				printf("5.Disparadores\n");
				printf("6.Infinitos\n\n");
				
				printf("Elegir: ");
				scanf("%d", &submenu);
				while(submenu < 0 || submenu > 6){
					printf("{Error: no puede ingresar ese numero}\n");
					scanf(" %d", &submenu);
				}
				
				if(submenu == 1){
					system("cls||clear");
					printf("\nElija un patron ingresando el numero correspondiente:\n\n");
					
					printf("*-------------------*\n");
					printf("|  Vidas estaticas  |\n");
					printf("*-------------------*\n\n");
					
					printf("0.volver\n\n");
	
					printf("1.block:\n\n");
					printf("  00\n");
					printf("  00\n\n");
				
					printf("2.bee-hive:\n\n");
					printf("   00\n");
					printf("  0  0\n");
					printf("   00\n\n");
				
					printf("3.loaf:\n\n");
					printf("   00\n");
					printf("  0  0\n");
					printf("   0 0\n");
					printf("    0\n\n");
				
					printf("4.boat:\n\n");
					printf("  00\n");
					printf("  0 0\n");
					printf("   0\n\n");
				
					printf("5.tub:\n\n");
					printf("   0\n");
					printf("  0 0\n");
					printf("   0\n\n");
					
					printf("Elegir: ");
					scanf("%d", &patron);
					while(patron < 0 || patron > 5){
						printf("{Error: no puede ingresar ese numero}\n");
						scanf(" %d", &patron);
					}
					
					if(patron == 0)
						submenu = -1;
					else
						ciclo = 0;
					
				}else if(submenu == 2){
					system("cls||clear");
					printf("\nElija un patron ingresando el numero correspondiente:\n\n");
					
					printf("*-------------------*\n");
					printf("|  Osciladores      |\n");
					printf("*-------------------*\n\n");
					
					printf("0.Volver\n\n");
					
					printf("6.blinker(2 estados):\n\n");
					printf("   0\n");
					printf("   0\n");
					printf("   0\n\n");
					
					printf("7.toad(2 estados):\n\n");
					printf("   000\n");
					printf("  000\n\n");
					
					printf("8.beacon(2 estados):\n\n");
					printf("  00\n");
					printf("  00\n");
					printf("    00\n");
					printf("    00\n\n");
					
					printf("9.pulsar(3 estados):\n\n");
					printf("    000   000\n");
					printf("               \n");
					printf("  0    0 0    0\n");
					printf("  0    0 0    0\n");
					printf("  0    0 0    0\n");
					printf("    000   000\n");
					printf("               \n");
					printf("    000   000\n");
					printf("  0    0 0    0\n");
					printf("  0    0 0    0\n");
					printf("  0    0 0    0\n");
					printf("               \n");
					printf("    000   000\n\n");
					
					printf("10.pentadecathlon(15 estados):\n\n");
					printf("  000\n");
					printf("  0 0\n");
					printf("  000\n");
					printf("  000\n");
					printf("  000\n");
					printf("  000\n");
					printf("  0 0\n");
					printf("  000\n\n");
					
					printf("Elegir: ");
					scanf("%d", &patron);
					while((patron < 6 && patron != 0) || patron > 10){
						printf("{Error: no puede ingresar ese numero}\n");
						scanf(" %d", &patron);
					}
					
					if(patron == 0)
						submenu = -1;
					else
						ciclo = 0;
					
				}else if(submenu == 3){
					system("cls||clear");
					printf("\nElija un patron ingresando el numero correspondiente:\n\n");
					
					printf("*-------------------*\n");
					printf("|  Naves espaciales |\n");
					printf("*-------------------*\n\n");
					
					printf("0.Volver\n\n");
					
					printf("11.glider(4 estados):\n\n");
					printf("    0\n");
					printf("  0 0\n");
					printf("   00\n\n");
					
					printf("12.light-weight spaceship(4 estados):\n\n");
					printf("   00\n");
					printf("  0000\n");
					printf("  00 00\n");
					printf("    00\n\n");
					
					printf("13.middle-weitght spaceship(4 estados):\n\n");
					printf("   000\n");
					printf("  00000\n");
					printf("  000 00\n");
					printf("     00\n\n");
					
					printf("14.heavy-weight spaceship(4 estados):\n\n");
					printf("   0000\n");
					printf("  000000\n");
					printf("  0000 00\n");
					printf("      00\n\n");
					
					printf("15.copperhead:\n\n");
					printf("   00  00\n");
					printf("     00\n");
					printf("     00\n");
					printf("  0 0  0 0\n");
					printf("  0      0\n");
					printf("\n");
					printf("  0      0\n");
					printf("   00  00\n");
					printf("    0000\n");
					printf("\n");
					printf("     00\n");
					printf("     00\n\n");
					
					printf("16.lobster\n\n");
					printf("   0            0\n");
					printf("  0 0          0 0\n");
					printf("   0            0\n");
					printf("   0            0\n");
					printf("    0   0000   0\n");
					printf("        0000\n");
					printf("    0000    0000\n");
					printf("\n");
					printf("      0      0\n");
					printf("       00  00\n\n");
					
					printf("Elegir: ");
					scanf("%d", &patron);
					while((patron < 11 && patron != 0) || patron > 16){
						printf("{Error: no puede ingresar ese numero}\n");
						scanf(" %d", &patron);
					}
					
					if(patron == 0)
						submenu = -1;
					else
						ciclo = 0;
					
				}else if(submenu == 4){
					system("cls||clear");
					printf("\nElija un patron ingresando el numero correspondiente:\n\n");
					
					printf("*-------------------*\n");
					printf("|  Methuselahs      |\n");
					printf("*-------------------*\n\n");
					
					printf("0.Volver\n\n");
					
					printf("17.the r-pentomino:\n\n");
					printf("   00\n");
					printf("  00\n");
					printf("   0\n\n");
					
					printf("18.diehard:\n\n");
					printf("        0\n");
					printf("  00\n");
					printf("   0   000\n\n");
					
					printf("19.acorn:\n\n");
					printf("   0\n");
					printf("     0\n");
					printf("  00  000\n\n");
					
					printf("Elegir: ");
					scanf("%d", &patron);
					while((patron < 17 && patron != 0) || patron > 19){
						printf("{Error: no puede ingresar ese numero}\n");
						scanf(" %d", &patron);
					}
					
					if(patron == 0)
						submenu = -1;
					else
						ciclo = 0;
					
				}else if(submenu == 5){
					system("cls||clear");
					printf("\nElija un patron ingresando el numero correspondiente:\n\n");
					
					printf("*-------------------*\n");
					printf("|  Disparadores     |\n");
					printf("*-------------------*\n\n");
					
					printf("0.Volver\n\n");
					
					printf("20.gosper glider gun:\n\n");
					printf("                         0\n");
					printf("                       0 0\n");
					printf("             00      00            \n");
					printf("            0   0    00            00\n");
					printf("           0     0   00            00\n");
					printf(" 00        0   0 00    0 0\n");
					printf(" 00        0     0       0\n");
					printf("            0   0\n");
					printf("             00\n\n");
					
					printf("21.simikin glider gun:\n\n");
					printf("  00     00***********\n");
					printf("  00     00\n");
					printf("           \n");
					printf("      00\n");
					printf("      00\n");
					printf("           \n\n\n\n");
					printf("                        00 00\n");
					printf("                       0     0\n");
					printf("                       0      0  00\n");
					printf("                       000   0   00\n");
					printf("                            0\n");
					printf("           \n\n\n");
					printf("                      00\n");
					printf("                      0\n");
					printf("                       000\n");
					printf("                         0\n\n");
					
					printf("Elegir: ");
					scanf("%d", &patron);
					while((patron < 20 && patron != 0) || patron > 21){
						printf("{Error: no puede ingresar ese numero}\n");
						scanf(" %d", &patron);
					}
					
					if(patron == 0)
						submenu = -1;
					else
						ciclo = 0;
					
				}else if(submenu == 6){
					system("cls||clear");
					printf("\nElija un patron ingresando el numero correspondiente:\n\n");
					
					printf("*-------------------*\n");
					printf("|  Infinitos        |\n");
					printf("*-------------------*\n\n");
					
					printf("0.Volver\n\n");
					
					printf("22.\n\n");
					printf("        0\n");
					printf("      0 00\n");
					printf("      0 0\n");
					printf("      0\n");
					printf("    0\n");
					printf("  0 0\n\n");
					
					printf("23.\n\n");
					printf("  000 0\n");
					printf("  0\n");
					printf("     00\n");
					printf("   00 0\n");
					printf("  0 0 0\n\n");
					
					printf("24.\n\n");
					printf("  00000000 00000   000      0000000 00000\n\n");
					
					printf("Elegir: ");
					scanf("%d", &patron);
					while((patron < 22 && patron != 0) || patron > 24){
						printf("{Error: no puede ingresar ese numero}\n");
						scanf(" %d", &patron);
					}
					
					if(patron == 0)
						submenu = -1;
					else
						ciclo = 0;
						
				}	
			}
			
			system("cls||clear");
			generarPatron(cuadricula, patron);
			submenu = -1;
			patron = 0;
			imprimirMatriz(cuadricula);
			printf("Ciclo: %d\n", ciclo);
			
		}else if(opcion == 'a'){
			
			system("cls||clear");
			simular(cuadricula);
			imprimirMatriz(cuadricula);
			ciclo++;
			printf("Ciclo: %d\n", ciclo);
			
		}else if(opcion == 'v'){
			
			system("cls||clear");
			imprimirMatriz(cuadricula);
			printf("Ciclo: %d\n", ciclo);
			
			printf("\nIngrese un numero entre 0 y 5\n");
			scanf("%d", &velocidad);
			while(velocidad < 0 || velocidad > 5){
				printf("{Error: no puede ingresar ese numero}\n");
				scanf(" %d", &velocidad);
			}
			velocidad *= 200;
			
			system("cls||clear");
			imprimirMatriz(cuadricula);
			printf("Ciclo: %d\n", ciclo);
			
		}else if(opcion == 'c'){
			
			bool pausar = false;
			char key;
			
			while(!pausar){
				
				if(kbhit()){
					key = getch();
					if(key == 'p')
						pausar = true;
				}
				
				msleep(1000-velocidad);
				
				system("cls||clear");
				simular(cuadricula);
				imprimirMatriz(cuadricula);
				
				ciclo++;
				printf("Ciclo: %d\n", ciclo);
				printf("\nPresionar (p) para detener la simulacion...\n");
			}
			
			system("cls||clean");
			imprimirMatriz(cuadricula);
			printf("Ciclo: %d\n", ciclo);
		}
		
		printf("\n*Opciones*\n");
		printf("-(G)enerar un patron aleatorio\n");
		printf("-(E)legir un patron predefinido\n");
		printf("-(A)vanzar manualmente un paso en la simulacion\n");
		printf("-(V)elocidad de la simulacion\n");
		printf("-(C)omenzar con la simulacion automatica\n");
		printf("-(S)alir\n");
	
		scanf(" %c", &opcion);
		while(opcion != 'g' && opcion != 'e' && opcion != 'a' && opcion != 'v' && opcion != 'c' && opcion != 's'){
			printf("{Error: no puede ingresar esa tecla}\n");
			scanf(" %c", &opcion);
		}
		if(opcion == 's'){

			system("cls||clear");
			imprimirMatriz(cuadricula);
			printf("Ciclo: %d\n", ciclo);
			
			printf("\nSeguro/a que quiere terminar?\n\n");
			printf("    (S)i              (N)o\n");
			
			scanf(" %c", &opcion);
			while(opcion != 's' && opcion != 'n'){
				printf("{Error: solo puede ingresar (s) o (n)}\n");
				scanf(" %c", &opcion);
			}
			
			system("cls||clear");
			imprimirMatriz(cuadricula);
			printf("Ciclo: %d\n", ciclo);
		}
	}
	
	printf("\nAdios!");
	
	return 0;
}
