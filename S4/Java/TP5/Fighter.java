package fr.umlv.fight;
import java.util.Random;

public class Fighter extends Robot{
	
	Random randomGenerator;
	public Fighter(String name, long randSeed) {
		super(name);
		this.randomGenerator = new Random(randSeed);
	}
 	
 	@Override
 	protected String getType() {
 		return "Fighter";
 	}
 	
 	
 	@Override
 	protected boolean rollDice() {
		return randomGenerator.nextBoolean();
	}
 

}

//
