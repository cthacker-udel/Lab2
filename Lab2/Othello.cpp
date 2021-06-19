/*
 * Othello.cpp
 *
 *  Created on: Jun 17, 2021
 *      Author: Trea & Cameron
 */

#include "Othello.hpp"

Othello::Othello(){

	Player player1("computer",'B');
	Player player2("computer",'O');
	numPlayer = 0;
	size = 8;

}

Othello::Othello(string playerName, char pieceColor){

	char computerPiece;
	if(tolower(pieceColor) != 'b'){
		computerPiece = 'B';
	}
	else if(tolower(pieceColor) != 'o'){
		computerPiece = 'O';
	}

	Player player1Instance("computer",computerPiece);
	Player player2Instance(playerName,pieceColor);
	player1 = player1Instance;
	player2 = player2Instance;
	numPlayer = 1;
	size = 8;

}

Othello::Othello(string player1Name, char player1PieceColor, string player2Name, char player2PieceColor){

	Player iPlayer1(player1Name,player1PieceColor);
	Player iPlayer2(player2Name,player2PieceColor);
	player1 = iPlayer1;
	player2 = iPlayer2;
	numPlayer = 2;
	size = 8;

}

void Othello::makemat(){

	int rMiddle = size / 2;
	int lMiddle = (size / 2)-1;

	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			//cout << "R middle = " << rMiddle << "\nL middle = " << lMiddle << "\nI = " << i << "\nJ = " << j << "\n\n-----";
			if(i == lMiddle && j == lMiddle){
				cout << "\nEntered first if" << endl;
				board[i][j] = player2.piece;
			}
			else if(i == rMiddle && j == lMiddle){
				cout << "entered second if" << endl;
				board[i][j] = player1.piece;
			}
			else if(i == lMiddle && j == rMiddle){
				cout << "entered third if" << endl;
				board[i][j] = player1.piece;
			}
			else if(i == rMiddle && j == rMiddle){
				cout << "entered fourth if" << endl;
				board[i][j] = player2.piece;
			}
			else{
				board[i][j] = ' ';
			}
		}
	}

}

void Othello::printmat(){

	/*
	 *
	 * Adding top layer of print
	 *
	 */

	cout << "\t";
	for(int i = 0; i < size-1; i++){
		cout << i << "\t";
	}
	cout << size-1 << endl;
	int j = 0;
		for(int x = 0; x < size; x++){
			cout << x << "\t";
			for(j = 0; j < size; j++){
				if(board[x][j] == ' '){
					cout << '_' << "\t";
				}
				else{
					cout << board[x][j] << "\t";
				}
			}
			cout << endl;
		}
}

void Othello::placepiece(Player p){

	int x;
	int y;
	while(1){
		cout << "Enter an x coordinate between 0 and " << size-1 << ":";
		cin >> x;
		cout << "Enter an y coordinate between 0 and " << size-1 << ":";
		cin >> y;
		if(x < 0 || y < 0){
			cout << "Enter valid coordinates" << endl;
			continue;
		}
		else if(x > size-1 || y > size-1){
			cout << "Enter valid coordinates" << endl;
			continue;
		}
		else if(board[x][y] != ' '){
			cout << "Piece already on board square" << endl;
			continue;
		}
		else{
			break;
		}
	}
	board[x][y] = p.piece;
	int max = 0;
	vector<pair<pair<int,int>,pair<int,int>>> coords;
	for(int i = 1; i < 9; i++){
		int j = countandflippieces(x,y,p.name,false,i);
		//string direction = i == 1? "up": i == 2? "right-up diag": i == 3? "right": i == 4? "right-down diag": i == 5? "down": i == 6? "left-down diag": i == 7? "left": i == 8? "left-up diag": "neither";
		//cout << "The number of flips found in the " << direction << " direction are : " << j << endl;
		pair<int,int> numFlippedAndDirection;
		numFlippedAndDirection.first = j;
		numFlippedAndDirection.second = i;
		max = fmax(max,j);
		pair<int,int> xAndY;
		xAndY.first = x;
		xAndY.second = y;
		pair<pair<int,int>,pair<int,int>> pushPair;
		pushPair.first = numFlippedAndDirection;
		pushPair.second = xAndY;
		coords.push_back(pushPair);
	}
	vector<pair<pair<int,int>,pair<int,int>>> coordsUpdated;
	for(int i = 0; i < (int)coords.size(); i++){
		if(coords.at(i).first.first == max){
			coordsUpdated.push_back(coords.at(i));
		}
	}
	int randNum = rand() % coordsUpdated.size();
	countandflippieces(x,y,p.name,true,coordsUpdated.at(randNum).first.second);

}


