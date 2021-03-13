import java.lang.Integer;
import java.util.Arrays;

public class StringToIntegers {
	public static int[] stringArrayToIntArray(String[] args) {
		var IntArray = new int[args.length];
		for(int i=0; i<args.length ; i++) {
			IntArray[i]= Integer.parseInt(args[i]);
		}
		
		return IntArray;

	}
	public static int sumElementsOfIntArray(int[] intArray) {
		var sum = 0;
		for(var intUnique : intArray) {
			sum = sum + intUnique;
		}
		return sum;
	}
	public static void main(String[] args) {
		var IntArrayFromArgs = stringArrayToIntArray(args);
		
		//Display the Int array
//		for(var arg : IntArrayFromArgs) {
//			System.out.println(arg);
//		}
		System.out.println(Arrays.toString(IntArrayFromArgs));

		
		var result = sumElementsOfIntArray(IntArrayFromArgs);
		System.out.println("The sum of the arguments is : " + result);
	}
}


//2
// Static means that we can use this method without having to create an instance of the class

//3
//It throws an exception 