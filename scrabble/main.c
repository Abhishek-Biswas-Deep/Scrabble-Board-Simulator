#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//Scrabble word game program.
int main() {

	//The size of the board.
	int n;
	
	scanf("%d", &n);
	
	//Denoting the number of words to place.
	int w;

	scanf("%d", &w);

	//Allocating a 2D array.
	//Initializing the board with . before placing any words.
	char board[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++) {
			board[i][j] = '.';
		}
	}

	//Asking the user to type in the position and direction of the letter.
	for(int i = 0; i < w; i++) {
		int x, y;
		char d;
		char s[50];
		scanf("%d %d %c %s", &x, &y, &d, s);
		
		int len = strlen(s);
		
		//Asking if the direction is horizontal.
		if(d == 'H') {
			//checking if the word extends past the edge of the board.
			if(x + len > n) {
				printf("Invalid word placement: (%d,%d) %c, %s\n", x, y, d, s); 
				continue;
			}
		        
			//This whole process is checking if the word does not cross one or more other words.
			//It also checkes if there is a letter mismatch at a crossing-point of two words.
			bool valid = false;
			if(i == 0) {
				valid = true;
			}
			else {
				for(int j = 0; j < len; j++) {
					if(board[y][x + j] == s[j]) {
						valid = true;
					} else if(board[y][x + j] != '.') {
						valid = false;
						break;
					}

				}
			}
			if (valid == false) {
				printf("Invalid word placement: (%d,%d) %c, %s\n", x, y, d, s);
				continue;
			}
			for(int k = 0; k < len; k++) {
				board[y][x + k] = s[k];
			}

		//Asking if the direction is vertical.
		} else if (d == 'V') {

			//Checking if the word extends past the edge of the board.
			if(y + len > n) {
				printf("Invalid word placement: (%d,%d) %c, %s\n", x, y, d, s);
				continue;
			}

			//This whole process is checking if the word does not cross one or more other words.
			//It also checks if there is a letter mismatch at a crossing-point of two words.
			bool valid = false;
			if(i == 0) {
				valid = true;
			}
			else {
			for(int j = 0; j < len; j++) {
				if(board[y + j][x] == s[j]) {
					valid = true;
				} else if(board[y + j][x] != '.') {
					valid = false;
					break;
				}
			}
			}
			if(valid == false) {
				printf("Invalid word placement: (%d,%d) %c, %s\n", x, y, d, s);
				continue;
			}
			for(int k = 0; k < len; k++) {
				board[y + k][x] = s[k];
			}
		}
	}

	//This piece of code is printing the board.
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			printf("%c", board[i][j]);
		}
		printf("\n");
	}

	//Asking the user for f, which is the number of searches to perform.
	int f;
	scanf("%d", &f);

	//Looping through the number of searches.
	for(int i = 0; i < f; i++) {

		//Asking the user for the integer denoting the number of blank spaces that the word needs before the letter.
		int b;
	
		//Asking the user for the character l that the user wants to put in the board.
		char l;

		//Asking the user for the integer denoting the number of blank spaces that the word needs after the letter.
		int a;
	
		scanf("%d %c %d", &b, &l, &a);


		int x;
		int y;
		
		//looping through the board.
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < n; k++) {
				
				//checking if the board has the letter.
				//if found then the letter is identified.
				if(board[j][k] == l){
					x = k;
					y = j;

					//if there are free spaces to the left before the letter, then the number of spaces are printed.
					if (x - b >= 0 && x + a < n) {
						bool valid = true;
						//then it checks if there are . or else the letter goes out of the board.
						for(int l = 1; l <= b; l++) {
							if(board[y][x-l] != '.') {
								valid = false;
								break;
							}

						}
					
						//this checks if there are free spaces to the right before the letter.
						for(int m = 1; m <= a; m++) {
							if(board[y][x+m] != '.') {
								valid = false;
								break;
							}
						}

						if(valid == true) {
							printf("Place horizontally at (%d,%d)\n", x, y);
						}
					


					} 

					//this checks if there are free spaces above or below the letter.
					//then it checks if the letter goes out of the board or not.
					if(y - b >= 0 && y + a < n) {
						bool valid = true;
						for(int l = 1; l <= b; l++) {
							if(board[y-l][x] != '.') {
								valid = false;
								break;
							}
						}

						for(int m = 1; m <= a; m++) {
							if(board[y+m][x] != '.') {
								valid = false;
								break;
							}
						}

						if(valid == true) {
							printf("Place vertically at (%d,%d)\n", x, y);
						}

					}
				}

			}
		}
	}

	return 0;

}	
