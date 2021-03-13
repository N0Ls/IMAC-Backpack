public class Pascal {

	public static int pascal(int nBut, int pBut) {
		int tab[] = new int[nBut + 1];
		int n, i;

		tab[0] = 1;

		for (n = 1; n <= nBut; n++) {
			tab[n] = 1;

			for (i = n - 1; i > 0; i--)
				tab[i] = tab[i - 1] + tab[i];
		}

		return tab[pBut];
	}

	public static void main(String[] args) {
		System.out.printf("Cn, p = %d\n", pascal(30000, 250));
	}

}


//TIME FOR C (without -O2)
//real    0m1.778s
//user    0m1.343s
//sys     0m0.015s

//TIME FOR JAVA
//real    0m0.422s
//user    0m0.016s
//sys     0m0.000s

//The difference might be explained by the optimizations made by the compiler 
// or the way that java handles the memory 