import java.util.Scanner;

//subclass of Player, it is a concrete class and it has to define the abstract methods inherited from calss Player,
//the pkayers should have the option of selecting the type of the players
public class HumanPlayer extends Player{
	public HumanPlayer(String name, char mark) {
		super(name, mark);
	}
	
	
	/**
	 * Asks the player to input a row and a column & checks whether it is a element to enter the mark, then, adds a mark to the element specified by the player.
	 */
	@Override
	protected void makeMove() {
		int r, c;
		while(true) {
			r = this.askForRow();
			c = this.askForCol();
			if(super.board.getMark(r, c) == ' ') 
				break;
			else
				System.out.print("This spot has already been played, play somewhere else!\n");
		}
		super.board.addMark(r, c, super.mark);
	}
	
	
	/**
	 * Checks whether the game is finished in a win or a tie, displays the current state of the board and initiates the respective players turn.
	 */
	@Override 
	protected void play() {
		if(!super.board.xWins() && !super.board.oWins() && !super.board.isFull()) 
			this.makeMove();
		else {
			super.checkGameOutcome();
		}
		
		super.board.display();
		super.checkGameOutcome();
		super.opponent.play();
	}
	
	/**
	 * Asks player to input row to enter mark, reads the players input from the scanner and checks that it is a valid input.
	 * @return Row number entered from the player.
	 */
	private int askForRow() {
		String row;
		this.scan = new Scanner(System.in);
		System.out.print(this.name + ", what row should your next " + this.mark + " be placed in? ");
		while(true) {
			row = scan.nextLine();
			if(row.contentEquals("0") || row.contentEquals("1") || row.contentEquals("2")) 
				break;
			System.out.print("Invalid input... enter row number again ");
		}
		return Integer.parseInt(row);
	}
	
	/**
	 * Asks player to input column to enter mark, reads the players input from the scanner and checks that it is a valid input.
	 * @return Column number entered from the player.
	 */
	private int askForCol() {
		String col;
		this.scan = new Scanner(System.in);
		System.out.print(this.name + ", what column should your next " + this.mark + " be placed in? ");
		while(true) {
			col = scan.nextLine();
			if(col.contentEquals("0") || col.contentEquals("1") || col.contentEquals("2")) 
				break;
			System.out.print("Invalid input... enter column number again ");
		}
		return Integer.parseInt(col);
	}
}
