In this level we get a very similar code structure to the last level (level-1) but this one has one difference:

![](Pasted%20image%2020250617112652.png)

Now instead of `xor` each char (`byte`) we `xor` a `dword` at a time with the `0x41524241` key.

So we wrote a new script to do so:

```cpp
#include <iostream>
int main() {
	const char* password = "into the rabbit hole";
	const uint32_t key = 0x41524241; // "ARBA" in ASCII
	std::string result;
	for (size_t i = 0; i < strlen(password); ++i) {
		// XOR each character with the key, cycling through the key's bytes
		result += password[i] ^ ((key >> ((i % 4) * 8)) & 0xFF);
	}
	std::cout << "Encrypted value: " << result << std::endl;
	return 0;
}
```

The resulting string is: `"(,&.a6:$a03##+&a)->$"`

![](Pasted%20image%2020250617113130.png)

![](Pasted%20image%2020250617113117.png)