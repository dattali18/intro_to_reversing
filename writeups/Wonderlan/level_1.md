
In this level the password is also in plain sight `"into the rabbit hole"` but when trying to use it we get an error message so after taking a better look at the code we see a loop taking each `BYTE` from the `Buffer` variable (the input string from the user) and `xor` it with `0xA = 10` so we understood that we needed some kind of script that takes in a string and a key and `xor` each byte of the string and output the result.

![](Pasted%20image%2020250617112123.png)

```cpp
#include <iostream>
#include <string>

using uint8_t = unsigned char;

int main() {
	using namespace std;
	// get from the user a string and a key (1 byte)
	// xor the string with the key given in hexadecimal
	// output the result to the console
	string input;
	cout << "Enter a string to encrypt: ";
	getline(cin, input);
	string hex_key;
	cout << "Enter a key (1 byte in hexadecimal, e.g., 0x1A): ";
	cin >> hex_key;
	// convert the hex string to a uint8_t key
	uint8_t key = static_cast<uint8_t>(stoi(hex_key, nullptr, 16));
	string output = input; // copy input to output
	for (char &c : output) 
		c ^= key; // XOR each character with the key
	cout << "Given string: \"" << input << "\"" << endl;
	cout << "Key: 0x" << hex << static_cast<int>(key) << endl;
	cout << "Encrypted string: ";
	cout << output << endl;
	return 0;
}
```

![](Pasted%20image%2020250617112352.png)

After input the resulting string `"cd~e*~bo*xkhhc~*befo"` into the program as a password we get the success message.

![](Pasted%20image%2020250617112100.png)