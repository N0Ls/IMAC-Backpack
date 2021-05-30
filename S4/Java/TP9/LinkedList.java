package fr.umlv.data;

import java.util.Objects;

public class LinkedList<T> {
	private Link<T> start;
	private int size;
	
	public LinkedList() {
		start = null;
		size = 0;
	}
	
	public LinkedList<T> add(T value) {
		start = new Link<T>(value, start);
		size++;
		
		return this;
	}
	
	public T get(int index) throws IllegalAccessException {
		if(size <= 0 ) {
			throw new IllegalAccessException("Linked list is empty");
		}
		if(index < 0 || index >= size) {
			throw new IllegalArgumentException("Invalid index");
		}
		
		int count = 0;
		Link<T> tmp = start;
		while(count < index && count < size) {
			count ++;
			tmp = tmp.next;
		}
		return tmp.value;
	}
	
	@Override
	public String toString(){
		Link<T> current = start;
		var msg = new StringBuilder();
		while(current != null) {
			msg.append(current.value).append(" ");
			current = current.next;
		}
		return msg.toString();
	}
	
	// Ex3 - 4 
	// We need to use an object o because contains uses the equals(Object o) method.
	// If our generic type T don't redefine this method then it won't work.
	
	public boolean contains(Object o) {
		if(o == null) {
			return false;
		}
		Boolean res = o.equals(start.value);
		for(Link<T> tmp = start; tmp != null; tmp=tmp.next) {
			if(o.equals(tmp.value)) {
				res = true;
				break;
			}
		}
		
		return res;
	}
}
