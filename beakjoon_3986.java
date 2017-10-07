

import java.util.*;

public class Main {
	
	public static void main(String[] args) {

		Scanner input = new Scanner(System.in);
		Stack<Character> stack = new Stack<Character>();
		
		int n = input.nextInt();
		int ans = 0;
		input.nextLine();
		
		for(int i = 0; i<n; ans += process(input.nextLine(), stack), ++i);
		System.out.println(ans);
	}
	public static int process(String input, Stack<Character> stack) {
		
		stack.clear();
		int len = input.length();
		for(int i = 0; i<len; ++i) {
			if(stack.empty()) stack.push(input.charAt(i));
			else if(stack.peek() == input.charAt(i)) stack.pop();
			else stack.push(input.charAt(i));
		}
		
		return stack.empty() ? 1 : 0;
	}
}


