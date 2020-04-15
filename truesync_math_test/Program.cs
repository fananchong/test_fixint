using System;
using TrueSync;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            test(1999.5f, 1.1f);
            test(1000.0f, 33.0f);
        }

        static private void test(float num1, float num2)
        {
            Console.WriteLine("num1:{0}, num2:{1}", num1, num2);

            float a1 = add1(num1, num2);
            float a2 = add2(num1, num2);
            Console.WriteLine("add, a1={0}({1}), a2={2}({3})", HexToString(a1), a1, HexToString(a2), a2);

            a1 = sub1(num1, num2);
            a2 = sub2(num1, num2);
            Console.WriteLine("sub, a1={0}({1}), a2={2}({3})", HexToString(a1), a1, HexToString(a2), a2);

            a1 = mul1(num1, num2);
            a2 = mul2(num1, num2);
            Console.WriteLine("mul, a1={0}({1}), a2={2}({3})", HexToString(a1), a1, HexToString(a2), a2);

            a1 = div1(num1, num2);
            a2 = div2(num1, num2);
            Console.WriteLine("div, a1={0}({1}), a2={2}({3})", HexToString(a1), a1, HexToString(a2), a2);
        }

        static private float add1(float n1, float n2) { return n1 + n2; }
        static private float sub1(float n1, float n2) { return n1 - n2; }
        static private float mul1(float n1, float n2) { return n1 * n2; }
        static private float div1(float n1, float n2) { return n1 / n2; }
        static private float add2(float n1, float n2) { return FP.ToFloat((FP.FromFloat(n1) + FP.FromFloat(n2))); }
        static private float sub2(float n1, float n2) { return FP.ToFloat((FP.FromFloat(n1) - FP.FromFloat(n2))); }
        static private float mul2(float n1, float n2) { return FP.ToFloat((FP.FromFloat(n1) * FP.FromFloat(n2))); }
        static private float div2(float n1, float n2) { return FP.ToFloat((FP.FromFloat(n1) / FP.FromFloat(n2))); }

        static private string HexToString(float valf)
        {
            byte[] bytes = BitConverter.GetBytes(valf);
            string hexString = "";
            for (int i = bytes.Length - 1; i >= 0; i--)
            {
                hexString += bytes[i].ToString("X2");
            }
            return hexString;
        }
    }
}
