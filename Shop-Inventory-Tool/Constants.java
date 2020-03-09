/**
 * Provides the constant to check inventory numbers against. Whether they are above or below this constant dictates whether a new order
 * must be processed or not.
 * @author Colton Osterlund
 * @version 1.0
 * @since February 5th, 2019
 *
 */
public interface Constants {
	/**
	 * Constant to be used as the minimum number of a specific tool in the inventory before an order is placed.
	 */
	final int MINIMUM = 40;
	
}
