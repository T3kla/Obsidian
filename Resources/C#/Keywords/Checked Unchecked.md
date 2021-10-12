# Checked/Unchecked

They delete themselves at the end of the code block.

```cs 
uint u = uint.MaxValue;
checked { u++; } // Will throw out OverflowException
unchecked { u++; } // Will not throw out OverflowException**
```