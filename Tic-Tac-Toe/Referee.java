/**
 * Sets opponents for each respective instance of class Player, initially displays the board and starts the game on xPlayers turn.
 * @author Colton Osterlund
 * @version 1.0
 * @since January 26, 2019
 *
 */
public class Referee {
	/**
	 * Instance of class Player with its member variable mark set to X. 
	 */
	private Player xPlayer;
	/**
	 * Instance of class Player with its member variable mark set to O.
	 */
	private Player oPlayer;
	/**
	 * Instance of class Board used to initially display the board to start the game.
	 */
	private Board board;
	
	/**
	 * Default constructor for Referee that sets all member variables to null.
	 */
	public Referee() {}
	
	/**
	 * Makes each instance of class Player aware of their opponents through association, displays the board and starts the game on xPlayers turn.
	 */
	public void runTheGame() {
		this.xPlayer.setOpponent(oPlayer);
		this.oPlayer.setOpponent(xPlayer);
		this.board.display();
		this.xPlayer.play();
	}
	
	/**
	 * Display the game board in the terminal.
	 * @param theBoard Instance of class Board to be displayed.
	 */
	public void setBoard(Board theBoard) {
		this.board = theBoard;
	}
	
	/**
	 * Sets instance of Player with member variable mark set to 'O' to oPlayer member variable.
	 * @param oPlayer Instance of class Player with member variable set to 'O'
	 */
	public void setoPlayer(Player oPlayer) {
		this.oPlayer = oPlayer;
	}
	
	/**
	 * Sets instance of Player with member variable mark set to 'X' to xPlayer member variable.
	 * @param xPlayer Instance of class Player with member variable set to 'X'
	 */
	public void setxPlayer(Player xPlayer) {
		this.xPlayer = xPlayer;
	}
}
