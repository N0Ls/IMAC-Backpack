
public class Morse {
	public static void main(String[] args) {
		
		//1
		if(args.length > 0) {
			var result = "";
			
			for(String arg : args) {
				result += arg + " Stop. ";
			}
			
			System.out.println(result);
		}
		
		//2 - 3
		// The java.lang.StringBuilder class is used to create mutable sequence of characters
		// it's a mutable alternative to the String class
		// Its method returns a StringBuilder so that we can keep on going with mutable strings
		// The advantage is that we don't create an intermediate string in the String pool for each argument
		// that's because of immutability
		// We just add the string at the end of our StringBuilder
		
		if (args.length > 0) {
			StringBuilder result2  = new StringBuilder("");
			for (String arg : args) {
				result2.append(arg).append(" Stop. ");
			}

			System.out.println(result2);
		}
		
		//4
		// The use of single quotes instead of double allows us to use a character instead of a string.
		// After using javap. We can see that Java itself uses a StringBuilder.
		
		//5
		// It is better to use a StringBuilder when we want to concatenate multiple times a string.
		// However, by default Java will create a StringBuilder even if we use the + concatenation

		// Moreover, if we write a "+" in a call to the append method, it will also
		// create another StringBuilder object. Instead, We would prefer chain calls
		// the "append" method.
	}
}


