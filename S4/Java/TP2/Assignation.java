
public class Assignation {
	public static void main(String[] args) {
		 var s1 = "toto";
	     var s2 = s1;
	     var s3 = new String(s1);

	       System.out.println(s1 == s2);
	       System.out.println(s1 == s3);
	       
	       System.out.println(s1.equals(s3));
	       
	     var s8 = "hello";
	     s8.toUpperCase();
	     System.out.println(s8);
	}

}


//1
//Var is of type : String
//The compiler set the appropriated type to the var at compile time.
//It can then read the methods of the type.

//2 
//The code display
// true
// false

//Why ? 
// s1 is a reference to the value
// When we create s2 we copy this reference in s2 so it is the same as s1
// With s3 we use new which creates a new reference

// So when we compare with the operator ==
// we compare the references and not the values directly 
// s1 and s2 are the same thus the true statement
// s1 and s3 aren't the same reference thus the false statement

//3

// we use the method equals()
// System.out.println(s1.equals(s3)); => true

//4
// The following code display true
// We get this result because in the compiler make some optimizations.
// To optimize memory, Java caches the string literals. So if different variables refer to the same object
// in the string pool the compiler will assign the same reference to the variables.

//5
// It is important that String is not mutable because as Java optimize the references
// if String was mutable the modifications made on what we thinks is a unique variable will in fact
// modify all the variables linked to the same reference. 

//6
// It displays "hello"
//This is an example of the immutability
//If the String was mutable the following example would have printed "HELLO"
//
// If we want to get the uppercase word we need to create a new unique reference on the result of s8.toUpperCase()



