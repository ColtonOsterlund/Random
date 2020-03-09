/**
 * 
 * Provides data fields and methods to create a game board for the tic-tac-toe game to be played on.
 * @author Colton Osterlund - 30038785
 * @version 1.0
 * @since January 26, 2019
 *
 */
public class Board implements Constants {
	/**
	 * 2D array of characters which will act as the game board to be played upon
	 */
	private char theBoard[][];
	/**
	 * Integer to keep track of how many player tokens either 'X' or 'O' have been placed on the board.
	 */
	private int markCount;

	/**
	 * Constructs an instance of Board of size 3x3 with all the elements containing white space and sets the markCount to 0.
	 */
	public Board() {
		setMarkCount(0);
		theBoard = new char[3][];
		for (int i = 0; i < 3; i++) {
			theBoard[i] = new char[3];
			for (int j = 0; j < 3; j++)
				theBoard[i][j] = SPACE_CHAR;
		}
	}

	/**
	 * Returns the character of the player token either 'X' or 'O' that has been placed on the board at the location specified by the parameters.
	 * @param row specifies the row of the element in which you are checking for the value of the player token.
	 * @param col specifies the column of the element in which you are checking for the value of the player token.
	 * @return the character 'X', 'O' or ' ' representing what currently resides on the game board at the row and column specified by the parameters.
	 */
	public char getMark(int row, int col) {
			return theBoard[row][col];
	}

	/**
	 * Checks whether all 9 of the game boards elements are occupied with a player token either 'X' or 'O'.
	 * @return Returns true if all 9 elements on the board are occupied with either an 'X' or an 'O' player token, otherwise returns false.
	 */
	public boolean isFull() {
		return getMarkCount() == 9;
	}

	/**
	 * Checks whether player 'X' has won the game.
	 * @return Returns true if player 'X' has won the game, otherwise returns false.
	 */
	public boolean xWins() {
		if (checkWinner(LETTER_X) == 1)
			return true;
		else
			return false;
	}

	/**
	 * Checks whether player 'O' has won the game.
	 * @return Returns true if player 'O' has won the game, otherwise returns false.
	 */
	public boolean oWins() {
		if (checkWinner(LETTER_O) == 1)
			return true;
		else
			return false;
	}

	/**
	 * Displays column headers, row headers, game board and all occupying player tokens or white spaces within the elements of the game board.
	 */
	public void display() {
		displayColumnHeaders();
		addHyphens();
		for (int row = 0; row < 3; row++) {
			addSpaces();
			System.out.print("    row " + row + ' ');
			for (int col = 0; col < 3; col++)
				System.out.print("|  " + getMark(row, col) + "  ");
			System.out.println("|");
			addSpaces();
			addHyphens();
		}
	}

	/**
	 * Adds a player token either 'X' or 'O' specified by the given parameters to the row and column on the game board specified by the given parameters.
	 * @param row The row of the game board to which the specified player token will be added.
	 * @param col The column of the game board to which the specified player token will be added.
	 * @param mark The player token either 'X' or 'O' that will be added to the specified location on the game board.
	 */
	public void addMark(int row, int col, char mark) {
		
		theBoard[row][col] = mark;
		setMarkCount(getMarkCount() + 1);
	}

	/**
	 * Clears all player tokens 'X' and 'O' from the game board and sets all 9 elements to white spaces ' ', resets the markCount data field to 0.
	 */
	public void clear() {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				theBoard[i][j] = SPACE_CHAR;
		setMarkCount(0);
	}

	/**
	 * Checks whether the player token either 'X' or 'O' specified by the given parameter 
	 * has successfully won the game by placing 3 vertical or horizontal marks in a row.
	 * @param mark Specifies the player token either 'X' or 'O' in which to check for a consecutive 3 marks in a row on the game board.
	 * @return Return true whether the player of the specified mark has won by successfully placing a consecutive 3 marks in a row on the game board.
	 */
	int checkWinner(char mark) {
		int row, col;
		int result = 0;

		for (row = 0; result == 0 && row < 3; row++) {
			int row_result = 1;
			for (col = 0; row_result == 1 && col < 3; col++)
				if (theBoard[row][col] != mark)
					row_result = 0;
			if (row_result != 0)
				result = 1;
		}

		
		for (col = 0; result == 0 && col < 3; col++) {
			int col_result = 1;
			for (row = 0; col_result != 0 && row < 3; row++)
				if (theBoard[row][col] != mark)
					col_result = 0;
			if (col_result != 0)
				result = 1;
		}

		if (result == 0) {
			int diag1Result = 1;
			for (row = 0; diag1Result != 0 && row < 3; row++)
				if (theBoard[row][row] != mark)
					diag1Result = 0;
			if (diag1Result != 0)
				result = 1;
		}
		if (result == 0) {
			int diag2Result = 1;
			for (row = 0; diag2Result != 0 && row < 3; row++)
				if (theBoard[row][3 - 1 - row] != mark)
					diag2Result = 0;
			if (diag2Result != 0)
				result = 1;
		}
		return result;
	}

	/**
	 * Displays the column headers indicating the column number above the game board.
	 */
	void displayColumnHeaders() {
		System.out.print("          ");
		for (int j = 0; j < 3; j++)
			System.out.print("|col " + j);
		System.out.println();
	}

	/**
	 * Adds hyphens in the construction of the physical look of the game board.
	 */
	void addHyphens() {
		System.out.print("          ");
		for (int j = 0; j < 3; j++)
			System.out.print("+-----");
		System.out.println("+");
	}

	/**
	 * Adds spaces in the construction of the physical look of the game board.
	 */
	void addSpaces() {
		System.out.print("          ");
		for (int j = 0; j < 3; j++)
			System.out.print("|     ");
		System.out.println("|");
	}

	public int getMarkCount() {
		return markCount;
	}

	public void setMarkCount(int markCount) {
		this.markCount = markCount;
	}
}
