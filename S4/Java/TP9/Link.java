package fr.umlv.data;

import java.util.Objects;

// 1
// We use the package visibility so that this class is accessible only in its package
// It will only be used by linked list who will use it to construct its links.

// Ex 3 - 1
// A generic type allows to manipulate any type of object
// This way we don't have to write a new class when we want to use a linked list for another type

class Link<T>{
	 final T value;
	 final Link<T> next;
	 	
	 Link(T value, Link<T> next) {
		this.value = value;
		this.next = next;
	 }
	
	public static void main(String[] args) {
		Link<Integer> link1 = new Link<Integer>(13, null);
		Link<Integer> link2 = new Link<Integer>(14, null);
	}
}
