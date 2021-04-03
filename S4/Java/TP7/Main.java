package fr.umlv.calc;

import java.util.Scanner;
import java.util.Vector;


public class Main {
	
	// Ex1
//	public static void main(String[] args){
//		Scanner myObj = new Scanner(System.in);  // Create a Scanner object
//	    System.out.println("Enter expression");
//	    
//	    OpOrValue test = OpOrValue.parse(myObj);
//	    
//	    System.out.println(test);
//	}
	
	public static void main(String[] args){
		
		//Building expression 
		Vector<String> vector = new Vector<String>();
		vector.add("-");
		vector.add("+");
		vector.add("2");
		vector.add("3");
		vector.add("5");
		
		//Parsing expression
		Expr exprTest = Expr.parse(vector);
		System.out.println(exprTest);
		System.out.println(exprTest.eval());
		
		Expr exprTest2 = new Sub(new Value(2), new Value(6));
		System.out.println(exprTest2);
		System.out.println(exprTest2.eval());

	}
}