/*
 * Othello.cpp
 *
 *  Created on: Jun 17, 2021
 *      Author: Treah
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

	Player player2(playerName,pieceColor);
	numPlayer = 1;
	size = 8;

}

Othello::Othello(string player1Name, char player1PieceColor, string player2Name, char player2PieceColor){

	Player player1(player1Name,player1PieceColor);
	Player player2(player2Name,player2PieceColor);
	numPlayer = 2;
	size = 8;

}

void Othello::makemat(){

	int rMiddle = size / 2;
	int lMiddle = size / 2;

	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; i++){
			if(i == lMiddle && j == lMiddle){
				board[i][j] = player1.piece;
			}
			else if(i == rMiddle && j == lMiddle){
				board[i][j] = player2.piece;
			}
			else if(i == lMiddle && j == rMiddle){
				board[i][j] = player2.piece;
			}
			else if(i == rMiddle && j == rMiddle){
				board[i][j] = player1.piece;
			}
			else{
				board[i][j] = ' ';
			}
		}
	}


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
