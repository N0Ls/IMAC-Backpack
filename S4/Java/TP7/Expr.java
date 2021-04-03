package fr.umlv.calc;

import java.util.Collection;
import java.util.Iterator;

// Ex2 4
// We can make Expr an interface, an abstract type, which is used to specify the behavior of a class.
// Add, Sub and Value classes will implement this interface because these expressions
// are intended to be parsed and evaluated.
public interface Expr {

	public int eval();

	// Ex2 2
	// We should write the parse method in the Expr class.
	public static Expr parse(Iterator<String> iterator) {
		var result = parseRec(iterator);
		if (iterator.hasNext()) {
			throw new IllegalStateException("Ill formed expression");
		}
		return result;
	}

	public static Expr parseRec(Iterator<String> iterator) {
		if (!iterator.hasNext()) {
			throw new IllegalArgumentException("Ill formed expression");
		}
		String current = iterator.next();
		try {
			int value = Integer.parseInt(current);
			return new Value(value);
		}
		catch (Exception e) {
			switch (current) {
				case "+" : {
					return new Add(parseRec(iterator), parseRec(iterator));
				}
				case "-" : {
					return new Sub(parseRec(iterator), parseRec(iterator));
				}
				default : {
					throw new IllegalArgumentException("Operator doesn't exist");
				}
			}
		}
	}

	static public Expr parse(Collection<String> collection) {
		return parse(collection.iterator());
	}
}