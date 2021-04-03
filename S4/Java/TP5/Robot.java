package fr.umlv.fight;

public class Robot {
	private final String name;
	private int health;
	private boolean isDead;
	
	protected String name() {
		return this.name;
	}
	
	public Robot(String name) {
		this.health = 10;
		this.name = name;
		this.isDead = false;
	}
	
	public void fire(Robot attacked) {
		if(rollDice()) {
			if(attacked.isDead()) {
				throw new IllegalStateException("Your opponent is already dead");
			}
	 		attacked.health -= 2;
	 		System.out.println(attacked.toString() + " a été touché par le " + this.toString());
	 		if(attacked.health <= 0) {
	 			attacked.isDead = true;
	 		}
		}

 	}
	
	public boolean isDead() {
 		return isDead;
 	}
	
	protected String getType() {
		return "Robot";
	}
	
	protected boolean rollDice() {
		return true;
	}
	
 	@Override
 	public String toString() {
 		return getType() + name();
 	}

	public static void main(String[] args){
		var bob = new Robot("bob");
		System.out.println(bob);
	}
}



