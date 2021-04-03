import java.util.Objects;

class Apple extends FruitsAbstract{
	
	private final int weight;
	private final AppleKind name;

	public Apple(int weight, AppleKind name) {
		Objects.requireNonNull(name, "Must have a name");
		if(weight <= 0 ) {
			throw new IllegalArgumentException("Wrong weight");
		}
		
		this.weight = weight;
		this.name = name;
	}
	
	private AppleKind name() {
		return this.name;
	}
	
	private int weight() {
		return this.weight;
	}
	
	public int getPrice() {
		return this.weight()/2;
	}
	
	@Override
	public String toString() {
		return this.name() + " " + this.weight();
	}
	
	@Override
	public boolean equals(Object o) {
		if(o == null) {
			throw new IllegalArgumentException(" Object is null");
		}
		if(!(o instanceof Apple)) {
			throw new IllegalArgumentException(" Wrong type");
		}
		if(this == o) {
			return true;
		}
		
		Apple appleToTest = (Apple) o;

		return this.name().equals(appleToTest.name()) && this.weight() == appleToTest.weight();
	}
	
	@Override
	public int hashCode() {
		return this.name().hashCode() + this.weight();
	}
}
