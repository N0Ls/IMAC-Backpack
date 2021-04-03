package fr.umlv.fight;

public class Arena {
	public static Robot fight(Robot fighter1, Robot fighter2) {
		Robot winner = null;
		while(!fighter1.isDead() && !fighter2.isDead() ) {
			
			fighter1.fire(fighter2);
			if(fighter2.isDead()) {
				winner = fighter1;
				break;
			}
			
			fighter2.fire(fighter1);
			if(fighter1.isDead()) {
				winner = fighter2;
				break;
			}
		}
		System.out.print("Le gagnant est le " + winner);
		return winner;
	}
	
	public static void main(String[] args){
		var r1 = new Robot("D2R2");
		var r2 = new Robot("Data");
		try {
			fight(r1, r2);
		}catch(Exception e){
			e.printStackTrace();
		}
		
		var john = new Fighter("John", 24);
		var jane = new Fighter("Jane", 2);
	    System.out.println(Arena.fight(john, jane) + " wins");

	}
}

//1
// A pseudo random number generator is an algorithm that generates
// a sequence of (approximates) random numbers.
// It is not truly random because is it determined by the initial value that we call the seed
// So the seed is this arbitrary number that determines the strating state of the generator

//3
// We shouldn't have anything decalred other than privates because if we don't, anyone can modify our fields
// Indeed, with private visibilty the users are forced to use the interfaces (methods) we provide them. 
// This way, the developper have all the control on what it is possible to do

//5
// Copy paste gives us problems to maintain code with inheritance
// because it duplicates the code

//6
// The method should be protected

//9
// Subtyping
// Subtyping is all about types.
// It describes a relashionship between types where the operations defined
// for a superype can be safely substituted with the the ones of the subtype.

// Example
// In our code Fighter is a subtype of Robot.
// Fighter is a type of Robot but Robot is not a fighter
// This means that the operations available with Robot can safely accept
// to operate with data of type Fighter. But the reverse operations is impossible.

// Polymorphism 
// Polymorphism means "many forms", and it occurs when we have classes that
// are related to each other by inheritance.
// Polymorphism allows us to perform a single action in different ways. 
// In other words, polymorphism allows you to define one interface and have multiple implementations.

// Example
// The method rollDice() have multiple implementations.



