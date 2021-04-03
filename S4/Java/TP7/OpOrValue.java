package fr.umlv.calc;
import java.util.Scanner;

public class OpOrValue {
	  public static final int OP_NONE = 0;
	  public static final int OP_ADD = 1;
	  public static final int OP_SUB = 2;
	  
	  private final int operator;
	  private final int value;
	  private final OpOrValue left;
	  private final OpOrValue right;
	  
	  private OpOrValue(int operator, int value, OpOrValue left, OpOrValue right) {
	    this.operator = operator;
	    this.value = value;
	    this.left = left;
	    this.right = right;
	  }
	  public OpOrValue(int value) {
	    this(OP_NONE, value, null, null);
	  }
	  public OpOrValue(int operator, OpOrValue left, OpOrValue right) {
		  this(operator, 0, left, right); 
		  if(operator > 2 || operator < 0) {
				throw new IllegalArgumentException("Operator doesn't exist");
		  } 
	  }
	  
	  public static OpOrValue parse(Scanner scanner) {
		  if(!scanner.hasNext()) {
			  throw new IllegalStateException("Ill formed expression");
		  }
		  String current = scanner.next();
		  try {
			 Integer.parseInt(current);
		  }
		  catch(Exception e){
			  int op=OP_NONE;
			  var left = parse(scanner);
			  var right = parse(scanner);
			  switch(current) {
			  	case "-" -> op = OP_SUB;
			  	case "+" -> op = OP_ADD;
			  	default -> throw new IllegalArgumentException("Operator doesn't exist");
			  }
			  return new OpOrValue(op, left, right);  
		  } 
		  return new OpOrValue(Integer.parseInt(current));
	  }
	  
	  public String toString() {
		  if(operator == OP_NONE) {
			  return Integer.toString(this.value);
		  }
		  else {
			  
			  if(operator == OP_SUB) { 
				  return "(" + left.toString() + "-" + right.toString() + ")";
			  }
			  if(operator == OP_ADD) {
				  return "(" + left.toString() + "+" + right.toString() + ")";
			  }
		  }
		  return Integer.toString(this.value);
	  }
	  
	  public int eval() {
	    switch(operator) {
	    case OP_ADD:
	      return left.eval() + right.eval();
	    case OP_SUB:
	      return left.eval() - right.eval();
	    default: // case OP_NONE:
	      return value;
	    }
	  }
	  
	}

// 1
// The constructor is declared private because this way the user won't have access to it.
// He will be used implicitly in other public constructors

// 2 
// The problem is that there is no verification for the operator

// 6
// We should use an iterator so we will be able to call the parse method with a list or a scanner


