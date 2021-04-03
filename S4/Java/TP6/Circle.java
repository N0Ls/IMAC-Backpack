package fr.umlv.geom;


public class Circle {
	private final Point center;
	private final int radius;
	
	public Circle(Point centerSet, int radiusSet) {
		this.center = new Point(centerSet.getX(), centerSet.getY());
		this.radius = radiusSet;
	}
	
	public String toString() {
		return "Center :  " + center + " Radius : " + radius + " Area : " + this.area();
	}
	
	public void translate(int dx, int dy) {
		center.translate(dx, dy);
	}

	
	public Point getCenter() {
       return new Point(center.getX(), center.getY());
    }
	
	public double area() {
		return Math.PI * this.radius * this.radius;
	}
	
	public boolean contains(Point p) {
		return (Math.sqrt(
				Math.pow(p.getX()-this.center.getX(), 2)+
				Math.pow(p.getY()- this.center.getY(), 2)
				) <= this.radius);
	}
	
	public static boolean contains(Point p, Circle ... circles) {
		for(Circle circle : circles) {
			if(circle.contains(p)) {
				return true;
			}
		}
		return false;
	}
	
	
}




//2

// We should specify that the attributes are private and final.


//6 

// This following code displays :
// Center :  (2,3) Radius : 1 Center :  (2,3) Radius : 2
// This means that both circles have been translated
// To prevent this from happening we need to avoid using a reference
// We can create a new point in our Circle using a copy of the one passed in parameters

//7
// The problem is that it returns the reference of the center of the point
// So when we modify the point that we get from the center it also modifies the center of our circle
// To avoid that we can return a new point that is a copy of our center

//10
// ... is a spread operator.
// It means that you can take any amount of Circles you want in parameter

