import java.util.Objects;

public class Book {
    final private String title;
    final private String author;
    final private String defaultAuthor = new String("no author");
    

    public String Title() {
    	return title;
    }
    
    public String Author() {
    	return author;
    }
    
    public Book(final String title, final String author) {
    	Objects.requireNonNull(title);
		Objects.requireNonNull(author);
    	this.title = title;
    	this.author = author;
    }
    
    public Book(final String title) {
    	this.title = title;
    	this.author = defaultAuthor;
    }
        
    public boolean compareBooks(Book book) {
        return this.title.equals(book.title) && this.author.equals(book.author);
    }
    
    @Override
    public boolean equals(Object otherBook) {
    	if(!(otherBook instanceof Book)) {
    		return false;
    	}
    	
  	  	return this.compareBooks((Book)otherBook);
    }
    
    
 	@Override
 	public String toString() {
 		if(author == defaultAuthor) {
 			return title + " !";
 		}
 		return title + " by " + author;
 	}
}
