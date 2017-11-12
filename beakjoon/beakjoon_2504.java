/*
 * 1. 입력이 여는 괄호이면 push
 * 2. 입력이 닫는 괄호이면 아래와 같은 프로세스를 한다.
 * 	2-1 스택에서 top 을 확인
 * 	2-2 만약 닫는 괄호이면 여는 괄호에 따라 x값을 설정
 * 	2-3 만약 숫자이면 x에 괄호를 곱한다.
 * 	2-4 스택 top 을 확인해서 숫자이면 x와 top값을 더해서 push
 * 
 */
		
import java.util.*;
public class Main {
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		process(scan.nextLine());
		
	}
	public static void process(String str) {
		Stack<String> stack = new Stack<String>();
		int i = 0;
		
		for(; i<str.length(); ++i) {
			if(str.charAt(i) == '(' || str.charAt(i) == '[') {
				stack.push(Character.toString(str.charAt(i)));
			}
			else {
				
				int x = 0;
				String p = stack.pop();
				if(p.equals("(") || p.equals("[")) {
					if(p.equals("(") && str.charAt(i) == ')') 
						x += 2;
					else if (p.equals("[") && str.charAt(i) == ']') 
						x += 3;
					else {
						//괄호 짝이 만맞는 경우 실패 
						break;
					}
				}
				else {
					x += Integer.parseInt(p);
					p = stack.pop();
					if(p.equals("(") && str.charAt(i) == ')') 
						x *= 2;
					else if (p.equals("[") && str.charAt(i) == ']') 
						x *= 3;
					else {
						//괄호 짝이 만맞는 경우 실패 
						break;
					}
				}
				
				if(!stack.isEmpty() && !stack.peek().equals("(") && !stack.peek().equals("[")) {
					x += Integer.parseInt(stack.pop());
				}
				
				stack.push(Integer.toString(x));
			}
		}
		
		if(i == str.length() && stack.size() == 1)
			System.out.println(stack.pop());
		else
			System.out.println(0);
	}
}

