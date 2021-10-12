# String Builder

A buffer for strings. Extremely fast at appending because generally doesn’t need to allocate new space for string appends. When reused, it becomes the ultimate weapon against wasteful string allocations. Modifying its capacity can be an expensive operation because it may need to be reallocated, so capacity should always be stated in the constructor.

```cs
// Create a StringBuilder that expects to hold 50 characters.
// Initialize the StringBuilder with "ABC".
StringBuilder sb = new StringBuilder("ABC", 50);

// Append three characters (D, E, and F) to the end of the StringBuilder.
sb.Append(new char[] { 'D', 'E', 'F' });

// Append a format string to the end of the StringBuilder.
sb.AppendFormat("GHI{0}{1}", 'J', 'k');

// Display the number of characters in the StringBuilder and its string.
Console.WriteLine("{0} chars: {1}", sb.Length, sb.ToString());

// Insert a string at the beginning of the StringBuilder.
sb.Insert(0, "Alphabet: ");

// Replace all lowercase k's with uppercase K's.
sb.Replace('k', 'K');

// Display the number of characters in the StringBuilder and its string.
Console.WriteLine("{0} chars: {1}", sb.Length, sb.ToString());
```

---
# References
- [StringBuilder Class (System.Text) | Microsoft Docs](https://docs.microsoft.com/en-us/dotnet/api/system.text.stringbuilder?view=net-5.0)
