/*  */
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace CSharp
{
    class Program
    {
        [DllImport("user32.dll")]
        private static extern bool BlockInput(bool block);

        [DllImport("kernel32.dll", SetLastError = true, CharSet = CharSet.Auto)]
        static extern ushort GlobalAddAtom(string lpString);

        [DllImport("kernel32.dll", SetLastError = true, ExactSpelling = true)]
        static extern ushort GlobalDeleteAtom(ushort nAtom);

        [DllImport("kernel32.dll", SetLastError = true, CharSet = CharSet.Auto)]
        static extern ushort GlobalFindAtom(string lpString);

        static void Main(string[] args)
        {
            Console.Title = "C#";
            if (GlobalFindAtom("test") == 0)
                GlobalAddAtom("test");
        }
    }
}
