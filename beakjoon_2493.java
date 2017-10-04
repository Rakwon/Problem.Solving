
/*
 * 입력의 크가가 500000이므로 O(n) 이하 시간의 알고리즘을 생각해야함
 *
 * 풀이
 * 1. 먼저 입력을 배열에 담는다.(arr)
 * 2. 입력으로 받은 배열을 하나씩 순회 하면서 다음과 같은 동작을 한다.
 * 	2-1 첫번째 기둥은 아무도 수신 하지 못함 ans[0] = -1(출력부에서 0으로 바꿈)
 * 	2-2 그다음기둥부터는 그 전기둥의 높이를 비교한다.
 * 		2-2-1 이전 기둥 높이가 더 크면 바로 이전 기둥이 수신 할 수 있으므로 ans[i] = i-1
 * 		2-2-2 이전 기둥높이가 더 작은경우 다음과 같은 사실을 알 수 있다.
 * 			# 이전 기둥의 신호를 수신 할 수 있는 기둥의 정보는 ans[i-1](i-1번째 기둥의 신호를 수신하는 기둥의 위치)에 들어있음.
 * 			# 이전 기둥의 신호를 수신 할 수 있는 기둥은 이전 기둥보다 높이가 높다.
 * 			# 따라서 이전 기둥들을 따라가다 보면 i번쨰 기둥보다 크거나 혹은 더 큰 기둥이 없는 경우로 나뉜다.
 * 		2-2-3 이전 기둥의 인덱스를 활용하여 i 번째 기둥을 수신 할 수 있는 기둥의 위치를 찾아간다.(before_index = ans[before_index])
 * 		2-2-4 ans[i] = befor_index
 * 	2-3 ans 를 출력한다.		
 */

import java.util.*;
public class Main {
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int arr[] = new int[500001];
		int ans[] = new int[500001];
		
		
		int n = scan.nextInt();
		scan.nextLine();
		
		for(int i = 0; i < n; arr[i++] = scan.nextInt()); 

		ans[0] = -1;
		for(int i = 1; i<n; ++i) {
			if(arr[i-1] > arr[i]) {
				ans[i] = i-1;
 			}
			else {
				int before_index = ans[i-1];
				for(; before_index != -1 && arr[before_index] < arr[i]; before_index = ans[before_index]);
				ans[i] = before_index;
			}
		}
		
		for(int i = 0; i<n; ++i) {
			if(arr[i] == -1) 
				System.out.println("0 ");
			else
				System.out.print(ans[i]+1+" ");
		}
	}
}

