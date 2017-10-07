/*
 * 
 * 입력 1,000,000 개 이므로 O(n)
 * 
 * 풀이 
 * 	문제에서 제시한대로 각 기능별로 나누어서 처리
 * 	1. < 이면 왼쪽 화살표
 * 	2. > 이면 오른쪽 화살표 
 * 	3. - 이면 백스페이스
 * 
 */
import java.util.*;

public class Main {
	
	public static void main(String[] args) {

		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		input.nextLine();
		
		Stack<Character> ans = new Stack<Character>();
		Stack<Character> temp = new Stack<Character>();
		
		for(int i = 0; i<n; ++i) {
			ans.clear();
			temp.clear();
			
			String str = input.nextLine();
			
			int len = str.length();
			for(int j = 0; j<len; ++j) {
				
				switch(str.charAt(j)) {
				case '<':
					if(!ans.isEmpty()) temp.push(ans.pop());
					break;
				case '>':
					if(!temp.isEmpty()) ans.push(temp.pop());
					break;
				case '-':
					if(!ans.isEmpty()) ans.pop();
					break;
				default:
					ans.push(str.charAt(j)) ;
					break;
				}
			}
			
			Iterator<Character> it = ans.iterator();
			while(it.hasNext()) System.out.print(it.next());
			int size = temp.size();
			for(int j = 0; j < size; System.out.print(temp.pop()), ++j);
			System.out.println("");
		}
	}
}


