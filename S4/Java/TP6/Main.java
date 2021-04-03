package fr.umlv.geom;

public class Main {
	public static void main(String[] args){
		try {
			var point = new Point(0, 0);
			var p2 = new Point(0, 0);
		    var circle = new Circle(point, 2);
		    System.out.println(circle);
		    var ring = new Ring(point, 2, 1);
		    System.out.println(ring);
		    
		    System.out.println(ring.contains(p2));
		}
		catch(Exception e){
			System.out.println(e);
		}
		
	}
}
