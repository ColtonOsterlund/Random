import javax.swing.JTextArea;

/**
 *  The following class is the Controller portion of the MVC design specification for
 *  this program. The controller instantiates the MyFrame and BinSearchTree classes
 *  and runs the program
 *  
 * @author Boma Nkwonta & Colton Osterlund
 * @Version 1.0
 * @Since March 29, 2019
 */
public class Controller {
	private BinSearchTree binTree = null;
	private MyFrame frame = null;

	public Controller(MyFrame frame, BinSearchTree binTree)
	{
		this.setFrame(frame);
		this.setBinTree(binTree);
		
		frame.setInsertBtnListener(new InsertBtnListener(this));
		frame.setCreateBtnListener(new CreateBtnListener(this));
		frame.setFindBtnListener(new FindBtnListener(this));
		frame.setBrowseBtnListener(new BrowseBtnListener(this));
		frame.addWindowListener(new MyFrameWindowListener(this));
		
	}
	
	/**
	 * The following method returns the controller's binary search tree
	 * @return the controller's binary search tree member variable 
	 */
	public BinSearchTree getBinTree() {
		return binTree;
	}

	/**
	 * The following method sets a binary search tree to the BST member variable in the
	 * controller
	 * @param binTree binary search tree to be set to the controller
	 */
	public void setBinTree(BinSearchTree binTree) {
		this.binTree = binTree;
	}
	
	/**
	 * The following method returns the controllers MyFrame
	 * @return the controller's MyFrame member variable
	 */
	public MyFrame getFrame() {
		return frame;
	}

	/**
	 * The following method sets the MyFrame member variable for the controller 
	 * @param f MyFrame object being set to the controller
	 */
	public void setFrame(MyFrame f) {
		this.frame = f;
	}
	
	/**
	 *  The following method returns the textArea member variable of 
	 *  the controller's MyFrame
	 * @return the textArea assigned to the controller's MyFrame object
	 */
	public JTextArea getTextArea() {
		return frame.getTextArea();
	}
	
	/**
	 *  The following method runs the program
	 * @param args command line arguments (not applicable for this program)
	 */
	public static void main(String [] args) {
		MyFrame frame = new MyFrame();
		BinSearchTree myTree =  new BinSearchTree();
		Controller control  = new Controller(frame, myTree);

	}
}