int Othello::countandflippieces(int x, int y, string player, bool flipPieces, int direction){

	/*
	 * Directions:
	 * 	1) up
	 * 	2) right-up diag
	 * 	3) right
	 * 	4) right-down diag
	 * 	5) down
	 * 	6) left-down diag
	 * 	7) left
	 * 	8) left-up diag
	 *
	 */

	//TODO : Tre - implement flipPieces
	/*
	 *
	 * flipPieces - boolean if true, turn all opposite player pieces to current player piece
	 *
	 */
<<<<<<< HEAD
	if(player == player2.name){
		if(board[x][y] == player1.piece){
			while((x>=0) && (x<8) && (y>=0) && (y<0)){
				x+=x;
				y+=y;
				if(board[x][y] == ''){
					flipPieces = false;
				}
				if(board[x][y] == player2.piece){
					flipPieces == true;
				}
			}
			flipPieces = false;
		}
	}

	if(player == player1.name){
		if(board[x][y] == player2.piece){
			while((x>=0) && (x<8) && (y>=0) && (y<0)){
				x+=x;
				y+=y;
				if(board[x][y] == ''){
					flipPieces = false;
				}
				if(board[x][y] == player1.piece){
					flipPieces == true;
				}
			}
			flipPieces = false;
		}
	}
=======
>>>>>>> branch 'master' of https://github.com/cthacker-udel/Lab2.git

	int count = 0;

	if(direction == 1){
		// rows = number -> 0
		// columns = same
		if(player == player1.name){
			for(int i = x-1; i >= 0; i--){
				if(board[i][y] == player2.piece){
					count++;
					if(flipPieces){
						board[i][y] = player1.piece;
					}
					// add in a statement that if flipPieces is true, then change board[i][y] = player1.piece, flip the opposing player piece to current player piece
				}
				if(board[i][y] == player1.piece){
					return count;
				}
				if(board[i][y] == ' '){
					return 0;
				}
			}
			return 0;
		}
		else{
			for(int i = x-1; i >= 0; i--){
				if(board[i][y] == player1.piece){
					count++;
					// add statement
					if(flipPieces){
						board[i][y] = player2.piece;
					}
				}
				if(board[i][y] == player2.piece){
					return count;
				}
				if(board[i][y] == ' '){
					return 0;
				}
			}
			return 0;
		}
	}
	else if(direction == 3){
		// column = increment -> < size
		if(player == player1.name){
			for(int i = y+1; i < size; i++){
				if(board[x][i] == player2.piece){
					count++;
					// add statement
					if(flipPieces){
						board[x][i] = player1.piece;
					}
				}
				if(board[x][i] == player1.piece){
					return count;
				}
				if(board[x][i] == ' '){
					return 0;
				}
			}
			return 0;
		}
		else{
			for(int i = y+1; i < size; i++){
				if(board[x][i] == player1.piece){
					count++;
					// add statement
					if(flipPieces){
						board[x][i] = player2.piece;
					}
				}
				if(board[x][i] == player2.piece){
					return count;
				}
				if(board[x][i] == ' '){
					return 0;
				}
			}
			return 0;
		}
	}
	else if(direction == 5){
		// column = same
		// row = increment
		if(player == player1.name){
			for(int i = x+1; i < size; i++){
				if(board[i][y] == player2.piece){
					count++;
					// add statement
					if(flipPieces){
						board[i][y] = player1.piece;
					}
				}
				if(board[i][y] == player1.piece){
					return count;
				}
				if(board[i][y] == ' '){
					return 0;
				}
			}
			return 0;
		}
		else{
			for(int i = x+1; i < size; i++){
				if(board[i][y] == player1.piece){
					count++;
					// add statement
					if(flipPieces){
						board[i][y] = player2.piece;
					}
				}
				if(board[i][y] == player2.piece){
					return count;
				}
				if(board[i][y] == ' '){
					return 0;
				}
			}
			return 0;
		}
	}
	else if(direction == 7){
		// column - decrement
		// row - same
		if(player == player1.name){
			for(int i = y-1; i >= 0; i--){
				if(board[x][i] == player2.piece){
					count++;
					// add statement
					if(flipPieces){
						board[x][i] = player1.piece;
					}
				}
				if(board[x][i] == player1.piece){
					return count;
				}
				if(board[x][i] == ' '){
					return 0;
				}
			}
			return 0;
		}
		else{
			for(int i = y-1; i >= 0; i--){
				if(board[x][i] == player1.piece){
					count++;
					// add statement
					if(flipPieces){
						board[x][i] = player2.piece;
					}
				}
				if(board[x][i] == player2.piece){
					return count;
				}
				if(board[x][i] == ' '){
					return 0;
				}
			}
			return 0;
		}
	}
	else if(direction == 2){
		// space ahead is row-1, column+1, column bounds < size, row >= 0
		if(player == player1.name){
			for(int i = x-1,j = y+1; i >= 0 && j < size; j++, i--){
				if(board[i][j] == player2.piece){
					count++;
					// add statement
					if(flipPieces){
						board[i][j] = player1.piece;
					}
				}
				if(board[i][j] == player1.piece){
					return count;
				}
				if(board[i][j] == ' '){
					return 0;
				}
			}
			return 0;
		}
		else{
			for(int i = x-1, j = y+1; i >= 0 && j < size; j++, i--){
				if(board[i][j] == player1.piece){
					count++;
					// add statement
					if(flipPieces){
						board[i][j] = player2.piece;
					}
				}
				if(board[i][j] == player2.piece){
					return count;
				}
				if(board[i][j] == ' '){
					return 0;
				}
			}
			return 0;
		}
	}
	else if(direction == 4){
		if(player == player1.name){
			for(int i = x+1, j = y+1; i < size && j < size; j++, i++){
				if(board[i][j] == player2.piece){
					count++;
					// add statement
					if(flipPieces){
						board[i][j] = player1.piece;
					}
				}
				if(board[i][j] == player1.piece){
					return count;
				}
				if(board[i][j] == ' '){
					return 0;
				}
			}
			return 0;
		}
		else{
			for(int i = x+1, j = y+1; i < size && j < size; j++, i++){
				if(board[i][j] == player1.piece){
					count++;
					// add statement
					if(flipPieces){
						board[i][j] = player2.piece;
					}
				}
				if(board[i][j] == player2.piece){
					return count;
				}
				if(board[i][j] == ' '){
					return 0;
				}
			}
			return 0;
		}
	}
	else if(direction == 6){
		if(player == player1.name){
			for(int i = x+1, j = y-1; i < size && j >= 0; j--, i++){
				if(board[i][j] == player2.piece){
					count++;
					// add statement
					if(flipPieces){
						board[i][j] = player1.piece;
					}
				}
				if(board[i][j] == player1.piece){
					return count;
				}
				if(board[i][j] == ' '){
					return 0;
				}
			}
			return 0;
		}
		else{
			for(int i = x+1, j = y-1; i < size && j >= 0; j--, i++){
				if(board[i][j] == player1.piece){
					count++;
					// add statement
					if(flipPieces){
						board[i][j] = player2.piece;
					}
				}
				if(board[i][j] == player2.piece){
					return count;
				}
				if(board[i][j] == ' '){
					return 0;
				}
			}
			return 0;
		}
	}
	else if(direction == 8){
		if(player == player1.name){
			for(int i = x-1, j = y-1; i >= 0 && j >= 0; j--, i--){
				if(board[i][j] == player2.piece){
					count++;
					// add statement
					if(flipPieces){
						board[i][j] = player1.piece;
					}
				}
				if(board[i][j] == player1.piece){
					return count;
				}
				if(board[i][j] == ' '){
					return 0;
				}
			}
			return 0;
		}
		else{
			for(int i = x-1, j = y-1; i >= 0 && j >= 0; j--, i--){
				if(board[i][j] == player1.piece){
					count++;
					// add statement
					if(flipPieces){
						board[i][j] = player2.piece;
					}
				}
				if(board[i][j] == player2.piece){
					return count;
				}
				if(board[i][j] == ' '){
					return 0;
				}
			}
			return 0;
		}
	}

	/*
		 * Directions:
		 * 	1) up ------> check
		 * 	2) right-up diag -----> check
		 * 	3) right ------> check
		 * 	4) right-down diag ----> check
		 * 	5) down ------> check
		 * 	6) left-down diag ----> check
		 * 	7) left -----> check
		 * 	8) left-up diag
		 *
		 */


	return 0;


}

