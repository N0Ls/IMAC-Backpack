import java.util.ArrayList;
import java.util.Iterator;

public class FreeShoppingCart {
	final private ArrayList<Book> books;

	public FreeShoppingCart() {
		this.books = new ArrayList<Book>();
	}

	public boolean add(Book book) {
		return this.books.add(book);
	}

//2
//	public Book longestTitle() {
//		if(books.size() == 0) {
//			return null;
//		}
//		Book bookWithLongestTitle = this.books.get(0);
//		
//		for (int i = 1; i < books.size(); i++) {
//			if (bookWithLongestTitle.Title().length() <= this.books.get(i).Title().length()) {
//					bookWithLongestTitle = this.books.get(i);
//			}
//		}
//		return bookWithLongestTitle;
//	}
	
//3
	
//	public Book longestTitle() {
//		if (this.books.size() == 0) {
//			return null;
//		}
//		Book bookWithLongestTitle = this.books.get(0);
//		Iterator<Book> iterator = this.books.iterator();
//
//		while (iterator.hasNext()) {
//			if (bookWithLongestTitle.Title().length() <= iterator.next().Title().length()) {
//					bookWithLongestTitle = iterator.next();
//			}
//		}
//
//		return bookWithLongestTitle;
//	}
	
//4
	public Book longestTitle() {
		if (this.books.size() == 0) {
			return null;
		}

		Book bookWithLongestTitle = this.books.get(0);
		int longestLength = bookWithLongestTitle.Title().length();
		int currentBookLength = longestLength;

		for (Book book : this.books) {
			longestLength = bookWithLongestTitle.Title().length();
			currentBookLength = book.Title().length();
			if (currentBookLength >= longestLength) {
					bookWithLongestTitle = book;
			}
		}

		return bookWithLongestTitle;
	}
	
	//On a collection, the compiler will copile the foreach loop as a loop with iterator
	
	//Simple arrays aren't iterable so in this case the compiler can't use a foreach loop
	//When on a iterable object the compiler will use an iterator like in the longest title method
	
//5
	
//	public boolean removeFirstOccurence(Book book) { 
//		return this.books.remove(book); 
//	}
	//In the worst case scenario, we need to iterate through the whole array so the complexity is O(n)

//6
	public void removeFirstOccurence(Book book) {
		Iterator<Book> iterator = this.books.iterator();
		
		while (iterator.hasNext()) {
			Book nextBook = iterator.next();
			if (nextBook.equals(book)) {
				iterator.remove();
				break;
			}	
		}
	}
//I have some difficulties seeing the difference with the other method but I suppose that the iterator is more efficient
	
//7
// I guess we should use iterator we we want to modify a collection (deleting items for example)
// It will be more efficient in time and complexity.

//When we just want to read the elements of our collection we can use a foreach loop 
//because it will be more convenient 

	
	 public static void main(String[] args){
		  var testCart = new FreeShoppingCart();
		  var book1 = new Book("Neo naturisme", "Vincent Scavinner");
	      var book2 = new Book("Minecraft pour les nuls", "Cloé Quirin");
	      var book3 = new Book("Vivre avec la grosse tête", "Erwann Lefevre");
	      var book4 = new Book("La goute de trop", "Aloïs Aubert");
	      
	      testCart.add(book1);
	      testCart.add(book2);
	      testCart.add(book3);
	      testCart.add(book4);
	      
	      for(String arg : args) {
	    	  System.out.println(arg);
	      }
	      System.out.println(testCart.longestTitle());

	 }
	
	

}
