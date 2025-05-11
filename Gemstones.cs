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

}
