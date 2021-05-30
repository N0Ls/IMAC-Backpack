package fr.umlv.data.main;

import fr.umlv.data.LinkedList;

public class Main {
	public static void main(String[] args) {
		final LinkedList testLinked = new LinkedList();
		testLinked.add(5);
		testLinked.add(9);
		System.out.println(testLinked);
		
		final LinkedList<String> fastFoods = new LinkedList<String>();
		
		fastFoods.add("McDonalds").add("Burger King").add("KFC");
		System.out.println(fastFoods);
		
		try {
			System.out.println(fastFoods.get(1).length());
		}catch(Exception e){
			System.out.println(e.getMessage());
		}
	}

}
