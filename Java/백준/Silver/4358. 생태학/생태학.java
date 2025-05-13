import java.util.*;
import java.io.*;

class Main {
    static HashMap<String, Integer> dic = new HashMap<>();
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static class KV {
        String key;
        String value;
        KV(String key, String value) {
            this.key = key;
            this.value = value;
        }
    }

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

        ArrayList<KV> kvs = new ArrayList<>();
        for (var entry : dic.entrySet()) {
            kvs.add(new KV(entry.getKey(), String.format("%.4f", entry.getValue() / cnt * 100)));
        }

        kvs.sort((kv1, kv2) -> kv1.key.compareTo(kv2.key));
        for (KV kv : kvs) {
            bw.write(kv.key + " " + kv.value + "\n");
        }

        br.close();
        bw.close();
    }
}