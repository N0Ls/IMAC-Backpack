import java.util.List;

public class Ex3 {
	
	//Ex3 - 1
	//We are not going to use the mapToInt method because it is more specialized
	//because it returns an explicit IntStream instead of a generic stream.
	
	public static int count3(List<String> list, String elem) {
		
		//return list.stream().filter(v -> v.equals(elem)).mapToInt(x->1).reduce(0, Integer::sum);
		
		return list.stream().mapToInt(v -> v.equals(elem) ? 1 : 0).sum();
	}
	
    public static void main(final String[] args) {
    	var list = List.of("hello", "world", "hello", "lambda");
        System.out.println(count3(list, "hello"));  // 2   
    }
	
	
}
