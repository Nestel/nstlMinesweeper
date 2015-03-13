#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FIELD_SIZE 8
#define TOTAL_NUM_OF_MINES 10

typedef struct {
	int value;
	//basically a boolean .. values 0 and 1
	int uncovered;
	int flag;
}fieldPos;

fieldPos field[FIELD_SIZE][FIELD_SIZE];

void generateField() {
	int i, j;
	//initialize the field
	for ( i = 0; i < FIELD_SIZE; i++ ) {
		for ( j = 0; j < FIELD_SIZE; j++ ) {
			field[i][j].value = 0;
			field[i][j].uncovered = 0;
			field[i][j].flag = 0;
		}
	}
}

/*
	plces a random mine on the field
*/
void placeRandomMine() {
	int randomI, randomJ;
	//generate random i and j coords (x and y coords in the field)
	do {
		randomI = rand()%FIELD_SIZE;
		randomJ = rand()%FIELD_SIZE;
	}while ( field[randomI][randomJ].value == -1 );

	field[randomI][randomJ].value = -1;
}

void printField() {
	int i, j;
	system ("clear");
	printf("   1  2  3  4  5  6  7  8 \n");
	printf("  -----------------------\n");
	for ( i = 0; i < FIELD_SIZE; i++ ) {
		printf("%i|", i+1);
		for ( j = 0; j < FIELD_SIZE; j++ ) {
			if (field[i][j].uncovered == 0) {
				if ( field[i][j].flag == 1 ) {
					printf(" f|");
				}
				else {
					printf("  |");
				}
			}
			else {
				printf("%2i|", field[i][j].value);
			}
		}
		printf("\n  -----------------------\n");
	}
}

void testPrintField() {
	int i, j;
	system ("clear");
	printf(" 1 2 3 4 5 6 7 8 \n");
	printf(" ----------------\n");
	for ( i = 0; i < FIELD_SIZE; i++ ) {
		printf("%i|", i+1);
		for ( j = 0; j < FIELD_SIZE; j++ ) {
			printf("%2i", field[i][j].value);
		}
		printf("|\n");
	}
	printf(" ----------------\n");
	printf("Position to be tested: ");
}

void checkSurroundingPositions(int x, int y) {
	//if i am in the upper row 
	if ( x == 0 ) {
		//if i am in the first column
		if ( y == 0 ) {
			if ( field[x+1][y].value == -1 ) {
				field[x][y].value++;
			}
			if ( field[x+1][y+1].value == -1 ) {
				field[x][y].value++;
			}
			if ( field[x][y+1].value == -1 ) {
				field[x][y].value++;
			}
		}
		//if i am in the last column
		else if ( y == FIELD_SIZE - 1 ) {
			if ( field[x+1][y].value == -1 ) {
				field[x][y].value++;
			}
			if ( field[x+1][y-1].value == -1 ) {
				field[x][y].value++;
			}
			if ( field[x][y-1].value == -1 ) {
				field[x][y].value++;
			}
		}
		else {
			if ( field[x+1][y].value == -1 ) {
				field[x][y].value++;
			}
			if ( field[x+1][y-1].value == -1 ) {
				field[x][y].value++;
			}
			if ( field[x+1][y+1].value == -1 ) {
				field[x][y].value++;
			}
			if ( field[x][y-1].value == -1 ) {
				field[x][y].value++;
			}
			if ( field[x][y+1].value == -1 ) {
				field[x][y].value++;
			}
		} 
	}
	//if i am in the bottom row
	else if ( x == FIELD_SIZE -1 ) {
		//if i am in the first column
		if ( y == 0 ) {
			if ( field[x-1][y].value == -1 ) {
				field[x][y].value++;
			}
			if ( field[x-1][y+1].value == -1 ) {
				field[x][y].value++;
			}
			if ( field[x][y+1].value == -1 ) {
				field[x][y].value++;
			}
		}
		//if i am in the last column
		else if ( y == FIELD_SIZE - 1 ) {
			if ( field[x-1][y].value == -1 ) {
				field[x][y].value++;
			}
			if ( field[x-1][y-1].value == -1 ) {
				field[x][y].value++;
			}
			if ( field[x][y-1].value == -1 ) {
				field[x][y].value++;
			}
		}
		else {
			if ( field[x-1][y].value == -1 ) {
				field[x][y].value++;
			}
			if ( field[x-1][y-1].value == -1 ) {
				field[x][y].value++;
			}
			if ( field[x-1][y+1].value == -1 ) {
				field[x][y].value++;
			}
			if ( field[x][y-1].value == -1 ) {
				field[x][y].value++;
			}
			if ( field[x][y+1].value == -1 ) {
				field[x][y].value++;
			}
		} 
	} 
	//if i am in the middle rows
	else {
		//if i am in the first column
		if ( y == 0 ) {
			if ( field[x-1][y].value == -1 ) {
				field[x][y].value++;
			}
			if ( field[x-1][y+1].value == -1 ) {
				field[x][y].value++;
			}
			if ( field[x][y+1].value == -1 ) {
				field[x][y].value++;
			}
			if ( field[x+1][y+1].value == -1 ) {
				field[x][y].value++;
			}
			if ( field[x+1][y].value == -1 ) {
				field[x][y].value++;
			}
		}
		//if i am in the last column
		else if ( y == FIELD_SIZE - 1 ) {
			if ( field[x-1][y].value == -1 ) {
				field[x][y].value++;
			}
			if ( field[x-1][y-1].value == -1 ) {
				field[x][y].value++;
			}
			if ( field[x][y-1].value == -1 ) {
				field[x][y].value++;
			}
			if ( field[x+1][y-1].value == -1 ) {
				field[x][y].value++;
			}
			if ( field[x+1][y].value == -1 ) {
				field[x][y].value++;
			}
		}
		else {
			if ( field[x-1][y-1].value == -1 ) {
				field[x][y].value++;
			}
			if ( field[x-1][y].value == -1 ) {
				field[x][y].value++;
			}
			if ( field[x-1][y+1].value == -1 ) {
				field[x][y].value++;
			}
			if ( field[x][y-1].value == -1 ) {
				field[x][y].value++;
			}
			if ( field[x][y+1].value == -1 ) {
				field[x][y].value++;
			}
			if ( field[x+1][y-1].value == -1 ) {
				field[x][y].value++;
			}
			if ( field[x+1][y].value == -1 ) {
				field[x][y].value++;
			}
			if ( field[x+1][y+1].value == -1 ) {
				field[x][y].value++;
			}
		} 
	}
}

