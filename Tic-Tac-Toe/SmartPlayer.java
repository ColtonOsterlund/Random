//first looks at board if it can move to win immediately it makes the move
//otherwise, it looks for a way to block its opponent from winning on the next move
//otherwise, it picks a vacant space at random
public class SmartPlayer extends BlockingPlayer implements Constants{ //added implementation here
	
	public SmartPlayer(String name, char mark) {
		super(name, mark);
	}
	
	
	@Override
	protected void makeMove() {
		int r, c;
		
		//testing for winning move
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				if(super.board.getMark(i, j) == ' ') {
					if(testForWinning(i, j)){
						super.board.addMark(i, j, mark);
						return;
					}
				}
			}
		}
		
		//testing for blocking move
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				if(super.board.getMark(i, j) == ' ') {
					if(super.testForBlocking(i, j)){
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


	
	
	
	boolean testForWinning(int row, int col) {
		boolean block = false;
		board.addMark(row, col, super.getMark());
		if(board.checkWinner(super.getMark()) == 1)
			block = true;
		board.addMark(row, col, SPACE_CHAR);
		board.setMarkCount(board.getMarkCount() - 2);
		return block;
	}
	
}
