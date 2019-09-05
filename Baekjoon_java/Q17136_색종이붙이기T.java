import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Q17136_색종이붙이기T {
	private static int[][] m = new int[10][10];
	private static int min, sum;
	private static int[] p = { 0, 5, 5, 5, 5, 5 }; // 색종이의 남은 장수. 0번은 안씀
	public static void main(String[] args) throws IOException {
		// input
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		sum = 0; // 1의 개수를 누적 할 변수
		for (int i = 0; i < 10; i++) {
			String str = br.readLine();
			for (int j = 0, index = 0; j < 10; j++, index += 2) {
				m[i][j] = str.charAt(index) - '0';
				sum += m[i][j];
			}
		}
		min = Integer.MAX_VALUE;
		if (sum < 3) {
			min = sum;
		} else if (sum == 100) {
			min = 4;
		} else {
			dfs(0, sum);
		}
		System.out.println(min == Integer.MAX_VALUE ? -1 : min);
	}
	
	private static void dfs(int cnt, int sum) { // cnt : 사용한 색종이의 갯수
		if (min < cnt) { // 이미 최소값보다 커졌다면 종료
			return;
		}
		if (sum == 0) { // m 배열에 더이상 1이 없으면 종료
			if(min > cnt) min = cnt;
			return;
		} else { // 재귀 파트
			int r = -1;
			int c = -1;
	ex:		for (r = 0; r < 10; r++) { // 맵에서 1의 위치를 체크
				for (c = 0; c < 10; c++) {
					if (m[r][c] == 1) {
						break ex;
					}
				}
			}
			int maxSize = 5;
			for (; maxSize >= 1; maxSize--) { // 큰 종이를 붙일 수 있다면, 그보다 작은 종이는 당연히 붙일 수 있음
				if(check(r, c, maxSize)) {
					break;
				}
			}
			for (int size = maxSize; size >= 1; size--) { // maxSize ~ 1까지의 크기 색종이를 붙여보자
				if (p[size] > 0) { // 사이즈의 색종이가 남아있으면
					paint(r, c, size, 0); // 사이즈만큼의 사각영역을 0으로 덮자
					p[size]--; // 사용한 색종이 감소
					// 다음 칸으로 재귀 호출
					dfs(cnt + 1, sum - (size * size));
					paint(r, c, size, 1);// 0으로 덮은 사각영역을 다시 1로
					p[size]++;// 사용한 색종이 증가 원복
				}
			}
		}
	}
	
	// (r,c) 좌표에서 시작하는 size 크기의 정사각형에 val로 채우는 메소드
	private static void paint(int r, int c, int size, int num) {
		for (int i = r; i < r + size; i++) {
			for (int j = c; j < c + size; j++) {
				m[i][j] = num;
			}
		}
	}
	
	// r,c 좌표에서 시작하는 size크기의 정사각형 영역이 모두 1인지 검사하는 메서드
	private static boolean check(int r, int c, int size) {
		if (r + size > 10 || c + size > 10) { // 색종이가 영역에서 벗어남
			return false;
		}
		for (int i = r; i < r + size; i++) {
			for (int j = c; j < c + size; j++) {
				if (m[i][j] == 0) {
					return false;
				}
			}
		}
		return true;
	}
}
