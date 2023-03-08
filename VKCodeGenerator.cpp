// Includes.
#include "./incluSing.cpp";

// Translator function. Translates character by character the message taken by parameter.
void translator(string message) {
	// Variables needed to provide information and process the data.
	string reference;
	string inputArrayName;
	
	// User will need to prompt the name of the INPUT VK array so it can generate the name properly.
	cout << "What's the name of your <INPUT> array? (Will be used when generating the instructions!) ";
	cin >> inputArrayName;

	// Used to track the array index.
	int arrayTracker = 0;

	// Letting the user know that the process of translating already started.
	cout << "Translating...\n";
	Sleep(1000); // Sleep one second.
	system("CLS"); // Clear screen to leave only the result of the conversion.
	cout << "Result: \n";

	// Code block in charge of translating the message into VirtualKeyStrokes and returning them in code format.
	ofstream codeFile("./VKCodeGenerator.txt");
	for (auto currChar : message) {
		ifstream referencesFile("./VKReferences.txt");
		while(getline(referencesFile, reference)) {
			if(reference.find(currChar) != string::npos){
				string arrayTrackerStr = to_string(arrayTracker);
				auto currReference = reference.substr(2, 5);
				string VKType = inputArrayName + "[" + arrayTrackerStr + "].type=INPUT_KEYBOARD";
				string VKStroke = inputArrayName + "[" + arrayTrackerStr + "].ki.wVk=" + currReference;
				cout << VKType << endl;
				cout << VKStroke << endl;
				codeFile << VKType << endl;
				codeFile << VKStroke << endl;
			}
		}
		arrayTracker = arrayTracker + 1;
		referencesFile.close(); // Closes file so it can be read again.
	}
	cout << "You can manually copy the code in console. However, a file has been created where you have stored this program.";
	codeFile.close();
}

// Main function.
int main() {
	// Defines a variable that stores the text to translate.
	string txtToTranslate;
	cout << "Text to translate:\n";

	// Gets and process the text from the user.
	getline(cin, txtToTranslate);

	// Invoke translator function and pass it as parameter.
	translator(txtToTranslate);
	
	// Ask for user to prompt a letter so the program can close. This makes the console stay so the user can copy the generated code.
	char leave = '0';
	cout << "\nPrompt any letter when you copied the code (this will close the program).\n";
	cin >> leave;

	// End of main function.
	return 0;
}