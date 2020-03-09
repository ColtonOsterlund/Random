//a BlockingPlayer is a kind of RandomPlayer that first looks at the board for a move that would block its opponent from winning on
//the next move. If it can't find such a move, it picks a vacant spot at random. Therefore, before making any move, this class needs 
//to call a method called testForBlocking(), this method should return true if there is a situation that needs to be blocked 
//the process is the traverse through the board and test the function for every available spot on the board and if it returns
//true for a specific i and j it places a mark there, if it is false for all i and j values it will place a mark in a random
//available spot
public class BlockingPlayer extends RandomPlayer implements Constants{ //added implementation here
	
	public BlockingPlayer(String name, char mark) {
		super(name, mark);
	}
	
	@Override
	protected void makeMove() {
		int r, c;
		
		//testing for blocking move
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				if(super.board.getMark(i, j) == ' ') {
					if(testForBlocking(i, j)){
						super.board.addMark(i, j, super.mark);
						return;
					}
				}
			}
		}
		
		//playing random move
			while(true) {
			r = this.rand.discrete(0, 2);
			c = this.rand.discrete(0, 2);
			if(super.board.getMark(r, c) == ' ') 
				break;
		}
		super.board.addMark(r, c, super.mark);
	}
	
	protected boolean testForBlocking(int row, int col) {
		boolean block = false;
		board.addMark(row, col, opponent.getMark());
		if(board.checkWinner(opponent.getMark()) == 1)
			block = true;
		board.addMark(row, col, SPACE_CHAR);
		board.setMarkCount(board.getMarkCount() - 2);
		return block;
	}
	
	
}