void Othello::ckwin(){

	int player1Count = 0;
	int player2Count = 0;

	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(board[i][j] == player1.piece){
				player1Count++;
			}
			else if(board[i][j] == player2.piece){
				player2Count++;
			}
		}
	}
	string result = player1Count > player2Count? "Player 1 won with: " + to_string(player1Count) + " versus " + to_string(player2Count) : player2Count > player1Count? "Player 2 won with: " + to_string(player2Count) + " versus " + to_string(player1Count): "Tie";
	cout << result;



}


void Othello::compplacepiece(Player p){

	vector<pair<pair<int,int>,pair<int,int>>> coords;
	for(int d = 1; d < 9; d++){
		for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
				int numFlip = countandflippieces(i,j,p.name,false,d);
				pair<int,int> coordPair;
				coordPair.first = i;
				coordPair.second = j;
				pair<pair<int,int>,pair<int,int>> coordDictionary;
				coordDictionary.first.first = d;
				coordDictionary.first.second = numFlip;

				// [(<direction,numFlipped>,<x,y>)],[(<direction,numFlipped>,<x,y>)]

				coordDictionary.second = coordPair;
				coords.push_back(coordDictionary);
			}
		}
	}
	int max = 0;
	for(int i = 0; i < (int)coords.size(); i++){
		max = fmax(max,coords.at(i).first.second);
	}
	if(max == 0){
		// player forfeits turn
	}
	else{
		vector<pair<pair<int,int>,pair<int,int>>> validCoords;
		for(int i = 0; i < (int)coords.size(); i++){
			if(coords.at(i).first.second == max){
				validCoords.push_back(coords.at(i));
			}
		}
		int randomCoord = rand() % validCoords.size();

		int randomXCoord = validCoords.at(randomCoord).second.first;
		int randomYCoord = validCoords.at(randomCoord).second.second;
		cout << "\nRandom coords selected are : " << randomXCoord << "," << randomYCoord << endl;

		countandflippieces(validCoords.at(randomCoord).second.first,validCoords.at(randomCoord).second.second,p.name,true,validCoords.at(randomCoord).first.first);
	}

}



