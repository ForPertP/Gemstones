import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'gemstones' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts STRING_ARRAY arr as parameter.
     */

    public static int gemstones(List<String> arr) {
        BitSet common = new BitSet(26);
        common.set(0, 26);

        for (String rock : arr) {
            BitSet current = new BitSet(26);
            for (char c : rock.toCharArray()) {
                current.set(c - 'a');
            }
            common.and(current);
        }

        return common.cardinality();
    }


    public static int popCount(int n) {
        int count = 0;
        while (n != 0) {
            n &= (n - 1);
            count++;
        }
        return count;
    }

    public static int gemstones2(List<String> arr) {
        int common = (1 << 26) - 1;

        for (String rock : arr) {
            int mask = 0;
            for (char c : rock.toCharArray()) {
                mask |= 1 << (c - 'a');
            }
            common &= mask;
        }

        return popCount(common);
    }


    public static int gemstones3(List<String> arr) {
        int gemsCount = 0;
        Map<Integer, Integer> mp = new HashMap<>();

        for (String rock : arr) {
            Set<Integer> st = new HashSet<>();
            for (char c : rock.toCharArray()) {
                st.add(c - 'a');
            }

            for (int ch : st) {
                mp.put(ch, mp.getOrDefault(ch, 0) + 1);
            }
        }

        for (int count : mp.values()) {
            if (count == arr.size()) {
                gemsCount++;
            }
        }

        return gemsCount;
    }
}


public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = Integer.parseInt(bufferedReader.readLine().trim());

        List<String> arr = IntStream.range(0, n).mapToObj(i -> {
            try {
                return bufferedReader.readLine();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        })
            .collect(toList());

        int result = Result.gemstones(arr);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
