package fr.umlv.geom;

public class Ring extends Circle {
	private final int innerRadius;
	
	public Ring(Point centerSet, int radiusSet, int innerRadiusSet) {
		super(centerSet, radiusSet);
		if(radiusSet < innerRadiusSet) {
			throw new IllegalArgumentException("Inner radius can't be bigger than the radius");
		}
		else {
			innerRadius = innerRadiusSet;
		}
	}
	
	@Override
	public String toString() {
		return super.toString() + " InternalRadius : " + innerRadius;
	}
	
	@Override
	public boolean contains(Point p) {
		Circle internalCircle = new Circle(this.getCenter(), this.innerRadius);
		return (super.contains(p) && !internalCircle.contains(p));
	}

	public static boolean contains(final Point p, final Ring... rings) {
		return Circle.contains(p, rings);
	}
}

//Ex 2 - 2
// The idea behind inheritance is that you can create new classes
// based upond existing classes

// When you inherit from an existing class, you can reuse methods and fields of the parent class.
// You can also add new methods and fields or redefine methods written in the parent class.
// Inheritance is really useful to avoid coding redundant code.

// Ex 2 - 4
// Using "super" keyword, we call the toString method which was overriden in the
// Circle class and add the specific behaviour (internal radius).

//Conclusion
//In this lab we explored the mutability of objects and how it is important to think about how we implements our classes.
// We saw the consequences of bad programming.

//We also tried multiple examples of inheritance and overriding
//We saw examples of varargs in JAVA.