void Othello::playGame(){

	makemat();
	printmat();
	bool play = true;
	int fullsqrs = 0;
	Player p = player1;
	bool whichp = true;
	bool turn = true;

	if(rand() % 2 == 0){ // p1 plays first
		p = player2;
		turn = false;
		whichp = false;
	}

	while((play) && (fullsqrs < 64)){
		cout << endl << p.name << " (" << p.piece << ") choose your square: " << endl;
		if((numPlayer == 2) || ((numPlayer == 1) && turn)){
			placepiece(p);
			cout << "\nPlayer placing piece\n" << endl;
		}
		else if((numPlayer == 0) || ((numPlayer == 1) && (turn == false))){
			compplacepiece(p);
			cout << "\nComputer placing piece\n" << endl;
		}
		turn = !turn;
		printmat();
		if(whichp){
			p = player2;
			whichp = false;
		}
		else{
			p = player1;
			whichp = true;
		}
		fullsqrs += 1;
	}
	ckwin();

}






/*

const char blank = '';
const char pieceB = 'B';
const char pieceW = 'O';

void makemat(){
	char mat[8][8] = {{'','','','','','','',''},{'','','','','','','',''},{'','','','','','','',''},
			{'','','',pieceB,pieceW,'','',''},{'','','',pieceW,pieceB,'','',''},
			{'','','','','','','',''},{'','','','','','','',''},{'','','','','','','',''}};


}

void printmat(){
	cout<< makemat() << endl;
}

void Othello::playGame(){
	makemat();
	printmat();
	bool play = true;
	int fullsqrs = 0;
	player p = p1;
	bool whichp = true;
	bool turn = true;
	if (rand()%2 == 0) { // p1 plays first
		p = p2;
		turn = false;
		whichp = false;
	}

	while ((play) && (fullsqrs < 64)){
		cout << endl << p.name <<" ("<<p.piece<<") choose your square: "<<endl;
		if ((numplayers == 2) || ((numplayers == 1) && turn)){
		placepiece(p);
		}
		else if ((numplayers == 0) || ((numplayers == 1) && (turn == false))){
		compplacepiece(p);
		}
		turn = !turn;
		printmat();
		if (whichp) {
		p = p2;
		whichp = false;
		}
		else {
		p=p1;
		whichp = true;
		}
		fullsqrs+=1;
		}
		ckwin();

	}

*/
