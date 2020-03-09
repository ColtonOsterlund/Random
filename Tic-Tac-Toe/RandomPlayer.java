//also a kind of Player, in fact, his is a computer-player that uses a random generator and picks a vacant spot on the board, randomly
//call the method discrete from class RandomGenerator twice to return random values between 0 and 2 for i and j, if the board[i][j]
//is available then mark it, if not repeat until you find an empty spot
public class RandomPlayer extends Player{
	RandomGenerator rand;
	
	public RandomPlayer(String name, char mark) {
		super(name, mark);
		rand = new RandomGenerator(); //changed the aggregation to composition, or else the main function they wrote for us would need to be edited
	}
	
	@Override
	protected void makeMove() {
		int r, c;
		while(true) {
			r = this.rand.discrete(0, 2);
			c = this.rand.discrete(0, 2);
			if(super.board.getMark(r, c) == ' ') 
				break;
		}
		super.board.addMark(r, c, super.mark);
	}
	
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
	
}
