import java.util.Random;
import java.util.function.LongSupplier;
import java.util.stream.Collectors;

public class Ex4 {
	
	//Ex4 - 1
	//The variable list2 contains a list of 1 000 000 random numbers between 0 and 100 as a String
	public static void main(final String[] args) {
		var list2 =new Random(0)
				.ints(100_000_000, 0, 100)
				.mapToObj(Integer::toString)
				.collect(Collectors.toList()); 
		
			printAndTime(() -> Ex1.count(list2, "33"));
	     printAndTime(() -> Ex1.count2(list2, "33"));
	     printAndTime(() -> Ex3.count3(list2, "33"));
		
    }
	
	//Ex4 - 2 
	
	public static void printAndTime(LongSupplier funct) {
		Long start = System.nanoTime();
		var result = funct.getAsLong();
		System.out.println(result);
		Long end = System.nanoTime();
		
		Double time = ((end - start) / 1000000000.0);
		
		String timeStr = "Time " + time + " s";
		System.out.println(timeStr);
	}
	
	
}
