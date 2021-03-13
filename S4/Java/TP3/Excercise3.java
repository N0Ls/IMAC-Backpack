import java.util.ArrayList;
public class Excercise3 {
	  public static void main(String[] args){
		  var book = new Book("Da Java Code", "Dan Duke");
	      System.out.println(book);
		  var book1 = new Book("Test Sans auteur");
	      System.out.println(book1);
	      var book2 = new Book("Test Sans auteur", "no author");
	      System.out.println(book2);
	  }
	  

}

//2
//Yes we can use the keyword override because we are redefining
//a method from object