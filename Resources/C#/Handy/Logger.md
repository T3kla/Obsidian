```cs
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Reflection;
using System.Text;
using Debug = UnityEngine.Debug;

public class Log
{
    enum Nature { None, Info, Warn, Error }

    static readonly string[] IgnoreGlobal = { };
    static readonly string[] IgnoreInfo = { };
    static readonly string[] IgnoreWarn = { };
    static readonly string[] IgnoreError = { };

    static readonly string InfoMessageColor = "c7c7c7";
    static readonly string WarnMessageColor = "c4a64d";
    static readonly string ErrorMessageColor = "eb3d3d";
    static readonly string OwnerDefaultColor = "d4d4d4";

    static readonly Dictionary<string, string> Owners = new()
    {
        { "Game", "87ABED" }, // celeste
        { "Phone", "EDB787" }, // naranja
        { "ObjPooler", "87ED96" }, // lima

        { "1", "ED8793" }, // rojizo
        { "3", "AE87ED" }, // violeta
        { "5", "87EDE1" }, // turquesa
        { "6", "879CED" }, // azul
        { "7", "EAED87" }, // amarillo
        { "8", "ED87DE" }, // rosa
    };

    static StringBuilder Builder = new(2048);

    public static void Info(in string message, in string owner = null)
    {
        var caller = owner ?? GetCaller();
        if (IsIgnored(caller, Nature.Info)) return;
        var color = GetColor(caller);

        Builder.Append("<b><color=#");
        Builder.Append(color);
        Builder.Append(">[");
        Builder.Append(caller);
        Builder.Append("]</color></b> <color=#");
        Builder.Append(InfoMessageColor);
        Builder.Append(">");
        Builder.Append(message);
        Builder.Append("</color>");
        Debug.Log(Builder.ToString());
        Builder.Clear();
    }

    public static void Warn(in string message, in string owner = null)
    {
        var caller = owner ?? GetCaller();
        if (IsIgnored(caller, Nature.Warn)) return;
        var color = GetColor(caller);

        Builder.Append("<b><color=#");
        Builder.Append(color);
        Builder.Append(">[");
        Builder.Append(caller);
        Builder.Append("]</color></b> <color=#");
        Builder.Append(WarnMessageColor);
        Builder.Append(">");
        Builder.Append(message);
        Builder.Append("</color>");
        Debug.LogWarning(Builder.ToString());
        Builder.Clear();
    }

    public static void Error(in string message, in string owner = null, UnityEngine.Object context = null)
    {
        var caller = owner ?? GetCaller();
        if (IsIgnored(caller, Nature.Error)) return;
        var color = GetColor(caller);

        Builder.Append("<b><color=#");
        Builder.Append(color);
        Builder.Append(">[");
        Builder.Append(caller);
        Builder.Append("]</color></b> <color=#");
        Builder.Append(ErrorMessageColor);
        Builder.Append(">");
        Builder.Append(message);
        Builder.Append("</color>");

        if (context == null)
            Debug.LogError(Builder.ToString(), context);
        else
            Debug.LogError(Builder.ToString());

        Builder.Clear();
    }

    private static bool IsIgnored(in string owner, Nature n = Nature.None)
    {
        if (IgnoreGlobal.Has(owner)) return true;
        if (n == Nature.Info && IgnoreInfo.Has(owner)) return true;
        if (n == Nature.Warn && IgnoreWarn.Has(owner)) return true;
        if (n == Nature.Error && IgnoreError.Has(owner)) return true;
        return false;
    }

    private static string GetColor(in string owner)
        => Owners.TryGetValue(owner, out string color) ? color : OwnerDefaultColor;

    private static string GetCaller()
    {
        string fullName;
        Type declaringType;
        int skipFrames = 2;

        do
        {
            MethodBase method = new StackFrame(skipFrames, false).GetMethod();
            declaringType = method.DeclaringType;

            if (declaringType == null)
                return method.Name;

            skipFrames++;
            fullName = declaringType.FullName;
        }
        while (declaringType.Module.Name.Equals("mscorlib.dll", StringComparison.OrdinalIgnoreCase));

        var start = fullName.IndexOf('.') + 1;
        var end = fullName.IndexOf('+');
        if (end == -1) end = fullName.Length;
        var trim = fullName.AsSpan()[start..end];

        // No Span alternative
        // var separators = new string[] { ".", "+<" };
        // var split = fullName.Split(separators, StringSplitOptions.None);
        // var name = split[split.Length == 1 ? 0 : 1];

        return trim.ToString();
    }
}
```