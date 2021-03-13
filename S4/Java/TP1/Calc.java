import java.util.Scanner; 
public class Calc {
	public static void main(String[] args) {
		Scanner scanner;
		scanner = new Scanner(System.in);
		
		//Inputs
		System.out.println("Please enter the first integer");
		var value1 = scanner.nextInt();	
		System.out.println("Please enter the second integer");
		var value2 = scanner.nextInt();
		
		
		//Compute the values
		var sum = value1+value2;
		var diff = value1-value2;
		var prod = value1*value2;
		var rest = value1%value2;
		
		
		//Print out the results
		System.out.println("Sum of the two integers is : " + sum);
		System.out.println("Difference of the two integers is : " + diff);
		System.out.println("Product of the two integers is : " + prod);
		if(value2 == 0) {
			System.out.println("Quotient impossible / by zero : ");
		}
		else {
			var quo = value1/(float)value2;
			System.out.println("Quotient of the two integers is : " + quo);
		}
		System.out.println("Rest is : " + rest);
		
		//Close scanner to avoid leaks
		scanner.close();
	}
}

//3 
// nextInt() is a method of the class Scanner
// (It's an iterator DP)

//4
// This line is used to import (include) the class Scanner into our program.

//7
// We can force the cast into float
