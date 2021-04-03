package fr.umlv.calc;

public class Value implements Expr {
	private final int value;

	public Value(int value) {
		this.value = value;
	}
	
	// Implementing eval
	@Override
	public int eval() {
		return this.value;
	}
	
	@Override
    public String toString() {
        return String.valueOf(this.value);
    }
}