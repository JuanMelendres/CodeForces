/*
    Juan Antonio Melendres Villa A00369017
*/
import java.util.*;
import java.io.*;

public class Main {

	static BufferedReader rd;
	static StringTokenizer tk;

	public static void init(InputStream input) {
		rd = new BufferedReader(new InputStreamReader(input));
		tk = new StringTokenizer("");
	}

	public static String next() throws IOException {
		while (!tk.hasMoreTokens()) {
			tk = new StringTokenizer(rd.readLine());
		}
		return tk.nextToken();
	}

	public static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	public static int potencia(int base, int exp) {
		if (exp == 0) {
			return 1;
		}
		if ((exp & 1) == 0) {
			int raiz = potencia(base, exp / 2);
			return (raiz * raiz) % 10;
		}
		else {
			return (base * potencia(base, exp - 1)) % 10;
		}
	}

	public static void main(String[] args) throws IOException {
		Main.init(System.in);
		int n = Main.nextInt();
		int l = Main.nextInt();
		int[] datos = new int[n];
		int res = 0;
		for (int i = 0; i < n; i++) {
			datos[i] = Main.nextInt();
		}
		for (int i = l; i <= 100; i++) {
			int cont = 0;
			for(int x : datos) {
				cont += x / i;
			}
			res = Math.max(cont * i, res);
		}
		System.out.println(res);
	}

}
