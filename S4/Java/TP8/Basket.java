import java.util.ArrayList;
import java.util.HashMap;

public class Basket {
	
	// private final ArrayList<Fruits>content = new ArrayList<Fruits>();
	private final HashMap<Fruits, Integer>basketContent = new HashMap<Fruits, Integer>();
	
	public Basket() {
		
	}
	
	public void add(Fruits newFruit, int quantity) {
		if(basketContent.get(newFruit) != null) {
			basketContent.computeIfPresent(newFruit,
                    (key, val) -> val + quantity);
		}
		else {
			basketContent.put(newFruit, quantity);
		}
		
//		for(var entry : basketContent.entrySet()) {
//			if(entry.getKey().equals(newFruit)) {
//				entry.getKey() == 
//			}
//		}
		
	}
	public void add(Fruits newFruit) {
		add(newFruit, 1);
	}
	
	
	@Override
	public String toString() {
		String result = "";
		int price = 0;
		
//		for(Fruits fruit : basketContent) {
//			System.out.print(fruit);
//			price += fruit.getPrice();
//		}
		
		for(var entry : basketContent.entrySet()) {
			System.out.print(entry.getKey() + " x" + entry.getValue() + " \n"); 
			price += entry.getKey().getPrice() * entry.getValue();
		}
			
			
		result += "price : " + price;
		return result;
	}
	
//	private final ArrayList<Apple>content = new ArrayList<Apple>();
//	public Basket() {
//		
//	}
//	
//	public void add(Apple newApple) {
//		content.add(newApple);
//	}
//	
//	@Override
//	public String toString() {
//		String result = "";
//		int price = 0;
//		
//		for(Apple apple : content) {
//			result += apple.name() + " " + apple.weight() + " g x1 \n";
//			price += apple.getPrice();
//		}
//		result += "price : " + price;
//		return result;
//	}
}
