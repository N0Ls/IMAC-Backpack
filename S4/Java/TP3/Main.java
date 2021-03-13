
public class Main {
	
  public static void main(String[] args) {
	var book = new Book("Le coucher de soleil", "ErwiT");
    System.out.println(book.Title() + " écrit par " + book.Author());
  }
}
//3
//We can't access the attributes title and author because they are private
//To solve this we need to create a method to access them
//It's called an interfacing
 

//4 
//The four distinct accessibilities are : 
// - private : it is accessible only from its own class 
// - public : it is accessible from anywhere in  the package 
// - default : by default, the classes visibility is package private, only visible for classes in the same package 
// - protected : it is accessible just for the subClass of the class

//We need to choose private everytime because we don't want the user to have the possibility to modify or access the attributes directly
//To interact with attributes we use methods of the class as an interface
//In this way we are always in control of what we present to the user and what he is able to do

//5
//An accessor is a method that will access or modify the value of the attributes for us 
//In our case we need to use a getter

//6 
//The title or author of a book shoudn't change because a book never changes title or author
//To tell we don't want the attribute to change we use the final keyword

//7
//The main code doesn't work anymore because there is no corresponding constructor
//In the main the constructor wants two parameters

//8
//There is an ambiguity because the parameters have the same name as the attributes 
//To clear the ambiguity, we specify that we talk about the attributes of the object by using .this

//10
//The compiler look for the best constructor according to the parameters