/*
	goes through the field, and sets the values
	according to how many mines surround the position
*/
void adjustFieldToMines() {
	int i, j, k, l;
	for ( i = 0; i < FIELD_SIZE; i++ ) {
		for ( j = 0; j < FIELD_SIZE; j++ ) {
			if ( field[i][j].value != -1 ) {	
				checkSurroundingPositions(i, j);
			}
		}
	}
}

void uncoverField(int x, int y) {

	if ( field[x][y].value == 0 && field[x][y].uncovered == 0 ) {
		field[x][y].uncovered = 1;
		//if i am in the upper row 
		if ( x == 0 ) {
			//if i am in the first column
			if ( y == 0 ) {
				if ( field[x+1][y].value >= 0 ) {
					uncoverField(x+1,y);
				}
				if ( field[x+1][y+1].value >= 0 ) {
					uncoverField(x+1,y+1);
				}
				if ( field[x][y+1].value >= 0 ) {
					uncoverField(x,y+1);
				}
			}
			//if i am in the last column
			else if ( y == FIELD_SIZE - 1 ) {
				if ( field[x+1][y].value >= 0 ) {
					uncoverField(x+1,y);
				}
				if ( field[x+1][y-1].value >= 0 ) {
					uncoverField(x+1,y-1);
				}
				if ( field[x][y-1].value >= 0 ) {
					uncoverField(x,y-1);
				}
			}
			else {
				if ( field[x+1][y].value >= 0 ) {
					uncoverField(x+1,y);
				}
				if ( field[x+1][y-1].value >= 0 ) {
					uncoverField(x+1,y-1);
				}
				if ( field[x+1][y+1].value >= 0 ) {
					uncoverField(x+1,y+1);
				}
				if ( field[x][y-1].value >= 0 ) {
					uncoverField(x,y-1);
				}
				if ( field[x][y+1].value >= 0 ) {
					uncoverField(x,y+1);
				}
			} 
		}
		//if i am in the bottom row
		else if ( x == FIELD_SIZE -1 ) {
			//if i am in the first column
			if ( y == 0 ) {
				if ( field[x-1][y].value >= 0 ) {
					uncoverField(x-1,y);
				}
				if ( field[x-1][y+1].value >= 0 ) {
					uncoverField(x-1,y+1);
				}
				if ( field[x][y+1].value >= 0 ) {
					uncoverField(x,y+1);
				}
			}
			//if i am in the last column
			else if ( y == FIELD_SIZE - 1 ) {
				if ( field[x-1][y].value >= 0 ) {
					uncoverField(x-1,y);
				}
				if ( field[x-1][y-1].value >= 0 ) {
					uncoverField(x-1, y-1);
				}
				if ( field[x][y-1].value >= 0 ) {
					uncoverField(x, y-1);
				}
			}
			else {
				if ( field[x-1][y].value >= 0 ) {
					uncoverField(x-1, y);
				}
				if ( field[x-1][y-1].value >= 0 ) {
					uncoverField(x-1, y-1);
				}
				if ( field[x-1][y+1].value >= 0 ) {
					uncoverField(x-1, y+1);
				}
				if ( field[x][y-1].value >= 0 ) {
					uncoverField(x, y-1);
				}
				if ( field[x][y+1].value >= 0 ) {
					uncoverField(x, y+1);
				}
			} 
		} 
		//if i am in the middle rows
		else {
			//if i am in the first column
			if ( y == 0 ) {
				if ( field[x-1][y].value >= 0 ) {
					uncoverField(x-1, y);
				}
				if ( field[x-1][y+1].value >= 0 ) {
					uncoverField(x-1, y+1);
				}
				if ( field[x][y+1].value >= 0 ) {
					uncoverField(x, y+1);
				}
				if ( field[x+1][y+1].value >= 0 ) {
					uncoverField(x+1, y+1);
				}
				if ( field[x+1][y].value >= 0 ) {
					uncoverField(x+1, y);
				}
			}
			//if i am in the last column
			else if ( y == FIELD_SIZE - 1 ) {
				if ( field[x-1][y].value >= 0 ) {
					uncoverField(x-1, y);
				}
				if ( field[x-1][y-1].value >= 0 ) {
					uncoverField(x-1, y-1);
				}
				if ( field[x][y-1].value >= 0 ) {
					uncoverField(x, y-1);
				}
				if ( field[x+1][y-1].value >= 0 ) {
					uncoverField(x+1, y-1);
				}
				if ( field[x+1][y].value >= 0 ) {
					uncoverField(x+1, y);
				}
			}
			else {
				if ( field[x-1][y-1].value >= 0 ) {
					uncoverField(x-1, y-1);
				}
				if ( field[x-1][y].value >= 0 ) {
					uncoverField(x-1, y);
				}
				if ( field[x-1][y+1].value >= 0 ) {
					uncoverField(x-1, y+1);
				}
				if ( field[x][y-1].value >= 0 ) {
					uncoverField(x, y-1);
				}
				if ( field[x][y+1].value >= 0 ) {
					uncoverField(x, y+1);
				}
				if ( field[x+1][y-1].value >= 0 ) {
					uncoverField(x+1, y-1);
				}
				if ( field[x+1][y].value >= 0 ) {
					uncoverField(x+1, y);
				}
				if ( field[x+1][y+1].value >= 0 ) {
					uncoverField(x+1, y+1);
				}
			} 
		}
	}
	else if ( field[x][y].value > 0 ) {
		field[x][y].uncovered = 1;
	}
}

