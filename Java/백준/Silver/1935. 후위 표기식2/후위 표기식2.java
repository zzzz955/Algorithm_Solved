import java.util.*;
import java.io.*;

class Main {
    static HashMap<Character, Double> dic = new HashMap<>();
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        String s = br.readLine();
        for (char c = 'A'; c < 'A' + N; ++c) {
            st = new StringTokenizer(br.readLine());
            double M = Double.parseDouble(st.nextToken());
            dic.put(c, M);
        }

        Deque<Double> stack = new ArrayDeque<>();
        for (int i  = 0; i < s.length(); ++i) {
            char ch = s.charAt(i);
            if ('A' <= ch && ch <= 'Z') {
                stack.push(dic.get(ch));
            }
            else {
                Double two = stack.pop();
                Double one = stack.pop();

                Double three;
                if (ch == '*') {
                    three = one * two;
                }
                else if (ch == '/') {
                    three = one / two;
                }
                else if (ch == '+') {
                    three = one + two;
                }
                else {
                    three = one - two;
                }
                stack.push(three);
//                bw.write(one + " " + two + " " + three + "\n");
//                bw.flush();
            }
        }
        bw.write(String.format("%.2f", stack.pop()));

        br.close();
        bw.close();
    }
}