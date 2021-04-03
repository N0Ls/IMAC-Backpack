
class Pear extends FruitsAbstract{
	private final int juice;
	public Pear(int juice) {
		this.juice = juice;
	}
	
	public int juice() {
		return this.juice;
	}
	
	public int getPrice() {
		return this.juice() * 3;
	}
	
	@Override
	public String toString() {
		return "Pear " + this.juice();
	}
}