void toggleFlag(int x, int y) {
	if ( field[x][y].uncovered == 0 ) {
		if ( field[x][y].flag == 1 ) {
			field[x][y].flag = 0;
		}
		else {
			field[x][y].flag = 1;
		}
	}
	else {
		printf("YOU CAN'T PLACE A FLAG ON AN UNCOVERED POSITION\n");
	}
}

int checkWin() {
	int i, j;

	for ( i = 0; i < FIELD_SIZE; i++ ) {
		for ( j = 0; j < FIELD_SIZE; j++ ) {
			//if the field is not uncovered and it is not a mine return false
			//because that you haven't won yet .. right ?
			if ( field[i][j].uncovered == 0 && field[i][j].value != -1 ) {
				return 0;
			}
		}
	}
	return 1;
}

int game() {
	int playerAlive = 1, userX, userY, numOfWhileCycles = 0;
	char choice;
	while (playerAlive == 1 && checkWin() == 0) {
		//testPrintField();
		printField();

		do {
			printf("Enter your choice: ");
			if ( numOfWhileCycles > 0 ) {
				printf("WRONG COORDINATES, TRY AGAIN ! \n");
			}
			scanf("%c", &choice );
			if ( choice == 'f' ) {
				printf("Position for the flag to be placed at: ");
			}		
			else {
				printf("Position to be tested: ");
			}
			scanf("%i %i", &userX, &userY);		
			numOfWhileCycles++;
		}while (userX > (FIELD_SIZE) || userX < 1 || userY > (FIELD_SIZE) || userY < 1);
		numOfWhileCycles = 0;
		userX--;
		userY--;

		if ( choice == 'f' ) {
			toggleFlag(userX, userY);		
		}
		else {
			if ( field[userX][userY].value == -1 ) {
				playerAlive = 0;
				printf("YOU DIED. A MINE BLASTED YOUR INTESTINES ALL OVER THE PLACE\n");
				return -1;
			}
			else {
				uncoverField(userX, userY);
			}
		}
		fflush(stdin);
	}
	printf("CONGRATULATION YOU WON MAN ! YOU ROCK !\n");
	return 1;
}



void gameInit() {
	int i;

	generateField();	

	for ( i = 0; i < TOTAL_NUM_OF_MINES; i++ ) {
		placeRandomMine();
	}
	adjustFieldToMines();
}
/*
	how do i do this ?? 
	0 -> no mine
	-1 -> mine
	-2 -> flag
*/
int main() {
	srand(time(0));

	gameInit();

	game();

	return 0;
}



