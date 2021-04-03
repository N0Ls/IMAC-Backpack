
public enum AppleKind {
	Golden, PinkLady, GrannySmith;
	
	@Override
	public String toString() {
		switch(this) {
			case Golden : return "Golden";
			case PinkLady : return "Pink Lady";
			case GrannySmith : return "Granny Smith"; 
			default : throw new IllegalArgumentException("Error in apple kind");
		}
	}
}
