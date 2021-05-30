import java.util.List;
import java.util.function.Predicate;

public class Ex1 {
	
	//Ex1 - 1
	public static Long count(List<String> list, String elem) {
		Long count = (long) 0;
		
		for(final String value : list) {
			if(value.equals(elem)) {
				count++;
			}
		}
		return count;
	}
	
	//Ex1 - 2
	//According to the documentation to get a Stream object from a List object
	//we need to call the .stream() method.
	
	//To filter a stream we need to use the method .filter() with a predicate or a lambda function
	
	//To count the number of elements inside a stream we use the .count() method
	
	public static Long count2(List<String> list, String elem) {
		return list.stream().filter(isValue(elem)).count();
	}
	
	//Predicate to use inside filter 
	public static Predicate<String> isValue(String str){
		return v -> v.equals(str);
	}
	
    public static void main(final String[] args) {
    	var list = List.of("hello", "world", "hello", "lambda");
        System.out.println(count(list, "hello"));  // 2
        System.out.println(count2(list, "hello"));   
    }
}
