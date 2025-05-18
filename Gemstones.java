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
    
}
