import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class Ex2 {
	
	//Ex2 - 1
	public static List<String> upperCase(List<String> list){
		List<String> upperCaseList = new ArrayList<String>();
		
		for(String elem : list) {
			upperCaseList.add(elem.toUpperCase());
		}
		
		return upperCaseList;
		
	}
	
	//Ex2 - 2 
	
	//The map() method allows us to apply a function to each element of the stream
	public static List<String> upperCase2(List<String> list){
		List<String> upperCaseList = new ArrayList<String>();
		
		list.stream().map(str -> str.toUpperCase()).forEach(str -> upperCaseList.add(str));
		
		return upperCaseList;
	}
	
	//Ex2 - 3 
	public static List<String> upperCase3(List<String> list){
		List<String> upperCaseList = new ArrayList<String>();
		
		list.stream().map(String::toUpperCase).forEach(str -> upperCaseList.add(str));
		
		return upperCaseList;
	}
	
	//Ex2 - 4
	public static List<String> upperCase4(List<String> list){
	
		return list.stream().map(str -> str.toUpperCase()).collect(Collectors.toList());
	}
	
	public static void main(final String[] args) {
		var list = List.of("hello", "world", "hello", "lambda");
		System.out.println(upperCase(list));  // [HELLO, WORLD, HELLO, LAMBDA]
		System.out.println(upperCase4(list));
    }
}
