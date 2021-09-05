# Tangara
*Platform for containing apps written on multiple languages.*
## Interop with other languages
For example you using cool library written on C#.
```cs
class CSharpClass
{
	public static void Println(string str) => System.Console.WriteLine(str);
}
```
But you don't want write your code on C#. For example you use Kotlin. But Kotlin hasn't interop with C#/.NET so Tangara will helps you.
```kt
fun main() {
	CSharpClass.Println("Hello from Kotlin")
}
```
After writing your code, just compile it using Tangara and it will works!
## Using Tangara API for scripting or anything else
Tangara has C API that you can port on any platform. You can analyse builds using Tangara API.
```c
#include "Tangara.h"

int main(void)
{
	FILE* file = tgOpenRead("my_build.tgr");
	ClassBlock clb;
	tgReadClassBlock(file, &clb);
	tgClose(file);
	int i;
	for (i = 0; i < clb.count; i++)
		printf("%s\n", clb.classes[i].name);
}
```
