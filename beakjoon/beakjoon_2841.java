
import java.util.*;

public class Main {
	
	static int ans = 0;
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		Stack<Integer> line1 = new Stack<Integer>();
		Stack<Integer> line2 = new Stack<Integer>();
		Stack<Integer> line3 = new Stack<Integer>();
		Stack<Integer> line4 = new Stack<Integer>();
		Stack<Integer> line5 = new Stack<Integer>();
		Stack<Integer> line6 = new Stack<Integer>();
		
		
		int n = input.nextInt();
		int p = input.nextInt();
		
		
		for(int i = 0; i<n; ++i) {
			
			int line = input.nextInt();
			int pret = input.nextInt();
			
			switch(line) {
			case 1 : 
				process(line1, pret);
				break;
			case 2 : 
				process(line2, pret);
				break;
			case 3 : 
				process(line3, pret);
				break;
			case 4 :
				process(line4, pret);
				break;
			case 5 : 
				process(line5, pret);
				break;
			case 6 : 
				process(line6, pret);
				break;
			}
		}		
		
		System.out.println(ans);
	}
	public static void process(Stack<Integer> stack, int pret) {
		
		while(!stack.empty() && stack.peek() > pret) {
			stack.pop();
			++ans;
		}
		if(stack.empty() || stack.peek() < pret) {
			stack.push(pret);
			++ans;
		}
	}
}


