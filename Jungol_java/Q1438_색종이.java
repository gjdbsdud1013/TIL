import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Q1438_������ {
	static int[][] map = new int[100][100];
	static int N, r, c;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		for (int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			r = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			for (int y = r; y < r + 10; y++) {
				for (int x = c; x < c + 10; x++) {
					map[y][x] = 1;
				}
			}
		}
		int res = 0;
		for (int y = 0; y < 100; y++) {
			for (int x = 0; x < 100; x++) {
				if(map[y][x] == 1) res++;
			}
		}
		System.out.println(res);
	}
}
