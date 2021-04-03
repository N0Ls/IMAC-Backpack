package fr.umlv.calc;

public class Add extends Op {
	
	public Add(Expr left, Expr right) {
		super(left, right);
	}

	// Implementing eval
	@Override
	public int eval() {
		return getLeft().eval() + getRight().eval();
	}

	@Override
	public String getOperatorAsString() {
		return " + ";
	}
}