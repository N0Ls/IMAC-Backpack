import java.util.ArrayList;
public class Exercise2 {
//  public static void main(String[] args) {
//	  
//      var b1 = new Book("Da Java Code", "Duke Brown");
//      var b2 = b1;
//      var b3 = new Book("Da Java Code", "Duke Brown");
//
//      System.out.println(b1 == b2);
//      System.out.println(b1 == b3);
//  }
  
//  public static void main(String[] args){
//      var b1 = new Book("Da Java Code", "Duke Brown");
//      var b2 = b1;
//      var b3 = new Book("Da Java Code", "Duke Brown");
//
//      var list = new ArrayList();
//      list.add(b1);
//      System.out.println(list.indexOf(b2));
//      System.out.println(list.indexOf(b3));
//  }
  
  public static void main(String[] args){
	  var aBook = new Book(null, null);
      var anotherBook = new Book(null, null);
      var list = new ArrayList();
      list.add(aBook);
      System.out.println(list.indexOf(anotherBook));
  }


}

//1
//The code displays :
//true
//false

//Like in the first TP we compare the references of the objects with the == operator
//b1 == b2 is true because they are the same reference
//b3 is a new reference so it is different than the others

//3
//This method return the index of a value present in the array
//It will return -1 if the value is absent

//4
//The code should display -1 and -1 because we are looking for b1 and nothing else

//5
//Index of calls the method equals.
//But because the method isn't properly defined for this object it acts like a reference comparison

//8
//@Override is an annotation that asks the compiler to
//verify that it does exist such a method to override in a
//super-type

//9
//It displays
//Exception in thread "main" java.lang.NullPointerException: 
//Cannot invoke "String.equals(Object)" because "this.title" is null

//The issue is that we use the null value is the comparison

//We should add a verification in order to check if the book is null or not

//10 
//A good practice is that we shouldn't use null

//11
// requireNonNull checks that the specified object reference is not null.
//This method is designed primarily for doing parameter validation in methods and constructors.