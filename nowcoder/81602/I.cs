using System.Runtime.CompilerServices;
using System.Text;
using System;

using static IO;

public static class Program
{
    public static bool Check(long a1, long k, long m, long h)
    {
        long sum = a1, term = a1;
        while (sum < h && term >= m)
        {
            long append = term / m * k;
            sum += append;
            term = term % m + append;
        }
        return sum >= h;
    }

    [MethodImpl(MethodImplOptions.AggressiveInlining | MethodImplOptions.AggressiveOptimization)]
    public static void Solve()
    {
        long m = ReadLong(), k = ReadLong(), h = ReadLong();
        if (k == m)
        {
            Out(Math.Min)
        }
    }

    public static void Main(string[] args)
    {
        using (AutoFlush())
        {
            var t = ReadInt();
            while (--t >= 0)
                Solve();
        }
    }
}

public static class IO
{
    public static readonly StreamWriter writer;
    public static readonly StreamReader reader;

    static IO()
    {
        var input = Console.OpenStandardInput();
        var output = Console.OpenStandardOutput();
        writer = new StreamWriter(output, Encoding.ASCII, 1024);
        reader = new StreamReader(input, Encoding.ASCII, false, 1024);
        writer.AutoFlush = false;
    }

    [MethodImpl(MethodImplOptions.AggressiveInlining | MethodImplOptions.AggressiveOptimization)]
    public static long ReadLong()
    {
        int c = ' ';
        while ((c < '0' || c > '9') && c != '-')
            c = reader.Read();

        var negative = c == '-';
        long result = 0;
        if (negative)
            c = reader.Read();

        while (c >= '0' && c <= '9')
        {
            result = result * 10 + (c - '0');
            c = reader.Read();
        }
        result *= negative ? -1 : 1;
        return result;
    }
    
    [MethodImpl(MethodImplOptions.AggressiveInlining | MethodImplOptions.AggressiveOptimization)]
    public static char ReadChar() => (char)reader.Read();
    
    [MethodImpl(MethodImplOptions.AggressiveInlining | MethodImplOptions.AggressiveOptimization)]
    public static int ReadInt()
    {
        int c = ' ';
        while ((c < '0' || c > '9') && c != '-')
            c = reader.Read();

        var negative = c == '-';
        int result = 0;
        if (negative)
            c = reader.Read();

        while (c >= '0' && c <= '9')
        {
            result = result * 10 + (c - '0');
            c = reader.Read();
        }
        result *= negative ? -1 : 1;
        return result;
    }
    
    [MethodImpl(MethodImplOptions.AggressiveInlining | MethodImplOptions.AggressiveOptimization)]
    public static string ReadString()
    {
        var result = string.Empty;
        Span<char> buffer = stackalloc char[256];
        int len = 0;
        int c = reader.Read();
        while (c == ' ' || c == '\n' || c == '\r' || c == -1) c = reader.Read();
        while (c != -1 && c != ' ' && c != '\r' && c != '\n')
        {
            buffer[len++] = (char)c;
            if (len == buffer.Length)
            {
                result += new string(buffer);
                len = 0;
            }

            c = reader.Read();
        }
        result += new string(buffer.Slice(0, len));
        return result;
    }


    [MethodImpl(MethodImplOptions.AggressiveInlining | MethodImplOptions.AggressiveOptimization)]
    public static void Out(string v) => writer.Write(v);
    
    [MethodImpl(MethodImplOptions.AggressiveInlining | MethodImplOptions.AggressiveOptimization)]
    public static void Out(int v) => writer.Write(v.ToString());
    
    [MethodImpl(MethodImplOptions.AggressiveInlining | MethodImplOptions.AggressiveOptimization)]
    public static void Out(long v) => writer.Write(v.ToString());
    
    [MethodImpl(MethodImplOptions.AggressiveInlining | MethodImplOptions.AggressiveOptimization)]
    public static void Out(char v) => writer.Write(v);
    
    [MethodImpl(MethodImplOptions.AggressiveInlining | MethodImplOptions.AggressiveOptimization)]
    public static void Endl() => writer.WriteLine();


    [MethodImpl(MethodImplOptions.AggressiveInlining | MethodImplOptions.AggressiveOptimization)]
    public static void Flush() => writer.Flush();
    

    [MethodImpl(MethodImplOptions.NoInlining)]
    public static FlushDisposable AutoFlush() => default;


    public struct FlushDisposable : IDisposable
    {
        public void Dispose() => writer.Flush();
    }
}