# IntroBox
An wasy way to create beautiful help and introductions for your command line program. Available options for the generated box are:
* Setting character for horizontal/vertical borders
* Setting box width in characters
* Setting box padding width (for now it's for all sides)
* Setting border width (for now it's for all sides)

Development ideas:
* Different padding/border width for left-right-bottom-top
* Word break to work correctly on long lines (setting how to handle word break)
* Easier content input through istream or some other way

Example code:
```cpp
int main() {
	std::string content;
	content += "This is IntroBox example\n\n";
	content +=
			"You can use IntroBox to create some beautiful command line helps for your programs\n";
	content += "There are multiple configuration params you can use:\n";
	content += "- Horizontal/vertical character to use\n";
	content += "- Box width\n";
	content += "- Padding width\n";
	content += "- Border width\n";
	content += "\nAnd later some more :)";

	IntroBox box(content);
	box.set_border_width(2);
	std::cout << box << std::endl;

	return 0;
}
```
Example output:
```
********************************************************************************
********************************************************************************
**                                                                            **
** This is IntroBox example                                                   **
**                                                                            **
** You can use IntroBox to create some beautiful command line helps for your  **
** programs                                                                   **
** There are multiple configuration params you can use:                       **
** - Horizontal/vertical character to use                                     **
** - Box width                                                                **
** - Padding width                                                            **
** - Border width                                                             **
**                                                                            **
** And later some more :)                                                     **
**                                                                            **
********************************************************************************
********************************************************************************
```
