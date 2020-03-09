//MCV MODEL

/**
 * Represents data within a node
 */
public class Data {
	
	/**
	 * id is the student's id
	 * faculty is the student's faculty 
	 */
	String  faculty, major, year;
	int id;
	
	public Data( int i, String f, String m, String y)
	{
		id = i;
		faculty = f;
		major = m;
		year = y;
	}
	
	public String toString()
	{
		return ("id : " + id + " faculty: " + faculty + " major: " + major + 
						" year: " + year);
	}	
}
