package fr.umlv.calc;

// Ex2 5

// To re-factor the code we can create an operator class that will implements Expr class.
// Our operators add and sub will then extends this class

// The methods will use a protected visibility so that add and sub can use it as well

// We will also use abstract methods that will be implement in the child classes

public abstract class Op implements Expr {
	private final Expr rightOperand;
	private final Expr leftOperand;

	public Op(Expr left, Expr right) {
		this.rightOperand = right;
		this.leftOperand = left;
	}

	protected Expr getRight() {
		return this.rightOperand;
	}

	protected Expr getLeft() {
		return this.leftOperand;
	}

	public abstract String getOperatorAsString();

	@Override
	public String toString() {
		return "(" + this.leftOperand + getOperatorAsString() + this.rightOperand + ")";
	}
}