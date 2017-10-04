
/*
 * 입력 크기가 1,000,000이기때문에 O(n) 시간 알고리즘을 생각.
 * 
 * 풀이.
 * 1. 입력 문자열과, 폭탄 물자열을 입력받는다.
 * 2. 입력 문자열을 하나씩 순회하면서 다음과 같은 작업을 한다
 * 	2-1 입력문자열을 하나씩 스택에 담는다.
 * 	2-2 입력문자열중 폭탄 문자열 마지막 문자와 같은 문자가 스택에 들어간 경우 스택에서 하나씩 빼면서 폭탄문자열과 비교한다.
 * 	2-3 폭탄문자열이 맞는 경우 폭탄문자열이 빠진 스택으로 2-1로 복귀 
 *  2-4 폭탄문자열이 아닌 경우 비교하기 위해 스택에서 뺐던 문자들을 다시 스택에 담고 2-1로 복귀
 *  
 */
import java.util.*;
public class Main {
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		Stack<Character> stack = new Stack<Character>();
		Stack<Character> ans = new Stack<Character>();
		
		String str = scan.nextLine();
		String bomb = scan.nextLine();
		
		for(int i = 0; i < str.length(); ++i) {
			stack.push(str.charAt(i));
			if(str.charAt(i) == bomb.charAt(bomb.length()-1)) {	
				checkBomb(stack, str, bomb);
			}
		}
		if(stack.empty())
			System.out.println("FRULA");
		else {
			while(!stack.empty())
				ans.push(stack.pop());
			while(!ans.empty())
				System.out.print(ans.pop());
		}
	}
	public static void checkBomb(Stack<Character> stack, String str, String bomb) {
		Stack<Character> basket = new Stack<Character>();
		
		int i = bomb.length() - 1; 
		for(; !stack.empty() && i >= 0 && bomb.charAt(i) == stack.peek() ; --i, basket.push(stack.pop()));
		
		if(i != -1) {
			while(!basket.isEmpty())
				stack.push(basket.pop());
		}
	}
}

