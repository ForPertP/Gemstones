using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

class Result
{

    /*
     * Complete the 'gemstones' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts STRING_ARRAY arr as parameter.
     */

    public static int gemstones(List<string> arr)
    {
        var common = new BitArray(26, true);

        foreach (var rock in arr)
        {
            var current = new BitArray(26);
            foreach (char c in rock)
            {
                current[c - 'a'] = true;
            }
            common.And(current);
        }

        int count = 0;
        foreach (bool b in common)
            if (b) count++;

        return count;
    }
    
    
    public static int PopCount(int n)
    {
        int count = 0;
        while (n != 0)
        {
            n &= (n - 1);
            count++;
        }
        return count;
    }

    public static int gemstones2(List<string> arr)
    {
        int common = (1 << 26) - 1;

        foreach (var rock in arr)
        {
            int mask = 0;
            foreach (char c in rock)
            {
                mask |= 1 << (c - 'a');
            }
            common &= mask;
        }

        return PopCount(common);
    }
    
    
    public static int gemstones3(List<string> arr)
    {
        int gemsCount = 0;
        var mp = new Dictionary<int, int>();

        foreach (var rock in arr)
        {
            var st = new HashSet<int>();
            foreach (char c in rock)
            {
                st.Add(c - 'a');
            }

            foreach (int ch in st)
            {
                if (mp.ContainsKey(ch))
                    mp[ch]++;
                else
                    mp[ch] = 1;
            }
        }

        foreach (var pair in mp)
        {
            if (pair.Value == arr.Count)
                gemsCount++;
        }

        return gemsCount;
    }
}


class Solution
{
    public static void Main(string[] args)
    {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        int n = Convert.ToInt32(Console.ReadLine().Trim());

        List<string> arr = new List<string>();

        for (int i = 0; i < n; i++)
        {
            string arrItem = Console.ReadLine();
            arr.Add(arrItem);
        }

        int result = Result.gemstones(arr);

        textWriter.WriteLine(result);

        textWriter.Flush();
        textWriter.Close();
    }
}
