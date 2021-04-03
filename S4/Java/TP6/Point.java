package fr.umlv.geom;

public class Point {
	private int x;
	private int y;

	public Point(int x, int y) {
		this.x = x;
		this.y = y;
	}

	public int getX() {
		return x;
	}

	public int getY() {
		return y;
	}

	@Override
	public String toString() {
		return "(" + x + ',' + y + ')';
	}
	
	public void translate(int dx, int dy) {
	  x += dx;
	  y += dy;
	}
	
}

//1

// The code doesn't compile because we set the attribute to final
// and we are trying to modify them inside the translate method.

// Here the implementation chosen makes the points immutable.
// But the problem is that the translate method is working against that implementation.



