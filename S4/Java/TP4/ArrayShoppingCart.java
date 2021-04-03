
public class ArrayShoppingCart {
    
    final static private int maxBookDefault = 20;

	final private Book[] books;
	private int nbBooks;
	private int maxBook;

	public ArrayShoppingCart(final int maxBook) {
		this.books = new Book[maxBook];
		this.nbBooks = 0;
		this.maxBook=maxBook;
	}

	public ArrayShoppingCart() {
		this(maxBookDefault);
	}

//2
//	public void add(Book book) {
//		books[this.nbBooks] = book;
//		this.nbBooks += 1;
//	}
	
//We need to add a verification
	
	public void add(Book book) {
		if(book == null) {
			throw new NullPointerException("Book is null");
		}
		if(this.nbBooks >= this.maxBook) {
			throw new IllegalStateException("Size overflow : cannot add any more book");
		}
		else{
			books[this.nbBooks] = book;
			this.nbBooks += 1;
		}
	}
	
 	public void display() {
 		System.out.println("Number of books in the cart : " + nbBooks);
 		for(var i=0; i<books.length; i++) {
 	 		System.out.println("	- "+books[i]);
 		}
 	} 
 	
 	public Book longestTitle() {
 		Book bookWithLongestTitle = null;
 		for(var i=0; i<books.length; i++) {
 	 		if(bookWithLongestTitle==null || books[i].Title().length() > bookWithLongestTitle.Title().length()) {
 	 			bookWithLongestTitle = books[i];
 	 		}
 		}
 		return bookWithLongestTitle;
 	}

	 public static void main(String[] args){
		  var testCart = new ArrayShoppingCart(3);
		  var book1 = new Book("Neo naturisme", "Vincent Scavinner");
	      var book2 = new Book("Minecraft pour les nuls", "Cloé Quirin");
	      var book3 = new Book("Vivre avec la grosse tête", "Erwann Lefevre");
	      var book4 = new Book("La goute de trop", "Aloïs Aubert");
	      
	      testCart.add(book1);
	      testCart.add(book2);
	      testCart.add(book3);
	      //testCart.add(book4);
	      
	      testCart.display();
	      System.out.println(testCart.longestTitle());

	 }
	 
	 
}

//1
//If we have the same max number for every shopping cart then we can decide to have a static field
//But in our case, we want this max number to be set by the shopping cart itself

//2
//If we add another book when the array is already full, 
//we get an error message saying we are out of bounds




