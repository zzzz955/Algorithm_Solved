import java.util.*;
import java.io.*;

class Main {
    static TreeMap<String, Integer> dic = new TreeMap<>();
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        String treeName = br.readLine();
        double cnt = 0;
        try {
            while (!treeName.isEmpty()) {
                cnt++;
                if (dic.containsKey(treeName)) {
                    dic.put(treeName, dic.get(treeName) + 1);
                } else {
                    dic.put(treeName, 1);
                }
                treeName = br.readLine();
            }
        } catch (Exception e) {
            
        }

        for (var entry : dic.entrySet()) {
            bw.write(entry.getKey() + " " + String.format("%.4f", entry.getValue() / cnt * 100) + "\n");
        }

        br.close();
        bw.close();
    }
}