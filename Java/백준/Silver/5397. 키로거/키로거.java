import java.util.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(st.nextToken());

        while (T-- > 0) {
            LinkedList<Character> list = new LinkedList<>();
            ListIterator<Character> it = list.listIterator();
            String s = br.readLine();
            int idx = 0;
            for (int i = 0; i < s.length(); i++) {
                char c = s.charAt(i);
                if (c == '<') {
                    if (it.hasPrevious()) it.previous();
                }
                else if (c == '>') {
                    if (it.hasNext()) it.next();
                }
                else if (c == '-') {
                    if (it.hasPrevious()) {
                        it.previous();
                        it.remove();
                    }
                }
                else {
                    it.add(c);
                }
//                bw.write(c + " " + idx + "\n");
//                bw.flush();
            }
            for (Character c : list) {
                bw.write(c);
            }
            bw.write("\n");
        }

        br.close();
        bw.close();
    }
}