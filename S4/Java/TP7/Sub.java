package fr.umlv.calc;

public class Sub extends Op {	
	public Sub(Expr left, Expr right) {
		super(left, right);
	}
	
	// Implementing eval
	@Override
	public int eval() {
		return getLeft().eval() - getRight().eval();
	}

	@Override
	public String getOperatorAsString() {
		return " - ";
	}
}