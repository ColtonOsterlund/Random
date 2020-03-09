import java.util.Scanner;

/**
 * Provides data fields and methods to create a player object for the game of Tic-Tac-Toe.
 * @author Colton Osterlund
 * @version 1.0
 * @since January 26, 2019
 *
 */
public abstract class Player {
	/**
	 * Name of the player.
	 */
	protected String name;
	/**
	 * Member variable to be set to an instance of class Board to be displayed & updated.
	 */
	protected Board board;
	/**
	 * Member variable to be set to the opponent instance of class Player
	 */
	protected Player opponent;
	/**
	 * Set to either 'X' or 'O' depending on the instance of Player
	 */
	protected char mark;
	/**
	 * Scanner that reads the row and column input values of the player
	 */
	protected Scanner scan;
	
	/**
	 * Default constructor for Player, sets everything to null
	 */
	protected Player() {} //this can be protected since you will never have an object of just Player 
	
	/**
	 * Constructor for class Player.
	 * Sets name and mark to the respective incoming arguments.
	 * @param name Name to be set to name member variable.
	 * @param mark Mark to be set to mark member variable.
	 */
	protected Player(String name, char mark) { //this can be protected since you will never have an object of just Player
		this.name = name;
		this.mark = mark;
	}
	
	
	protected abstract void play();

	
	protected abstract void makeMove();
	
	/**
	 * Sets opponent member variable to an instance of class Person taken in as an argument.
	 * @param opp Instance of class Player which is the other player in the game, the opponent. 
	 */
	protected void setOpponent(Player opp) {
		this.opponent = opp;
	}
	
	/**
	 * Sets board member variable to an instance of class Board taken in as an argument.
	 * @param theBoard Instance of class Board to be set to member variable Board. 
	 */
	protected void setBoard(Board theBoard) {
		this.board = theBoard;
	}
	
	public char getMark() {
		return mark;
	}
	
	/**
	 * Checks whether one of the Instances of class Players has won by inserting 3 of their marks in a row, or whether the board is full and nobody has won resulting in a tie.
	 * Clears the board and exits application if the game has resulted in a win or a tie, returns to calling function if there has not yet been a win or a tie.
	 */
	protected void checkGameOutcome() {
		if(this.board.isFull()) {
			System.out.print("It's a tie!\n"); 
			System.out.print("Game Ended...");
			this.board.clear();
			System.exit(0);
		}
		else if(this.board.checkWinner(this.mark) == 1) {
			System.out.print(this.name + " Wins!\n");
			System.out.print("Game Ended...");
			this.board.clear();
			System.exit(0);
		}
		else if(this.board.checkWinner(this.opponent.mark) == 1) {
			System.out.print(this.opponent.name + " Wins!\n");
			System.out.print("Game Ended...");
			this.board.clear();
			System.exit(0);
		}
		else {
			return;
		}
	}
	
}
