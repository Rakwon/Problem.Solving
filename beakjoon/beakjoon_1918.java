
import java.util.*;

public class Main {
	
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String inorder = input.nextLine();
		Stack<Character> stack = new Stack<Character>();
		int len = inorder.length();
		
		for(int i = 0; i<len; ++i) {
			if(inorder.charAt(i) - 0 >= 65 && inorder.charAt(i) - 0 <= 90) {
				System.out.print(inorder.charAt(i));
			}
			else {
				
				if(stack.empty() || inorder.charAt(i) == '(') 
					stack.push(inorder.charAt(i));
				else if(inorder.charAt(i) == ')') {
					while(stack.peek() != '(')
						System.out.print(stack.pop());
					stack.pop();
				}
				else if(compareOperation(stack.peek(), inorder.charAt(i)) == 0) {
					while(!stack.empty() && compareOperation(stack.peek(), inorder.charAt(i)) == 0)
						System.out.print(stack.pop());
				
					stack.push(inorder.charAt(i));
				}
				else {
					stack.push(inorder.charAt(i));
				}
			}
		}
		
		int slen = stack.size();
		for(int i = 0 ; i<slen; System.out.print(stack.pop()), ++i);
	}
	
	public static int compareOperation(char a, char b) {
		
		int pri1 = getPriority(a);
		int pri2 = getPriority(b);
		
		return pri1 >= pri2 ? 0 : 1;
	}

	public static int getPriority(char ch) {
		
		switch(ch) {
		case '+':
			return 1;
		case '-':
			return 1;
		case '/':
			return 2;
		case '*':
			return 2;
		default : 
			return -1;
		}
	}
}



